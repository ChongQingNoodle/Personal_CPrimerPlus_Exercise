// 2.使用嵌套循环,按下面的格式打印字符:
// $
// $$
// $$$
// $$$$
// $$$$$

#include <stdio.h>

int main(void)
{
    int n;
    printf("Please input a number you like:");
    scanf("%i" , &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j <= i ; j++)
        {
            printf("$");
        }
        printf("\n");
    }
    return 0;
}