/*
6.编写一个程序,生成1000个1~10范围内的随机数。不用保存或打印这些数字,仅打印每个数出
现的次数。用10个不同的种子值运行,生成的数字出现的次数是否相同?可以使用本章自定义的函
数或ANSIC的rand()和srand()函数,它们的格式相同。这是一个测试特定随机数生成器随机性的
方法。
*/
#include <stdio.h>
#include <stdlib.h>/*提供库函数rand()的原型*/
#include <time.h>

int range;

int randnum (int num);
void set_array(int * array, int n);
void show_array(int * array , int n);
void sort_array( int * array , int n);
void count_array(int * array, int n);

int main(void)
{
    
    printf("Please enter the range you need: ");
    scanf("%d",&range);
    int num_array;
    printf("Enter the amount of array: ");
    scanf("%d",&num_array);

    int arr[num_array];
    
    set_array(arr, num_array);
    //puts("Your randam array is :");
    //show_array(arr, num_array);
    puts("I will count it.");
    count_array(arr , num_array);
    //sort_array(arr, num_array);
    //show_array(arr, num_array);
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

void count_array(int * array, int n)
{
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5=0 , num6= 0, num7 = 0, num8 = 0, num9 = 0, num10 = 0;
    for (int i = 0; i < n; i++)
    {
        switch (array[i])
        {
        case 1:
            num1++;
            break;

        case 2:
            num2++;
            break;

        case 3:
            num3++;
            break;

        case 4:
            num4++;
            break;

        case 5:
            num5++;
            break;
        
        case 6:
            num6++;
            break;

        case 7:
            num7++;
            break;

        case 8:
            num8++;
            break;

        case 9:
            num9++;
            break;
        
        case 10:
            num10++;
            break;
        
        default:
            break;
        }
    }
    printf(" 1 : %d\n 2 : %d\n 3 : %d\n 4 : %d\n 5 : %d\n 6 : %d\n 7 : %d\n 8 : %d\n 9 : %d\n10 : %d\n",num1,num2,num3,num4,num5,num6,num7,num8,num9,num10);
}