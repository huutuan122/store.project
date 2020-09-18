#ifndef _DISCOUNT_
#define _DISCOUNT_

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
#include "../Good/Good.h"
using namespace std;

class Discount {
private:
	map<string,string> _discountList;
public:
	static map<string, string> getDiscountFile();
	void UpdateDiscountListFromFile(string filename);
	float countDiscount(float price, string codeDiscount, int UsePoint, bool& codeIsValid);
	static void showVoucher();
	static void addVoucher();
};





#endif // !_DISCOUNT_
