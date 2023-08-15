/* append.c -- 把文件附加到另一个文件末尾*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);
char * s_gets(char * st, int n);

int main(void)
{
    FILE *fa, *fs;              //fa指向目标文件，fs指向源文件
    int files = 0;              //附加文件数量
    char file_app[SLEN];        //目标文件名
    char file_src[SLEN];        //源文件名
    int ch;

    puts("Enter name of destination file:");//输入一个文件名
    s_gets(file_app , SLEN);//从主要输入流中取80个字存到file_app指针中
    if ((fa = fopen(file_app, "a+")) == NULL)//在file_app这个文件的末尾添加内容，如果没有则创建
    {//如果指针指控，则返回无法打开
        fprintf(stderr , "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)//如果分配一个完全缓冲区未成功目标
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter name of first source file (empty line to quit):");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp(file_src, file_app) == 0)
        {
            fputs("Can't appen file to itself\n", stderr);
        }
        else if ((fs = fopen(file_src, "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", file_src);
        }
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE))
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
            {
                fprintf(stderr, "Error in reding file %s.\n",file_src);
            }
            if (ferror(fa) != 0)
            {
                fprintf(stderr, "Error in writing file %s.\n",file_app);
            }
            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empt line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n",file_app);
    while ((ch = getc(fa)) != EOF)
    {
        putschar(ch);
    }
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];          //只分配一次

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
    {
        fwrite(temp, sizeof(char), bytes, dest);
    }
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