// 6.1个水分子的质量约为3.0×10的-23次克。1夸脱水大约是950克。
// 编写一个程序,提示用户输入水的夸脱数,并显示水分子的数量。

#include <stdio.h>

int main(void)
{
    int n;
    printf("Please input the quator number of water:");
    scanf("%i",&n);
    printf("there are %0.2e H2O in the water.\n", n*950/3.0e-23);
}