#include<iostream>
#include<cmath>
#include <stdlib.h>

double diff_legendre(double x, int n);
double legendre(double x, int n);

//returns n gauss quadrature points x[] and weights w[].
void gauss_quadrature(int n, double x[], double w[])
{
    //initialise variables and tolerance for Newton method
    double x_i, tol=0.0000000000001, pi=3.14159265358979323846;
    for(int i=1;i<n+1;i++) //iterate for each gauss quadrature point
    {
        //initial guess
        x_i=-cos(pi*((2*(double)(i))-1)/(2*(double)(n)));
        //makes sure guess is within tolerance
        while (legendre(x_i,n)>tol|| legendre(x_i,n)<-tol)
        {
            //Newton Method to guess closer
            x_i=x_i-(legendre(x_i,n)/diff_legendre(x_i,n));
        }
        //add gauss quadrature points to array
        x[i-1]=x_i;
        //calculate weights and add to array
        w[i-1]=2/((1-pow(x_i,2))*pow(diff_legendre(x_i,n),2));
    }
}

