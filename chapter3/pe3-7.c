// 7.1英寸相当于2.54厘米。编写一个程序,
// 提示用户输入身高(/英寸),然后以厘米为单位显示身高。

#include <stdio.h>

int main(void)
{
    printf("How tall are you?:");
    int n;
    scanf("%i",&n);
    printf("You height in inche is %0.2f.\n",n/2.54);
}