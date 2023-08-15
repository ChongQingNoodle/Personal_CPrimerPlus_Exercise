/*
7.编写一个函数string_in(),它接受两个字符串指针参数。如果第二个字符串被包含在第一个字符
串中,函数就返回被包含的字符串开始的地址。例如,string_in("hats","at")返回hats中a的地址,否
则,函数返回空指针。在一个使用循环语句为这个函数提供输入的完整程序中进行测试。
*/
#include <stdio.h>
#define LIMIT 81

char * string_in(const char * string ,const char * check);

int main(void)
{
    char * str = "Hello, world!";
    char check[LIMIT];
    printf("The sourse string is : %s\n", str);
    printf("Which character do you want to find: ");
    scanf("%s" , check);
    printf("%s\n", string_in( str , check));
    return 0;
}

char * string_in(const char * string ,const char * check)
{
    char *ptr = NULL;
    int i = 0;
    int j = 0;
    while ( *(check+i) != '\0' && *(string+i+j) != '\0')
    {
        if ( *(check+i) == *(string+i+j))
        {
            i++;
        }
        else
        {
            i=0;
            j++;
        }
    }
    if (*check == *(string+j))
    {
        ptr = (char *)(string+j);
    }
    
    return ptr;
}