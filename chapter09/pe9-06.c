/*
6.编写一个程序,使其从标准输入读取字符,直到遇到文件结尾。对于每个字符,程序需要检查并报
告该字符是否是一个字母。如果是的话,程序还应报告该字母在字母表中的数值位置。例如,c和C的字
母位置都是3。可以先实现这样一个函数:接受一个字符参数,如果该字符为字母则返回该字母的数值位
置,否则返回-1。
*/

#include <stdio.h>
#include <ctype.h>

void alpha_number(char ch);

int main(void)
{
    char ch;
    while ((ch = getchar())!= EOF)
    {
        alpha_number(ch);
    }
    printf("End\n");
}

void alpha_number(char ch)
{
    int n;
    if (isalpha(ch))
    {
        n = tolower(ch) - 'a'+1;
        printf("%c is no.%d\n",ch, n);
    }
    else
        printf("%c is not an alpha.\n",ch);
}