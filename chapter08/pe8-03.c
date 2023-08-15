// 3.编写一个程序,在遇到E0F之前,把输入作为字符流读取。该程序要报告输入中的大写字
// 母和小写字母的个数。假设大小写字母数值是连续的。或者使用ctype.h库中合适的分类函数
// 更方便。

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int n_upper = 0;
    int n_lower = 0;
    int ch;

    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
        {
            n_upper++;
        }
        else
        {
            n_lower++;
        }
    }
    printf("Uppers : %d , lowers : %d\n",n_upper,n_lower);
}