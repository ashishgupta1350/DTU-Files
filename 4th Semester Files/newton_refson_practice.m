syms x

y=x-(23/10)*(x^(10/23)-exp(1))/(x^(-13/23));

i=0;
x=8;
while i<10
    
    xkplus1=eval(subs(y));
    fprintf('the value of xk is %d and value of xk+1 is :%d ',x,xkplus1);
    x=xkplus1;
    i=i+1;
    fprintf('\n')
    eval(subs(x^(10/23)-exp(1)))
    
end