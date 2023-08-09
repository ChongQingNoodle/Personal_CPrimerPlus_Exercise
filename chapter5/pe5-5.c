// 5.修改程序addemup.c
// (程序清单5.13),你可以认为addemup.c是计算20天里赚多少4钱的程
// 序(假设第1天赚$1、第2天赚$2、第3天赚$3,以此类推)。修改程序,使其可以与用户交
// 互,根据用户输入的数进行计算(即,用读入的一个变量来代替20)。

#include <stdio.h>


int main(void)
{
    int count , sum , n; 
    count = 0;
    sum = 0;
    printf("Please enter a number:");
    scanf("%d",&n);
    while (count++ < n)
        sum = sum + count ;
    printf("sum = %d\n", sum);
    return 0;
}