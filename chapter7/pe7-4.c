// 4.使用ifelse语句编写一个程序读取输入,读到#停止。用感叹号替换句号,用两个感叹号
// 替换原来的感叹号,最后报告进行了多少次替换。

#include <stdio.h>
#include <stdlib.h>
#define STOP '#'

int main(void)
{
    char chr[255];//定义1个255个字符的字符串
    int cnt_rpl = 0;//定义并初始化替换次数
    char tmp;//定义一个临时变量
    printf("Enter some paragraphs:\n");
    int i=-1;
    while ((scanf("%c", &tmp)==1)&&tmp!=STOP)//读取1个字符到临时变量中
    {
        i++;
        if(tmp == '.')//临时变量是句号则变感叹号
        {
            chr[i] = '!';
            cnt_rpl++;
        }
        else if (tmp == '!')//临时变量是感叹号就加一个感叹号
        {
            chr[i] = '!';
            i++;
            chr[i] = '!';
            cnt_rpl++;
        }
        else
        {
            chr[i] = tmp;//临时变量放入字符串
        }
    };

    printf("%s\n" , chr);
    printf("replase %d times.\n" , cnt_rpl);
    return 0;
}