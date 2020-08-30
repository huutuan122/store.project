#include "Order.h"

// Order's Class
Order::Order() {
	_id = "1";
	_name = "Hamburger";
	_price = 0.0;
	_amount = 0;
	_customerName = "Nguyen Van A";
}

Order::Order(string id, string name, double price, int amount, Date date, Time time, string customerName) {
	_id = id;
	_name = name;
	_price = price;
	_amount = amount;
	_date = date;
	_time = time;
	_customerName = customerName;
}

shared_ptr<Order> Order::inputOrder(string id, string name, double price, int amount, Date date, Time time, string customerName) {
	return make_shared<Order>(id, name, price, amount, date, time, customerName);
}

bool Order::checkOrder(string userID, string userName, string checkID, string checkName) {
	if (userID != checkID || userName != checkName) return false;
	return true;
}

string Order::toString() {
	stringstream out;
	out << "ID: " << _id;
	out << "\nItem name: " << _name;
	out << "\nPrice: " << _price;
	out << "\nAmount: " << _amount;
	out << "\nDate: " << date();
	out << "Time: " << time();
	out << "\nCustomer name: " << _customerName << '\n';
	return out.str();
}

// OrderStore's Class
void OrderStore::add(shared_ptr<Order>order) {
	_orderList._list.push_back(order);
}

void OrderStore::deleteAnOrder(string id)
{
	for (int i = 0; i < _orderList._list.size(); i++)
	{
		if (_orderList._list[i]->id() == id)
		{
			_orderList._list.erase(_orderList._list.begin() + i);
		}
	}
}

void OrderStore::deleteAllOrder() {
	_orderList._list.clear();
}

void OrderStore::displayAllOrder() {
	for (const auto& order : _orderList._list) {
		cout << order->toString() << '\n';
	}
}