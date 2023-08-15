/*
3.编写一个文件拷贝程序,提示用户输入文本文件名,并以该文件名作为原始文件名和输出文件
名。该程序要使用ctype.h中的toupper()函数,在写入到输出文件时把所有文本转换成大写。
使用标准I/O和文本模式。
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define LEN 41

int main(int argc, char * argv[])
{
    FILE * fin, * fout;
    int ch;
    char name[LEN];
    
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ((fin = fopen(argv[1], "r")) == NULL )
    {
        fprintf(stderr , "I couldn't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    strncpy(name, argv[1], LEN - 7);
    name[LEN - 7] = '\0';
    strcat(name, ".upcpy");
    if ((fout = fopen(name , "wb")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    while ((ch = getc(fin)) != EOF)
    {
        putc(toupper(ch), fout);
    }
    
    if (fclose(fin) != 0 || fclose(fout) != 0)
    {
        fprintf(stderr, "Error in closeing files\n");
    }
    return 0;
}