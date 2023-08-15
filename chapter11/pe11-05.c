/*
5.编写一个函数is_within()。它接受两个参数,一个是字符,另一个是字符串指针。其功能是如果
字符在字符串中,就返回一个非0值(真);如果字符不在字符串中,就返回0值(假)。在一个使用循环
语句为这个函数提供输入的完整程序中进行测试。
*/
#include <stdio.h>

int is_within(char ch, char * string);

int main(void)
{
    char * str = "Hello, world!";
    char chr;
    printf("The sourse string is : %s\n", str);
    printf("Which character do you want to find: ");
    scanf("%c" , &chr);
    printf("%d\n",is_within(chr , str));
    return 0;
}

int is_within(char ch, char * string)
{
    int i = 0;
    while (*string != '\0')
    {
        if (ch == *string)
        {
            i = 1;
        }
        string++;
    }
    return i;
}