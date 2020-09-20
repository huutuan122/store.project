#ifndef _ORDER_H_
#define _ORDER_H_
#include "../Bill_Order/ZTime.h"
#include "../Bill_Order/ZDate.h"
#include "../Bill_Order/ZTime.cpp"
#include "../Bill_Order/ZDate.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Order
{
private:
	string _id;
	string _name;
	float _price;
	int _amount;
	ZDate _date;
	ZTime _time;
	string _customerName;

public:
	string id() { return _id; }
	string name() { return _name; }
	float price() { return _price; }
	int amount() { return _amount; }
	ZDate date() { return _date; }
	ZTime time() { return _time; }
	string customerName() { return _customerName; }

public:
	Order();
	Order(string id, string name, float price, int amount, ZDate date, ZTime time, string customerName);

public:
	static void tokenizer(string line, string &id, string &name, float &price, int &amount, ZDate &date, ZTime &time, string &customerName);
	bool checkOrder(string userID, string userName, string checkID, string checkName);
	string toString(bool);
};

class OrderStore
{
public:
	vector<Order *> _list;

public:
	int size() { return _list.size(); }
	void add(string id, string name, float price, int amount, ZDate date, ZTime time, string customerName);
	void deleteAnOrder(string id);
	void deleteAllOrder();
	void displayAllOrder();
	friend class OrderFile;
	friend class Bill;
};

#endif // !_ORDER_H_