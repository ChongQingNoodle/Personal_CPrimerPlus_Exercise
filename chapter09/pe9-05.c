/*5.编写并测试函数larger_of(),其功能是将两个double类型变量的数值替换成它们中的较大值。
例如,larger_of(x,y)会把x和y中的较大数值重新赋给变量x和y*/

#include "get.h"

void large_of(double * u, double * v);

int main(void)
{
    double a, b;
    printf("Enter the first number (double): ");
    a = get_double();
    printf("Enter the second number (double): ");
    b = get_double();
    large_of(&a,&b);
    printf("The large of them = %g\n",a);
}

void large_of(double * u, double * v)
{
    if (*u >= *v)
    {
        *v = *u;
        *u = *u;
    }
    else
        *u = *v;
        *v = *v;
}