//
// Created by alex on 11/30/18.
//

/**
 * 动态内存与智能指针
 * 在C++中,动态内存的管理是通过一堆运算符完成的: new, 在动态内存中作为对象分配空间并返回一个指向该对象的指针,
 * 可以选择对对象初始化; delete,接受一个动态对象指针,销毁该对象,并释放与之相关的内存
 *
 * 为了更容易(同时也更安全)地使用动态内存,新的标准库提供了两种智能指针(smart pointer)类型来管理动态对象.
 * 智能指针的行为类似常规指针,重要的区别是它负责自动释放所指向的对象.
 * 新标准库提供的这两种智能指针的区别在于管理底层指针的方式:
 *
 * shared_ptr   允许多个指针指向同一个对象;
 * unique_ptr   "独占"所指向的对象
 * 标准库还定义了一个名为weak_ptr的伴随类,它是一种弱引用,指向shared_ptr所管理的对象.
 * 这三种对象都定义在memory头文件中
 */

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include "StarBlob.h"
using namespace std;

constexpr int size() {
    return 10;
}

int main() {
    shared_ptr<string> p1;  // shared_ptr,可以指向string
    shared_ptr<list<int>> p2;   // shared_ptr, 可以指向int的list

    shared_ptr<int> p3 = make_shared<int>(42);  // 指向一个值为42的int的shared_ptr
    shared_ptr<string> p4 = make_shared<string>(10, '9');   // p4指向一个值为"9999999999"的string
    shared_ptr<int> p5 = make_shared<int>();    // p5所指向一个值初始化的int,即值为0
    auto p6 = make_shared<vector<string>>();    // p6指向一个动态分配的空vector<string>

    // shared_ptr copy
    const auto &q(p3);
    cout << *q << endl;

    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2; // b1和b2共享相同的元素
    }  // b2被销毁了, 但b2中的元素不能被销毁
    cout << b1.front() << endl;
    b1.push_back("hello");
    cout << b1.back() << endl;
    constexpr int s = size();
    cout << s << endl;
    return 0;
}