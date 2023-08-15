/*
5.编写一个程序,生成100个1~10范围内的随机数,并以降序排列(可以把第11章的排序算法稍
加改动,便可用于整数排序,这里仅对整数排序)。
*/
#include <stdio.h>
#include <stdlib.h>/*提供库函数rand()的原型*/
#include <time.h>

int range;

int randnum (int num);
void set_array(int * array, int n);
void show_array(int * array , int n);
void sort_array( int * array , int n);

int main(void)
{
    
    printf("Please enter the range you need: ");
    scanf("%d",&range);
    int num_array;
    printf("Enter the amount of array: ");
    scanf("%d",&num_array);

    int arr[num_array];
    
    set_array(arr, num_array);
    puts("Your randam array is :");
    show_array(arr, num_array);
    puts("I will sort it.");
    sort_array(arr, num_array);
    show_array(arr, num_array);
}


int randnum(int n)//生成1个1～n之间的随机数
{
    int randnum;
    
    randnum = rand()%n + 1;
    return randnum;
}

void set_array(int * array, int n)//把数组设为随机数
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        array[i] = randnum(range);
    }
}

void show_array(int * array , int n)//展示数组
{
    int count = 0 ;
    for (int i = 0; i < n; i++)
    {
        printf("%2d  ", array[i]);
        count++;
        if (count%10 == 0)
        {
            printf("\n");
        } 
    }
}

void sort_array( int * array , int n)//对数组降序排列
{
    int temp;
    int top , seek;

    for ( top = 0; top < n-1; top++)
    {
        for ( seek = top + 1; seek < n; seek++)
        {
            if (array[top]<array[seek])
            {
                temp = array[top];
                array[top] = array[seek];
                array[seek] = temp;
            }
        }
    }
}