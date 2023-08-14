/*设计函数chline(ch,i,j)，实现指定字符在i列到j列的输出，并用一个简单的驱动程序测试改函数*/
#include "get.h"

void chline(char ch, int i, int j);

int main(void)
{
    char c;
    int a, b;
    printf("Please input a char: ");
    c = get_first();
    printf("Please input first number: ");
    a = get_int();
    printf("Please input second number(bigger than first): ");
    b = get_int();
    chline(c , a , b);
    return 0;
}

void chline(char ch, int i, int j)
{
    for (int n = 1; n < i; n++)
    {
        printf(" ");
    }
    for (int m = 0; m <= (j-i); m++)
    {
        printf("%c" , ch);
    }
    printf("\n");
}