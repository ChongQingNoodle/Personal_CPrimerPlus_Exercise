/*5.修改程序清单13.5中的程序,用命令行界面代替交互式界输。*/

/*1305 append.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];          //只分配一次

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
    {
        fwrite(temp, sizeof(char), bytes, dest);
    }
}

int main(int argc, char * argv[])
{
    FILE *fa, *fs;//fa is the target file, fs is the source file
    int files = 0;
    int ch;

    if (argc != 3)
    {
        fprintf(stderr, "Usage %s filename1 filename2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    

    if ((fa = fopen(argv[1], "a+")) == NULL)//append in argv[1], if argv[1] is not exist, then create it
    {//if argv[1] is null , then puts error
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], argv[2]) == 0)
    {
        fputs("Can't appen file to itself\n", stderr);
        exit(EXIT_FAILURE);
    }
    else if ((fs = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    else
    {
        if (setvbuf(fs, NULL, _IOFBF, BUFSIZE))
        {
            fputs("Can't create input buffer\n", stderr);
            exit(EXIT_FAILURE);
        }
        append(fs, fa);
        if (ferror(fs) != 0)
        {
            fprintf(stderr, "Error in reading file %s.\n", argv[2]);
        }
        if (ferror(fa) != 0)
        {
            fprintf(stderr, "Error in writing file %s.\n", argv[1]);
        }
        fclose(fs);
    }
    
    printf("Done appending.");
    rewind(fa);
    printf("%s contents:\n", argv[1]);
    while ((ch = getc(fa)) != EOF)
    {
        putchar(ch);
    }
    puts("Done displaying.");
    fclose(fa);

    return 0;
}