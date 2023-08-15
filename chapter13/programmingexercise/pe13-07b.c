/*
7.编写一个程序打开两个文件。可以使用命令行参数或提示用户输入文件名。
a.该程序以这样的顺序打印:打印第1个文件的第1行,第2个文件的第1行,第1个文件的第2
行,第2个文件的第2行,以此类推,打印到行数较多文件的最后一行。
b.修改该程序,把行号相同的行打印成一行。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LEN 1024

int main(int argc, char * argv[])
{
    FILE * fileOne, * fileTwo;
    char line1[LINE_LEN], line2[LINE_LEN];
    int line_count = 1;

    if (argc != 3)
    {
        fprintf(stderr, "Usage %s filename1 filename2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ((fileOne = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Couldn't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fileTwo = fopen(argv[2], "rb")) == NULL)
    {
        fprintf(stderr, "Couldn't open the file \"%s\"\n", argv[2]);
        if(fclose(fileOne) != 0)
        {
            fprintf(stderr, "Error in closing files\n");
        }
        exit(EXIT_FAILURE);
    }
    
    while (1)
    {
        if(fgets(line1, LINE_LEN ,fileOne) != NULL)
        {
            if (line1[strlen(line1)-1] == '\n')
            {
                line1[strlen(line1)-1] = '\t';
            }
            else
                line1[strlen(line1)] = '\t';
            printf("%s", line1);
        }
        else
        {
            
            while (fgets(line2, LINE_LEN, fileTwo) != NULL)
            {
                if (line2[strlen(line2)-1] == '\n')
                {
                    line2[strlen(line2)-1] = '\t';
                }
                else
                    line2[strlen(line2)] = '\t';
                printf("%s", line2);
            }
            
            break;
        }

        if(fgets(line2 , LINE_LEN, fileTwo) != NULL)
        {
            if (line2[strlen(line2)-1] == '\n')
            {
                line2[strlen(line2)-1] = '\t';
            }
            else
                    line2[strlen(line2)] = '\t';
            printf("%s", line2);
        }
        else
        {
            
            while (fgets(line1, LINE_LEN, fileOne) != NULL)
            {
                if (line1[strlen(line1)-1] == '\n')
                {
                    line1[strlen(line1)-1] = '\t';
                }
                else
                    line1[strlen(line1)] = '\t';
                printf("%s", line1);
            }
            break;
        }
        printf("\n");
        line_count++;
    }
    
    if(fclose(fileOne) != 0)
    {
        fprintf(stderr, "Error in closing fileOne\n");
    }
    if(fclose(fileTwo) != 0)
    {
        fprintf(stderr, "Error in closing fileTwo\n");
    }
    
    return 0;
}