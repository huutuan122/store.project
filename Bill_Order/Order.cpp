#include "Order.h"

// Order's Class
Order::Order()
{
	_id = "1";
	_name = "Hamburger";
	_price = 0.0;
	_amount = 0;
	_customerName = "A";
}

Order::Order(string id, string name, float price, int amount, ZDate date, ZTime time, string customerName)
{
	_id = id;
	_name = name;
	_price = price;
	_amount = amount;
	_date = date;
	_time = time;
	_customerName = customerName;
}

void Order::tokenizer(string hayStack, string &id, string &name, float &price, int &amount, ZDate &date, ZTime &time, string &customerName)
{
	int currentPos{0}, nextPos{0};

	nextPos = hayStack.find(',', currentPos);
	id = hayStack.substr(currentPos, nextPos - currentPos);
	currentPos = nextPos + 1;

	nextPos = hayStack.find(',', currentPos);
	name = hayStack.substr(currentPos, nextPos - currentPos);
	currentPos = nextPos + 1;

	nextPos = hayStack.find(',', currentPos);
	price = stof(hayStack.substr(currentPos, nextPos - currentPos));
	currentPos = nextPos + 1;

	nextPos = hayStack.find(',', currentPos);
	amount = stoi(hayStack.substr(currentPos, nextPos - currentPos));
	currentPos = nextPos + 1;

	nextPos = hayStack.find(',', currentPos);
	date = date.parse(hayStack.substr(currentPos, nextPos - currentPos));
	currentPos = nextPos + 1;

	nextPos = hayStack.find(',', currentPos);
	time = time.parse(hayStack.substr(currentPos, nextPos - currentPos));
	currentPos = nextPos + 1;

	customerName = hayStack.substr(currentPos, hayStack.size());
}

bool Order::checkOrder(string userID, string userName, string checkID, string checkName)
{
	if (userID != checkID || userName != checkName)
		return false;
	return true;
}

string Order::toString(bool choice)
{ //If choice is 1: display to file || 0: display to screen
	stringstream out;
	if (choice == 0)
	{
		out << "ID: " << _id;
		out << "\nItem name: " << _name;
		out << "\nPrice: " << _price;
		out << "\nAmount: " << _amount;
		out << "\nDate: " << _date.toString();
		out << "\nTime: " << _time.displayIn24hFormat();
		out << "\nCustomer name: " << _customerName << '\n';
	}
	else
	{
		out << _id;
		out << "," << _name;
		out << "," << _price;
		out << "," << _amount;
		out << "," << _date.toString();
		out << "," << _time.displayIn24hFormat();
		out << "," << _customerName;
	}
	return out.str();
}

// OrderStore's Class
void OrderStore::add(string id, string name, float price, int amount, ZDate date, ZTime time, string customerName)
{
	_list.push_back(new Order(id, name, price, amount, date, time, customerName));
}

void OrderStore::deleteAnOrder(string id)
{
	for (int i = 0; i < _list.size(); i++)
	{
		if (_list[i]->id() == id)
			_list.erase(_list.begin() + i);
	}
}

void OrderStore::deleteAllOrder()
{
	_list.clear();
}

void OrderStore::displayAllOrder()
{
	for (auto &order : _list)
		cout << order->toString(0) << '\n';
}