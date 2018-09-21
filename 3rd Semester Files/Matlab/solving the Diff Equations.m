syms x;
f=3*sin(x)+7*cos(5*x);
lhs=diff(f,x,2)+f;
rhs=-5*cos(2*x);
if(isequal(lhs,rhs))
    disp('yes they are equal');
else 
    disp('No they are not true');
end
disp('value of LHS is : '),disp(lhs);