/*
3.重新设计编程练习2,要求只使用自动变量。该程序提是供的用户界面不变,即提示用户输入模式
等。但是,函数调用要作相应变化。
*/
// ex3-b.c
// ex3-a.c一起编译
#include <stdio.h>
#include "pe12-03-a.h"
int main(void)
{
    int mode;//获取用户的输入
    int mould;
    double distance = 0;
    double fuel_consumed = 0;
    int * ptr_md = &mould;
    double * ptr_dis = &distance;
    double * ptr_fc = &fuel_consumed;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode , ptr_md);
        get_info(mould , ptr_dis , ptr_fc);
        show_info(mould , ptr_dis , ptr_fc);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
