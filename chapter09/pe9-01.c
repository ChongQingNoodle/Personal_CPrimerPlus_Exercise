/*1.设计函数min(x,y)，返回两个double数值种较小的数值，同时用一个简单的驱动程序测试改函数*/
#include "get.h"

double min( double u, double v);

int main(void)
{
    double a, b;
    printf("Please enter the first number: ");
    a = get_double();
    printf("Please enter the second number: ");
    b = get_double();
    printf("The min is %g\n",min(a,b));
    return 0;
}

double min( double u, double v)
{
    if (u > v)
    {
        return v;
    }
    else if (v > u)
    {
        return u;
    }
    else
        return u;
}