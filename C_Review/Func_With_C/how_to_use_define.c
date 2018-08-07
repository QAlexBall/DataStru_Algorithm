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
#define int_max (struct max) {1, 2}

int main(void) {
        int x = add(1, 1);
        printf("1 plus 1 is: %d\n", x);
        printf("%d\n", int_max.x);
        return 0;
}
