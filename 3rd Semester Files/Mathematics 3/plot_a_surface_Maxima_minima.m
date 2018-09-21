clc;
clear;
syms x y; 
[x,y]=meshgrid(-2:0.03:2,-2:0.03:2);
f=-x.*y.*exp(-2*(x.^2+y.^2));
figure(1)
mesh(x,y,f),xlabel('X'),ylabel('y'),grid
figure(2) 
contour(x,y,f) 
xlabel('X'),ylabel('y'),grid,hold on 
fmax=max(max(f)) 
kmax=find(f==fmax)
pos=[x(kmax) y(kmax)]
%pos = -0.5000 0.5000 0.5000 -0.5000

plot(x(kmax),y(kmax),'*') 
text(x(kmax),y(kmax),'Maximum') 
%plotting the maximum value on the fraph
fmin=min(min(f))
kmin=find(f==fmin) 
pos1=[x(kmin) y(kmin)]
plot(x(kmin),y(kmin),'*') 
% We are plotting the minimum value now
text(x(kmin),y(kmin),'Minimum') 
hold off 