/*
3.编写一个函数,返回一个int数组中存储的最大数值,并在一个简单的程序中测试这个函数。
*/

#include <stdio.h>

int arr_max(int * arr, int n);

int main()
{
    int arr[5]={2, 5, 11, 6, 4};
    printf("The max of arr is : %d.\n", arr_max(arr, 5));
}

int arr_max(int * arr, int n)
{
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (tmp <= *(arr + i) )
        {
            tmp = *(arr + i);
        }
    }
    return tmp;
}