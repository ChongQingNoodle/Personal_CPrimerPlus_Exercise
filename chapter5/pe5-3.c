// 3.编写一个程序,提示用户输入天数,然后将其转换成周数和1天数。例如,用户输入18,则
// 转换成2周4天。以下面的格式显示结果:
// 18 days are 2 weeks, 4 days.
// 通过while循环让用户重复输入天数,当用户输入一个非正数值时(如0或-20),循环结束。

#include <stdio.h>

int main(void)
{
    int n;
    int n_weeks;
    int n_days;
    printf("Please input a int:");
    scanf("%d",&n);
    while (n>0)
    {
        n_weeks = n/7;
        n_days = n%7;
        printf("%d days are %d weeks , %d days\n",n,n_weeks,n_days);
        printf("Please input a new int:");
        scanf("%d",&n);
        if (n <= 0)
        {
            printf("THE END\n");
            break;
        }
    }
    return 0;
}