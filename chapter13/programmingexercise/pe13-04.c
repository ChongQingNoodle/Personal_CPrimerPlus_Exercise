/*
4.编写一个程序,按顺序在屏幕上显示命令行中列出的所有文件。使用argc控制循环。
*/

#include <stdio.h>
#include <stdlib.h>//exit()
#include <string.h>
#define LEN 40

int main(int argc, char * argv[])
{
    FILE * in;
    int ch;
    char name[LEN];
    int count = 1;

    if (argc < 2)
    {
        fprintf(stderr, "Usage %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    

    while (count < argc)
    {
        printf("FILE NO.%d %s:\n", count ,argv[count]);
        if ((in = fopen(argv[count],"rb")) == NULL)
        {
            fprintf(stderr, "Couldn't open the file \"%s\"\n", argv[count]);
            
        }
        else
        {
            while ((ch = getc(in))!= EOF)
            {
                putc(ch, stdout);
                
            }
            printf("\n");
            printf("\n");
            if (fclose(in) != 0)
            {
                fprintf(stderr, "Error in closing files\n");
            }
        }
        count++;
    }
    return 0;
}