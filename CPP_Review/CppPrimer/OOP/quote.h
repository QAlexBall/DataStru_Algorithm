#pragma once
#ifndef QUOTE_H_
#define QUOTE_H_
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(std::string book, double sales_price) : bookNo(std::move(book)), price(sales_price) { }
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }  // 返回给定数量的书籍的销售总额
																		 // 派生类负责修改并使用不同的折扣计算算法
	virtual ~Quote() = default;	// 对析构函数进行动态绑定

private:
	std::string bookNo;	// 书籍ISBN编号

protected:
	double price = 0.0;
};

class Bulk_quote : public Quote { // Bulk_quote继承自Quote
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	double net_price(std::size_t cnt) const override; // 覆盖基类的函数版本以实现基于大量购买的折扣政策

private:
	std::size_t min_qty = 0; 	// 适用折扣政策的最低购买量
	double discount = 0.0;		// 以小数表示的折扣额
};

// dynamic binding
// 计算并打印销售给定数量的某种书籍所得的费用
double print_total(ostream &os,
		const Quote &item, size_t n) {		// 根据传入item形参的对象类调用Qoute::net_price,或者Bulk_quote::item.net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()	// 调用Quote::isbn
	   << " # sold: " << n << " total due: " << ret <<endl;
	return ret;
}

Bulk_quote::Bulk_quote(const std::string &, double, std::size_t, double) {

}

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
#endif
