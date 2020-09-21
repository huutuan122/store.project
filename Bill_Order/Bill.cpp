#include "Bill.h"
#include <iomanip>
#include "../Utility/util.h"



double Bill::revenue = 0;
Bill::Bill()
{
	_customerName = "";
	_total = 0;
}

Bill::Bill(string customerName, vector<pair<string, int>> list, int total)
{
	_customerName = customerName;
	_itemsList = list;
	_total = total;
	revenue += _total;
}

Bill::Bill(string customerName, OrderStore list, int total)
{
	_customerName = customerName;
	for (auto &order : list._list)
	{
		if (order->customerName() == customerName)
		{
			_itemsList.push_back(make_pair(order->name(), order->amount()));
		}
	}
	_total = total;
	revenue += _total;
}

Bill::Bill(OrderStore list, string customerName)
{
	_total = 0;
	for (auto &order : list._list)
	{
		if (order->customerName() == customerName)
		{
			_itemsList.push_back(make_pair(order->name(), order->amount()));
			_total += order->price() * order->amount();
		}
	}
	_customerName = customerName;
	revenue += _total;
}

void Bill::tokenizer(string hayStack, string &customerName, vector<pair<string, int>> &itemsList, int &total)
{
	int currentPos{0}, nextPos{0};

	nextPos = hayStack.find(';', currentPos);
	customerName = hayStack.substr(currentPos, nextPos - currentPos);
	currentPos = nextPos + 1;

	while (1)
	{
		nextPos = hayStack.find(",", currentPos);
		if (nextPos != string::npos)
		{
			string itemNameAndAmount = hayStack.substr(currentPos, nextPos - currentPos);
			string itemName = itemNameAndAmount.substr(0, itemNameAndAmount.find("."));
			int amount = stoi(itemNameAndAmount.substr(itemNameAndAmount.find(".") + 1, itemNameAndAmount.size()));
			itemsList.push_back(make_pair(itemName, amount));
			currentPos = nextPos + 1;
		}
		else
		{
			nextPos = hayStack.find(';', currentPos);
			string itemNameAndAmount = hayStack.substr(currentPos, nextPos - currentPos);
			string itemName = itemNameAndAmount.substr(0, itemNameAndAmount.find("."));
			int amount = stoi(itemNameAndAmount.substr(itemNameAndAmount.find(".") + 1, itemNameAndAmount.size()));
			itemsList.push_back(make_pair(itemName, amount));
			currentPos = nextPos + 1;
			break;
		}
	}

	total = stoi(hayStack.substr(currentPos, hayStack.size() - currentPos));
}

string Bill::toString(string mode)
{ //Print to file, mode = "FILE"; Print to console, mode = "CONSOLE"
	stringstream out;
	if (mode == "CONSOLE")
	{
		out << "Customer's name: " << _customerName;
		out << "\nItem list: ";
		for (auto &order : _itemsList)
		{
			out << "";
		}
		out << "\nTotal: " << _total;
	}
	else
	{
		out << _customerName << ";";
		out << _itemsList[0].first << "." << _itemsList[0].second;
		for (int i = 1; i < _itemsList.size(); i++)
		{
			out << "," << _itemsList[0].first << "." << _itemsList[0].second;
		}
		out << ";" << _total;
	}
	return out.str();
}

void BillStore::add(string customerName, vector<pair<string, int>> itemsList, int total)
{
	_list.push_back(Bill(customerName, itemsList, total));
}

void BillStore::add(Bill myBill)
{
	_list.push_back(myBill);
}

void BillStore::deleteABill(string customerName)
{
	for (int i = 0; i < _list.size(); i++)
	{
		if (_list[i].customerName() == customerName)
			_list.erase(_list.begin() + i);
	}
}

void BillStore::deleteAllBill()
{
	_list.clear();
}

void BillFile::write(BillStore myBill)
{
	ofstream outputFile(Util::path() + "\\Bill_Order\\Bill.txt", ios::out);
	ofstream f(Util::path() + "\\Bill_Order\\TotalBill.txt", ios::app);
	for (auto &order : myBill._list)
	{
		outputFile << '\n'
				   << order.toString("FILE");
		outputFile.flush();
		f << endl
		  << order.customerName() << " - "
		  << fixed << setprecision(0) << order.total();
	}
	outputFile.close();
	f.close();
}

BillStore BillFile::read()
{
	BillStore list;

	string sCustomerName, line;
	vector<pair<string, int>> itemsList;
	int total;

	ifstream inputFile("Bill.txt");

	getline(inputFile, line);
	while (!inputFile.eof())
	{
		getline(inputFile, line);
		Bill::tokenizer(line, sCustomerName, itemsList, total);
		list.add(sCustomerName, itemsList, total);
	}
	inputFile.close();
	return list;
}

void BillFile::deleteBill(string customerName)
{
	BillStore myBill;
	myBill = read();
	myBill.deleteABill(customerName);
	ofstream outputFile(Util::path() + "\\Bill_Order\\Bill.txt");
	for (auto &order : myBill._list)
	{
		outputFile << '\n'
				   << order.toString("FILE");
		outputFile.flush();
	}
	outputFile.close();
}
