/*
11.编写一个程序。功能是读取输入,直到遇到EOF,并报告单词数、大写字母数、小写字母数、标
点符号数和数字字符数。使用ctype.h系列的函数。
*/
#include <stdio.h>
#include <ctype.h>
#define LIMIT 255

int main(void)
{
    char str[LIMIT];
    printf("Please input:\n");
    char a ;
    int words_amount = 0 , 
    upper_amount = 0 , 
    lower_amount = 0 ,
    punct_amount = 0 , 
    digit_amount = 0 ,
    n = 0;
    while ((a = getchar()) != EOF && n < LIMIT - 1)
    {
        str[n] = a;
        n++;
        if (isupper(a))
        {
            upper_amount++;
        }
        if (islower(a))
        {
            lower_amount++;
        }
        if (ispunct(a))
        {
            punct_amount++;
        }
        if (isdigit(a))
        {
            digit_amount++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isalpha(str[i]) && isspace(str[i+1]))
        {
            words_amount++;
        }
        else if (isalpha(str[i]) && ispunct(str[i+1]))
        {
            words_amount++;
        }
    }
    
    printf("Word : %d\n",words_amount);
    printf("Upper : %d\n",upper_amount);
    printf("Lower : %d\n",lower_amount);
    printf("Punct : %d\n",punct_amount);
    printf("Digit : %d\n",digit_amount);
}