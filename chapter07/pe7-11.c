// 11.ABC邮购杂货店出售的洋蓟售价为2.05美元/磅,甜菜售价为1.15美元/磅,胡萝卜售价为
// 1.09美元/磅。在添加运费之前,100美元的订单有5%的打折优惠。少于或等于5磅的订单收取
// 6.5美元的运费和包装费,5磅~20磅的订单收取14美元的运费和包装费,超过20磅的订单在14
// 美元的基础上每续重1磅增加0.5美元。编写一个程序,在循环中用switch语句实现用户输入不
// 同的字母时有不同的响应,即输入a的响应是让用户输入洋蓟的磅数,b是甜菜的磅数,c是
// 胡萝卜的磅数,q是退出订购。程序要记录累计的重量。即,如果用户输入4磅的甜菜,然后
// 输入5磅的甜菜,程序应报告9磅的甜菜。然后,该程序要计算货物总价、折扣(如果有的
// 话)、运费和包装费。随后,程序应显示所有的购买信息:物品售价、订购的重量(单位:
// 磅)、订购的蔬菜费用、订单的总费用、折扣(如果有的话)、运费和包装费,以及所有的
// 费用总额。

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define PRICE_OF_A 1.25
#define PRICE_OF_B 0.65
#define PRICE_OF_C 0.89
#define STOP 'q'
#define POUND_L1 5
#define POUND_L2 20

void menu (void);
void line (void);
void question1 (void);
void question2 (void);
void interface(void);

float pound_a = 0; 
float pound_b = 0;
float pound_c = 0;
float pound_all = 0;
float pay_for_all = 0;
float expense_of_consignment = 0;
char name;
float tmp;

int main(void)
{
       
    interface();
    question1();
    while((name = getchar()) != STOP)
    {
        switch (toupper(name))
        {
        case 'A':
            question2();
            scanf("%f", &tmp);
            pound_a += tmp;
            break;
        case 'B':
            question2();
            scanf("%f", &tmp);
            pound_b += tmp;
            break;
        case 'C':
            question2();
            scanf("%f", &tmp);
            pound_c += tmp;
            break;
        case '\n':
            interface();
            question1();
            break;
        default:
            printf("Your input is wrong!\n");
            break;
        }
    }
    printf("End\n");
}

void menu(void)
{
    pound_all = pound_a + pound_b + pound_c;
    pay_for_all = pound_a * PRICE_OF_A + pound_b * PRICE_OF_B + pound_c * PRICE_OF_C;

    if (pay_for_all >= 100)
    {
        pay_for_all = pay_for_all * 0.95;
    }

    if (pound_all == 0)
    {
        expense_of_consignment = 0;
    }
    else if (pound_all <= POUND_L1)
    {
        expense_of_consignment = 3.5;
    }
    else if (pound_all <= POUND_L2)
    {
        expense_of_consignment = 10;
    }
    else
    {
        expense_of_consignment = 8 + pound_all * 0.1;
    }
    

    printf("LIST OF NAME      PRICE PER POUND      WEIGHT        EXPENSE\n");
    printf("A                 %.2f                 %.2f          %.2f\n",PRICE_OF_A , pound_a , pound_a*PRICE_OF_A);
    printf("B                 %.2f                 %.2f          %.2f\n",PRICE_OF_B , pound_b , pound_b*PRICE_OF_B);
    printf("C                 %.2f                 %.2f          %.2f\n",PRICE_OF_C , pound_c , pound_c*PRICE_OF_C);
    printf("TOTAL OF GOODS    -                    %.2f          %.2f\n",pound_all , pay_for_all);
    printf("CONSIGNMENG       -                    -             %.2f\n",expense_of_consignment);
    printf("ALL EXPENSE       -                    -             %.2f\n",pay_for_all+expense_of_consignment);
}

void line(void)
{
    for (int i = 0; i < 80; i++)
    {
        printf("*");
    }
    printf("\n");
}

void question1 (void)
{
    printf("Which one do you need ?:");
}

void question2(void)
{
    printf("How many the %c do you need ?" , name);
}

void interface(void)
{
    line();
    menu();
    line();
}
