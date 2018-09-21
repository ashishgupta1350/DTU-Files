function[y] = lagrange(x,n)
    ax=input('the given abscisssae');
    ay=input('the given ordinates');
    y=0;
    for i=1:n
        nr=1;
        dr=1;
        for j=1:n
        if(j~=i)
        nr=nr*(x-ax(j));
        dr=dr*(ax(i)-ax(j));
    end
   end
    y=y+(nr/dr)*(ay(i));
 end
fprintf('The required value of y is: %f',y);
