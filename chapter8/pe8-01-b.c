// 1.设计一个程序,统计在读到文件结尾之前读取的字符数。
// 这是第二种方法，重定向法
// ./prog > file1 输出到文件
// ./prog < file2 从文件输入

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int n = 0;
    int ch;
 
    while ((ch = getchar())!= EOF)
    {
        if(isspace(ch))
        {
            n=n;
        }
        else
            n++;
    }
    printf("%d\n",n);
    return 0;
}