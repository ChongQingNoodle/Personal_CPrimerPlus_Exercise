/*
12.编写一个程序,按照相反的单词顺序显示命令行参数。即,如果是命令行参数是see you later,
程序的显示应该为later you see。
*/
#include <stdio.h>
#include <string.h>
#define LIMIT 81

int main(int argc, char *argv[])
{
    while (argc > 1)
    {
        printf("%s ",argv[argc-1]);
        argc--;
    }
    printf("\n");
}