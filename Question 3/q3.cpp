#include<iostream>
#include <iomanip>
#include<cmath>

double integrate_h(int n);

int main()
{
    for(int i=1;i<=5;i++)
    {
        std::cout << std::setprecision(16) << std::fixed;
        std::cout<<"n="<<i<<": "<<integrate_h(i)<<"\n";
    }
}
