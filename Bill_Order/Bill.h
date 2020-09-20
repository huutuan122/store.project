#ifndef _BILL_H_
#define _BILL_H_
#include "Order.h"

class Bill
{
private:
	string _customerName;
	vector<pair<string,int>> _itemsList;
	int _total;

public:
	string customerName() { return _customerName; }
	double total() { return _total; }

public:
	static double revenue;
	Bill();
	Bill(string customerName, vector<pair<string, int>> list, int total);
	Bill(string customerName, OrderStore list, int total);
	Bill(OrderStore list, string customerName);
	static void tokenizer(string hayStack, string &customerName, vector<pair<string, int>> &itemsList, int &total);
	string toString(string mode);
	string printItems()
	{
		stringstream out;
		for (auto i : _itemsList)
		{
			out << i.second << " " << i.first << ", ";
		}
		return out.str();
	}
};

class BillStore
{
private:
	vector<Bill> _list;
	string path = "E:\\VSC\\C++\\Project Store\\github";

public:
	int size() { return _list.size(); }
	Bill billWithCustomer(string customerName)
	{
		Bill temp;
		for (auto i : _list)
		{
			if (i.customerName() == customerName)
			{
				temp = i;
			}
		}
		return temp;
	}
	void add(string customerName, vector<pair<string, int>> itemsList, int total);
	void add(Bill myBill);
	void deleteABill(string customerName);
	void deleteAllBill();
	friend class BillFile;
};

class BillFile
{
public:
	static void write(BillStore myBill);
	static BillStore read();
	static void deleteBill(string customerName);
};

#endif // !_BILL_H_
