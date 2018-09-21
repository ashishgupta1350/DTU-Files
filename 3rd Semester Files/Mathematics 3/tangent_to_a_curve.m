hold off;
syms x t;
f1=1+x^2;
d(x)=diff(f1);
m=d(2);
c=5-m*2;
f2=m*x+c;
plot1=ezplot(f1);
set(plot1,'color','r');
hold on;
grid on;
plot2=ezplot(f2);
legend('1+x^2','y=m*x+c');
xlabel('X-axis');
ylabel('Y-axis');
title('Tangent to the curve');
ydot2=diff(diff(f1));
roc=sqrt((1+m^2)^3)/2
hold off;