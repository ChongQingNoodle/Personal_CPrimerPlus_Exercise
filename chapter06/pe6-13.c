// 13.编写一个程序,创建一个包含8个元素的int类型数组,分别把数组元素设置为2的前8次
// 幂。使用for循环设置数组元素的值,使用do while循环显示数组元素的值。

#include <stdio.h>
#include <math.h>

int main(void)
{
    int a[8];
    int j = 0;
    for (int i = 0; i < 8; i++)
    {
        a[i] = pow(2,i);
    }
    do
    {
        
        printf("%d\n",a[j]);
        j++;
    } while (j<8);
}