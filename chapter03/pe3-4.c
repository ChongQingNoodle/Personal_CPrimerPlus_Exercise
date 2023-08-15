// 4.编写一个程序,读取一个浮点数,先打印成小数点形式,再打印成指数形式。然后,如果
// 系统支持,再打印成p记数法(即十六进制记数法)。按以下格式输出(实际显示的指数位数
// 因系统而异):
// Enter a floating-point value: 64.25
// fixed-point notation: 64.250000
// exponential notation: 6.425000e+01
// p notation: 0x1.01p+6

#include <stdio.h>

int main(void)
{
    float n;
    printf("Please enter a float number:");
    scanf("%f",&n);
    printf("This input in %f or %e.\n", n ,n);
}