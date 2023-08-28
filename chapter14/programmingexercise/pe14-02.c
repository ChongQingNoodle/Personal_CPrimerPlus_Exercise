// 2.编写一个函数,提示用户输入日、月和年。月份可以是月份号、月份名或月份名缩写。然
// 后该程序应返回一年中到用户指定日子(包括这一天)的总天数。

#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#include <stdlib.h> // 提供atoi的原型


typedef struct Month
{
    char monthName[20];
    char monthShortName[5];
    int monthDays;
    int monthNumber;
} Month;

Month months[12] = {
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

void is_leap_year(int year);
int days_result(char *month, int days);

int main(void)
{
    int n ,val;
    int day, year;
    char month[12];

    printf("Please enter day, month and year (q to quit): ");
    while (scanf("%d %11s %d",&day, month, &year) == 3)
    {
        is_leap_year(year);
        val= days_result(month, day);
        if (val > 0)
        {
            printf("There are %d days from the beginning of %d to %s %d\n",val, year, month ,day);
        }
        else
        {
            printf("You entered invalid datas!\n");
        }
        months[1].monthDays = 28;
        printf("You can enter day , month and year again(q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

void is_leap_year(int year) // 计算是否时闰年
{
    if(( year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        months[1].monthDays = 29;
    }
    return;
}

int days_result(char * month, int days)
{
    int i;
    int total = 0;
    int temp = atoi(month); // str类型 强制转换为int

    if (days < 1 || days > 31)
    {
        return -1;
    }
    if (0 == temp)  // 如果强制转换失败，则为字符串，整理字符串的格式
    {
        month[0] = toupper(month[0]);
        for ( i = 0; month[i] != '\0'; i++)
        {
            month[i] = tolower(month[i]);
        }
    }
    for ( i = 0; i < 12; i++)
    {
        if ((temp == months[i].monthNumber) || (strcmp(month, months[i].monthName) == 0) || (strcmp(month, months[i].monthShortName) == 0))
        {
            if (days > months[i].monthDays)
            {
                return -1;
            }
            else
                return total + days;
        }
        else
        {
            total += months[i].monthDays;
        }
    }
    return -1;
}