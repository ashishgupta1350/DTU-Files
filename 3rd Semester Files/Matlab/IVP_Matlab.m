% linear_DE_IVP_Solver : solves a system of linear homogeneous DE IVP functions 
% linear_DE_IVP_solver(A,B,C)--> [sols,vals]

function [sols,vals]=linear_DE_IVP_solver(A,B,C)
    syms t lambda
    n=length(A);
    [V, D]=eig(A);
    eigenValues=diag(D);
    consts=reshape(sym('c%d',1:n),n,1);
    unique_eigenValues=unique(eigenValues);
    mults=histc(eigenValues,unique_eighenValues);
    sols=sym('x%d',[1 n]);
    if length(unique_eigenValues)~=length(eigenValues)
        %for the 2nd case :  IE repeating eigen values
        i=1;
        ch_mat=A-lambda*eye(n);
        V=vpa(V);
        while i<=n
            [pos]=find(unique_eigenValues==eigenValues(i));
            if mults(pos) > 1
                e_vector=V(:, i);
                a_mat=subs(ch_mat,eigenValues(i));
                for  j = 1:mults(pos)
                    p=inv(a_mat^(j-1))*e_vector;
                    V(:,i)=V(:,i).*(t^(j-1));
                    V(:,i)=V(:,i)+p;
                    i=i+1;
                end;
            else
                i=i+1;
            end;
        end;
    end;
    for i=1:n
        sols(i)=(V(i,:).* exp(eigenValues' *t)*consts);
    end;
    vals=solve(subs(sols,t,B)==C);
    costNames=fieldnames(vas);
    %Final solutions --->answers
    
    for i =1:n
        sols=subs(sols,consts,vals.(costNames{i}));
    end;
    
    %Invocation of the made function
    
    linear_DE_IVP_solver([1 2;3 2], 0 ,[0 -4])
    
        
        