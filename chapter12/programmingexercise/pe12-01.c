/*
1.不使用全局变量，重写程序清单12.4。
*/

#include <stdio.h>

void critic(int * u);

int main(void)
{
    int units = 0;/*代码块变量，内部链接*/

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
    {
        critic(&units);
    }
    printf("You must have looked it up!\n");
    return 0;
}

void critic(int * u)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d",u);
}