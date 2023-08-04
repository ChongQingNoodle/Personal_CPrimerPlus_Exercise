// 5．编写一个程序，先提示用户输入名，然后提示用户输入姓。在一行打印用户输入的名和姓，下一行分别打印名和姓的字母数。字母数要与相应名和姓的结尾对齐，如下所示：

// Melissa Honeybee
//       7        8


// 接下来，再打印相同的信息，但是字母个数与相应名和姓的开头对齐，如下所示：

// Melissa Honeybee
// 7       8

#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[40];
    char last_name[40];
    int first_name_len;
    int last_name_len;
    printf("What's your first name:");
    scanf("%s",first_name);
    printf("What's your last name:");
    scanf("%s",last_name);
    first_name_len = strlen(first_name);
    last_name_len = strlen(last_name);
    printf("%-*s",first_name_len+1,first_name);
    printf("%s\n",last_name);
    printf("%*d",first_name_len,first_name_len);
    printf("%*d\n",last_name_len+1,last_name_len);
    printf("%-*s",first_name_len+1,first_name);
    printf("%s\n",last_name);
    printf("%-*d",first_name_len+1,first_name_len);
    printf("%-*d\n",last_name_len,last_name_len);
}