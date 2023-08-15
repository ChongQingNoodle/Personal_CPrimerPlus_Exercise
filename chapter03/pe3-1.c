// 1.通过试验(即编写带有此类问题的程序)观察系统
// 如何[处理整数上溢、浮点数上溢和浮点数下溢的情况。

#include <stdio.h>

int main(void)
{
    int i ;
    i = 2000000000;
    float j ;
    j = 0.012345692131313;
    printf("整数上溢:%i\n",i+i);
    printf("浮点数下溢：%f\n",j/10);
}