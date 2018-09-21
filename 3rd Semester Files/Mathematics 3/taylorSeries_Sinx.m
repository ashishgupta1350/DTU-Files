syms f x;
f=taylor(sin(x),'Order',11)% it represents the powers from 0
%all the way upto 10  
h=ezplot(x,f);
set(h,'color','r');
grid on;
hold on;
y=sin(x);
plot2=ezplot(y);
set(plot2,'color','g');
hold off;


