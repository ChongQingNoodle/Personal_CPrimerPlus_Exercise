// 9.修改练习8,使用一个函数返回计算的结果。

#include <stdio.h>


float cal(float i, float j);
int main(void)
{
    float a;
    float b;
    printf("Please enter two float :");
    while (scanf("%f %f",&a,&b) == 2)
    {
        
        printf("%f\n",cal(a,b));
        printf("Please enter again:");
    }
    printf("Done.\n");
}

float cal(float i, float j)
{
    float ia;
    if(i<j)
    {
        ia= j- i ;
    }
        else
    {
        ia = i-j;
    }
    return ia/i*j;
}