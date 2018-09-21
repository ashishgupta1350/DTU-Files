function factor=calcFunction(fun,x2,x1)
    x=x2;
    f2=double(subs(fun));
    x=x1;
    f1=double(subs(fun));
    
    factor=x2-((x2-x1)./(f2-f1))*f2;
end