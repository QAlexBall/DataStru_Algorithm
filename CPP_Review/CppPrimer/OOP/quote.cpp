#include <iostream>
#include <fstream>
using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price):
		bookNo(book), price(sales_price) { }
	std::string isbn() const { return bookNo }
	// 返回给定数量的书籍的销售总额
	// 派生类负责修改并使用不同的折扣计算算法
	virtual double net_price(std::size_t n) const { return n * price }
	virtual ~Quote() = default;	// 对析构函数进行动态绑定

private:
	std::string bookNo;	// 书籍ISBN编号

protected:
	double price = 0.0;
	// std::string isbn() const;	// return book number
	// virtual double net_price(std::size_t n) const;	// return book price
};

class Bulk_quote : public Quote { // Bulk_quote继承自Quote
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	// 覆盖基类的函数版本以实现基于大量购买的折扣政策
	double net_price(st::size_t) const override;

private:
	std::size_t min_qty = 0; 	// 适用折扣政策的最低购买量
	double discount = 0.0;		// 以小数表示的折扣额
};



// dynamic binding

// 计算并打印销售给定数量的某种书籍所得的费用
double print_total(ostream &os,
		const Quote &item, size_t n) {
	// 根据传入item形参的对象类调用Qoute::net_price
	// 或者Bulk_quote::item.net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()	// 调用Quote::isbn
	   << " # sold: " << n << " total due: " << ret <<endl;
	return ret;

}


