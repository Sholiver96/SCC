#include <cmath>

//return dP_n/dx(x) where P_n is the Legandre polynomial
double diff_legendre(double x, int n)
{
    //initialise variables
    double diff_P_0 = 0, diff_P_1 = 1, diff_P_n;

    //if n>1, iterate for find diff_P_n
    if (n>1)
    {
        for(int i=1;i<n;i++)
        {
            //calc diff_P_n+1 from diff_P_n and diff_P_n-1
            diff_P_n=((2*i+1)*x*diff_P_1/i)-((i+1)*diff_P_0/i);
            //diff_P_0 is diff_P_n-1
            diff_P_0=diff_P_1;
            //diff_P_1 is diff_P_n
            diff_P_1=diff_P_n;
        }
        return diff_P_n;
    }
    //know for n=1 or n=0
    else if (n=1)
    {
        return 1;
    }
    else if (n=0)
    {
        return 0;
    }
}

