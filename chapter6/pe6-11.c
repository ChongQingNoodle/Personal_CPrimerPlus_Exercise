// 11.编写一个程序,在数组中读入8个整数,然后按倒序打!印这8个整数。

#include <stdio.h>

int main(void)
{
    int a[8];
    printf("Enter 8 numbers :");
    scanf("%d %d %d %d %d %d %d %d",
    &a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7]);
    for (int i = 7; i >= 0; i--)
    {
        printf("%d\n" , a[i]);
    }
    return 0;
}