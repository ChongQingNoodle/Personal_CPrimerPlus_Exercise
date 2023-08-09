// 17.Chuckie Lucky赢得了100万美元(税后),他把奖金存入年利率8%的账户。在每年的最后
// 一天,Chuckie取出10万美元。编写一个程序,计算多少年后Chuckie会取完账户的钱?

#include<stdio.h>

int main(void)
{
    double s = 0.08;
    double a = 1000000;
    int i = 0;
    do
    {
        i++;
        a = a * (1+s);
        a = a - 100000;
    } while (a>0);
    printf("The year is %d.\n" , i );
    return 0;
}