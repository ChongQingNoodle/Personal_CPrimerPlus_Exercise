// 1.编写一个程序,创建一个包含26个元素的数组,并在其中储存26个小写字母。然后打印数
// 组的所有内容。

int main(void)
{
    char a[] = {
        97, 98 ,99 ,100, 101, 102, 
        103, 104, 105, 106, 107, 
        108, 109, 110, 111, 112, 
        113, 114, 115, 116, 117, 
        118, 119, 120, 121, 122, 123
        };
    
    for (int i = 0; i < 26; i++)
    {
        printf("%c  " , a[i]);
    }
    return 0;
}