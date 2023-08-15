/*
7.编写一个程序,按照程序清单12.13输出示例后面讨论的内容,修改该程序。使其输出类似:
Enter the number of sets; enter q to stop : 18
How many sides and how many dice? 6 3
Here are 18 sets of 3 6-sided throws.
12 10 6 9 8 14 8 15 9 14 12 17 11 7 10
13 8 14
How many sets? Enter q to stop: q
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randnum(int n);

int dice, side, number;

int main(void)
{
    printf("Enter the number of sets; enter q to stop :");
    while(scanf("%d", &number)==1 && number != 'q')
    {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &side , &dice);
        srand(time(0));
        for (int i = 0; i < number; i++)
        {
            int tot = 0;
            
            for (int j = 0; j < dice; j++)
            {
                tot += randnum(side);
            }
            printf("%4d",tot);
        }
        printf("\n");
        printf("How many sets? Enter q to stop: ");
    }
}

int randnum(int n)//生成1个1～n之间的随机数
{
    int randnum;
    
    randnum = rand()%n + 1;
    return randnum;
}