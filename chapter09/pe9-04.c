/*ex4两数值的协均值（调和平均）是这样计算的：首先对两个数值的倒数取平均值，
最后再取倒数。编写一个带有两个double参数的函数，计算两个参数的调和平均数。*/
#include "get.h"

void adjust_average(double u , double v);

int main(void)
{
    double a, b;
    printf("Enter the first number (double): ");
    a = get_double();
    printf("Enter the second number (double): ");
    b = get_double();
    adjust_average(a,b);
}

void adjust_average(double u , double v)
{
    double temp;
    u = 1/u;
    v = 1/v;
    temp = (u+v)/2;
    temp = 1/temp;
    printf("The adjust_average = %g\n", temp);
}