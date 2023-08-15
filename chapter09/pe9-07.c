/*
7.在第6章"C控制语句:循环"的程序清单6.20中,函数power()的功能是返回一个double类
型数的某个正整数次幂。现在改进该函数,使其能正确地计算负幂。同时,用该函数实现0的任何次幂为
0,并且任何数值的0次幂为1。使用循环的方法编写该函数并在在一个程序中测试它
*/

#include "get.h"

double power(double n , int p);

int main(void)
{
    double a, b;
    printf("Enter a number (double): ");
    a = get_double();
    printf("Enter the power (int): ");
    b = get_int();
    a = power(a,b);
    printf("The power = %g\n",a);
}


double power(double n , int p)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (p > 0)
    {
        double pow = 1;
        int i;

        for ( i = 0; i <= p; i++)
        {
            pow *= n;
        }
        return pow;
    }
    else if (p ==0 )
    {
        return 1;
    }
    else
    {
        n = 1/n;
        p = -p;
        double pow = 1;
        for (int i = 0; i < p ; i++)
        {
            pow *= n;
        }
        return pow;
    }
}
