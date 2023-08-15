// 8.编写一个程序,要求用户输入两个浮点数,并打印两数之差除以两数乘积的结果。在用户
// 输入非数字之前,程序应循环处理用户输入的每对值。

#include <stdio.h>

int main(void)
{
    float a;
    float b;
    printf("Please enter two float :");
    while (scanf("%f %f",&a,&b) == 2)
    {
        float ia;
        if(a<b)
        {
            ia= b -a ;
        }
        else
        {
            ia = a-b;
        }
        printf("%f\n",ia/a*b);
        printf("Please enter again:");
    }
    printf("Done.\n");
}