syms t;
syms y;
yt=dsolve('Dy+y=t','y(0)=1');
clear
syms k T t;
xt=dsolve('k*Dx+T*x=4*cos(t)+3*sin(t)','x(0)=1')



