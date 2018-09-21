syms myFunc diffMyFunc 

myFunc=x^3-4*x-9;
x0=3;%take this as input
diffMyFunc=diff(myFunc);
x=x0;
for i=[0:3]
   
   x=x0-subs(myFunc)./subs(diffMyFunc);
   x0=x;
   
end
x0