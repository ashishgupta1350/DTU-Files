A=[1 2 1;2 3 5;7 1 2];
B=[5;7;0];
Aug=[A,B];
flag=0;
RankofA=rank(A);
RankOfAug=rank(Aug);
if(RankofA~=RankOfAug)
    fprintf('The given system of equations is inconsistent')
    flag=1;
else
        fprintf('The given system is consistent\n')
        
end
clear X;
if(flag==0)
    
   % fprintf('\n')
   X=inv(A);
   
   Ans=(X*B)
end