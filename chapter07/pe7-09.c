// 9.编写一个程序,只接受正整数输入,然后显示所有小于或等于该数的素数。

#include <stdio.h>
#include <stdlib.h>
#define STOP 'q'

int isPrime(int n);

int main(void)
{
    unsigned int num;
    printf("Enter a unsigned number:");
    while (scanf("%u",&num)==1)
    {
        for (int i = 1; i < num; i++)
        {
            if (isPrime(i))
            {
                printf("%d\n",i);
            }
        }
        printf("Enter a unsigned number again ( not number to quit ):");
    }
    printf("End.\n");
}

int isPrime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        int i;
        for (i = 2; i < n; i++)
        {
            if(n%i == 0)
            {
                break;
            }
        }
        if (i<n)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}