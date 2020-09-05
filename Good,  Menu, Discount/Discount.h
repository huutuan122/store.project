#ifndef _DISCOUNT_
#define _DISCOUNT_

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
using namespace std;

class Discount {
private:
	map<string,string> _discountList;
public:
	void UpdateDiscountListFromFile(string filename);
	float countDiscount(float price, string codeDiscount, int UsePoint, bool& codeIsValid);
	void showVoucher();
};





#endif // !_DISCOUNT_
