// 5.使用switch重写练习3。

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STOP 0


int main()
{
    int cnt_odd = 0;//统计奇数个数
    int cnt_even = 0;//统计偶数个数
    int sum_odd = 0;//统计奇数的和
    int sum_even = 0;//统计偶数的和
    int n;//扫描到的数字

    printf("Enter some number (0 to quit):\n");
    while((scanf("%d",&n)==1)&& n!= STOP)//成功读取且非终止
    {
        switch (n%2)
        {
        case 0:
            cnt_even++;
            sum_even += n;
            break;
        
        case 1:
            cnt_odd++;
            sum_odd += n;
            break;
        
        }
    }

    printf("Odd numbers: %d\n" , cnt_odd);
    printf("Average of odd: %.2f\n",(float)sum_odd/cnt_odd);
    printf("Even numbers: %d\n" , cnt_even);
    printf("Average of even: %.2f\n",(float)sum_even/cnt_even);
}