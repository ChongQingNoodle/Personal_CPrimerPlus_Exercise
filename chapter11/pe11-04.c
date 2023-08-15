/*
4.设计并测试一个函数,其功能是搜索由函数的第一个参数指定的字符串,在其中查找由函数的第二
个参数指定的字符的第一次出现的位置。如果找到,返回指向这个字符的指针;如果没有找到,返回空字符
(这种方式和strchr()函数的功能一样)。在一个使用循环语句为这个函数提供输入的完整程序中进行测试。
*/
#include <stdio.h>

char* strfind(char * string, char key);

int main(void)
{
    char * str = "Hello, world!";
    char chr;
    printf("The sourse string is : %s\n", str);
    printf("Which character do you want to find: ");
    scanf("%c" , &chr);
    printf("%s\n",strfind(str , chr));
    return 0;
}

char* strfind(char * string, char key)
{
    char *ptr = string;
    while (*ptr != key && *ptr != '\0')
    {
        ptr++;
    }
    return ptr;
}