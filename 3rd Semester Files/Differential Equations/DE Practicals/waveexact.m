function [ sol evalue ] = waveexact( k, a )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    syms X(x) T(t) sig c1 c2 d1 d2 C3 C4
    [evaluet X coeffx] = sturm_liouville(sig);
    [evaluet T coefft] = sturm_liouville(k * sig);
    T = subs(subs(subs(T, x, t), C3, d1), C4, d2);
    sol = [T * X];

end

 