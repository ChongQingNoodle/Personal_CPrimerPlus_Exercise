/*
8.编写一个程序,初始化一个3x5的二维double数组,并利用一个基于变长数组的函数把该数
组复制到另一个二维数组。还要编写一个基于变长数组的函数来显示两个数组的内容。这两个函数应
该能够处理任意的NxM数组(如果没有可以支持变长数组的约编译器,就使用传统C中处理Nx5数组
的函数方法)。
*/

#include <stdio.h>
void print_double_arr(const double * arr ,int n);
void print_double_2darr(int n, int m, const double (*arr)[m]);

int main()
{
    double arr[3][5]={
        {1.1, 1.2, 1.3, 1.4, 1.5},
        {2.1, 2.2, 2.3, 2.4, 2.5},
        {3.1, 3.2, 3.3, 3.4, 3.5}
    };
    print_double_2darr(3,5,arr);//把长度放在前面的方法就是变长数组
    //实际上我们在定义数组的时候需要function(*arr , int n , int m)
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