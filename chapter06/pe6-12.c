// 12.考虑下面两个无限序列:
// 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
// 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
// 编写一个程序计算这两个无限序列的总和,直到到达某次数。提示:奇数个-1相乘得-1,偶数
// 个-1相乘得1。让用户交互地输入指定的次数,当用户输入0或负值时结束输入。查看运行100
// 项、1000项、10000项后的总和,是否发现每个序列都收敛于某值?

#include <stdio.h>
#include <math.h>

long double a1(long double i);
long double b1(long double i);

int main(void)
{
    long double n;
    printf("Please input the times you want:");
    while(scanf("%Lf" , &n)==1)
    {
    printf("%Lf\n" , a1(n));
    printf("%Lf\n" , b1(n));
    printf("enter again:");
    }
    printf("done.\n");
}

long double a1(long double i)
{
    long double A = 0;
    for (long double n = 1 ; n <= i; n++)
    {
        A = A+1/n;
    }
    return A;
}

long double b1(long double i)
{
    long double B = 0;
    for (long double n = 1; n <= i; n++)
    {
        B = B - pow(-1,n)/n;
    }
    return B;
}