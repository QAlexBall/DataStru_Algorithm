#include <iostream>
#include "OOP/stock00.h"
#include <cctype>
#include "OOP/stack.h"
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

void UseStock2WithArrayClass() {
    const int STKS = 4;

    Stock stocks[STKS] = {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
            Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++) {
        stocks[st].show();
    }

    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++) {
        top = &top->topval(stocks[st]);
    }
    std::cout << "\nMost valuable holding:\n";
    top->show();
}

void UseListForClass() {
    Stock hot_tip = {"Derivatives Plus Plus", 100, 45.0};   // c++11中可以将列表初始化语法用于类
    hot_tip.show();
    Stock jock {"Sport Age Storage, Inc"};
}

void UseStack() {
    {
        using namespace std;
        Stack st; // create an empty stack;
        char ch;
        unsigned long po;
        cout << "Please enter A to  add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
        while (cin >> ch && toupper(ch) != 'Q') {
            while (cin.get() != '\n')
                continue;
            if (!isalpha(ch)) {
                cout << '\a';
                continue;
            }
            switch (ch) {
                case 'A':
                case 'a': cout << "Enter a PO number to add: ";
                          cin >> po;
                          if (st.isfull())
                              cout << "stack already full\n";
                          else
                              st.push(po);
                          break;
                case 'P':
                case 'p': if (st.isempty())
                              cout << "stack already empty\n";
                          else {
                              st.pop(po);
                              cout << "PO #" << po << " poped\n";
                          }
                          break;
            }
            cout << "Please enter A to add a purchase order,\n"
                 << "P to process a PO, or Q to quit.\n";
        }
        cout << "Bye\n";
    }

}
int main() {
//    UseStock2();
//    UseStock();
//    UseListForClass();
//    UseStock2WithArrayClass();
    UseStack();
    return 0;
}