#ifndef _ORDER_H_
#define _ORDER_H_
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Order {
private:
	string _id;
	string _name;
	double _price;
	int _amount;
	Date _date;
	Time _time;
	string _customerName;
public:
	string id() { return _id; }
	string name() { return _name; }
	double price() { return _price; }
	int amount() { return _amount; }
	Date date() { return _date; }
	Time time() { return _time; }
	string customerName() { return _customerName; }
public:
	Order();
	Order(string id, string name, double price, int amount, Date date, Time time, string customerName);
public:
	static void tokenizer(string line, string& id, string& name, double& price, int& amount, Date& date, Time& time, string& customerName);
	bool checkOrder(string userID, string userName, string checkID, string checkName);
	string toString(bool);
};

class OrderStore {
private:
	vector<Order> _list;
public:
	int size() { return _list.size(); }
	void add(string id, string name, double price, int amount, Date date, Time time, string customerName);
	void deleteAnOrder(string id);
	void deleteAllOrder();
	void displayAllOrder();
	friend class OrderFile;
	friend class Bill;
};

class OrderFile {
private:
	string _fileName;
public:
	void write(OrderStore orderList);
	OrderStore read();
	void deleteOrder(string ID);
	OrderFile(string name) { _fileName = name + ".txt"; }
};

#endif // !_ORDER_H_