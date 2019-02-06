#include<iostream>
#include<cmath>

void gauss_quadrature(int n, double x[], double w[]);

//uses gauss quadrature points and weights to approximate the integral of f(x) = pi*cos(pi*x)*exp(pi*x) between -1 and 1.
double integrate_f(int n)
{
    //initialise variables/arrays
    double *x, *w, pi=3.14159265358979323846, integral_approx=0;
    x=new double [n];
    w=new double [n];

    //find gauss quadrature points and weights
    gauss_quadrature(n, x, w);
    //integral = sum of w[i]*f(x[i])
    for (int i=0; i<n; i++)
    {
        integral_approx=integral_approx+(pi*w[i]*cos(pi*x[i])*exp(x[i]*pi));
    }
    //delete arrays
    delete [] x;
    delete [] w;
    return integral_approx;
}
