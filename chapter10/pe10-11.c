/*
11.重写程序清单10.7的程序rain,main()中的主要功能改为为由函数来执行。
*/

#include <stdio.h>
void float_col_sum_ptr_print( int rows , int cols , const float (* ar)[cols]);
void float_row_sum_ptr_print( int rows , int cols , const float (* ar)[cols]);

int main()
{
    const float rain[5][12] = {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

    float_col_sum_ptr_print(5, 12 , rain);
    float_row_sum_ptr_print(5, 12, rain);
}

//逐列打印float数组，打印每列的和，同时计算总和与均值
void float_col_sum_ptr_print( int rows , int cols , const float (* ar)[cols])
{//上面这种声明形式，其实是一种叫做变长数组的声明形式，他的列数是一个可以变动的，在C99中被支持。
    int r;
    int c;
    float subtot, tot;
    for ( c = 0; c < cols; c++)
    {
        for ( r = 0; r < rows; r++)
        {
            //subtot += rain[year][month];      //数组形式
            subtot += *(*(ar + r) + c);         //指针形式
        }
        printf("The COL_%D : %g\n", c+1, subtot);
        tot+= subtot;
    }
    printf("The total COLS : %g\n", tot);
    printf("The AVERAGE of every COL : %g\n", tot/c);
}


//逐行打印float数组,打印每行的值
void float_row_sum_ptr_print( int rows , int cols , const float (* ar)[cols])
{
    int r;
    int c;
    float subtot, tot;
    for ( r = 0 , tot = 0 ; r < rows; r++)
    {           //对于每一年，各月的降水总量
        for ( c = 0 , subtot = 0 ; c < cols; c++)
        {
            //subtot += rain[year][month];      //数组形式
            subtot += *(*(ar + r) + c);         //指针形式
        }
        printf("The ROW_%d : %g\n" , r + 1, subtot);
        tot += subtot;
    }
    printf("The total ROWS : %g\n", tot);
    printf("The AVERAGE of everry ROW : %g\n", tot/r);
}