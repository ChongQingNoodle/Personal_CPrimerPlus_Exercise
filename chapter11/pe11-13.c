/*
13.编写一个计算乘幂的基于命令行的程序。第一个命令行参数为double类型数,作为幂的底数;第
二个参数为整数,作为幂的指数。
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc ,char *argv[])
{
    if (argc != 3)
    {
        printf("Error input.\n");
        return 1;
    }
    
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);

    double result = pow(base, exponent);
    
    printf("exp : %g\n" , result);
}