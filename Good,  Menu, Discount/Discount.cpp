#include"Discount.h"
#include"Good.h"

void Discount::UpdateDiscountListFromFile(string filename) {
	ifstream file;
	file.open(filename);
	int n;
	file >> n;
	file.ignore();
	for (int i = 0; i < n; i++) {
		string line;
		getline(file, line);
		vector<string> info = Tokenizer::splitString(line, "-");
		_discountList[info[0]] = info[1];
	}
	file.close();
}

void Discount::showVoucher() {
	for (auto e : _discountList)
		cout << e.first << ": " << e.second << endl;
}

float Discount::countDiscount(float price, string codeDiscount, int UsedPoint, bool& codeIsValid) {
	float result = price;
	result = result - UsedPoint * 5;
	for (auto e : _discountList) {
		if (e.first == codeDiscount) {
			codeIsValid = true;
			if (e.second[e.second.size() - 1] == '%')result = result - result * stof(e.second) / 100;
			else result = result - stof(e.second);
		}
		else codeIsValid = false;
	}
	return result;
}