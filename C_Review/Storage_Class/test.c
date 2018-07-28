#include <stdio.h>

void hello() {
	/*static int i = 100;*/
	printf("hello!");
}
int i = 100;
int main() {
	printf("%d\n", i);
	const char *p = "ABC";
	const char *q = "abc";
	printf("%p, %p\n", p, q);
	const char *a = "Xyz";
	*(&p) = "a";
	printf("%s, %p\n", p, p);
	p = q;
	printf("%s ,%s\n", p, a);
	printf("%p, %p\n", p, a);
	return 0;
}
