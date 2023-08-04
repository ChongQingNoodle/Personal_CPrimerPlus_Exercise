// 5.一年大约有3.156×107秒。编写一个程序,提示用户输入年龄,然后显示该年龄对应的秒数。

#include <stdio.h>

int main(void)
{
    printf("How old are you?:");
    int n;
    scanf("%i" , &n);
    printf("Well , you have been living for %e seconds!\n", n * 3.156e7);
    return 0;
}