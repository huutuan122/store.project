#include "Discount.h"
// #include"Good.h"
#include <iostream>
#include "../Good/Good.cpp"
#include "../Member/Tokenizer.h"
#include "../Console/Common.h"
#include "../Console/interface.h"
#include "../Member/member.h"
#include "../System/system.h"
#include "../Utility/util.h"

using namespace std;
// Nhóm hàm chức năng với voucher
void Discount::showVoucher()
{
	system("cls");
	UserInterface::Screen();
	Common::color(14);
	int choice;
	Common::gotoXY(49, 2);
	cout << "---------- DANH SACH KHUYEN MAI ----------";
	map<string, string> discountList = getDiscountFile();
	int i = 5;
	int length = discountList.size();
	for (auto e : discountList)
	{
		Common::gotoXY(30, i);
		cout << e.first << ": " << e.second;
		i++;
		if (i == 24)
		{
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

map<string, string> Discount::getDiscountFile()
{
	ifstream f;
	f.open(Util::path() + "\\Discount\\CodeDiscount.txt");
	map<string, string> discount;
	string s;
	int n;
	getline(f, s);
	n = stoi(s);

	while (!f.eof())
	{
		getline(f, s);

		vector<string> str = TokenizerStr::split(s, "-");
		discount[str[0]] = str[1];
	}

	f.close();

	return discount;
}

void Discount::addVoucher()
{
	Common::color(14);
	map<string, string> discountList = getDiscountFile();
	string code, percent;
	system("cls");
	UserInterface::Screen();
	Common::gotoXY(48, 6);
	cout << "----------THEM VOUCHER KHUYEN MAI----------";
	Common::gotoXY(35, 10);
	cout << "Nhap code: ";
	cin >> code;
	Common::gotoXY(35, 12);
	cout << "Nhap phan tram khuyen mai: ";
	cin >> percent;

	discountList[code] = percent;
	Common::gotoXY(40, 16);
	cout << "Da them thanh cong!";

	Common::gotoXY(40, 26);
	int i;
	cout << "Nhan '0' de quay lai: ";
	cin >> i;
	if (i == 0)
		Manager::ManagerMenu();

	ofstream f;
	f.open("CodeDiscount.txt", ios::out);
	f << discountList.size();

	for (auto p : discountList)
	{
		f << endl
		  << p.first << "-" << p.second << "%";
	}
	f.close();
}

// Tính tổng tiền được giảm
float Discount::countDiscount(float price, string codeDiscount, int UsedPoint, bool &codeIsValid)
{
	float result = price;
	result = result - UsedPoint * 1000;
	map<string, string> discountList = getDiscountFile();
	for (auto e : discountList)
	{
		if (e.first == codeDiscount)
		{
			codeIsValid = true;
			if (e.second[e.second.size() - 1] == '%')
				result = result - result * stof(e.second) / 100;
			else
				result = result - stof(e.second);
		}
		else
			codeIsValid = false;
	}
	return result;
}