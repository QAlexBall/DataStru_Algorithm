#include <stdlib.h>
#include <iostream>
using namespace std;

extern "C"
{
	void test() {
		cout << "TEST" << endl;
	}

	int addTest(int a, int b) {
		int c = a + b;
		return c;
	}
}
