//2.编写一个程序,要求提示输入一个ASCII码值(如,666),然后打印输入的字符。
#include <stdio.h>

int main(void)
{
    int n;
    printf("Please enter a number:");
    scanf("%i",&n);
    char a;
    a = n;
    printf("This number in ASCII is %c.\n",a);
}