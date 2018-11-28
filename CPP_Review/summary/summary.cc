#include <iostream>
using namespace std;

int main() {
	int *a = new int[10] {1, 2, 3, 4, 5};
	int a1[10] = {1, 2, 3, 4, 5};
	
	int *point_array[10];		// 指针数组
	
	point_array[1] = a;
	for (int i = 0; i < 5; i++) {
		cout << point_array[1][i] << " " << a[i] << endl;
	}

	point_array[2] = a1;
	for (int i = 0; i < 5; i++) {
		cout << point_array[2][i] << " " << a1[i] << endl;
	}

	cout << "array point" << endl;
	int a2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int (*array_point)[3];	// 数组指针
	array_point = a2;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << array_point[i][j] << " " << a2[i][j] << endl;
		}
	}
	int a3[3][3] = {1, 2, 3};
	int (*c1)[3];
	c1 = a3;
	return 0;
}