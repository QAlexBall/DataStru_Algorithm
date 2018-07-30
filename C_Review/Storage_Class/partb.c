/*
 * 复杂的c程序通常由多个单独的源代码文件组成.
 * 有时,这些文件可能要共享一个外部变量.
 * c通过在一个文件中进行定义式声明,然后在其他文件中
 * 进行引用式声明来实现共享.
 */
/*parta.c -- 不同的存储类别*/
/*与partb.c一起编译*/
#include <stdio.h>

void report_count();
void accumulate(int k);

