#include <stdio.h>

int fibo(int n) {
	int f;
	if(n < 2) f = n;
	else f = fibo(n - 1) + fibo(n - 2);
	return f;
}

int fib(int n) {
	int i, f, f0 = 0, f1 = 1;
	for(i = 2; i <= n; i++) {
		f = f1;
		f1 = f + f0;
		f0 = f;
	}
	if(n == 0) {
		f1 = 0;
	}
	return f1;
}

int main() {
	int result, result1 = 0;
	result = fibo(4);
	result1 = fib(4);
	printf("%d\n%d\n", result, result1);
	return 0;
}