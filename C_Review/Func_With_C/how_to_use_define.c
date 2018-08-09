/**
 * 1. 无参宏的宏名后不带参数
 * #define 标识符 字符串
 * #define MAXNUM 12345
 *
 * 2. 有参宏定义
 * #define 宏名(形参表) 字符串
 * #dfine add(x, y) (x + y)
 */
#include <stdio.h>
#define add(x, y) (x + y) 
struct max {
        int x;
        int y;
};
#define int_max (struct max) {1, 2} // initilaizing a struct named max with x = 1, y = 2;

int main(void) {
        int x = add(1, 1);
        printf("1 plus 1 is: %d\n", x);
        printf("%d\n", int_max.x);      
#define SQUARE(X) X * X
        int X = 5;
        printf("%d\n", SQUARE(X + 2)); // this place opetation is X + 2 * X + 2
                                       // X = 5; the result = 5 + 2 * 5 + 2 = 17
/**
 * 用参数创建字符串: #运算符
 * C允许在字符串中包含宏参数.
 * 在类函数宏的替换体中,#号作为一个预处理运算符,可以吧记号转换成字符串
 */
#define PSQR(x) printf("The square of " #x " is %d.\n", ( (x) * (x)) )
        int y = 5;

        PSQR(y); // 调用第一个宏时,用"y"替换#x.
                 // ANSI C字符串的串联特性将这些字符串与printf()语句的其他字符串组合,生成最终的字符串
        PSQR(2 + 3);
        printf("hello" " " "World!\n"); // ANSI C字符串串联特性例子

/**
 * 预处理器黏合剂: ##运算符
 * 与#运算符类似,##运算符可用于类函数宏的替换部分.
 * 而且,##还可以用于对象宏的替换部分.##运算符把两个记号组合成一个记号
 */
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n);   // #运算符用于组合字符串,##运算符用于把记号组合为一个新的标识符
        int XNAME(1) = 8;
        PRINT_XN(1);    // output: x1 = 8
        int x3 = 30;
        PRINT_XN(3);    // output: x3 = 30;


        return 0;
}
