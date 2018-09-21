syms x t;
f1=x^3- 3*x^2 +3*x;
f2=x^2;
plot1=ezplot(f1);
set(plot1,'color','r');
hold on;
plot2=ezplot(f2);
set(plot2,'color','g');
grid on;
legend('x^3- 3*x^2 +3*x','x^2');
xlabel('X-Axis');
ylabel('Y-Axis');
title('Area Enclosed');
area1=int(f1-f2,0,1);
area2=int(f2-f1,1,3);
area=area1+area2
