/*
2.编写一个程序,初始化一个double数组,然后把数组内容复告制到另外两个数组(3个数组都需要在
主程序中声明)。制作第一份拷贝的函数使用数组符号。制作第二份拷贝的函数使用指针符号,并使用指针
的增量操作。把目标数组名和要复制的元素数目做为参数传递给函数。也就是说,如果给定了下列声明,
函数调用应该如下面所示:
double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
double target1[5]:
double target2[5];
copy_arr (source,target1,5);
copy_ptr (source,target1,5);
*/
#include <stdio.h>

void copy_arr (const double * source_arr, double * target_arr, int n);
void copy_ptr (const double * source_arr, double * target_arr, int n);
void print_double_arr(const double * arr ,int n);


int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    copy_arr (source,target1,5);
    copy_ptr (source,target2,5);
    print_double_arr( source , 5);
    print_double_arr( target1 , 5);
    print_double_arr( target2 , 5);

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

void print_double_arr(const double * arr ,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%4.2f ", arr[i]);
    }
    printf("\n");
}