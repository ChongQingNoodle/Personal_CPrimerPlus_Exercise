//一个用于操作数组的头文件，整理了一些常用的操作数组的函数，不过函数头需要和stdio.h一起使用，否则无法顺利使用该头下的printf函数。
#include<stdio.h>

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

//打印一维double数组
void print_double_arr(const double * arr ,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%4.2f ", arr[i]);
    }
    printf("\n");
}


//打印二维double数组
void print_double_2darr(int n, int m, const double (*arr)[m])
{
    for (int i = 0; i < n; i++)
    {
        print_double_arr( arr[i] , m);
    }
    
}

void add_arr(const double * source1, const double * source2, double * target , int n)
{
    for(int i = 0 ; i < n; i++)
    {
        target[i]=source1[i]+source2[i];
    }
}

void arr_n (int rows, int cols,  double (*arr)[cols] , int n)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j<cols ; j++)
        {
            arr[i][j] = arr[i][j] * n;
        }
    }
}