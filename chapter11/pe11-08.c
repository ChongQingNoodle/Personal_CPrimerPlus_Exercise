/*
8.编写一个函数,其功能是使输入字符串反序。在一个使用循环语句为这个函数提供输入的完整程序
中进行测试。
*/
#include <stdio.h>
#define LIMIT 81

void turn_back(char * string);

int main(void)
{
    char str[LIMIT] = "Hello, world!";
    printf("The sourse string is : %s\n", str);
    printf("The turnback is : ");
    turn_back(str);
    printf("%s\n", str);
    return 0;
}

void turn_back(char * string)//注意 向函数传递字符串时只能采用指针形式，这就必须确保传入的指针已被分配合法内存
{
    int i = 0 ;
    int j = 0 ;

    while (*(string + j)!= '\0')
    {
        j++;
    }

    char tmp[j+1];
    while (j > 0)
    {
        j--;
        *(tmp+i) = *(string+j);
        i++;
    }

    *(tmp+i) = '\0';

    while (*(tmp+j) != '\0')
    {
        *string = *(tmp+j);
        string++;
        j++;
    }
}