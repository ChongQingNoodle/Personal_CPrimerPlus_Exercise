// 5.修改程序清单8.4的猜数字程序,使用更智能的猜测策略。例如,程序最初猜50,询问用
// 户是猜大了、猜小了还是猜对了。如果猜小了,那么下一次猜测的值应是50和100中值,也
// 就是75。如果这次猜大了,那么下一次猜测的值应是50禾和75的中值,等等。使用二分查找
// (binarysearch)策略,如果用户没有欺骗程序,那么程序很快就会猜到正确的答案。

#include <stdio.h>

int main(void)
{
    int guess = 50;
    int start = 0;
    int end  = 100;
    char response;
    printf("Pick an integer from 1 to 100. I will try to guess it\n");
    printf("Respond with a y if my guess is right and with an n if it is wrong.\n");
    printf("Uh... is your number %d? More or little?\n", guess);
    while ((response = getchar())!= 't')
    {
        if(response == 'm')
        {
            start = guess;
            guess = ( start + end ) / 2 ;
            printf("Well, then , is it %d\n", guess);
        }
        else if(response == 'l')
        {
            end = guess;
            guess = ( start + end ) / 2 ;
            printf("Well, then , is it %d\n", guess);
        }
        else
        {
            printf("Sorry, I understand only m or l or t.\n"); 
        }
        while (getchar()!='\n')
        {
            continue;
        }
        
    }
    printf("I knew I could do it !\n");
    return 0;
}