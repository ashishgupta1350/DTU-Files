%Gauss Elimination Method for 3*3 Matrix

syms x y z z1

eqn1 = 2*x + y + z +z1 == 2;
eqn2 = -x + y - z +3*z1== 3;
%eqn3 = x + 2*y + 3*z -4*z1 == -10;
eqn3= 3*x -3*y + 4*z -2*z1 == -5;
eqn4 = 3*x -3*y + 4*z -2*z1 == -5;

[A,B]=equationsToMatrix([eqn1,eqn2,eqn3, eqn4],[x y z z1]);


augA=[A,B];
ansMatrix=rref(augA)
b=[0;0;0;0;1];
ansMatrix1=ansMatrix*b

