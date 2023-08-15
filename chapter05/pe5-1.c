// 1.编写一个程序,把用分钟表示的时间转换成用小时和分钟表示的时间。使用#define
// 或const创建一个表示60的符号常量或const变量。通过while循环让用户重复输入值,直到
// 用户输入小于或等于0的值才停止循环。

#include <stdio.h>

const float N = 60;

int main(void)
{
    float time;
    printf("Please input time num in the min:");
    scanf("%f",&time);
    while (time > 0)
    {
        printf("%f minuetes is %.2f hours\n",time,time/N);
        printf("%f minuetes is %.0f seconds\n",time,time*N);
        printf("Please input time num in the min:");
        scanf("%f",&time);
        if (time <=0 )
        {
            printf("THE END\n");
            break;
        }
    }
    
    return 0;
}