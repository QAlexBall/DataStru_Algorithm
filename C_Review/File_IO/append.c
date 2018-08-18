/**
 * int ungetc()         int unget(int c, FILE *fp);
 * 函数把c指定的字符放回输入流中
 * 
 * int ffluash()        int fflush(FILE *fp);
 * 调用fflush()函数引起输入缓冲区所有的未写入数据被发送到fp指定的输出文件
 * 
 * int setvbuf()        int setvbuf(FILE * restruct fp, cahr * restrict buf, int mode, size_t size);
 * 创建了一个供标准I/O函数替换使用的缓冲区
 *
 * fread() and fwrite()
 * size_t fwrite()      size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict fp);
 * fwirte()函数把二进制数据写入文件     char buffer[256]; fwrite(buffer, 256, 1, fp) 把一块256字节的数据从buffer写入文件.
 * prt: 待写入数据块地址
 * size: 数据块大小
 * nmemb: 待写入数据块的数量
 * fp: 待写入文件
 *
 * size_t fread()       size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE * restrict fp);
 * double earnings[10];  fread(earnings, sizeof (double), 10, fp);      把10个double大小的值拷贝进earnings数组中
 *
 * 如果标准如数函数返回EOF,通常表明函数已到达文件结尾.然而,出现读取错误时,函数也会返回EOF.feof()和ferror()用于区分这两种情况.
 * int feof(FILE *fp)   当上一次输入调用检测到文件结尾时,feof()函数返回一个非0值,否则返回0.
 * int ferror(FILE *fp) 当出现读写错误时,ferror()函数返回一个非0值,否则返回0.
 */


/* append.c -- 把文件附加到另一个文件末尾 */

/** 
 * 询问母校文件的名称并打开它
 * 使用一个循环访问源文件
 * 以读模式一次打开每个源文件,并将其添加到目标文件的末尾
 */

