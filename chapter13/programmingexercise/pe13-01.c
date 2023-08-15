/*
1.修改程序清单13.1中的程序,要求提示用户输入文件名,并读取用户输入的信息,
不使用命令行参数。
*/

/* count.c -- 使用标准 I/O*/
#include <stdio.h>
#include <stdlib.h>//提供exit()原型

int main(int argc, char *argv[])
{
    int ch;//读取文件时，存储每个字符的地方
    char fname[81];
    FILE *fp;//“文件指针”
    unsigned long count = 0;
    printf("Please input a file name: ");
    scanf("%s", fname);
    
    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);//与putchar(ch);相同
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", fname , count);

    return 0;
}