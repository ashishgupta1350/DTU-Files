function [  sol ] = lagrange_sam(n,x1)

    syms product;
    syms i j k;
    syms sum1;
    syms x;
    sum1=0;
    [m,k]=size(n);
    for i=1:m
        product =1;
        for j=1:m
        if(j==i)
        else
            product = product *((x- n(j,1))/(n(i,1)-n(j,1)));
        end
    end
    product = product *n(i,2);
    sum1 = sum1 + product;
    end
display(sum1);
sol = subs(sum1,x1);
end

