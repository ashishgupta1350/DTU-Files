function [ sol evalue ] = heat_exact( k, a )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
    syms G(t) phi(x) lambda
    [evalue phi coeff] = sturm_liouville(a);
    phi = subs(phi, lambda, evalue);
    t_ode = diff(G, t) == -k *lambda*G;
    t_sol = dsolve(t_ode);
    sol = t_sol * phi;

end

