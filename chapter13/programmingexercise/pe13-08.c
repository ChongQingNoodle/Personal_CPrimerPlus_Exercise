/*
8.编写一个程序,以一个字符和任意文件名作为命令行参数。如果字符后面没有参数,该程序读取
标准输入;否则,程序依次打开每个文件并报告每个文件中该字符出现的次数。文件名和字符本身
也要一同报告。程序应包含错误检查,以确定参数数量是否正确和是否能打开文件。如果无法打开
文件,程序应报告这一情况,然后继续处理下一个文件。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 41

static int mode;

void SetMode(int n);


int main(int argc, char * argv[])
{
    int ch , alphaCount = 0, fileCount = 0;
    int fileChar;
    FILE * filePoint;
    char name[LEN];
    SetMode(argc);

    if (mode == 1 )
    {
        if (strlen(argv[1]) > 1)
        {
            fprintf(stderr , "Usage %s [character] [filename1] [filename2] ...\n%s must be one alpha, now I will use %c\n" , argv[0], argv[1], argv[1][0]);
        }
        ch = argv[1][0];
        printf("Please input your words: \n");
        while ((fileChar = fgetc(stdin)) != EOF)
        {
            if (ch == fileChar)
            {
                alphaCount++;
            }
        }
        printf("\"%c\" in your input counts : %d\n", ch, alphaCount);
        alphaCount = 0;
    }
    else if(mode == 2)
    {
        if (strlen(argv[1]) > 1)
        {
            fprintf(stderr , "Usage %s [character] [filename1] [filename2] ...\n%s must be one alpha, now I will use \"%c\"\n" , argv[0], argv[1], argv[1][0]);
        }
        ch = argv[1][0];
        for (fileCount = mode; fileCount < argc; fileCount++)
        {
            if ((filePoint = fopen(argv[fileCount],"r")) == NULL)
            {
                fprintf(stderr , "Error in open \"%s\"\n", argv[fileCount]);
                continue;
            }
            while ((fileChar = fgetc(filePoint)) != EOF)
            {
                if (ch == fileChar)
                {
                    alphaCount++;
                }
            }
            printf("\"%c\" in file \"%s\" : %d\n", ch, argv[fileCount], alphaCount);
            alphaCount = 0;
            if (fclose(filePoint) != 0)
            {
                fprintf(stderr, "Error in close \"%s\"\n", argv[fileCount]);
            }
        }
    }
    else
    {
        fprintf(stderr, "Usage %s [character] [filename1] [filename2] ...\n" , argv[0]);
        exit(EXIT_FAILURE);
    }
    
}

void SetMode(int n)
{
    if(n == 2)
    {
        mode = 1;
    }
    else if (n >= 3)
    {
        mode = 2;
    }
    else
    {
        mode = 0;
    }
}
