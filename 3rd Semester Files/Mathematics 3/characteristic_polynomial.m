function [ co ] = charpoly( A ) 
[m n]=size(A) ;
if m~=n
  disp('matrix is not square') 
  co=[] ;
  return
end
for i=1:(n+1) 
    x(i)=(i-1)*pi/n;
    y(i)=det(A-x(i)*eye(n)); 
    % det is used to find determinant of 
end
co=polyfit(x,y,n);

A=[1 2 3; 4 5 6 ; 7 8 9];
charpoly(A)
z=length(ans);
syms x;
f=0; 
i=4; 
for y=1:1:z 
    f=f+ans(y).*x.^(i-1);
    i=i-1;
end
f