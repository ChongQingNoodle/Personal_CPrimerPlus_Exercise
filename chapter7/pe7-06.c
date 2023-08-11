// 6.编写程序读取输入,读到#停止,报告ei出现的次数。
// 注意该程序要记录前一个字符和当前字符。
// 用"Receive your eiecio award"这样的输入来测试。

#include <stdio.h>
#include <stdlib.h>
#define STOP '#'

int main(void)
{
    char former_chr ;
    char now_chr ;
    char tmp;
    int cnt_ei = 0;
    printf("Enter some grapher:\n");
    while ((tmp = getchar())!= STOP)
    {
    former_chr = now_chr;
    now_chr = tmp;
    if (former_chr == 'e' && now_chr == 'i')
        {
        cnt_ei++;
        }
    }
    printf("The \"ei\" is %d times.\n", cnt_ei);
}