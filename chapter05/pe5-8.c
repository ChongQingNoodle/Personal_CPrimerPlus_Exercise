// 8.编写一个程序,要求用户输入一个华氏温度。程序应读取double类型的值作为温度值,并
// 把该值作为参数传递给一个用户自定义的函数Temperatures()。该函数计算摄氏温度和开氏
// 温度,并以小数点后面两位数字的精度显示3种温度。要使用用不同的温标来表示这3个温度
// 值。下面是华氏温度转摄氏温度的公式:
// 摄氏温度=5.0/9.0*(华氏温度-32.0)
// 开氏温标常用于科学研究,0表示绝对零,代表最低的温度。下面是摄氏温度转开氏温度的公
// 式:
// 开氏温度=摄氏温度+273.16
// Temperatures()函数中用const创建温度转换中使用的变量。在main()函数中使用一个循环
// 让用户重复输入温度,当用户输入q或其他非数字时,循环结)束。scanf()函数返回读取数据
// 的数量,所以如果读取数字则返回1,如果读取q则不返回1。。可以使用==运算符将scanf()
// 的返回值和1作比较,测试两值是否相等。
#include <stdio.h>

void Temperatures(double n);

int main(void)
{
    double t;
    printf("Please input a temperatures in F:");
    while (scanf("%lf" , &t)==1)
    {
        Temperatures(t);
        printf("Please input a temperatures in F (q to quit):");
    }
    printf("BYE\n");
}

void Temperatures(double n)
{
    const double A = 1.8;
    const double B = 32.0;
    const double KELVIN = 273.16;
    double Celsius = n*A+B ;
    double Kelvin = Celsius + KELVIN;
    printf("Celsius is %.2f\n" , Celsius);
    printf("Kelvin is %.2f\n" , Kelvin);
}