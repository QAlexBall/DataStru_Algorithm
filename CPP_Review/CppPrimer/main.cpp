//
// Created by alex on 10/30/18.
//
#include <iostream>
#include <vector>
#include <memory>
#include "OOP/quote.h"
#include "C++11/namespace.h"
using namespace test;

//using namespace std;

void in_out() {
    std::filebuf fb;
    fb.open("test.txt",std::ios::out);
    std::ostream os(&fb);
    os << "Test sentence\n";
    fb.close();

    ifstream file;
    file.open("a.text", std::ios::in);
    string data;
    file >> data;
    cout << data << "?";
    file.close();
}

void use_auto() {
    int a[] = {1, 2, 3, 4, 5};
    for (auto &i : a) {
        cout << i << endl;
    }

    const int j = 5;
    auto b = j;
    b = 6;// auto或忽略顶层const,保留底层const
    cout << j << " " << b << endl;
}

int sum(double a, double b) {
    return static_cast<int>(a + b);
}

void use_vector() {
    vector<int> vec = {1, 2, 3};
    vec.push_back(4);
    for (auto &i : vec) {
        cout << i << endl;
    }

}

void use_decltype() {
    double d = 1.0;
    decltype(d) s = sum(1, 2);
    cout << s << endl;

    const int a = 1;
    decltype(a) b = a;
    // b = 3; err, decltype会保留底层const和顶层const
    auto c = a;
    c = 3; // right, auto会忽略底层const
}

void const_up_down() {
    int num_c = 3;
    const int *p_c = &num_c;  //p_c为底层const的指针
    // int *p_d = p_c;  //错误，不能将底层const指针赋值给非底层const指针
    const int *p_d = p_c; //正确，可以将底层const指针复制给底层const指针

    int num_e = 4;
    const int *p_e = &num_e;
    // *p_e = 5;  //错误，不能改变底层const指针指向的内容
    int *p_f = const_cast<int *>(p_e);  //正确，const_cast可以改变运算对象的底层const。但是使用时一定要知道num_e不是const的类型。
    *p_f = 5;  //正确，非顶层const指针可以改变指向的内容
    cout << num_e;  //输出5

    /**
     ***** for test *****
    int num = 3;
    const int *p = &num;    // p为底层const
    num = 5;
    cout << *p << " " << num << endl;
    // *p = 6; readonly
    // int *p1 = p; Cannot initialize a variable of type 'int *' with an lvalue of type 'const int *
    // const int *p1 = p; right
    int *p1 = const_cast<int *>(p); // p指向的值不能为const.
    // const_cast只能改变运算对象的底层const,不能改变运算对象本身
    *p1 = 6;
    cout << *p << " " << num << " " << *p1 << endl;
     */
}

void unique_ptr_test() {
    unique_ptr<int[]> up(new int[10]{1, 2, 3, 4, 5});
    cout << "up[0]: " << up[0] << endl;
    cout << "*up.get(): " << *up.get() << endl;
    up.release();   // 自动用delete[]销毁其指针
}

int get_size() {
    return static_cast<int>(random() % 15);
}
void allocator_test() {
//    int n = get_size();
//    auto *const p = new string[n];
//    string s;
//    string *q = p;
//    while (cin >> s && q != p + n)
//        *q++ = s;
//    const size_t size = q - p;
//    delete[] p; // p指向一个数组,记得使用delete[]释放

    int n = 1000;
    allocator<string> alloc;
    auto const p = alloc.allocate(static_cast<unsigned long>(n));
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");
    cout << "p[1]: " << p[1] << endl;           // output : p[1]: cccccccccc
    cout << "p[0]: " << p[0] << endl;           // output : p[0]:
    cout << "p[2]: " << p[2] << endl;           // output : p[2]: hi

    while (q != p)  // 对每个构造的元素调用destroy来销毁.
        alloc.destroy(--q);

    alloc.deallocate(p, static_cast<unsigned long>(n)); // 释放内存
}

#include "TextQurey/text_query.h"
#include "TextQurey/query_result.h"
void run_queries(ifstream &infile) {
    TextQuery text_query(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, text_query.query(s)) << endl;
    }
}

void test_point_array() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {10, 20, 30, 40, 50};
    int (*p)[5];    // 数组指针
    p = &a;
    int (*p1)[5];   // 数组指针
    p1 = &b;
    int *(q[5]);      // 指针数组, 此例中有五个指针
    q[0] = *p;
    q[1] = *p1;
    cout << (*p)[0] << endl;
    cout << q[0][3] << endl;
    cout << q[1][3] << endl;
}

// 第一个命名空间
namespace first_space{
    void func(){
        cout << "Inside first_space" << endl;
    }
}
// 第二个命名空间
namespace second_space{
    void func(){
        cout << "Inside second_space" << endl;
    }
}

int main () {
//    use_vector();
//    unique_ptr_test();
//    allocator_test();
//
//    string text;
//    ifstream is("a.txt");
//    while (is >> text) {
//        cout << text << endl;
//    }
//    ifstream is1("b.txt");
//    string text1;
//    while (getline(is1, text1)) {
//        cout << text1 << endl;
//    }
//    ifstream is2("b.txt");
//    run_queries(is2);
//#include "OOP/test.h"
//    A a;'
    test_point_array();

    first_space::func();
    second_space::func();
    Test t(3);
    t.print();
    show();

    return 0;
}