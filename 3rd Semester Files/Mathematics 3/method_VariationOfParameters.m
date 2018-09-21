syms x t;
cf=dsolve('D2y+4*y=0');
y1dot=diff('cos(2*t)',t);
y2dot=diff('sin(2*t)',t);

w=[cos(2*t) sin(2*t) ;y1dot y2dot];
wdet=det(w);
w1=[0 sin(2*t); sec(t) y2dot];
w1det=det(w1);
w2=[cos(2*t) 0 ;y1dot sec(t)];
w2det=det(w2);
u=int(w1det/wdet);
v=int(w2det/wdet);
perticular_solution=u*cos(2*t)+v*sin(2*t);
Answer=cf+perticular_solution

