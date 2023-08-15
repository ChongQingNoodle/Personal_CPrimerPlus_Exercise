// 7.编写一个程序,提示用户输入一个double类型的数,并打印该数的立方值。自己设计一个
// 函数计算并打印立方值。main()函数要把用户输入的值传递给该函数。
#include <stdio.h>

float cube(float n);

int main(void)
{
    float a;
    float b;
    printf("Please enter a number :");
    scanf("%f",&a);
    b = cube(a);
    printf("The number's cube is %.2f !\n",b);
}

float cube(float n)
{
    return n*n*n;
}