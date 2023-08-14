/*
12.编写一个程序,提示用户输入3个数集,每个数集包括5个doruble值。程序应当实现下列所有功能:
a.把输入信息存储到一个3x5的数组中
b.计算出每个数集(包含5个数值)的平均值
c.计算所有数值的平均数
d.找出这15个数中的最大值.
e.打印出结果
每个任务需要用一个单独的函数来实现(使用传统C处理数组的方法)。对于任务b,需要编写计算并
返回一维数组平均值的函数,循环3次调用该函数来实现任务b。对于其他任务,函数应当把整个数组做
为参数,并且完成任务c和d的函数应该向它的调用函数返回答案。
*/

#include <stdio.h>
#define ROWS 3
#define COLS 5

void get_5_double(int n , double (* arr)[COLS]);
void print_average(double (*arr)[COLS]);
double findmax(double (*arr)[COLS]);
void print_double_2darr(int n, int m, const double (*arr)[m]);
void print_double_arr(const double * arr ,int n);

int main(void)
{
    double arr[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        get_5_double(i , arr);
    }
    printf("OK your arr here :\n");
    print_double_2darr(3,5,arr);
    print_average(arr);
    printf("The max number of the array is : %g.\n" , findmax(arr));
}

void get_5_double(int n , double (* arr)[COLS]) //获取5个double，同时注入到1个二维数组的某一行中
{
    char c;
    printf("Enter the NO.%d row 5 number: " , n+1);
    for (int i = 0; i < COLS ; i++)
    {
        scanf("%lf" , *(arr+n)+i);
    }
}

void print_average(double (*arr)[COLS])
{
    double subtot = 0;
    double total = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            subtot += arr[i][j];
        }
        printf("The NO.%d row's average is %g\n", i+1 , subtot/5);
        total += subtot;
        subtot = 0;
    }
    printf("The average of all the numbers is : %g\n" , total/15);
}

double findmax(double (*arr)[COLS])
{
    double tmp = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (tmp <= arr[i][j])
            {
                tmp = arr[i][j];
            }
        }
    }
    return tmp;
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