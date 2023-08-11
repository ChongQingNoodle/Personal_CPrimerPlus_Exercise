// 1.编写一个程序读取输入,读到#字符停止,然后报告读取的空格数、换行符数和所有其他
// 字符的数量。

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define STOP '#'

int main(void)
{
    char c;
    int n_spaces = 0;
    int n_lines = 0;
    int n_chars = 0;

    printf("Enter sth please:");
    while ((c = getchar()) != STOP)
    {
        n_chars++;          //统计字符
        if (c == '\n')
            n_lines++;      //统计行数
        if (isspace(c))
            n_spaces++;     //统计空格
    }
    printf("characters = %d, spaces = %d, lines = %d.\n" , n_chars , n_spaces , n_lines);
    return 0;
}