// 8.在C语言中,函数可以调用另一个函数。编写一个程序,调用一个名为one_three()的函
// 数。该函数在一行打印单词"one",再调用第2个函数two(),然后在另一行打印单词"three
// "。two()函数在一行显示单词"two"。main()函数在调用Jone_three()函数前要打印短语
// "starting now:",并在调用完毕后显示短语"done!"。因此,该程序的输出应如下所示:
// starting now:
// one
// two
// three
// done!

#include <stdio.h>

void one(void)
{
    printf("one\n");
}

void two(void)
{
    printf("two\n");
}

void three(void)
{
    printf("three\n");
}

void one_three(void)
{
    one();
    two();
    three();
}

int main(void)
{
    printf("starting now:\n");
    one_three();
    printf("done!\n");
}