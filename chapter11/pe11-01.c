/*
1.设计并测试一个函数,可以从输入读取n个字符(包括空格、制制表符和换行符),把结果存储在
一个数组中,这个数组的地址通过参数来传递。
*/

#include <stdio.h>
#define SIZE 81            //数组大小

void get_string(char *str, int n);

int main(void)
{
    char str[SIZE];        //声明一个字符数组
    int n;                 //获取输入的字符个数
    printf("Enter the number of characters you want to input (not more than %d): ", SIZE - 1);
    while (scanf("%d", &n) != 1 || n <= 0 || n >= SIZE - 1)
    {
        printf("Please enter a positive integer (not more than %d): ", SIZE - 1);
        while (getchar() != '\n') // 清空缓冲区
        {
            continue;
        }
    }
    while (getchar() != '\n') //晴空缓冲区
    {
        continue;
    }
    // 获取输入的字符串
    get_string(str , n);
    printf("The input string is: %s\n", str);
    return 0;
}

void get_string(char *str, int n)
{
    int ch;
    int i = 0;
    // 读区输入的字符，存储到字符数组中
    while( i < n && (ch = getchar())!= EOF)
    {
        str[i] = ch;
        i++;
    }
    while (i == n && (ch = getchar())!= EOF)
    {
        str[i] = '\0';
        break;
    }
    while (getchar() != '\n') //晴空缓冲区
    {
        continue;
    }
}
