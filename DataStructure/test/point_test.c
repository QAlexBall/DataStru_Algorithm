#include <stdio.h>

void simple_trans(int x) {
	x = 5;
}

void use_point(int *x) {
	*x = 5;
}

int main() {
	int x = 3;
	simple_trans(x);
	printf("%d\n", x);
	use_point(&x);  // 使用指针之后被传递的地址经过指针又重新指向x
	printf("%d\n", x);

	int *y;
	y = &x;
	printf("%d", *y);
	return 0;
}