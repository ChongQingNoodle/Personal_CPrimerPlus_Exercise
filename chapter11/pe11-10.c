/*
10.编写一个程序,读取输入,直到读入了10个字符串或遇到EOF,由二者中最先被满足的那个终
止读取过程。这个程序可以为用户提供一个有5个选项的菜单:输出初始字符串列表、按ASCII顺序输出
字符串、按长度递增顺序输出字符串、按字符串中第一个单词的长度输出字符串和退出。菜单可以循环,
直到用户输入退出请求。当然,程序要能真正完成菜单中的各项功能。
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 101
#define LIM 10
#define STOP ""

//输出菜单
void menu(void)
{
    puts("***************************");
    puts("A.Show me the strings");
    puts("B.Sort by ASCII");
    puts("C.Sort by length");
    puts("D.Print the first words");
    puts("Q.Quit");
    puts("***************************");
}



//用来输出列表，n为表内元素数，* string[]为二维字符串指针
void output_strlst(char * string[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("NO.%d ",i+1);
        puts(string[i]);
    }
}

//获取第一个字符
char get_first(void)
{
    int ch;
    while (isspace(ch = getchar()))//如果是空的，就继续获取下一个字符
    {
        continue;
    }
    return ch;
}

//根据字符ASCII排序，*string[]是指针，num是排序列表数
void stsrt_by_ASCII (char * strings[] , int num)
{
    char * temp;
    int top, seek;

    for(top = 0; top < num - 1; top++ )
    {
        for ( seek = top + 1; seek < num; seek++)
        {
            if (strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
            
        }
        
    }
}

//根据字符串长度排序，*string[]是指针，num是排序列表数
void strst_by_length( char * strings[] , int num)
{
    char * temp;
    int top, seek;

    for ( top = 0; top < num-1; top++)
    {
        for ( seek = top + 1; seek < num; seek++)
        {
            if(strlen(strings[top]) > strlen(strings[seek]))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }
}

//打印字符串中的第一个单词，*string[]是指针，num是排序列表数
void out_put_first_word( char * strings[], int num)
{
    int i , j = 0 ;

    for ( i = 0; i < num; i++)
    {
        printf("NO.%d ",i);
        j = 0;
        while (isalnum(strings[i][j]) && j < SIZE-1)
        {
            printf("%c" , strings[i][j]);
            j++;
        }
        
        printf("\n");
    }
}


int main()
{
    char input[LIM][SIZE];
    char * ptrstr[LIM];//用指针来存储输入的每个字符串的开头
    int ct = 0;//用来统计输入字符串数量

    printf("Input up to %d lines.\n" , LIM);
    puts("To stop, press the Enter key at a line's start.");

    while (ct < LIM && fgets( input[ct], SIZE, stdin ) != NULL && input[ct][0] != '\0')
    {
        *(strchr(input[ct] , '\n')) = '\0';//清除'\n'字符，这样就不会换行了。
        ptrstr[ct] = input[ct];
        ct++;
    }
    
    char select;
    menu();
    puts("Please selct: ");

    while((select = toupper(get_first())) != 'Q')
    {
        switch (select)
        {
        case 'A':
            output_strlst(ptrstr , ct);
            break;
        case 'B':
            stsrt_by_ASCII(ptrstr , ct);
            output_strlst(ptrstr , ct);
            break;
        
        case 'C':
            strst_by_length(ptrstr , ct);
            output_strlst(ptrstr, ct);
            break;

        case 'D':
            out_put_first_word(ptrstr ,ct);
        
        default:
            puts("Error, your input is not in menu");
            break;
        }
        menu();
        puts("Please selct: ");
    }
    
    puts("End.");
    return 0;
}