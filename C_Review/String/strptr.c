/* strptr.c -- 把字符串看做指针 */
#include <stdio.h>
int main(void) {
	printf("%s, %p, %c\n", 
		"We", "are", *"space farers");
	return 0;
}
