/*
15.编写一个程序,其功能是读取输入,直到遇到文件结尾,并把文件显示出来。要求程序可以识别
并执行下面的命令行参数:
- p 按照原样显示输入
- u 把输入全部转换为大写
- l 把输入全部转换为小写
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81

void print_usage();
void print_file(FILE *fp , int mode);

int main(int argc , char * argv[])
{
    
    int mode = 'p';

    if (argc == 2)
    {
        if (strcmp(argv[1], "-p") == 0)
        {
            mode = 'p';
        }
        else if (strcmp(argv[1], "-u") == 0)
        {
            mode = 'u';
        }
        else if (strcmp(argv[1], "-l") == 0)
        {
            mode = 'l';
        }
        else
        {
            print_usage();
            return 1;
        }
    }
    else
    {
        print_usage();
    }
    
    print_file(stdin , mode);
}

void print_usage()
{
    printf("Usage: mycat [-p|-u|-l]\n");
}

void print_file(FILE *fp , int mode)
{
    char line[LIMIT];

    while (fgets(line , LIMIT , fp) != NULL)
    {
        switch (mode)
        {
        case 'p':
            printf("%s", line);
            break;
        case 'u':
            for (int i = 0; i < strlen(line); i++)
            {
                putchar(toupper(line[i]));
            }
            break;
        case 'l':
            for (int i = 0; i < strlen(line); i++)
            {
                putchar(tolower(line[i]));
            }
            break;
        default:
            printf("Invalid mode.\n");
            return;
        }
    }
}