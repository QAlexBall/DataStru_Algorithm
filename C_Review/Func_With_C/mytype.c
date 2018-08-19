/**
 * C11增加了一种表达式,叫做泛型选择表达式(generic selection expression)
 * 可以根据表达式的类型(即表达式的类型是int, double还是其他类型)选择一个值.
 * 泛型选择表达式不是预处理指令,但是在一些泛型编程中它常作#define宏定义的一部分
 */

#include <stdio.h>

#define MYTYPE(X) _Generic((X), \
        int :"int", \
        float : "float", \
        double : "double", \
        default : "other" \
        )

int main(void) {
        int d = 5;

        printf("%s\n", MYTYPE(d));              // d是int类型
        printf("%s\n", MYTYPE(2.0 * d));        // 2.0 * d 是double类型
        printf("%s\n", MYTYPE(3L));
        printf("%s\n", MYTYPE(&d));             // &d的类型是 int*

        return 0;
}

