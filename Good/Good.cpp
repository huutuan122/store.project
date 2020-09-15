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

Good GoodList::goodAt(int position) {
	return list[position];
}

void GoodList::updateGood(Good newgood, int position) {
	list[position] = newgood;
}

void GoodList::add(Good newGood) {
	list.push_back(newGood);
}

void GoodList::erase(int position) {
	list.erase(list.begin()+position);
}

void GoodList::moveUp(int position) {
	swap(list[position - 1], list[position]);
}

void GoodList::moveDown(int position) {
	swap(list[position + 1], list[position]);
}

Good GoodList::bestSeller() {
	Good result = list[0];
	for (auto e : list)
		if (e.quantitySold() > result.quantitySold())result = e;
	return result;
}

// string GoodList::showList() {
	
// }

void GoodList::sortAZ() {
	sort(list.begin(), list.end(), compNameAZ);
}

void GoodList::sortZA() {
	sort(list.begin(), list.end(), compNameZA);
}

void GoodList::sortByPriceAscending() {
	sort(list.begin(), list.end(), compPriceAs);
}

void GoodList::sortByPriceDescending() {
	sort(list.begin(), list.end(), compPriceDes);
}

void GoodList::sortByRateAscending() {
	sort(list.begin(), list.end(), compRateAs);
}

void GoodList::sortByRateDescending() {
	sort(list.begin(), list.end(), compRateDes);
}

void GoodList::sortByPopular() {
	sort(list.begin(), list.end(), compBestSeller);
}

vector<Good> GoodList::search(string GoodName) {
	vector<Good> result;
	int start = 0;
	for (auto e : list)
		if (e.name().find(GoodName, start) != string::npos)result.push_back(e);
	return result;
}

map<string, vector<Good>> GoodList::classify() {
	map<string, vector<Good>>result;
	for (auto e : list)
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

void GoodList::saveGoodListToFile(GoodList list, string fileGood, string fileRate, string fileComment) {
	ofstream file;
	file.open(fileGood);
	file << list.size() << endl;
	for (auto good : list.list)
		file << good.name() << " - "
		<< good.code() << " - "
		<< good.price() << " - "
		<< good.amount() << " - "
		<< good.description() << " - "
		<< good.type() << endl;
	file.close();
	file.open(fileComment);
	file << list.size() << endl;
	for (auto good : list.list) {
		file << good.code();
		vector<string> cmt = good.comment();
		for (auto e : cmt)file << " - " << e;
		file << endl;
	}
	file.close();
	file.open(fileRate);
	file << list.size() << endl;
	for (auto good : list.list) {
		file << good.code();
		vector<float> rate = good.rate();
		for (auto e : rate)file << " - " << e;
		file << endl;
	}
	file.close();
}

vector<string> Tokenizer::splitString(string haystack, string needle) {
	vector<string> token;
	int start = 0;
	size_t foundPosition = haystack.find(needle, start);
	while (foundPosition != string::npos) {
		token.push_back(haystack.substr(start, foundPosition - start));
		start = foundPosition + needle.size();
		foundPosition = haystack.find(needle, start);
	}
	token.push_back(haystack.substr(start, foundPosition - start));
	return token;
}

GoodList GoodList::readGoodListFromFile(string fileGood, string fileRate, string fileComment) {
	ifstream file;
	file.open(fileGood);
	GoodList result;
	int n;
	file >> n;
	file.ignore();
	for (int i = 0; i < n; i++) {
		string line;
		getline(file, line);
		vector<string> info = Tokenizer::splitString(line, " - ");
		Good newGood(info[0], info[1], stof(info[2]), stoi(info[3]), info[4], info[5]);
		result.add(newGood);
	}
	file.close();

	file.open(fileRate);
	int n2;
	file >> n2;
	file.ignore();
	for (int i = 0; i < n2; i++) {
		string line;
		getline(file, line);
		vector<string> info = Tokenizer::splitString(line, " - ");
		for (int k = 0; k < result.list.size(); k++) {
			if (result.list[k].code() == info[0]) {
				for (int j = 1; j < info.size(); j++) {
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
	for (int i = 0; i < n3; i++) {
		string line;
		getline(file, line);
		vector<string> info = Tokenizer::splitString(line, " - ");
		for (int k = 0; k < result.list.size();k++) {
			if (result.list[k].code() == info[0]) {
				for (int j = 1; j < info.size(); j++) {
					result.list[k].addComment(info[j]);
				}
			}
		}
	}
	file.close();
	return result;
}