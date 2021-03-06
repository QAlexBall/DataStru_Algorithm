## FileIO
### 文件(file)
文件通常是在磁盘或固态硬盘上的一段已命名的存储区

C把文件看作是**一系列连续的字节**,每个字节都能被**单独读取**.
这与Unix环境中(C的发源地)的文件结构相对应.由于其他环境中可能
无法完全对应这个模型,C提供两种文件模式:**文本模式**和**二进制模式**

### 文本模式和二进制模式
**所有文件的内容肉都是以二进制形式(0或1)存储.**
如果文件最初使用二进制编码的字符表示文本,该文件就是文本文件,其中包含文本内容.
如果文件中的二进制值代表机器语言代码或数值数据或图片或音乐编码,该文件就是二进制文件,其中包含二进制内容.

Unix用同一种文件格式处理文本文件和二进制文件的内容.
为了规范文本文件的处理,C提供两种访问文件的途径:**二进制模式**和**文本模式**

在二进制模式中,程序可以访问文件的每个字节.
而在文本模式中,程序所见的内容和文件的实际不同.
程序以文本模式读取文件时,把本地环境表示的行尾或文件行尾映射为C模式.

### I/O的级别
除了选择文件的模式,大多数情况下,还可以选择I/O的两个级别(即处理文件访问的两个级别).
* 底层I/O(low-level I/O):使用操作系统提供基本I/O服务.
* 标准高级I/O(standard high-level I/O): 使用C库的标准包和stdio.h头文件定义.
因为无法保证所有的操作系统都使用相同的底层I/O模型,**C标准只支持标准I/O包**

### 标准文件
C程序会自动打开3个文件,它们被称为
**标准输入(standard input), 标准输出(standard output),和标准错误输出(standard Error output)**

通常,**标准输入**为程序提供输入,它是getchar()和scanf()使用的文件.
程序通常输出到**标准输出**,它是putchar(),puts()和printf()使用的文件.
**标准错误输出**提供了一个**逻辑上不同的地方**来发送错误信息.

### 标准I/O
与底层I/O相比,标准I/O包除了可以移植以外还有两个好处.
* 标准I/O有许多专门的函数简化了处理不同I/O的问题.
例如,(printf()把不同形式的数据转换成与终端相适应的字符串输出)
* 输入和输出都是**缓冲的**.
(也就是说,一次转移一大块信息而不是一个字节信息(通常至少512字节))
例如,当程序读取文件时,一块数据被拷贝到缓冲区(一块中介存储区域).
程序可以检查缓冲区中的字节.缓冲在后台处理.
