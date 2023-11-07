// 5．编写一个程序满足下面的要求。
//  a．外部定义一个有两个成员的结构模板name：一个字符串储存名，一个字符串储存姓。
//  b．外部定义一个有3个成员的结构模板student：一个name类型的结构，一个grade数组储存3个浮点型分数，一个变量储存3个分数平均数。
//  c．在main()函数中声明一个内含CSIZE（CSIZE = 4）个student类型结构的数组，并初始化这些结构的名字部分。用函数执行g、e、f和g中描述的任务。
//  d．以交互的方式获取每个学生的成绩，提示用户输入学生的姓名和分数。把分数储存到grade数组相应的结构中。可以在main()函数或其他函数中用循环来完成。
//  e．计算每个结构的平均分，并把计算后的值赋给合适的成员。
//  f．打印每个结构的信息。
//  g．打印班级的平均分，即所有结构的数值成员的平均值。

#include <stdio.h>
#define LEN 20
#define CSIZE 4

typedef struct Name
{
    char firstname[LEN];
    char lastname[LEN];
}Name;

typedef struct Student
{
    Name name;
    float Grade[3];
    float avgGrade;
}Student;

void getgrade(Student target[]);
void AvgGrade(Student target[]);
void Printinfo(Student target[]);
void PrintAvg(Student target[]);

int main(void)
{
    Student student[CSIZE] = {
        {"Ziyan","Jia"},
        {"Xiao","Ming"},
        {"Li","Hong"},
        {"Mei","Han"}
    };
    getgrade(student);
    AvgGrade(student);
    Printinfo(student);
    PrintAvg(student);
}

void getgrade(Student target[])
{
    int ch;
    for (int i = 0; i < CSIZE; i++)
    {
        printf("Please input %s %s's grade as 3 numbers:\n",target[i].name.lastname,target[i].name.firstname);
        while (scanf("%f %f %f",&target[i].Grade[0],&target[i].Grade[1],&target[i].Grade[2])!=3)
        {
            while((ch = getchar()) != '\n')
                putchar(ch); //删除错误的输入
            printf(" is not a correct input.\n");
            printf("Error, again please.Input %s %s's grade as 3 numbers:\n",target[i].name.lastname,target[i].name.firstname);
        }
        printf("Ok, the next one\n");
    }
    printf("Input success!\n");
}

void AvgGrade(Student target[])
{
    printf("Calculate avg...\n");
    for (int i = 0; i < CSIZE; i++)
    {
        target[i].avgGrade = (target[i].Grade[0] + target[i].Grade[1] + target[i].Grade[2])/3;
    }
    printf("Done.\n");
}

void Printinfo(Student target[])
{
    for (int i = 0; i < CSIZE; i++)
    {
        printf("%5s %5s  score: %.2f %.2f %.2f  avg: %.2f\n",target[i].name.lastname,target[i].name.firstname,target[i].Grade[0],target[i].Grade[1],target[i].Grade[2],target[i].avgGrade);
    }
}

void PrintAvg(Student target[])
{
    float avg = 0;
    for (int i = 0; i < CSIZE; i++)
    {
        avg += target[i].avgGrade;
    }
    avg /= CSIZE;
    printf("The avg of all grades is %.2f.\n", avg);
}