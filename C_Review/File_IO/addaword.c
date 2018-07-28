/*addaword.c -- 使用 fprintf(), fscanf() 和 rewind()*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void) {
	FILE *fp;
	char words[MAX];

	if((fp = fopen("wordy", "a+")) == NULL) {
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a lineto terminate.");
	while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);
	
	return 0;
}
