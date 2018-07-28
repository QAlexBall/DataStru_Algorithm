/*loc_stat.c --使用局部静态变量*/
/*
 * 静态变量(static variable)
 * 静态的意思是该变量在内存中原地不动,并不是它的值不会变.
 * 具有文件作用域的变量自动具有(也必须是)静态存储期.
 */
#include <stdio.h>

void trystat(void);

int main(void) {
        int count;
        
        for(count = 1; count <= 3; count++) {
                printf("Here comes iteration %d:\n", count);
                trystat();
        }

        return 0;
}

void trystat(void) {
        int fade = 1;
        static int stay = 1;

        printf("fade = %d and stay = %d\n", fade++, stay++);
}
