// 1.重新编写复习题5,用月份名的拼写代替月份号(别忘了使用strcmp()。在一个简单的
// 程序中测试该函数。

// 复习题 5.编写一个函数,用户提供月份号,该函数就返回一年中到该月为止(包括该月)的总天
// 数。假设在所有函数的外部声明了第3题的结构模版和一个该类型结构的数组。

// 复习题 3.设计一个结构模板储存一个月份名、该月份名的3个字母缩写、该月的天数以及月份号。

#include <stdio.h>
#include <string.h>

int get_int(void);
int calYTM(int monthNumber);
int monthNameToNumber(char * mName);

typedef struct Month
{
    char monthName[20];
    char monthShortName[5];
    int monthDays;
    int monthNumber;
} Month;

Month month[12] = {
    {"January"  ,"Jan"  , 31, 1},
    {"February" ,"Feb"  , 28, 2},
    {"March"    ,"Mar"  , 31, 3},
    {"April"    ,"Apr"  , 30, 4},
    {"May"      ,"May"  , 31, 5},
    {"June"     ,"Jun"  , 30, 6},
    {"July"     ,"Jul"  , 31, 7},
    {"Augest"   ,"Aug"  , 31, 8},
    {"September","Sep"  , 30, 9},
    {"October"  ,"Oct"  , 30, 10},
    {"November" ,"Nov"  , 30, 11},
    {"December" ,"Dec"  , 31, 12}
};

int main(void)
{
    int number;
    char name[20];
    puts("Please enter the number of month:");
    number = get_int();     //复习题5中要求输入数字的方法
    printf("To the No.%i month from this year has %i days.\n",number,calYTM(number));

    puts("Please enter the name of month:");
    scanf("%s",name);
    printf("To %s from this year has %i days.\n" , name, calYTM(monthNameToNumber(name)));
    return 0;
}

int monthNameToNumber(char * mName)  //本题中要求的输入名字，利用strcmp函数返回月份数字
{
    int ret_val = 0;
    for (int i = 0; i < 12; i++)
    {
       if(strcmp(mName , month[i].monthName) == 0)
       ret_val = month[i].monthNumber;
    }
    return ret_val;
}

int calYTM(int monthNumber) //复习题5中要求根据数字计算的方法
{
    int ret_val = 0;
    for (int i = 0; i < monthNumber; i++)
    {
        ret_val += month[i].monthDays;
    }
    return ret_val;
}

int get_int(void)
{
    int input;
    char ch;

    while (scanf("%d", &input ) != 1)
    {
        while((ch = getchar()) != '\n')
            putchar(ch); //删除错误的输入
        printf(" is not an integer.\n");
        printf("Please enter an integer value, such as 25, -178, or 3: ");
    }
    return input;
}