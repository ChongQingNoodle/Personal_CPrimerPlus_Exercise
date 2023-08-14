/*
9.为了使程序清单9.8中的函数to_binary()更一般化,可以在新的函数to_base_n()中使用第二
个参数,且该参数的范围从2到10。然后,这个新函数输出第一个参数在第二个参数规定的进制数下的数
值结果。例如,to_base_n(129,8)的输出是201,也就是129的八进制数值。最后在一个完整的程序中
对该函数进行测试。
*/

/*binary.c -- 以二进制形式输出函数*/
#include "get.h"
void to_binary(unsigned long n);
void to_base_on(unsigned long n, int i);

int main(void)
{
    int a, b ,c;
    printf("Now we trust to_binary function.\n");
    printf("Enter a number (int): ");
    a = get_int();
    printf("The first number in to_binary() is ");
    to_binary(a);
    printf("\n");
    printf("Now we trust to_base_on function.\n");
    printf("Enter the second number (int): ");
    b = get_int();
    printf("Enter the third number (int): ");
    c = get_int();
    printf("The 2 and 3 in to_base_on function is ");
    to_base_on(b,c);
    printf("\n");
}

void to_binary(unsigned long n)
{
    int r;
    r = n%2;
    if (n >= 2)
        to_binary(n/2);
    putchar('0'+r);

    return;
}

void to_base_on(unsigned long n, int i)
{
    if ( i<2 || i>10 )
    {
        printf("The function to_base_on's second var should be in 2 to 10!\nPlease check.\n");
        return;
    }
    int r;
    r = n%i;
    if (n>= i)
    {
        to_base_on(n/i,i);
    }
    putchar('0'+r);

    return;
}