#include"Discount.h"
// #include"Good.h"
#include <iostream>
#include "../Good/Good.cpp"
#include "../Member/Tokenizer.h"
#include "../Console/Common.h"
#include "../Console/interface.h"
#include "../Member/member.h"

using namespace std;

// void Discount::UpdateDiscountListFromFile(string filename) {
// 	ifstream file;
// 	file.open(filename);
// 	int n;
// 	file >> n;
// 	file.ignore();
// 	for (int i = 0; i < n; i++) {
// 		string line;
// 		getline(file, line);
// 		vector<string> info = TokenizerStr::split(line, "-");
// 		_discountList[info[0]] = info[1];
// 	}
// 	file.close();
// }

void Discount::showVoucher() {
	system("cls");
	UserInterface::Screen();
	int choice;
	Common::gotoXY(49, 2);
	cout << "---------- DANH SACH KHUYEN MAI ----------";
	map<string, string> discountList = getDiscountFile();
	int i = 5;
	int length = discountList.size();
	for (auto e : discountList){
		Common::gotoXY(30, i);
		cout << e.first << ": " << e.second;
		i++;
		if (i == 24){
			i = 5;
			system("cls");
			UserInterface::Screen();
		}
	}

	Common::gotoXY(30, 26);
	cout << "Nhan '0' de quay lai: ";
	cin >> choice;
	if (choice == 0)
		return;
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

map<string, string> Discount::getDiscountFile(){
	ifstream f;
	f.open("E:\\VSC\\C++\\Project Store\\github\\Discount\\CodeDiscount.txt");
	map<string, string> discount;
	string s;
	int n;
	getline(f, s);
	n = stoi(s);

	while(!f.eof()){
		getline(f, s);

		vector<string> str = TokenizerStr::split(s, "-");
		discount[str[0]] = str[1];
	}

	f.close();

	return discount;
}

void Discount::addVoucher(){
	map<string, string> discountList = getDiscountFile();
	string code, percent;
	Common::gotoXY(40, 14);
	cout << "Them voucher: ";
	Common::gotoXY(35, 16);
	cout << "Nhap code: ";
	cin >> code;
	Common::gotoXY(35, 18);
	cout << "Nhap phan tram khuyen mai: ";
	cin >> percent;

	discountList[code] = percent;

	ofstream f;
	f.open("E:\\VSC\\C++\\Project Store\\github\\Discount\\CodeDiscount.txt" , ios::out);
	f << discountList.size();

	for (auto p: discountList){
		f << endl << p.first << "-" << p.second;
	}
	f.close();
}
