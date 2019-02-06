#include <cmath>

//returns the P_n(x) where P_n is a Legendre polynomial
double legendre(double x, int n)
{
    //initialise variables. P_0 and P_1 known
    double P_0 = 1, P_1 = x, P_n;
    //if n>1, iterate to find solution
    if (n>1)
    {
        for(int i=1;i<n;i++)
        {
            //P_n+1 = (2n+1)x*P_n/(n+1)   -   n*P_n-1/(n+1)
            P_n=((2*i+1)*x*P_1/(i+1))-(i*P_0/(i+1));
            //P_0 is now P_n-1
            P_0=P_1;
            //P_1 is now P_n
            P_1=P_n;
        }
        return P_n;
    }
    //already know n=1 and n=0
    else if (n=1)
    {
        return P_1;
    }
    else if (n=0)
    {
        return P_0;
    }
}
