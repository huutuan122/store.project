#include"Good.h"

Good::Good() {
	_name = "";
	_code = "";
	_price = 0;
	_amount = 0;
	_description = "";
	_type = "";
	_quantitySold = 0;
}

Good::Good(string name, string code, float price, int amount, string description, string type) {
	_name = name;
	_code = code;
	_price = price;
	_amount = amount;
	_description = description;
	_type = type;
	_quantitySold = 0;
}

void Good::update(string name, float price, int amount, string description, string type, int quantitySold) {
	_name = name;
	_price = price;
	_amount = amount;
	_description = description;
	_type = type;
	_quantitySold = quantitySold;
}

void Good::addComment(string comment) {
	_cmt.push_back(comment);
}

void Good::deleteComment(int position) {
	_cmt.erase(_cmt.begin()+position);
}

string Good::listOfComment() {
	stringstream result;
	for (auto e : _cmt)result << e << endl;
	return result.str();
}

void Good::addRate(float rate) {
	_rate.push_back(rate);
}

void Good::deleteRate(int position) {
	_rate.erase(_rate.begin() + position);
}

string Good::listOfRate() {
	stringstream result;
	for (auto e : _rate)result << e << endl;
	return result.str();
}

float Good::averageRate() {
	float s = 0;
	for (auto e : _rate)s += e;
	return s / _rate.size();
}

string Good::status() {
	if (_amount > 0)return "Stocking!";
	else return "Out of stock!";
}

bool GoodList::compNameAZ(Good a, Good b) {
	return a.name() < b.name();
}

bool GoodList::compNameZA(Good a, Good b) {
	return a.name() > b.name();
}

bool GoodList::compPriceAs(Good a, Good b) {
	return a.price() < b.price();
}

bool GoodList::compPriceDes(Good a, Good b) {
	return a.price() > b.price();
}

bool GoodList::compBestSeller(Good a, Good b) {
	return a.quantitySold() > b.quantitySold();
}

bool GoodList::compRateAs(Good a, Good b) {
	return a.averageRate() < b.averageRate();
}

bool GoodList::compRateDes(Good a, Good b) {
	return a.averageRate() > b.averageRate();
}

void GoodList::add(Good newGood) {
	_list.push_back(newGood);
}

void GoodList::erase(int position) {
	_list.erase(_list.begin()+position);
}

void GoodList::moveUp(int position) {
	swap(_list[position - 1], _list[position]);
}

void GoodList::moveDown(int position) {
	swap(_list[position + 1], _list[position]);
}

Good GoodList::bestSeller() {
	Good result = _list[0];
	for (auto e : _list)
		if (e.quantitySold() > result.quantitySold())result = e;
	return result;
}

string GoodList::list() {
	stringstream result;
	for (auto e : _list)result << e.name() << endl;
	return result.str();
}

void GoodList::sortAZ() {
	sort(_list.begin(), _list.end(), compNameAZ);
}

void GoodList::sortZA() {
	sort(_list.begin(), _list.end(), compNameZA);
}

void GoodList::sortByPriceAscending() {
	sort(_list.begin(), _list.end(), compPriceAs);
}

void GoodList::sortByPriceDescending() {
	sort(_list.begin(), _list.end(), compPriceDes);
}

void GoodList::sortByRateAscending() {
	sort(_list.begin(), _list.end(), compRateAs);
}

void GoodList::sortByRateDescending() {
	sort(_list.begin(), _list.end(), compRateDes);
}

void GoodList::sortByPopulartity() {
	sort(_list.begin(), _list.end(), compBestSeller);
}

vector<Good> GoodList::search(string GoodName) {
	vector<Good> result;
	int start = 0;
	for (auto e : _list)
		if (e.name().find(GoodName, start) != string::npos)result.push_back(e);
	return result;
}

map<string, vector<Good>> GoodList::classify() {
	map<string, vector<Good>>result;
	for (auto e : _list)
		result[e.type()].push_back(e);
	return result;
}

string GoodList::listClassify() {
	stringstream result;
	map<string, vector<Good>> list = classify();
	for (auto e : list) {
		result << e.first << "\t";
		for (auto good : e.second)result << good.name() << "\t ";
		result << endl;
	}
	return result.str();
}