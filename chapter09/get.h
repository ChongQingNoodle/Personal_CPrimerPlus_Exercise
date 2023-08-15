/*一个用于读取用户输入的头文件*/
//注意，只是为了便于此章节做练习题，这并不是一个标准的头文件

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double get_double(void)
{
    double num;
    char c;
    while (scanf("%lf" , &num)!=1)
    {
        c = getchar();
        putchar(c);
        printf(" is not a number.\nPlease enter a number ,such as 2.5, -1.78E8, or 3: ");
    }
    return num;
}

int get_int(void)
{
    int input;
    char ch;

    while (scanf("%d", &input ) != 1)
    {
        while((ch = getchar()) != '\n')
            putchar(ch); //删除错误的输入
        printf(" is not an integer.\n");
        printf("Please enter an integer value, such as 25, -178, or 3: ");
    }
    return input;
}

char get_first(void)
{
    int ch;

    ch = getchar();
    while (getchar() != '\n')
    {
        continue;
    }
    return ch;
}

float get_nozero_float(void)
{
    float num;
    char c;
    int status = 0;
    do
    {
        while (scanf("%f", &num)!=1)
        {
            c = getchar();
            putchar(c);
            printf(" is not a number.\nPlease enter a number ,such as 2.5, -1.78E8, or 3: ");
        }
        if (num == 0)
        {
            printf("Enter a number other than 0: ");
        }
        else if(num != 0)
        {
            status = 1;
        }
    } while (status == 0);
    return num;
}
