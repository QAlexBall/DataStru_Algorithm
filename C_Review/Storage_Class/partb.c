/*
 * 复杂的c程序通常由多个单独的源代码文件组成.
 * 有时,这些文件可能要共享一个外部变量.
 * c通过在一个文件中进行定义式声明,然后在其他文件中
 * 进行引用式声明来实现共享.
 */
/*parta.c -- 不同的存储类别*/
/*与partb.c一起编译*/
#include <stdio.h>

extern int count;       // 引用式声明,外部链接

static int total = 0;   // 静态定义,内部链接
void accumulate(int k); // 函数原型

void accumulate(int k){ // k具有块作用域,无链接
        static int subtotal = 0; // 静态,无链接

        if(k <= 0) {
                printf("loop cycle: %d\n", count);
                printf("subtotal: %d; total: %d\n", subtotal, total);
                subtotal = 0;
        } else {
                subtotal += k;
                total += k;
        }
} 

