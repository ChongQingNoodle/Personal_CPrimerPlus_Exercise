// 6.编写一个程序打印一个表格,每一行打印一个整数、该数的平方、该数的立方。要求用户
// 输入表格的上下限。使用一个for循环。

#include <stdio.h>

int main(void)
{
    int lower;
    int upper;
    printf("Please enter lower and upper integer limits:");
    scanf("%d %d" , &lower , &upper);
    if ((lower < upper))
    {
        printf("int   quater   cube\n");
        for ( int i = lower ; i <= upper; i++)
        {
            printf("%d      %d      %d\n",i,i*i,i*i*i);
        }   
    }
    printf("Done.\n");
    return 0;
}