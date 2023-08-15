/*
9.编写一个函数。其参数为一个字符串,函数删除字符串中的空格。在一个可以循环读取的程序中进
行测试,直到用户输入空行。对于任何输入字符串,函数都应该适用并可以显示结果。
*/
#include <stdio.h>
#define LIMIT 81

void get_no_space_string(char * string);

int main(void)
{
    char str[LIMIT];
    get_no_space_string(str);
    puts(str);
    return 0;
}

void get_no_space_string(char * string)
{
    char a ;
    int n = 0;
    int stop = 0;
    while ( n < LIMIT-1 && stop < 2)
    {
        a = getchar();
        if (a == ' ')
        {
            continue;
        }
        else
        {
            *(string + n) = a;
            n++;
            if (a == '\n')
            {
                stop++ ;
            }
            else
                stop = 0;
        }
    }
}
