/*
6.使用命令行参数的程序依赖于用户的内存如何正确地使用它们。重写程序清单13.2中的程序,不
使用命令行参数,而是提示用户输入所需信息。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

char * s_gets(char * st, int n);

int main(void)
{
    FILE * in, * out;
    int ch;
    char namein[LEN];
    char nameout[LEN];
    int count = 0;

    puts("Enter name of destination file:");//input a file name
    s_gets(namein, LEN);
    if ((in = fopen(namein, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", namein);
        exit(EXIT_FAILURE);
    }
    
    strncpy(nameout, namein, LEN - 7 );
    nameout[LEN - 7] = '\0';
    strcat(nameout, ".myred");
    if ((out = fopen(nameout, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    
    while ((ch = getc(in)) != EOF)
    {
        if (count++ % 3 == 0)
        {
            putc(ch, out);
        }
        
    }
    
    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error in closing files\n");
    }
    
    return 0;
}

char * s_gets(char * st, int n)//从主要输入流获取字符串同时返回到指针中
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');        //查找换行符
        if (find)                       //如果地址不是NULL
        {
            *find = '\0';               //在此处放置一个空字符
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}