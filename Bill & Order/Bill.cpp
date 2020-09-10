#include "Bill.h"

double Bill::revenue = 0;
Bill::Bill() {
	_customerName = "";
	_total = 0;
}

Bill::Bill(string customerName, vector<string> list, int total) {
	_customerName = customerName;
	_itemsList = list;
	_total = total;
	revenue += _total;
}

Bill::Bill(string customerName, OrderStore list, int total) {
	_customerName = customerName;
	for (auto& order : list._list) {
		if (order.customerName() == customerName)
		{
			_itemsList.push_back(order.name());
		}
	}
	_total = total;
	revenue += _total;
}

Bill::Bill(OrderStore list, string customerName) {
	_total = 0;
	for (auto& order : list._list) {
		if (order.customerName() == customerName)
		{
			_itemsList.push_back(order.name());
			_total += order.price();
		}
	}
	_customerName = customerName;
	revenue += _total;
}

void Bill::tokenizer(string hayStack, string& customerName, vector<string> &itemsList, int& total) {
	int currentPos{ 0 }, nextPos{ 0 };

	nextPos = hayStack.find(';', currentPos);
	customerName = hayStack.substr(currentPos, nextPos - currentPos);
	currentPos = nextPos + 1;

	while (1) {
		nextPos = hayStack.find(",", currentPos);
		if (nextPos != string::npos) {
			itemsList.push_back(hayStack.substr(currentPos, nextPos - currentPos));
			currentPos = nextPos + 1;
		}
		else {
			nextPos = hayStack.find(';', currentPos);
			itemsList.push_back(hayStack.substr(currentPos, nextPos - currentPos));
			currentPos = nextPos + 1;
			break;
		}
	}

	total = stoi(hayStack.substr(currentPos, hayStack.size() - currentPos));
}



string Bill::toString(string mode) { //Print to file, mode = "FILE"; Print to console, mode = "CONSOLE"
	stringstream out;
	if (mode == "CONSOLE")
	{
		out << "Customer's name: " << _customerName;
		out << "\nItem list: ";
		for (auto& order : _itemsList) {
			out << "\n " << order;
		}
		out << "\nTotal: " << _total;
	}
	else {
		out << _customerName << ";";
		out << _itemsList[0];
		for (int i = 1; i < _itemsList.size(); i++)
		{
			out << "," << _itemsList[i];
		}
		out << ";" << _total;
	}
	return out.str();
}

void BillStore::add(string customerName, vector<string> itemsList, int total)
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
		if (_list[i].customerName() == customerName) _list.erase(_list.begin() + i);
	}
}

void BillStore::deleteAllBill()
{
	_list.clear();
}

void BillFile::write(BillStore myBill)
{
	ofstream outputFile(_fileName, ios::app);
	for (auto& order : myBill._list) {
		outputFile << '\n' << order.toString("FILE");
		outputFile.flush();
	}
	outputFile.close();
}

BillStore BillFile::read()
{
	BillStore list;

	string sCustomerName, line;
	vector<string> itemsList; int total;

	ifstream inputFile(_fileName);

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
	ofstream outputFile(_fileName);
	for (auto& order : myBill._list) {
		outputFile << '\n' << order.toString("FILE");
		outputFile.flush();
	}
	outputFile.close();
}
