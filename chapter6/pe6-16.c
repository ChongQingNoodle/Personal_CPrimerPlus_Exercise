// 16.Daphne以10%的单利息投资了100美元(也就是说,每每年投资获利相当于原始投资的
// 10%)。Deirdre以5%的复合利息投资了100美元(也就是说,利息是当前余额的5%,包含之
// 前的利息)。编写一个程序,计算需要多少年Deirdre的投资额才会超过Daphne,并显示那时
// 两人的投资额。

#include <stdio.h>

const double DA = 0.1;
const double DE = 0.05;
int main(void)
{
    int a = 100;
    int e = 100;
    int i = 0;
    do
    {
        i++;
        a = a + a*DA;
        e = e * (1+DE);
    } while (e < a);
    printf("The year in %d , the De will lager than DA\n De = %d , Da = %d\n", i , e, a);
}