### 依赖
* linux 环境
* SWI-Prolog
* g++

### 编译
```
swipl-ld -o love -ld g++ -goal true love.cpp love.pl
```

### 运行测试
```
root@ubuntu:~/prolog-demo# ./love
Usage: love x [y] or love -sanjiaolian
root@ubuntu:~/prolog-demo# ./love a
a love:
        b
root@ubuntu:~/prolog-demo# ./love b
b love:
        c
root@ubuntu:~/prolog-demo# ./love c
c love:
        a
root@ubuntu:~/prolog-demo# ./love a b
yes
root@ubuntu:~/prolog-demo# ./love b c
yes
root@ubuntu:~/prolog-demo# ./love c a
yes
root@ubuntu:~/prolog-demo# ./love a c
no
root@ubuntu:~/prolog-demo# ./love -sanjiaolian
Sanjiaolian people:
        a
        b
        c
        b
        c
        a
        c
        a
        b
```

### 尾声
本代码参考自官方demo --> likes.pl 和 likes.cpp
