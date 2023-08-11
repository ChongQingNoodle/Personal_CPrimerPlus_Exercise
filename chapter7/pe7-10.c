// 10.1988年的美国联邦税收计划是近代最简单的税收方案。它分为4个类别,每个类别有两个
// 等级。下面是该税收计划的摘要(美元数为应征税的收入):
// 类别            税金
// 单身            17850美元按15%计,超出部分按28%计
// 户主            23900美元按15%计,超出部分按28%计
// 已婚,共有        29750美元按15%计,超出部分按28%计
// 已婚,离异        14875美元按15%计,超出部分按28%计
// 例如,一位工资为20000美元的单身纳税人,应缴纳税费0.15×17850+0.28×(200000-17850)
// 美元。编写一个程序,让用户指定缴纳税金的种类和应纳税收入,然后计算税金。程序应通
// 过循环让用户可以多次输入。

#include <stdio.h>
#include <stdlib.h>

#define W1 17580
#define W2 23900
#define W3 29750
#define W4 14875

void line(void);
void menu(void);
float TAX_LEVEL(int n);
float TAX(float wage ,float tax_level);

int main(void)
{
    line();
    menu();
    line();

    int num ;
    float tax_level , wage , tax;
    while(scanf("%d" , &num)==1)
    {
        tax_level = TAX_LEVEL(num);
        if (tax_level == 0)
        {   
            break;
        }
        printf("How many wage do you have ? :");
        scanf("%f" , &wage);
        tax = TAX(wage , tax_level);
        printf("Your tax : %.2f\n", tax);
        printf("\nAgain\n");
        line();
        menu();
        line();
    }
    printf("End\n");
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
    printf("1)single                        2)hoster\n");
    printf("3)married,common                4)married,broken\n");
    printf("5)quit\n");
}

float TAX_LEVEL(int n)
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

float TAX(float wage ,float tax_level)
{
    int tax;
    if (wage < tax_level)
    {
        tax = wage * 0.15;
    }
    else
    {
        tax = tax_level * 0.15 + (wage - tax_level) * 0.28;
    }
    return tax;
}