%Van Der Paul equation solving using ode45 in Matlab
 
% for Mu=0.1
 
type vanderpoldemo
tspan=[0,20];
y0=[2;0];
Mu=0.1;
ode=@(t,y)vanderpoldemo(t,y,Mu);
[t,y]=ode45(ode,tspan,y0);
 
%ploting the solution on to graph
 
plot(t,y(:,1))
xlabel('t -> axis')
ylabel('Soln Y')
title('Van Der Paul Equation For Mu=0.1')
