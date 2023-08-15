// 6．编写一个程序，将一个double类型的变量设置为1.0/3.0，
// 一个float类型的变量设置为1.0/3.0。分别显示两次计算的结果各3次：
// 一次显示小数点后面6位数字；一次显示小数点后面12位数字；
// 一次显示小数点后面16位数字。程序中要包含float.h头文件，
// 并显示FLT_DIG和DBL_DIG的值。1.0/3.0的值与这些值一致吗？
#include <stdio.h>
#include <float.h>

const double d = 1.0/3.0;
const float f = 1.0/3.0;

void first(void);
void second(void);
void third(void);

int main(void)
{
    first();
    second();
    third();
    printf("a = %d, b = %d\n" , FLT_DIG , DBL_DIG);
}

void first(void)
{
    printf("double = %.4f\n",d);
    printf("flout = %.4f\n",f);
    printf("\n");
}

void second(void)
{
    printf("double = %.12f\n",d);
    printf("float = %.12f\n",f);
    printf("\n");
}

void third(void)
{
    printf("double = %.16f\n",d);
    printf("float = %.16f\n",f);
    printf("\n");
}