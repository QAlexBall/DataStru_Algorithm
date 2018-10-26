##### C++文件和流

* ofstream	该数据表示输出文件流,用于创建文件并向文件写入信息
* ifstream          该数据类型表示输入文件流,用于文件读取信息
* fstream            该数据类型同城表示文件流,且同事具有ofstream和ifstream两种功能,这意味着它可以创建文件,向文件写入信息,从文件中读取信息



###### 打开文件

```c++
void open(const char *filename, ios::openmode mode);
```

在这里,open()成员函数的第一参数指定要打开的文件的名称和位置,第二个参数定义文件被打开的模式

模式标志

* ios::app     追加模式.所有写入都追加到文件末尾.
* ios::ate        文件打开后定位到文件末尾.
* ios::in          打开文件用于读取.
* ios::out       打开文件用于写入.
* ios::trunc    如果该文件已经存在,其内容在代开文件之前被截断,即把文件长度设为0. 

例如,如果需要以写入模式打开文件,并希望截断文件,以防文件已存在

```c++
fstream afile;
afile.open("file.dat", ios::out | ios::in);
```

###### 关闭文件

当C++程序终止时,它会自动关闭刷新所有流,释放所有分配的内存,并关闭所有打开的文件.

```c++
void close()
```



###### 写入文件

在C++编程中,使用流插入运算符( << )性文件写入信息,就像使用该运算符输出信息到屏幕上一样.

###### 读取文件

在C++编程中,使用流提取运算符( >> )从文件读取信息,就行使用该运算符从键盘输入信息一样.



##### 文件位置指针

istream和ostream都提供了用于重新定位文件位置指针的成员函数.这些成员函数包括istream的seekg("seek get")和关于ostream的seekp("seek put").

seekg和seekp的参数是一个长整形.第二个参数可以用于指定查找方向.查找方向可以是ios::beg(默认的,从流的开头开始定位),也可以是ios::cur(从流的当前位置开始定位), 亦可以使ios::end(从流的末尾开始定位).



文件指正是一个整数值,指定了从文件的起始位置到指针所在位置的字节数.下面是关于定位"get"文件位置指针的实例:

```c++
// 定位到fileObject的第n个字节(假设是ios:beg)
fileObject.seekg(n);

// 把文件的指针从fileObject当前位置后移n个字节
fileObject.seekg(n, ios::cur);

// 把文件的读指针从fileObject末尾往回移n个字节
fileObject(n, ios::end);

// 定位到fileObject的末尾
fileObject.seekg(0, ios::end);
```

