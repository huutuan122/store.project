#ifndef _BILL_H_
#define _BILL_H_
#include "Order.h"

class Bill {
private:
	string _customerName;
	vector<string> _itemsList;
	int _total;
public:
	string customerName() { return _customerName; }
	double total() { return _total; }
public:
	static double revenue;
	Bill();
	Bill(string customerName, vector<string> list, int total);
	Bill(string customerName, OrderStore list, int total);
	Bill(OrderStore list, string customerName);
	static void tokenizer(string hayStack, string& customerName, vector<string> &itemsList, int& total);
	string toString(string mode);
};

class BillStore {
private:
	vector<Bill> _list;
public:
	int size() { return _list.size(); }
	void add(string customerName, vector<string> itemsList, int total);
	void add(Bill myBill);
	void deleteABill(string customerName);
	void deleteAllBill();
	friend class BillFile;
};

class BillFile {
public:
	static void write(BillStore myBill);
	static BillStore read();
	static void deleteBill(string customerName);
};

#endif // !_BILL_H_

