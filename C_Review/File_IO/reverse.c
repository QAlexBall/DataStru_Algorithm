/* reverse.c -- 倒序显示文件的内容 */

#include <stdio.h>
#include <stdlib.h>

#define CNTL_Z '\032'   /* DOS文本文件中的文件结尾标记 */
#define SLEN 81
/**
 * ftell(): 返回当前位置; 返回一个long类型的值,表示文件中的当前位置
 * fseek(): 3个参数,返回int类型的值
 *              fseek()第一个参数是FILE指针,指向待查找的文件,fopen()应该以打开该文件
 *              fseek()第二个参数是偏移量(offset)
 *              fseek()第三个参数是模式,该参数确定起始点
 *              SEEK_SET        :       文件开始处
 *              SEEK_CUR        :       当前位置
 *              SEEK_END        :       文件末尾
 */
int main(void) {
        char file[SLEN];
        char ch;
        FILE *fp;
        long count, last;

        puts("Enter the name of the file to be processed: ");
        scanf("%80s", file);
        if((fp = fopen(file, "rb")) == NULL) {
                printf("reverse can't open %s\n", file);
                exit(EXIT_FAILURE);
        }
        fseek(fp, 0L, SEEK_END);        /* 定位到文件末尾 */
        last = ftell(fp);       
        printf("last is %ld\n", last);
        for(count = 1L; count <= last; count++) {
               fseek(fp, -count, SEEK_END);     /* 回退 */ 
               ch = getc(fp);                   /* 从fp指向的文件中获取一个字符 */
               /* putc(ch, fpout)               把字符ch放入FILE指针fpout指定的文件中 */

               if(ch != CNTL_Z && ch != '\r') /* MS-DOS文件 */
                        putchar(ch);
        }
        putchar('\n');
        fclose(fp);

        return 0;
}
