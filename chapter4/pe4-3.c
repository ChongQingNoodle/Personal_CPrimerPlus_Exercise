// 3．编写一个程序，读取一个浮点数，首先以小数点记数法打印，然后以指数记数法打印。用下面的格式进行输出（系统不同，指数记数法显示的位数可能不同）：
// 　　a．The input is21.3 or 2.1e+001.

// 　　b．The input is+21.290 or 2.129E+001.

#include<stdio.h>

int main(void)
{
    float n;
    printf("Please intput a float number:");
    scanf("%f",&n);
    printf("a. The input is %.1f or %.1e\n",n , n);
    printf("b. The input is %+0.3f or %.3E\n",n ,n);
}