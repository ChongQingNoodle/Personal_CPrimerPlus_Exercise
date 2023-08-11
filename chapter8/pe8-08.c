// 8.编写一个程序,显示一个提供加法、减法、乘法、除法的菜单。获得用户选择的选项后,
// 程序提示用户输入两个数字,然后执行用户刚才选择的操作。该程序只接受菜单提供的选
// 项。程序使用float类型的变量储存用户输入的数字,如果,用户输入失败,则允许再次输入。
// 进行除法运算时,如果用户输入0作为第2个数(除数),程序应提示用户重新输入一个新
// 值。该程序的一个运行示例如下:
// Enter the operation of your choice:
// a. add          s. subtract
// d. divide       m. multiply
// q. quit

// a
// Enter first number: 22
// .4
// Enter second number: one
// one is not an number.
// Please enter a number, such as 2.5, -1.78E8, or3:1
// 22.4 + 1 = 23.4
// Enter the operation of your choice:
// a. add
// s. subtract
// d. divide
// m. multiply
// q. quit
// d
// Enter first number: 18.4
// Enter second number: 0
// Enter a number other than 0: 0.2
// 18.4/0.2=92
// Enter the operation of your choice:
// a. add
// s. subtract
// d. divide
// m. multiply
// q. quit
// q
// Bye.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STOP 'q'

void line(void);
void menu(void);
char get_first(void);
void add(void);
void subtract(void);
void multiply(void);
void divide(void);
float get_float(void);
float get_nozero_float(void);

int main(void)
{
    line();
    menu();
    line();

    int ch;
    float number_first;
    float number_second;

    while((ch = get_first()) != STOP)
    {
        switch (tolower(ch))
        {
        case 'a':
            add();
            break;
        
        case 's':
            subtract();
            break;
        
        case 'm':
            multiply();
            break;
        
        case 'd':
            divide();
            break;

        default:
            printf("Please select from the menu\n");
            break;
        }
        line();
        menu();
        line();
    }

    printf("End.\n");
    return 0;
}

char get_first(void)
{
    int ch;
    while (isspace(ch = getchar()))//如果是空的，就继续获取下一个字符
    {
        continue;
    }
    return ch;
}

void line(void)
{
    for (int i = 0; i < 70; i++)
    {
        printf("*");
    }
    printf("\n");
}

void menu(void)
{
    printf("Enter the operation of your choice:\n");
    printf("a. add                      s. substract\n");
    printf("m. multiply                 d. divide\n");
    printf("q. quit\n");
}

float get_float(void)
{
    float num;
    char c;
    while (scanf("%f" , &num)!=1)
    {
        c = getchar();
        putchar(c);
        printf(" is not a number.\nPlease enter a number ,such as 2.5, -1.78E8, or 3: ");
    }
    return num;
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

void add(void)
{
    float num1 , num2;
    printf("Enter first number: ");
    num1 = get_float();
    printf("Enter second number: ");
    num2 = get_float();
    printf("%g + %g = %g\n" , num1, num2 , num1+num2);
}

void subtract(void)
{
    float num1 , num2;
    printf("Enter first number: ");
    num1 = get_float();
    printf("Enter second number: ");
    num2 = get_float();
    printf("%g - %g = %g\n" , num1, num2 , num1-num2);
}

void multiply(void)
{
    float num1 , num2;
    printf("Enter first number: ");
    num1 = get_float();
    printf("Enter second number: ");
    num2 = get_float();
    printf("%g * %g = %g\n" , num1, num2 , num1*num2);
}

void divide(void)
{
    float num1 , num2;
    printf("Enter first number: ");
    num1 = get_float();
    printf("Enter second number: ");
    num2 = get_nozero_float();
    printf("%g / %g = %g\n" , num1, num2 , num1/num2);
}