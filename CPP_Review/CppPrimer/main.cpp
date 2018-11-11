//
// Created by alex on 10/30/18.
//
#include <iostream>
#include "OOP/quote.h"
using namespace std;

int main () {
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
    return 0;
}