% A is a matrix and apply gauss jordan method
syms x y z
eqn1= 2*x+3*y-z==2;
eqn2= 3*x+ 7*y+4*z==11;
eqn3= x-5*y-3*z==-4;

% covert the code to matrix with A and B
[A,B]=equationsToMatrix(eqn1,eqn2,eqn3);
%convert A,b to augmented matrix
augmat=[A,B];
%call the rref function
aug=rref(augmat);
%extract the elements
ans = aug*[0;0;0;1]