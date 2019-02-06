#include<iostream>
#include<cmath>
#include <stdlib.h>

double integrate_f(int n);

int main()
{
    double pi=3.14159265358979323846, actual_value=-sinh(pi), approx_value, abs_error;
    for(int i=1;i<=10;i++)
    {
        approx_value=integrate_f(i);
        if (approx_value>actual_value)
        {
            abs_error=approx_value-actual_value;
        }
        else
        {
            abs_error=actual_value-approx_value;
        }
        std::cout<<"n="<<i<<": "<<approx_value<<", Which has error: "<<abs_error<<"\n";
    }
}
