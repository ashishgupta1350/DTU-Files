
syms x

y=x*exp(x)-3;
x1=1;
x2=1.5;
x=x2;
f2=double(subs(y));
x=x1;
f1=double(subs(y));
count=0;
fprintf('Running code\n')
while count<6
    x3=calcFunction(y,x2,x1);
    fprintf('Value of x1 and x2 is : ')
    x1
    x2
    fprintf('Value of x3 is : ')
    x=x3
    fprintf('\n')
    fx3=double(subs(y));
    if fx3*f1<0
        x2=x3;
    else 
        x1=x2;
        x2=x3;
    end
    count=count+1;
end
fprintf('The Final Root is : ')
x3


