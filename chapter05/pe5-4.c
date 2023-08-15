// 4.编写一个程序,提示用户输入一个身高(单位:厘米),主千分别以英尺和英寸为单位显示
// 该值,允许有小数部分。程序应该能让用户重复输入身高,直直到用户输入一个非正值。其输
// 出示例如下:
// Enter a height in centimeters: 182
// 182.0 cm = 5 feet, 11.7 inches
// Enter a height in centimeters (<=0 to quit): 168.7
// 168.7 cm = 5 feet, 6.4 inches
// Enter a height in centimeters (<=0 to quit): 0
// bye

#include <stdio.h>

const float F_CM = 30.48;
const float I_CM = 2.54;
int main(void)
{
    float height;
    printf("Enter a height in centimeters:");
    scanf("%f",&height);
    while (height > 0)
    {
        printf("%.1f cm = %.0f feet , %.1f inches\n",height, height/F_CM,height/I_CM);
        printf("Enter a height in centimeters ( <= 0 to quit):");
        scanf("%f",&height);
        if (height <= 0 )
        {
            printf("BYE\n");
            break;
        }
    }
    return 0;
}