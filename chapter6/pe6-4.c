// 4.使用嵌套循环,按下面的格式打印字母:
// A
// BC
// DEF
// GHIJ
// KLMNO
// PQRSTU
// 如果你的系统不使用以数字顺序编码的代码,请参照练习3的方案解决。


#include <stdio.h>

int main(void)
{
    char n = 'A';
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%c", n);
            
            n++;
        }
        printf("\n");
    }
    
}