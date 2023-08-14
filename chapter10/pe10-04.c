/*
4.编写一个函数,返回一个double数组中存储的最大数值的索引,并在一个简单程序中测试这个函数。
*/

#include <stdio.h>

int arr_index_max(double * arr, int n);

int main()
{
    double arr[5]={2.5, 5.1, 11.4, 6.5, 5.4};
    printf("The max index of arr is : %d.\n", arr_index_max(arr, 5));
}

int arr_index_max(double * arr, int n)
{
    int tmp = 0;
    int j;
    for (int i = 0; i < n; i++)
    {
        if(tmp <= *(arr + i))
        {
            tmp = *(arr + i);
            j = i;
        }
    }
    return j;
}