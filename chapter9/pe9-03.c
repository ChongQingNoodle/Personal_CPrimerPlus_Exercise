/*3.编写一个函数。函数的3个参数是一个字符和两个整数。字符参数是需要输出的字符。第一个整数
说明了在每行中该字符输出的个数,而第二个整数指的是需要输出的行数。编写一个调用该函数的程序。*/
#include "get.h"

void cube(char ch, int i, int j);

int main(void)
{
    char c;
    int a , b;
    printf("Enter a char: ");
    c = get_first();
    printf("Enter first number: ");
    a = get_int();
    printf("Enter second number: ");
    b = get_int();
    cube(c , a, b);
}

void cube(char ch, int i, int j)
{
    for (int m = 0; m < j; m++)
    {
        for (int n = 0; n < i; n++)
        {
            printf("%c",ch);
        }
        printf("\n");
    }
}