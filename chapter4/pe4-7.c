// 8．编写一个程序，提示用户输入旅行的里程和消耗的汽油量。
// 然后计算并显示消耗每加仑汽油行驶的英里数，显示小数点后面一位数字。
// 接下来，使用1加仑大约3.785升，1英里大约为1.609千米，
// 把单位是英里/加仑的值转换为升/100公里（欧洲通用的燃料消耗表示法），
// 并显示结果，显示小数点后面1位数字。
// 注意，美国采用的方案测量消耗单位燃料的行程（值越大越好），
// 而欧洲则采用单位距离消耗的燃料测量方案（值越低越好）。
// 使用#define创建符号常量或使用const限定符创建变量来表示两个转换系数。

#include <stdio.h>

const float LV = 3.785;
const float KM = 1.609;

int main(void)
{
    double mile;
    double gal; 
    printf("How many mile did you drive:");
    scanf("%lf" , &mile);
    printf("How many gal oil did you ues:");
    scanf("%lf" , &gal);
    printf("Per gal you could drive %.1f miles.\n",mile/gal);
    printf("Per 100km would cost %.fL oil.\n",((mile*KM)/(gal*LV))*100);
}