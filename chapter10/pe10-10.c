/*
10.编写一个程序,声明一个3x5的数组并初始化,具体数值可以随意。程序打印出数值,然后数值
翻一番,接着再次打印出新值。编写一个函数来显示数组的内容,再编写另一个函数执行翻倍功能。数组
名和数组行数作为参数由程序传递给函数。
*/
#include <stdio.h>
void print_double_arr(const double * arr ,int n);
void print_double_2darr(int n, int m, const double (*arr)[m]);
void arr_n (int rows, int cols,  double (*arr)[cols] , int n);

int main(void)
{
    double arr[3][5]={
        {1.1, 1.2, 1.3, 1.4, 1.5},
        {2.1, 2.2, 2.3, 2.4, 2.5},
        {3.1, 3.2, 3.3, 3.4, 3.5}
    };
    arr_n(3, 5, arr , 2);
    print_double_2darr(3, 5, arr);
    return 0;
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

//数组内的数值翻倍函数
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