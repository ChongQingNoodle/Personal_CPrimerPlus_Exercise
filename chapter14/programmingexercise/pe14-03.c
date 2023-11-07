// 3．修改程序清单14.2中的图书目录程序，使其按照输入图书的顺序输出图书的信息，
// 然后按照标题字母的声明输出图书的信息，最后按照价格的升序输出图书的信息。


/* manybook.c -- 包含多本书的图书目录*/
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);//函数返回一个字符指针，即字符串

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100  /*书籍的最大数量*/

struct book         /*建立book模板*/
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void sort_by_input(const struct book library[] , int n);
void sort_by_title(struct book library[] , int n);
void sort_by_price(struct book library[] , int n);


int main(void)
{
    struct book library[MAXBKS];/*book 类型结构的数组*/
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author , MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar()!= '\n')
        {
            continue;       /*清理输入行*/
        }
        if (count < MAXBKS)
        {
            printf("Enter the next title.\n");
        }
    }

    if (count > 0)
    {
        printf("Here is the list of your books order by your input:\n");
        sort_by_input(library,count);
        printf("And here is the list of your books order by title:\n");
        sort_by_title(library,count);
        printf("And here is the list of your books order by price:\n");
        sort_by_price(library,count);
    }
    else
        printf("No books? Too bad.\n");
    return 0;
    
}

void sort_by_input(const struct book library[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s by %s: $%.2f\n" , library[i].title , library[i].author , library[i].value);
    }
    printf("\n");
}

void sort_by_title(struct book library[], int n)
{
    int i, j;
    struct book temp;
    // 双指针排序算法
    for ( i = 0; i < n - 1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (strcmp(library[i].title , library[j].title) > 0)
            {
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%s by %s: $%.2f\n" , library[i].title , library[i].author , library[i].value);
    }
    printf("\n");
}

void sort_by_price(struct book library[], int n)
{
    int i, j;
    struct book temp;
    // 双指针排序算法
    for ( i = 0; i < n - 1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (library[i].value > library[j].value)
            {
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%s by %s: $%.2f\n" , library[i].title , library[i].author , library[i].value);
    }
    printf("\n");
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n , stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            * find = '\0';
        else
            while (getchar()!= '\n')
                continue;
    }

    return ret_val;
}