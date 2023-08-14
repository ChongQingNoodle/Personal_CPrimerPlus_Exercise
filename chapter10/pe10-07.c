/*
7.利用练习2中的复制函数,把一个包含7个元素的数组内第3到第5元素复制到一个包含3个元素
的数组中。函数本身不需要修改,只需要选择合适的实际参数(实际参数不需要是数组名和数组大小,而
只须是数组元素的地址和需要复制的元素数目)。
*/
#include <stdio.h>

void copy_ptr (const double * source_arr, double * target_arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        *target_arr ++ = *source_arr ++;
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

int main(void)
{
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5 ,6.6, 7.7};
    double target1[3];
    copy_ptr(source+2,target1,3);
    print_double_arr( target1 , 3);
}