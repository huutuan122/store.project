#ifndef _ORDER_H_
#define _ORDER_H_
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
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
	string date() { return _date.toString(); }
	string time() { return _time.displayIn24hFormat(); }
	string customerName() { return _customerName; }
	void setID(string id) { _id = id; }
	void setName(string name) { _name = _name; }
	void setPrice(double price) { _price = _price; }
	void setAmount(int amount) { _amount = _amount; }
	void setDate(Date date) { _date = _date; }
	void setTime(Time time) { _time = _time; }
	void setCustomerName(string name) { _customerName = name; }
public:
	Order();
	Order(string id, string name, double price, int amount, Date date, Time time, string customerName);
public:
	shared_ptr<Order> inputOrder(string id, string name, double price, int amount, Date date, Time time, string customerName);
	bool checkOrder(string userID, string userName, string checkID, string checkName);
	string toString();
};


class OrderState {
private:
	vector<shared_ptr<Order>> _list;
	friend class OrderStore;
};

class OrderStore {
private:
	OrderState _orderList;
public:
	void add(shared_ptr<Order>order);
	void deleteAnOrder(string id);
	void deleteAllOrder();
	void displayAllOrder();
};

#endif // !_ORDER_H_

