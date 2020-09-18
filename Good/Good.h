#pragma once
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>
using namespace std;

class Good {
private:
	string _name;
	string _code;
	float _price;
	int _amount;
	vector<float> _rate;
	vector<string> _cmt;
	string _description;
	string _type;
	int _quantitySold;
public:
	string name() { return _name; }
	string code() { return _code; }
	float price() { return _price; }
	int amount() { return _amount; }
	vector<float> rate() { return _rate; }
	vector<string> comment() { return _cmt; }
	string description() { return _description; }
	string type() { return _type; }
	int quantitySold() { return _quantitySold; }
	void setName(string value) { _name = value; }
	void setCode(string value) { _code = value; }
	void setPrice(float value) { _price = value; }
	void setAmount(int value) { _amount = value; }
	void setQuantitySold(int value) { _quantitySold = value; }
	void setDescription(string value) { _description = value; }
	void setType(string value) { _type = value; }
public:
	Good();
	Good(string name, string code, float price, int amount, string description, string type);
	void update(string name, float price, int amount, string description, string type, int quantitySold);
	void addComment(string comment);
	string listOfComment();
	void deleteComment(int position);
	void addRate(float rate);
	string listOfRate();
	void deleteRate(int position);
	float averageRate();
	string status();
};

class GoodList {
public:
	vector<Good> list;
public:
	static bool compNameAZ(Good a, Good b);
	static bool compNameZA(Good a, Good b);
	static bool compPriceAs(Good a, Good b);
	static bool compPriceDes(Good a, Good b);
	static bool compBestSeller(Good a, Good b);
	static bool compRateAs(Good a, Good b);
	static bool compRateDes(Good a, Good b);
	int size() { return list.size(); }
	Good goodAt(int position);
	void updateGood(Good newgood, int position);
	void add(Good newGood);
	void erase(int position);
	void moveUp(int position);
	void moveDown(int position);
	Good bestSeller();
	string showList(){
		stringstream result;
		for (auto e : list)
			result << e.name() << endl;
		return result.str();
	}
	void sortAZ();
	void sortZA();
	void sortByPriceAscending();
	void sortByPriceDescending();
	void sortByPopulartity();
	void sortByRateAscending();
	void sortByRateDescending();
	vector<Good> search(string GoodName);
	map<string, vector<Good>> classify();
	string listClassify();
	static GoodList readGoodListFromFile(string fileGood, string fileRate, string fileComment);
	static void saveGoodListToFile(GoodList list, string fileGood, string fileRate, string fileComment);
};
