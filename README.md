## Prolog 使用笔记

### 安装

下载 Windows版本 prolog

下载页面：http://www.swi-prolog.org/download/stable

我选择了 **[SWI-Prolog 7.6.0-rc2 for Microsoft Windows (64 bit)](http://www.swi-prolog.org/download/stable/bin/swipl-w64-760-rc2.exe)** 下载安装

安装后，启动 **C:\Program Files\swipl\bin\swipl-win.exe**，可以打开 prolog 控制台。


### 打开现成的 Prolog 程序

比如，[Prolog 的 C++ 开发包](https://github.com/SWI-Prolog/packages-cpp) 里有一个示例程序 **likes.pl**

克隆该项目到本地
```
git clone https://github.com/SWI-Prolog/packages-cpp.git
```

在目录中可以找到 likes.pl 文件，双击打开

在弹出的控制台中输入 

```
likes(X,Y).
```
然后会输出，所有 X 喜欢 Y 的关系


### 编写 prolog 程序

首先在桌面创建一个 Prolog 文件 **ex.pl**

然后在 prolog 控制台中点击 **File --> Edit**，选择刚刚创建的 **ex.pl**

然后我们便可以编辑 **ex.pl** 文件：
```
love(a,b).
love(b,c).
love(c,a).

sanjiaolian(X,Y,Z) :-
    love(X,Y),
    love(Y,Z),
    love(Z,X).
```
按住 **ctrl+s** 保存

双击刚刚编辑过的 ex.pl 文件

在弹出的控制台中输入
```
sanjiaolian(a,b,c)
```
正确输出
```
true
```
我们**成功判断了 a，b，c 三个人是否为三角恋关系**


### [packages-cpp](https://github.com/SWI-Prolog/packages-cpp) likes demo 安装测试
**注意**：安装需在 linux 环境、默认已经安装 g++ 编译器

1. 安装 swipl  
```
wget http://www.swi-prolog.org/download/stable/src/swipl-7.6.0.tar.gz
tar zvxf swipl-7.6.0.tar.gz
cd swipl-7.6.0/
./configure
make
make install
```

2. 克隆仓库 packages-cpp，编译 likes.cpp 和 likes.pl  
```
git clone https://github.com/SWI-Prolog/packages-cpp.git
cd packages-cpp/
swipl-ld -o likes -ld g++ -goal true likes.cpp likes.pl
```
swipl-ld 参数说明：
[11.5 Linking embedded applications using swipl-ld](http://www.swi-prolog.org/pldoc/man?section=plld)

3. 运行测试  
输入
```
./likes
```
输出（提示信息）
```
Usage: likes x [y] or likes -happy
```
输入
```
./likes -happy
```
输出
```
Happy people:
        mary
        mary
        john
        sue
        paul
        jane
```
输入
```
./likes mary
```
输出
```
mary likes:
        john
        potplants
        jane
        paul
        Heartbreak High
        sunbathing
```