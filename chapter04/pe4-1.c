// 1．编写一个程序，提示用户输入名和姓，然后以“名,姓”的格式打印出来。

#include <stdio.h>

int main(void)
{
    char first_name[40];
    char last_name[40];
    printf("Please input your first name:");
    scanf("%s",first_name);
    printf("Please input your last name:");
    scanf("%s",last_name);
    printf("Your name is %s , %s.\n",first_name,last_name);
}