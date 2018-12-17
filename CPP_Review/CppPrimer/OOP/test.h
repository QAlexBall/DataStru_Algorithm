//
// Created by alex on 12/17/18.
//

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Cons" << endl;
    }
    ~Base() {
        cout << "Base Des" << endl;
    }
};

class A : Base {
public:
    A() {
        cout << "A Cons" << endl;
    }
    ~A() {
        cout << "A Des" << endl;
    }
};