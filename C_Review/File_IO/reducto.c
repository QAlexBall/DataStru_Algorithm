// reducto.c -把文件压缩成原来的1/3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(int argc, char *argv[]) {
	FILE *in, *out;		// 声明两个指向FILE的指针
	int ch;
	char name[LEN];		// 存储输出文件名

	/*检查命令行参数*/
	if(argc < 2) {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/*设置输入*/
	if ((in = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "I couldn't open file the file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*设置输出*/
	strncpy(name, argv[1], LEN - 5);	// 拷贝文件名
	name[LEN - 5] = '\0';
	strcat(name, ".red"); 			// 在文件名后添加.red

	return 0;
}
