//
// Created by alex on 10/24/18.
//

#include <iostream>
#include "OOP/mytime1.h"
using namespace std;

int main1() {
    using std::cout;
    using std::endl;
    Time1 aida(3, 35);
    Time1 tosca(2, 48);
    Time1 temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;    // operator+()
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;     // member operator*()
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
}