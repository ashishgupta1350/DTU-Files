% program Starts

%x is matrix of given values
%y is the matrix of values corresponding to x
%x1 values have to be found
clear all;
close all
clc
% Input: Enter the following

disp('Newton forward and backward applied on the following data');
x=[0 0.1 0.2 0.3 0.4 0.5]
y=[-1.5 -1.27 -0.98 -0.63 -0.22 0.25]
x1=[0.15 0.25 0.45]

%Solution starts:
for l=1:3
    p=x1(l);
    fprintf('\n\nAppllying newton forward difference formula for x=%g.',x1(1));
    %newton forward interpolation formula
    n=length(x); 
    a(1)=y(1);
    for k=1:n-1
        d(k,l)=(y(k+1) - y(k))/(x(k+1) - x(k));%finite forward difference matrix
    end
    
    for j= 2:n
        a(j)=d(1,j-1);
    end
    Df(1)=1;
    c(1)=a(1);
    for j=2:n
        Df(j)=(p-x(j-1)).*Df(j-1);
        c(j)
    
    