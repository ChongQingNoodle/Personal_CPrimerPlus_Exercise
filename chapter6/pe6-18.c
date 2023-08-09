// 18.Rabnud博士加入了一个社交圈。起初他有5个朋友。他注意到他的朋友数量以下面的方式
// 增长。第1周少了1个朋友,剩下的朋友数量翻倍;第2周少了2个朋友,剩下的朋友数量翻
// 倍。一般而言,第N周少了N个朋友,剩下的朋友数量翻倍。编写一个程序,计算并显示
// Rabnud博士每周的朋友数量。该程序一直运行,直到超过邓巴数(Dunbar'snumber)。邓巴
// 数是粗略估算一个人在社交圈中有稳定关系的成员的最大值,该值大约是150。


#include<stdio.h>

const int DunbarsNumber = 150;

int main(void)
{
    int startFriendCount = 5;
    int currentFriendCount = startFriendCount;
    int week = 0;
    
    while (currentFriendCount < DunbarsNumber)
    {
        
        week++;
        currentFriendCount -= week;
        currentFriendCount *= 2;
        if (currentFriendCount > DunbarsNumber)
        {
            break;
        }
        
        printf("%i\n",currentFriendCount);
    }
    
}