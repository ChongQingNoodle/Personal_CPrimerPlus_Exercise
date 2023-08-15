// 7.修改第7章的编程练习8,用字符代替数字标记菜单的选项。用q代替5作为结束输入的标记。

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define WAGE_LEVEL1 8.75
#define WAGE_LEVEL2 9.33
#define WAGE_LEVEL3 10
#define WAGE_LEVEL4 11.2
#define BASIC_DURATION_PE_RWEEK 40
#define TX_WAGE1 300
#define TX_WAGE2 450
#define TX_1 0.15
#define TX_2 0.2
#define TX_3 0.25
#define STOP 'q'

void line(void);
void menu(void);
float WAGE_PER_MONTH(float drt_perweek , float wage_per_hour);//传入工作周时长和时薪，传出计算过加班的月薪资
float WAGE_PER_HOUR(char n);
float TAX_OF_WAGE(float n);
char get_first(void);

int main(void)
{
    char select;
    float work_duration_per_week;
    float wage;
    float tax;
    float wage_notax;
    float wage_per_hour;

    line();
    menu();
    line();

    while((select=get_first())!= STOP)
    {
        wage_per_hour = WAGE_PER_HOUR(select);
        if (wage_per_hour == 0)
        {
            printf("YOUR INPUT IS ILLIGELLY!\n");
            line();
            menu();
            line();
        }
        else
        {
            printf("How long do you work every week ?\n");
            scanf("%f" , &work_duration_per_week);
            while(work_duration_per_week < 0)
            {
                printf("Your input is error.\nHow long do you work every week ?\n");
                scanf("%f" , &work_duration_per_week);
            }
            wage = WAGE_PER_MONTH(work_duration_per_week , wage_per_hour);
            tax = TAX_OF_WAGE(wage);
            wage_notax = wage - tax;
            printf("Your work\'s information\nwage : %.2f\ntax : %.2f\nnotaxwage : %.2f\n",wage,tax,wage_notax);
            printf("PLEASE SELECT AGAIN:\n");
            line();
            menu();
            line();
        }
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
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("A)$8.75/hr                      B)$9.23/hr\n");
    printf("C)$10.00/hr                     D)$11.20/hr\n");
    printf("Q)quit\n");
}

float WAGE_PER_MONTH(float drt_perweek , float wage_per_hour)
{
    float drt_permonth = drt_perweek*4;
    float wage_per_month;
    if ( drt_permonth <= BASIC_DURATION_PE_RWEEK )
    {
        wage_per_month = drt_permonth * wage_per_hour;
    }
    else
    {
        wage_per_month = BASIC_DURATION_PE_RWEEK * wage_per_hour + (drt_permonth-BASIC_DURATION_PE_RWEEK)*1.5*wage_per_hour;
    }
    return wage_per_month;
}

float WAGE_PER_HOUR(char n)
{
    switch (tolower(n))
    {
    case 'a':
        return WAGE_LEVEL1;
        break;
    case 'b':
        return WAGE_LEVEL2;
        break;
    case 'c':
        return WAGE_LEVEL3;
        break;
    case 'd':
        return WAGE_LEVEL4;
        break;
    default:
        return 0;
        break;
    }
}

float TAX_OF_WAGE(float n)
{
    float tax;
    if (n <= TX_WAGE1)
    {
        tax = n*TX_1;
    }
    else if (n <= TX_WAGE2)
    {
        tax = TX_WAGE1*TX_1+ (n-TX_WAGE1)*TX_2;
    }
    else
    {
        tax = TX_WAGE1*TX_1+ (TX_WAGE1 - TX_WAGE2)* TX_2+ ( n- TX_WAGE2 )*TX_3;
    }
    return tax;
}