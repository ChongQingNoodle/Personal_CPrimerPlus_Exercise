/*
6.编写一个程序,初始化一个二维double数组,并利用练习2中的任一函数来把这个数组复制
到另一个二维数组(因为二维数组是数组的数组,所以可以使使用处理一维数组的函数来复制数组的每
个子数组)。
*/

#include <stdio.h>

void copy_arr (const double * source_arr, double * target_arr, int n);
void copy_ptr (const double * source_arr, double * target_arr, int n);
void copy_2darr(int n, int m, const double (*source_arr)[m], double (*target_arr)[m] );
void print_double_arr(const double * arr ,int n);
void print_double_2darr(int n, int m, const double (*arr)[m]);

int main(void)
{
    //初始化一个二维数组
    const double rain[5][12] = {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    double target1[5][12];
    double target2[5][12];
    copy_2darr(5, 12, rain , target1);
    print_double_2darr(5, 12 , target1);
}


void copy_2darr(int n, int m, const double (*source_arr)[m], double (*target_arr)[m] )
{
    for (int i = 0; i < n; i++)
    {
        copy_arr(source_arr[i], target_arr[i], m);
    }
}

void copy_arr (const double * source_arr, double * target_arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        target_arr[i] = source_arr[i];
    }
}

void copy_ptr (const double * source_arr, double * target_arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        *target_arr ++ = *source_arr ++;
    }
}

//打印二维double数组
void print_double_2darr(int n, int m, const double (*arr)[m])
{
    for (int i = 0; i < n; i++)
    {
        print_double_arr( arr[i] , m);
    }
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