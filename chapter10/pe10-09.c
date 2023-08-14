/*
9.编写一个函数,把两个数组内的相应元素相加,结果存储到第3个数组内。也就是说,如果数组1
具有值2、4、5、8,数组2具有值1、0、4、6,则函数对数组3赋值为3、4、9、14。函数的参数包括3
个数组名和数组大小。并在一个简单的程序中测试这个函数。
*/
#include <stdio.h>

void add_arr(const double * source1, const double * source2, double * target , int n);
void print_double_arr(const double * arr ,int n);

int main(void)
{
    double arr1[4] = {1.1, 1.2, 1.3, 1.4};
    double arr2[4] = {2.1, 2.2, 2.3, 2.4};
    double target1[4];
    add_arr(arr1, arr2, target1, 4);
    print_double_arr(target1 , 4);
}


//2个数组相加的函数方法，第1、2个参数是原始数组，第3个数组是目标数组，最后1个参数是数组大小
void add_arr(const double * source1, const double * source2, double * target , int n)
{
    for(int i = 0 ; i < n; i++)
    {
        target[i]=source1[i]+source2[i];
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
