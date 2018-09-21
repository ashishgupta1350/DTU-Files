% make a table of values where you take X, FX

% make the difference table

% Write the formula of newton forward interpolation

% Take the values from the table and the required data according to the
% initial value 

% place the result in a container and print this result

%Newton's Forward and Backward Difference Interpolation
%x is the matrix for which value is given
%y is the matrix giving values corresponding to
%x1 is the matrix whose values are to be found
clear all: close all: cle:
%INPUTS: Enter the following
disp('The Newton Forward and Backward interpolation formala applied on the following data.');
x= [0 0.1 0.2 0.3 0.4 0.51]
y=[-1.5 -1.27 -0.98 -0.63 -0.22 0.25]
xl-[0.15 0.25 0.45]
%Solution starts here..
for l=1:3
    p=xl(1);
fprintf('\n\nApplying Newton forward Interpolation difference formula for x =%g.',xl (1));
%Newton's Forward Interpolation Formula
n length (x) = calculating length of
(1) = y(1):
for k = 1 n 1
end
difference matrix
for j = 2 n 1
d (k, 1) = (y (k+1) y(k) 1/(x (k+1) xk): finite forward
for k 1 n
end
end
for 3 2 n
d (k. (d (k+1, 1 1) d (k, 3 114xx (k) -x(K):
end
DF (1) = 1;
a (3) d(1, 3-1):
c(1) = a (1):
for j = 2 n
Df (3) (p x (i-1)). DE (3-1):

end
fp-surm (c):
fprintf("\nwe get value as Sg.', fp): finding sum
fintf("\n\nApplying Newton Backward Interpolation difference
formula for x= g. ',xl (1):
Newton's Backward Interpolation Formula
diff (1,1)=y(i): 1finite backwa
for i=1:n ut finite backward difference operator matr

end

2K13/MC/081