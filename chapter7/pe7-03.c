// 3.编写一个程序,读取整数直到用户输入0。输入结束后,程序应报告用户输入的偶数(不
// 包括0)个数、这些偶数的平均值、输入的奇数个数及其奇数的平均值。

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STOP 0


int main()
{
    int cnt_odd = 0;//统计奇数个数
    int cnt_even = 0;//统计偶数个数
    int sum_odd = 0;//统计奇数的和
    int sum_even = 0;//统计偶数的和
    int n;//扫描到的数字

    printf("Enter some number (0 to quit):\n");
    while((scanf("%d",&n)==1)&& n!= STOP)//成功读取且非终止
    {
        if (n%2 == 0)//对2取模，为零则偶
        {
            cnt_even++;
            sum_even += n;
        }
        if (n%2 == 1)//对2取模，为一则奇
        {
            cnt_odd++;
            sum_odd += n;
        }
    }

    printf("Odd numbers: %d\n" , cnt_odd);
    printf("Average of odd: %.2f\n",(float)sum_odd/cnt_odd);
    printf("Even numbers: %d\n" , cnt_even);
    printf("Average of even: %.2f\n",(float)sum_even/cnt_even);
}