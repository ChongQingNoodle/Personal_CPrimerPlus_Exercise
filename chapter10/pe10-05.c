/*
5.编写一个函数,返回一个double数组中最大的和最小的数之间的差值,并在一个简单的程序中测
试这个函数。
*/

#include <stdio.h>

double max_subtract_min(const double * arr , int n);

int main()
{
    const double arr[5]={2.5, 5.1, 11.4, 6.5, 5.4};
    double substract = max_subtract_min(arr , 5);
    printf("The max substracted min of arr is : %g.\n", substract);
}

double max_subtract_min(const double * arr , int n)
{
    double max_num = *arr;
    double min_num = *arr;
    int max_index = 0;
    int min_index = 0;

    for (int i = 0; i < n; i++)
    {
        if (max_num <= *(arr + i))
        {
            max_num = *(arr + i);
            max_index = n;
        }
        if (min_num >= *(arr + i))
        {
            min_num = *(arr + i);
            min_index = n;
        }
    }
    return (max_num - min_num);
}