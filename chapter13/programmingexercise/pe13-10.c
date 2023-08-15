/*
10.编写一个程序打开一个文本文件,通过交互方式获得文件名。通过一个循环,提示用户输入一
个文件位置。然后该程序打印从该位置开始到下一个换行符之前的内容。用户输入负数或非数值字
符可以结束输入循环。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

int main(void)
{
    FILE * fp;
    char fileName[BUF_SIZE], buf[BUF_SIZE];
    long pos;
    int ret;
    //获取文件名
    printf("Enter your file name :");
    
    fgets(fileName, BUF_SIZE, stdin);
    //删除换行符
    
    char * posn = strchr(fileName, '\n');
    if (posn != NULL)
    {
        *posn = '\0';
    }
    
    //打开文件
    if ((fp = fopen(fileName, "r"))== NULL)
    {
        fprintf(stdout, "Can't open \"%s\" file.\n",fileName);
        exit(EXIT_FAILURE);
    }
    while (1) 
    {
        printf("请输入文件位置（负数或非数值字符结束）：");
        if (fgets(buf, BUF_SIZE, stdin) == NULL) 
        {
            break;
        }
        // 解析输入
        ret = sscanf(buf, "%ld", &pos);
        if (ret != 1 || pos < 0) 
        {
            break;
        }
        // 定位文件位置
        if (fseek(fp, pos, SEEK_SET) != 0) 
        {
            printf("无法定位文件位置\n");
            break;
        }
        // 输出内容
        if (fgets(buf, BUF_SIZE, fp) != NULL) 
        {
            printf("%s", buf);
        } else 
        {
            printf("无法读取文件内容\n");
            break;
        }
        // 定位下一个换行符
        while (fgets(buf, BUF_SIZE, fp) != NULL) 
        {
            if (strchr(buf, '\n') != NULL) 
            {
                break;
            }
        }
        // 输出换行符后的内容
        if (fgets(buf, BUF_SIZE, fp) != NULL) 
        {
            printf("%s", buf);
        } 
        else 
        {
            printf("已到达文件末尾\n");
            break;
        }
    }
    // 关闭文件
    fclose(fp);
    return 0;
}