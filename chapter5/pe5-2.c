// 2.编写一个程序,提示用户输入一个整数,然后打印从该数到比该数大10的所有整数(例
// 如,用户输入5,则打印5~15的所有整数,包括5和15)。要求打印的各值之间用一个空
// 格、制表符或换行符分开。


#include <stdio.h>

int main()
{
    int n;
    printf("Please input a number:");
    scanf("%d",&n);
    for (int i = n; i <= n+10; i++)
    {
        printf("%d\n",i);
    }
    return 0;
}