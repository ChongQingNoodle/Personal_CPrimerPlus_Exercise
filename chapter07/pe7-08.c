// 8.修改练习7的假设a,让程序可以给出一个供选择的工资等级菜单。使用switch完成工资等
// 级选择。运行程序后,显示的菜单应该类似这样:
// *************************************
// Enter the number corresponding to the desired payy rate or action:
// 1)$8.75/hr
// 3)$10.00/hr
// 5) quit
// 2)$9.33/hr
// 4)$11.20/hr
// *****************
// 如果选择1~4其中的一个数字,程序应该询问用户工作的小时数。程序要通过循环运行,除
// 非用户输入5。如果输入1~5以外的数字,程序应提醒用户输入正确的选项,然后再重复显示
// 菜单提示用户输入。使用#define创建符号常量表示各工资等等级和税率。

#include <stdio.h>
#include <stdlib.h>

#define W1 8.75
#define W2 9.33
#define W3 10
#define W4 11.2
#define BASIC_DRT 40
#define TX_WAGE1 300
#define TX_WAGE2 450
#define TX_1 0.15
#define TX_2 0.2
#define TX_3 0.25
#define STOP 5

void line(void);
void menu(void);
float WAGE_PER_MONTH(float drt , float wage_per_hour);
float WAGE_PER_HOUR(int n);
float TAX_OF_WAGE(float n);

int main(void)
{
    int select;
    int status = 0;
    float workdrt;
    float wage;
    float tax;
    float wage_notax;
    float wage_hour;

    line();
    menu();
    line();

    while(scanf("%d",&select)==1 && select != STOP)
    {
        wage_hour = WAGE_PER_HOUR(select);
        if (wage_hour == 0)
        {
            printf("YOUR INPUT IS ILLIGELLY!\n");
            line();
            menu();
            line();
        }
        else
        {
            printf("How long do you work every week ?\n");
            scanf("%f" , &workdrt);
            wage = WAGE_PER_MONTH(workdrt , wage_hour);
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
    printf("1)$8.75/hr                      2)$9.23/hr\n");
    printf("3)$10.00/hr                     4)$11.20/hr\n");
    printf("5)quit\n");
}

float WAGE_PER_MONTH(float drt , float wage_per_hour)
{
    float drt4 = drt*4;
    float wage_per_month;
    if ( drt4 <= 40 )
    {
        wage_per_month = drt4 * wage_per_hour;
    }
    else
    {
        wage_per_month = 40 * wage_per_hour + (drt4-40)*1.5*wage_per_hour;
    }
    return wage_per_month;
}

float WAGE_PER_HOUR(int n)
{
    switch (n)
    {
    case 1:
        return W1;
        break;
    case 2:
        return W2;
        break;
    case 3:
        return W3;
        break;
    case 4:
        return W4;
        break;
    default:
        return 0;
        break;
    }
}

float TAX_OF_WAGE(float n)
{
    float tax;
    if (n <= 300)
    {
        tax = n*TX_1;
    }
    else if (n <= 450)
    {
        tax = 300*TX_1+ (n-300)*TX_2;
    }
    else
    {
        tax = 300*TX_1+ 150* TX_2+ ( n- 450 )*TX_3;
    }
    return tax;
}