/*
9.修改程序清单13.3中的程序,从1开始,根据加入列表的顺序为每个单词编号。当程序下次运行
时,确保新的单词编号接着上次的编号开始。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
    FILE * fp;
    char words[MAX];
    int word_count = 1;
    
    if ((fp = fopen("mywordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"mywordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file; press the #");
    puts("key at the begining of a line to terminate.");
    while ((fscanf(stdin,"%40s", words) == 1) && (words[0] != '#'))
    {
        fprintf(fp, "%s\n", words);
    }
    puts("File contents:");
    rewind(fp);
    while (fscanf(fp , "%s" , words) == 1)
    {
        fprintf(stdout, "NO.%d ", word_count);
        puts(words);
        word_count++;
    }
    puts("Done!");
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Error closing file\n");
    }
    return 0;
}