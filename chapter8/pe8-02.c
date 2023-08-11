// 2.编写一个程序,在遇到EOF之前,把输入作为字符流读取。程序要打印每个输入的字符及
// 其相应的ASCII十进制值。注意,在ASCII序列中,空格字符前面的字符都是非打印字符,要
// 特殊处理这些字符。如果非打印字符是换行符或制表符,则分别打印\n或\t。否则,使用控
// 制字符表示法。例如,ASCII的1是Ctrl+A,可显示为^A。注意,A的ASCII值是Ctrl+A的值
// 加上64。其他非打印字符也有类似的关系。除每次遇到换行符打印新的一行之外,每行打印
// 10对值。(注意:不同的操作系统其控制字符可能不同。)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
    int ch;
    int n = 0;

    while((ch = getchar())!= EOF)
    {
        n++;
        if(n%10==0)
        {
            int i = 1;
            printf("\n");
        }

        if (ch == '\n')
        {
            printf("-\\n\n");
            n = 0;
        }
        else if (ch == '\t')
        {
            printf("-\\t ");
        }
        else if (ch == '1')
        {
            printf("^A");
        }
        else if (isalpha(ch))
        {
            printf("%c" , ch);
            printf("-%d " ,ch);
        }
        
    }
}