function[e_value,e_function,non_zero]=sturm_liouville(L)
syms y(x);
syms lambda n;
sprintf('solving for various values of lambda=')
sprintf('for lambda >0')
assume(lambda>0)
solution=dsolve(diff(y,2)+lambda*y==0);
e_function=solution;
diff_sol=diff(solution,x);
vals=vpasolve(subs(diff_sol,0)==0,subs(diff_sol,L)==0);
non_zero=vals;
sprintf('non zero values in solution')
vals
%%eigen value sfor this solution
e_value=[(n*pi)/L].^2;
sprintf('when lambda=0')
try
    solution =dsolve(subs(diff(y,2)+lambda*y==0),lambda,0);
catch
    sprintf('no trivial solution')
end
sprintf('when lambda <0')
assume(lambda<0)
solution=dsolve(diff(y,2)+lambda*y==0);
diff_sol=diff(solution,x);
%%no explicit trivial solutionn possibkle
vals=vpasolve(subs(diff_sol,0)==0,subs(diff_sol,L)==0);
