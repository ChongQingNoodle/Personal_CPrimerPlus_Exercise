/*
2.编写一个文件拷贝程序,该程序通过命令行获取原始文件名和拷贝文件名。
尽量使用标准I/O和二进制模式。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 41

int main(int argc, char * argv[])
{
    int ch;//需要拷贝的文件的内容
    FILE *fin, *fout;//声明两个指向FILE的指针
    char name[LEN];//存储输出文件的名称

    //检查命令行参数
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    //设置输入
    if ((fin = fopen(argv[1], "rb")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    //设置输出
    strncpy(name, argv[1], LEN - 5);//拷贝文件名
    name[LEN - 5] = '\0';
    strcat(name, ".copy");          //文件名添加.copy
    if ((fout = fopen(name, "wb")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    //拷贝数据
    while ((ch = getc(fin)) != EOF)
    {
        putc(ch, fout);             //打印每一个字符
    }
    //收尾
    if (fclose(fin) != 0 || fclose(fout) != 0)
    {
        fprintf(stderr, "Error in closeing files\n");
    }
    return 0;
}
