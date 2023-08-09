// 5.编写一个程序,提示用户输入大写字母。使用嵌套循环以下面金字塔型的格式打印字母:
//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
// 打印这样的图形,要根据用户输入的字母来决定。例如,上面的图形是在用户输入E后的打印
// 结果。提示:用外层循环处理行,每行使用3个内层循环,分别处理空格、以升序打印字母、
// 以降序打印字母。如果系统不使用ASCII或其他以数字顺户序编码的代码,请参照练习3的解决方案。

#include <stdio.h>

int main(void)
{
    int ROWS; //All the rows
    char b;
    char a = 'A'; //The start char
    printf("Please input a charactor :");
    scanf("%c" , &b);
    ROWS = b-a+1 ; //The rows equal char b - a
    for (int row = 0; row < ROWS; row++) //rows in the outside loop
    {
        for (int blank = + row ; blank < + ROWS ; blank++ )
        {
            printf(" ");//row less than the ROWS , than print blank.
        }
        for (int i =0 ; i<=row ; i++)
        {
            printf("%c",a+i);//正序打印
        }
        for (int j = 0; j < row; j++)
        {
            printf("%c" , a+row-j-1);//逆序打印
        }
        printf("\n");
    }
    return 0;
}