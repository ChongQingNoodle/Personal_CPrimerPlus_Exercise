// 7.编写一个程序,提示用户输入一周工作的小时数,然后打打印工资总额、税金和净收入。
// 做如下假设:
//  a.基本工资=10.00美元/小时
//  b.加班(超过40小时)=1.5倍的时间
//  c.税率:
//      前300美元为15%
//      续150美元为20%
//      余下的为25%
// 用#define定义符号常量。不用在意是否符合当前的税法。

#include <stdio.h>
#include <stdlib.h>
#define BS_WAGE 10
#define BS_TIME 40
#define ONE_P 0.15
#define TWO_P 0.20
#define THREE_P 0.25

float wg(float n);//定义一个求工资的函数
float tx(float n);//定义一个求税的函数
float wt(float n , float m);//定义一个求净工资的函数

int main(void)//定义主函数
{
    float hr_week;
    float wage;
    float tax;
    float wage_tax;
    printf("How long do you work a week ?\n");
    scanf("%f" ,&hr_week);//读入一个周工作时长

    wage  = wg(hr_week);//把周工作时长传入计算工资的函数
    tax = tx(wage);//把工资传入计算税费的函数
    wage_tax = wt(wage , tax);//把工资和税费传入到

    printf("Your total wage : %.2f.\n" , wage);
    printf("Your tax : %.2f.\n", tax);
    printf("Your wage exclude tax : %.2f.\n",wage_tax);

    return 0;
}

float wg(float n)
{
    float wg;//定义工资
    float n4 = n*4;
    if (n4 <= BS_TIME)
    {
        wg = n4 * BS_WAGE;
    }
    else
    {
        wg = BS_TIME * BS_WAGE + (n4 - BS_TIME) * 1.5 * BS_WAGE;
    }
    return wg;
}

float tx(float n)
{
    float tx;
    if (n <= 300)
    {
        tx = n * ONE_P;
    }
    else if (n <= 450)
    {
        tx = 300 * ONE_P + (n-300) * TWO_P;
    }
    else
    {
        tx = 300 * ONE_P + 150 * TWO_P + (n - 450 ) * THREE_P;
    }
    return tx;
}

float wt(float n, float m)
{
    return n - m;
}