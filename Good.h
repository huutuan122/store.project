#pragma once
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<map>
#include<algorithm>
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
private:
	vector<Good> _list;
public:
	static bool compNameAZ(Good a, Good b);
	static bool compNameZA(Good a, Good b);
	static bool compPriceAs(Good a, Good b);
	static bool compPriceDes(Good a, Good b);
	static bool compBestSeller(Good a, Good b);
	static bool compRateAs(Good a, Good b);
	static bool compRateDes(Good a, Good b);
	void add(Good newGood);
	void erase(int position);
	void moveUp(int position);
	void moveDown(int position);
	Good bestSeller();
	string list();
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
};