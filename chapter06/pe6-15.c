// 15.编写一个程序,读取一行输入,然后把输入的内容倒序打!印出来。可以把输入储存在char
// 类型的数组中,假设每行字符不超过255。回忆一下,根据%c转换说明,scanf0函数一次只能
// 从输入中读取一个字符,而且在用户按下Enter键时scanf(p函数会生成一个换行字符(\n)。
#include <stdio.h>

int main(void)
{
    char a[255];
    printf("Please input sth:");
    int i = -1;
    do
    {
        i++;
        scanf("%c" , &a[i]);
    } while (a[i]!='\n');
    
    for (int j = i ; j>0 ; j--)
    {
        printf("%c" , a[j-1]);
    }
    printf("\n");
    return 0;
}