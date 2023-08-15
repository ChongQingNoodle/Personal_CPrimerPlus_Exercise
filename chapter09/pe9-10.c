/*
10.编写并测试一个函数Fibonacci(),
在该函数中使用循环代替递归完成斐波纳契数列的计算
*/
#include "get.h"

long Fibonacci (int n);
long Fibonacci_new(int n);

int main(void)
{
    int n;
    printf("Enter a number (int) to get its Fibonacci: ");
    n = get_int();
    for (int i = 1; i <= n; i++)
    {
        printf("%ld  ",Fibonacci_new(i));
    }
    printf("\n");
}

long Fibonacci (int n)
{
    if (n >2)
    {
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
    else
        return 1;
}

long Fibonacci_new(int n)
{
    int i = 1;
    int j = 1;
    int tmp;
    if (n > 2)
    {
        for (int k = 1; k <= (n-2); k++)
        {
            tmp = i;
            i = i+j;
            j = tmp;
        }    
    }
    else
        i = 1;
    return i; 
}