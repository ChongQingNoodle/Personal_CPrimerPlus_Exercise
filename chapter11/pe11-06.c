/*
6.strncpy(s1,s2,n)函数从s2复制n个字符给sl,并在必要时截断s2或为其填充额外的空字符。
如果s2的长度等于或大于n,目标字符串就没有标志结束的空字符。函数返回s1。自己编写这个函数,并
在一个使用循环语句为这个函数提供输入的完整程序中进行测试。
*/
#include <stdio.h>

void str_n_cpy(char * target ,const char * sourse , int n);

int main(void)
{
    char * str = "Hello, world!";
    int n;
    char target[n];
    printf("The sourse string is : %s\n", str);
    printf("How many character do you want to copy: ");
    scanf("%d" , &n);
    str_n_cpy(target , str , n);
    printf("%s\n",target);
    return 0;
}

void str_n_cpy(char * target ,const char * sourse , int n)
{
    for (int i = 0; i < n; i++)
    {
        * (target + i) = * (sourse + i);
    }
    if (*(target + n) != '\0')
    {
        *(target + n) = '\0';
    }
}