#include <iostream>
#include "OOP/stock00.h"

void UseStock() {
    Stock fluffy_the_cat("NanoSmart", 20, 12.5);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
}

void UseStock2() {
    {
        using std::cout;
        cout << "Using constructors to create new objects\n";
        Stock stock1("NanoSmart", 12, 20.0);
        stock1.show();
        Stock stock2 = Stock("Boffo Objects", 2, 2.0);
        stock2.show();

        cout << "\n";

        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;    // 将对象stock1赋值给stock2
        stock1.show();
        stock2.show();

        cout << "\n";

        cout << "Using a constructor to reset an object\n";
        stock1 = Stock("Nifty Foods", 10, 50.0);    // 通过构造创建一个新的,临时的对象然后将其内容复制给stock1
                                                    // 来实现的,随后程序会调用析构函数,以删除该临时对象.
        cout << "Revised stock1:\n";
        stock1.show();
        cout << "Done\n";
        // 由于自动变量存放在栈中,最后创建的对象将最先被删除
    }
}

void UseListForClass() {
    Stock hot_tip = {"Derivatives Plus Plus", 100, 45.0};   // c++11中可以将列表初始化语法用于类
    hot_tip.show();
    Stock jock {"Sport Age Storage, Inc"};
}
int main() {
//    UseStock2();
//    UseStock();
    UseListForClass();
    return 0;
}