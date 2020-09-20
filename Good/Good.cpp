#include "Good.h"
#include "../Member/Tokenizer.h"
#include <iomanip>

// Construc của class Good
Good::Good()
{
	_name = "";
	_code = "";
	_price = 0;
	_amount = 0;
	_description = "";
	_type = "";
	_quantitySold = 0;
}

Good::Good(string name, string code, float price, int amount, string description, string type)
{
	_name = name;
	_code = code;
	_price = price;
	_amount = amount;
	_description = description;
	_type = type;
	_quantitySold = 0;
}

// Nhóm hàm class Good (Methods)
void Good::update(string name, float price, int amount, string description, string type, int quantitySold)
{
	_name = name;
	_price = price;
	_amount = amount;
	_description = description;
	_type = type;
	_quantitySold = quantitySold;
}

void Good::addComment(string comment)
{
	_cmt.push_back(comment);
}

void Good::deleteComment(int position)
{
	_cmt.erase(_cmt.begin() + position);
}

string Good::listOfComment()
{
	stringstream result;
	for (auto e : _cmt)
		result << e << endl;
	return result.str();
}

void Good::addRate(float rate)
{
	_rate.push_back(rate);
}

void Good::deleteRate(int position)
{
	_rate.erase(_rate.begin() + position);
}

string Good::listOfRate()
{
	stringstream result;
	for (auto e : _rate)
		result << e << endl;
	return result.str();
}

float Good::averageRate()
{
	float s = 0;
	for (auto e : _rate)
		s += e;
	return s / _rate.size();
}

string Good::status()
{

	if (_amount > 0)
		return "Con hang";
	else
		return "Het hang";
}

// Nhóm hàm class GoodList (Method)

bool GoodList::compNameAZ(Good a, Good b)
{
	return a.name() < b.name();
}

bool GoodList::compNameZA(Good a, Good b)
{
	return a.name() > b.name();
}

bool GoodList::compPriceAs(Good a, Good b)
{
	return a.price() < b.price();
}

bool GoodList::compPriceDes(Good a, Good b)
{
	return a.price() > b.price();
}

bool GoodList::compBestSeller(Good a, Good b)
{
	return a.quantitySold() > b.quantitySold();
}

bool GoodList::compRateAs(Good a, Good b)
{
	return a.averageRate() < b.averageRate();
}

bool GoodList::compRateDes(Good a, Good b)
{
	return a.averageRate() > b.averageRate();
}

bool GoodList::compClassify(Good a, Good b)
{
	return a.type() < b.type();
}

// Nhóm hàm quản lí danh sách sản phẩm (dành cho quản lí)
Good GoodList::goodAt(int position)
{
	return list[position];
}

void GoodList::updateGood(Good newgood, int position)
{
	list[position] = newgood;
}

void GoodList::add(Good newGood)
{
	list.push_back(newGood);
}

void GoodList::erase(int position)
{
	list.erase(list.begin() + position);
}

void GoodList::moveUp(int position)
{
	swap(list[position - 1], list[position]);
}

void GoodList::moveDown(int position)
{
	swap(list[position + 1], list[position]);
}

Good GoodList::bestSeller()
{
	Good result = list[0];
	for (auto e : list)
		if (e.quantitySold() > result.quantitySold())
			result = e;
	return result;
}

void GoodList::showList()
{
	Common::color(14);
	Common::gotoXY(52, 2);
	int i = 4;
	cout << "_______DANH SACH HANG HOA_______";
	for (auto p : list)
	{
		Common::gotoXY(10, i);
		cout << i - 3;
		Common::gotoXY(15, i);
		cout << p.name();
		Common::gotoXY(35, i);
		cout << p.code();
		i++;
	}
}

void GoodList::addGood()
{
	Common::color(14);
	Common::gotoXY(49, 4);
	cout << "----------Hoan tat cac thong tin sau----------" << endl;
	Common::gotoXY(40, 6);
	cout << "Nhap ten san pham: ";
	string name;
	getline(cin, name);
	getline(cin, name);
	Common::gotoXY(40, 8);
	cout << "Nhap id: ";
	string id;
	cin >> id;
	Common::gotoXY(40, 10);
	cout << "Nhap gia: ";
	float price;
	cin >> price;
	Common::gotoXY(40, 12);
	cout << "Nhap so luong: ";
	int amount;
	cin >> amount;
	Common::gotoXY(40, 14);
	cout << "Nhap mo ta: ";
	string description;
	getline(cin, description);
	getline(cin, description);
	Common::gotoXY(40, 16);
	cout << "Nhap loai hang: ";
	string type;
	getline(cin, type);
	Good newGood(name, id, price, amount, description, type);
	list.push_back(newGood);
	
}

// Sắp xếp sản phẩm theo yêu cầu
void GoodList::sortAZ()
{
	sort(list.begin(), list.end(), compNameAZ);
}

void GoodList::sortZA()
{
	sort(list.begin(), list.end(), compNameZA);
}

void GoodList::sortByPriceAscending()
{
	sort(list.begin(), list.end(), compPriceAs);
}

void GoodList::sortByPriceDescending()
{
	sort(list.begin(), list.end(), compPriceDes);
}

void GoodList::sortByRateAscending()
{
	sort(list.begin(), list.end(), compRateAs);
}

void GoodList::sortByRateDescending()
{
	sort(list.begin(), list.end(), compRateDes);
}

void GoodList::sortByPopular()
{
	sort(list.begin(), list.end(), compBestSeller);
}

void GoodList::classify()
{
	sort(list.begin(), list.end(), compClassify);
}

vector<Good> GoodList::search(string GoodName)
{
	vector<Good> result;
	int start = 0;
	for (auto e : list)
		if (e.name().find(GoodName, start) != string::npos)
			result.push_back(e);
	return result;
}

map<string, vector<Good>> GoodList::classifyMap()
{
	map<string, vector<Good>> result;
	for (auto e : list)
		result[e.type()].push_back(e);
	return result;
}

string GoodList::listClassify()
{
	stringstream result;
	map<string, vector<Good>> list = classifyMap();
	for (auto e : list)
	{
		result << e.first << "\t";
		for (auto good : e.second)
			result << good.name() << "\t ";
		result << endl;
	}
	return result.str();
}

// Hàm hỗ trợ làm việc với file
void GoodList::saveGoodListToFile(GoodList list, string fileGood, string fileRate, string fileComment)
{
	ofstream file;
	file.open(fileGood);
	file << list.size() << endl;
	for (auto good : list.list)
		file << good.name() << " - "
			 << good.code() << " - " << fixed << setprecision(0)
			 << good.price() << " - "
			 << good.amount() << " - "
			 << good.description() << " - "
			 << good.type() << endl;
	file.close();
	file.open(fileComment);
	file << list.size() << endl;
	for (auto good : list.list)
	{
		file << good.code();
		vector<string> cmt = good.comment();
		for (auto e : cmt)
			file << " - " << e;
		file << endl;
	}
	file.close();
	file.open(fileRate);
	file << list.size() << endl;
	for (auto good : list.list)
	{
		file << good.code();
		vector<float> rate = good.rate();
		for (auto e : rate)
			file << " - " << e;
		file << endl;
	}
	file.close();
}

GoodList GoodList::readGoodListFromFile(string fileGood, string fileRate, string fileComment)
{
	ifstream file;
	file.open(fileGood);
	GoodList result;
	int n;
	file >> n;
	file.ignore();
	for (int i = 0; i < n; i++)
	{
		string line;
		getline(file, line);
		vector<string> info = TokenizerStr::split(line, " - ");
		Good newGood(info[0], info[1], stof(info[2]), stoi(info[3]), info[4], info[5]);
		result.add(newGood);
	}
	file.close();

	file.open(fileRate);
	int n2;
	file >> n2;
	file.ignore();
	for (int i = 0; i < n2; i++)
	{
		string line;
		getline(file, line);
		vector<string> info = TokenizerStr::split(line, " - ");
		for (int k = 0; k < result.list.size(); k++)
		{
			if (result.list[k].code() == info[0])
			{
				for (int j = 1; j < info.size(); j++)
				{
					result.list[k].addRate(stof(info[j]));
				}
			}
		}
	}
	file.close();

	file.open(fileComment);
	int n3;
	file >> n3;
	file.ignore();
	for (int i = 0; i < n3; i++)
	{
		string line;
		getline(file, line);
		vector<string> info = TokenizerStr::split(line, " - ");
		for (int k = 0; k < result.list.size(); k++)
		{
			if (result.list[k].code() == info[0])
			{
				for (int j = 1; j < info.size(); j++)
				{
					result.list[k].addComment(info[j]);
				}
			}
		}
	}
	file.close();
	return result;
}
