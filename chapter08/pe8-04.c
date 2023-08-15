// 4.编写一个程序,在遇到EOF之前,把输入作为字符流读B取。该程序要报告平均每个单词的
// 字母数。不要把空白统计为单词的字母。实际上,标点符号号也不应该统计,但是现在暂时不
// 同考虑这么多(如果你比较在意这点,考虑使用ctype.h系)列中的ispunct()函数)。

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    float n_contrl = 0;
    float n_alpha = 0;
    float n_print = 0;
    float n_punct = 0;
    float ch;

    while ((ch = getchar())!= EOF)
    {
        if (iscntrl(ch))
        {
            
            n_contrl++;
        }
        if (isalpha(ch))
        {
            n_alpha++;
        }
        if (ispunct(ch))
        {
            n_punct++;
        }
        if (isprint(ch))
        {
            n_print++;
        }
    }
    printf("words have %.2f\n" , n_alpha/(n_print + n_contrl - n_alpha - n_punct));
}
