#include <stdio.h>
#include <stdlib.h>
int main(void) {
        int a = 10;
        int *p;
        int **q;

        p = &a;
        q = &p;
        printf("a = %d, *p =  %d, **p = %d\n", a, *p, **q);
        printf("&a = %p, p = %p, &p = %p, q = %p, * q = %p\n", &a, p, &p, q, *q);
        int *x = p;
        printf("*x = %d, x = %p\n", *x, x);
        return 0;
}
