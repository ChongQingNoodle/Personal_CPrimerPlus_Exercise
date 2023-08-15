/*
3.重新设计编程练习2,要求只使用自动变量。该程序提是供的用户界面不变,即提示用户输入模式
等。但是,函数调用要作相应变化。
*/
#include "pe12-03-a.h"
#include <stdio.h>

void set_mode(int n , int * m)
{
    *m = n;
    if (*m != 0 || *m != 1)
    {
        *m = 1;
        printf("Invalid mode specified. Mode 1(US) used.\n");
    }
}

void get_info(int mould , double * distance , double * fuel_consumed)
{
    switch (mould)
    {
    case 0:
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", fuel_consumed);
        break;
    
    case 1:
        printf("“Enter distance traveled in miles: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", fuel_consumed);
        break;

    default:
        break;
    }
}

void show_info(int mould, double * distance, double * fuel_consumed)
{
    switch (mould)
    {
    case 1:
        printf("Fuel consumption is %.2f miles per gallon.\n",*distance/(*fuel_consumed));
        break;
    
    case 0:
        printf("Fuel consumption is %.2f liters per 100 km.\n",*fuel_consumed/(*distance)*100);
        break;
    
    default:
        break;
    }
}