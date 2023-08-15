/*
14.使用字符分类函数实现atoi()函数。
*/
#include <stdio.h>
#include <ctype.h>

int my_atoi(const char *str);

int main(void)
{
    char str[10] = "13";
    int num;
    num = my_atoi(str);
    printf("%d\n" , num);
}


int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    // 跳过空白字符
    while (isspace(*str))
    {
        str++;
    }

    // 处理符号
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
        {
            sign = -1;
        }
        str++;
    }

    // 转换数字
    while (isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}