// 1.设计一个程序,统计在读到文件结尾之前读取的字符数。
// 这是第一种方法，让用户输入需要读取的文件的名称
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    int n = 0;
    int ch;
    char fname[50];

    printf("Enter the name of file:");
    scanf("%s", fname);
    fp = fopen(fname,"r");
    if(fp == NULL)
    {
        printf("Failed to open file. Bye\n");
        exit(1);
    }
    while ((ch = getc(fp))!= EOF)
    {
        if(isspace(ch))
        {
            n=n;
        }
        else
            n++;
    }
    printf("%d\n",n);
    fclose(fp);
    return 0;
}