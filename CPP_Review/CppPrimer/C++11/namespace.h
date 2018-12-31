//
// Created by alex on 12/28/18.
//

#ifndef CPPPRIMER_NAMESPACE_H
#define CPPPRIMER_NAMESPACE_H

#include <iostream>

namespace test {
    class Test {
    public:
        explicit Test(int X) {
            this->X = X;
        }
        void print() {
            std::cout << X << std::endl;
        }

    private:
        int X;
    };

    void show() {
        Test t(3);
        t.print();
    }
}


#endif //CPPPRIMER_NAMESPACE_H
