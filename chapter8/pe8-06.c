// 6.修改程序清单8.8中的get_first()函数,让该函数返回读取的第1个非空白字符,并在一个
// 简单的程序中测试。

#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
    printf("%c\n",get_first());
}

char get_first(void)
{
    int ch;
    while (isspace(ch = getchar()))//如果是空的，就继续获取下一个字符
    {
        continue;
    }
    return ch;
}