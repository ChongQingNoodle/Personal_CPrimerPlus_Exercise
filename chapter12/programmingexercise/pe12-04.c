/*
4.在一个循环中编写并测试一个函数,该函数返回它初被调用的次数。
*/
#include <stdio.h>

static int n = 0;
void test(void);
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        test();
    }
    printf("%d\n",n);
}

void test(void)
{
    n++;
}