//3.编写一个程序把你的年龄转换成天数,并显示这两个值。这里不用考虑闰年的问题。

#include <stdio.h>

int main(void) 
{
    int birthYear , birthMonth , birthDay;
    birthYear = 1998;
    birthMonth = 1;
    birthDay = 31;

    int todayYear , todayMonth , todayDay;
    todayYear = 2022;
    todayMonth = 12;
    todayDay = 28;

    int days , old;
    days = (todayYear - birthYear)*365 + (todayMonth - birthMonth)*30 + (todayDay - birthDay);
    old = todayYear - birthYear;
    printf("You are %i years old.\n" , old);
    printf("You have been living in the world for %i days.\n",days);
    return 0;
}