hold off;
y0=1;
yspan=[-5,5];
[x,y]=ode45('fun1',yspan,y0);
%output
plot(x,y,'g*');
y1=y(3)
grid on;
title('using ode 45')
