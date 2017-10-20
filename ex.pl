love(a,b).
love(b,c).
love(c,a).

sanjiaolian(X,Y,Z) :-
    love(X,Y),
    love(Y,Z),
    love(Z,X).

