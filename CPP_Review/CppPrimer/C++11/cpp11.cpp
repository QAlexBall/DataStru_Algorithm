//
// Created by alex on 10/30/18.
//
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void inOut() {
    std::filebuf fb;
    fb.open("test.txt", std::ios::out);
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

void useAuto() {
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

void useVector() {
    vector<int> vec = {1, 2, 3};
    vec.push_back(4);
    for (auto &i : vec) {
        cout << i << endl;
    }

    for (auto &j : vec)
        j *= j;
    for (auto k : vec) {
        cout << k << endl;
    }
}

void useDecltype() {
    double d = 1.0;
    decltype(d) s = sum(1, 2);
    cout << s << endl;

    const int a = 1;
    decltype(a) b = a;
    // b = 3; err, decltype会保留底层const和顶层const
    auto c = a;
    c = 3; // right, auto会忽略底层const
}

void constUpDown() {
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

void UseIterator() {
    string s("some string");
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = static_cast<char>(toupper(*it));
    }
    cout << s << endl;

    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
        *it = static_cast<char>(toupper(*it));
    }
    cout << s << endl;

    string::iterator it;
    string::const_iterator const_it;
    it = s.begin();
    it.base();
    cout << "it.base : " << it.base() << endl;
    it++;
    for (it = s.begin(); it != s.end(); ++it) {
        cout << "it.base: " << *it.base() << " " << endl;
    }
    cout << "it - 3 :" << *(it - 3) << endl;

    vector<int> vec = {1, 2, 3};
    auto vec_iter = vec.begin();
    cout << *vec_iter << endl;

}

int main () {
//    useDecltype();
//    useVector();
    UseIterator();
    return 0;
}
