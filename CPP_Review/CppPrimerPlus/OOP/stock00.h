//
// Created by alex on 10/17/18.
//

#ifndef STOCK00_H_
#define STACK00_H_

#include <string>

class Stock // class declaration
{
private:
    std::string company = "apple";
    long shares;
    double share_val;
    double  total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock();
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    ~Stock();
    // void acquire(const std::string & co, long n, double pr); // 某个公司股票的首次购买
    void buy(long num, double price);                        // 管理增加持有的股票
    void sell(long num, double price);                       // 管理减少持有的股票
    void update(double price);
    void show1();//
    void show();
};  // note semicolon at the end;

#endif //STOCK00_H_
