/*
9.编写一个符合以下描述的函数。首先,询问用户需要输入多少个单词。然后,接收用户输入的单
词,并显示出来,使用malloc()并回答第1个问题(即要输入多少个单词),创建一个动态数组,
该数组内含相应的指向char的指针(注意,由于数组的每个元素都是指向char的指针,所以用于储
存malloc()返回值的指针应该是一个指向指针的指针,且它所指向的指针指向char)。在读取字符
串时,该程序应该把单词读入一个临时的char数组,使用malloc()分配足够的存储空间来储存单
词,并把地址存入该指针数组(该数组中每个元素都是指向char的指针)。然后,从临时数组中把
单词拷贝到动态分配的存储空间中。因此,有一个字符指针数组,每个指针都指向一个对象,该对
象的大小正好能容纳被储存的特定单词。下面是该程序的一个运行示例:

How many words you wish to enter? 5
Enter 5 words now:
I enjoyed doing this exercise
Here are your words:
I
enjoyed
doing
this
exercise
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num;
    printf("How many words you wish to enter? ");
    scanf("%d", &num);
    printf("Enter %d words nuw: ", num);
    char ** words = (char **)malloc(num * sizeof (char *));
    for (int i = 0; i < num; i++)
    {
        char tmp[100];
        scanf("%s", tmp);
        int char_num;
        char_num = strlen(tmp);
        char * word = (char *)malloc(char_num * sizeof(char));
        strncpy(word , tmp , char_num);//strncpy
        
        words[i] = word;
        //之前错误的在此处释放了word的内存，所以最终打印的数组是空的
    }
    puts("Here are your words:");
    for (int i = 0; i < num; i++)
    {
        puts(words[i]);
    }
    for (int i = 0; i < num; i++)
    {
        free(words[i]);//可以直接释放指向被malloc分配的内存的指针来释放内存
        //malloc 分配的内存属于堆内存，堆内存是一种动态内存。不受代码块生命周期影响
    }
    free(words);
}