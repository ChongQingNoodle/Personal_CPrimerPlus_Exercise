// 4．编写一个程序，创建一个有两个成员的结构模板：
// a．第1个成员是社会保险号，第2个成员是一个有3个成员的结构，第1个成员代表名，第2个成员代表中间名，
// 第3个成员表示姓。创建并初始化一个内含5个该类型结构的数组。该程序以下面的格式打印数据：

// Dribble, Flossie M. –– 302039823

// 如果有中间名，只打印它的第1个字母，后面加一个点（.）；
// 如果没有中间名，则不用打印点。编写一个程序进行打印，把结构数组传递给这个函数。
// b．修改a部分，传递结构的值而不是结构的地址。

#include <stdio.h>
#define LEN 20


struct names{
    char first[LEN];
    char mid[LEN];
    char last[LEN];
};

struct archives{
    int social_num;
    struct names name;
};

void print_info(struct archives info[], int n);

int main()
{
    struct archives person[4] = {
        101102103,{"Jia","Zi","Yan"},
        101102305,{"Li","He","Xi"},
        101102507,{"Guan","Zi","Wei"},
        101102233,{"Chen","Zhu","Bing"}
    };
    print_info(person, 4);

    return 0;
}

void print_info(struct archives info[], int n)
{
    int i;
    
    for (i = 0; i<n; i++)
    {
        printf("%s, %s %c. - %d\n", info[i].name.last,info[i].name.first,info[i].name.mid[0],info[i].social_num);
    }
}