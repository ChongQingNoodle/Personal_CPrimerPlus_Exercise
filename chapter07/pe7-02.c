// 2.编写一个程序读取输入,读到#字符停止。程序要打印每个输入的字符以及对应的ASCII码
// (十进制)。每行打印8个"字符-ASCII码"组合。建议:使用字符计数和求模运算符(%)在每8
// 个循环周期时打印一个换行符。

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STOP '#'

int main(void)
{
    char c; //def a char
    int n_chars = 0; //initialize the numbers of the n_chars
    int n = 0;
    printf("Enter sth please:");
    while ((c = getchar())!= STOP)
    {
        n_chars++; //统计字符
        printf("%d  ",c);
        n++; //增加换行符
        if (n==8)
        {
            printf("\n");
            n=0;
        }
    }
    printf("\n");
}