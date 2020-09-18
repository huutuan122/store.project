#include "Menu.h"
#include "interface.h"
#include "../Member/member.h"
#include "../Member/member.cpp"
#include "../Employee/Employee.h"
#include "../Employee/Employee.cpp"
#include "../System/system.h"
#include "../System/system.cpp"
#include <vector>
#include "Common.h"
#include <sstream>
#include "../Employee/Time.h"

using namespace std;
// Khoi tao Menu
Menu::Menu()
{
	_hotline = "";
	_address = "";
	_moreInfo = "";
}

Menu::Menu(string hotline, string address, string moreInfo)
{
	_hotline = hotline;
	_address = address;
	_moreInfo = moreInfo;
}

// Nhom ham truy cap khi moi vao Menu (4 ham)

void Menu::Danhgia()
{
	system("cls");
	UserInterface::Screen();
	Menu menu;
	int i;
	do{
	menu.ViewFeedBack();

	Common::gotoXY(20, 26);
	cout << "1. Danh gia                   2. Thoat";
	Common::gotoXY(24, 27);
	cout << "Chon mot trong cac muc tren: ";
	cin >> i;

	if (i == 1)
	{
		system("cls");
		UserInterface::Screen();
		Menu menu;
		string feedback;
		Common::gotoXY(20, 14);
		Time now;
		cout << "De lai danh gia cua ban: ";
		Common::gotoXY(30, 16);
		getline(cin, feedback);
		getline(cin, feedback);

		Common::gotoXY(40, 26);
		menu.addFeedback(feedback, now);
	}
	
	} while (i != 2);
	if (i==2){
		UserInterface::MainMenu();
	}
}

void Menu::Thongtincuahang()
{
	system("cls");
	UserInterface::Screen();
	Menu menu;
	menu.ViewStoreInfo();

}

void Menu::SignIn()
{
	int choice;
	system("cls");
	UserInterface::Screen();
	Common::gotoXY(49, 4);
	cout << "--------- MENU DANG NHAP ----------";
	Common::gotoXY(40, 6);
	cout << "1.    Dang nhap hoi vien";
	Common::gotoXY(40, 8);
	cout << "2.    Dang nhap nhan vien";
	Common::gotoXY(40, 10);
	cout << "3.    Dang nhap quan li";
	Common::gotoXY(40, 12);
	cout << "4.    Exit";

	Common::gotoXY(50, 14);
	cout << "Chon mot trong cac muc tren: ";
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Member::loginasMember();
			choice = 4;
			break;
		}
		case 2:
		{
			Employee::loginAsEmployee();
			choice = 4;
			break;
		}
		case 3:
		{
			Manager::LoginAsManager();
			choice = 4;
			break;
		}
		case 4:
		{
			UserInterface::MainMenu();
		}
		}
	} while (choice != 4);
}


// Nhom hang khi mua hang o ham Menu::Signin(), Signin As Member
void Menu::Muahang(string name)
{

	int choice;
	Menu menu;
	Common::gotoXY(1, 2);
	menu.data = GoodList::readGoodListFromFile("E:\\VSC\\C++\\Project Store\\github\\Good\\GoodList.txt", "E:\\VSC\\C++\\Project Store\\github\\Good\\Rate.txt", "E:\\VSC\\C++\\Project Store\\github\\Good\\Comment.txt");
	do
	{
		system("cls");
		UserInterface::Screen();
		menu.ViewGoodList();
		cin >> choice;

		if (choice > 0 && choice < menu.data.list.size())
		{
			Common::gotoXY(1, 27);
			cout << "                   ";
			Common::gotoXY(1, 27);
			cout << "So luong mua: ";
			int num;
			cin >> num;
			menu.data.list[choice - 1].setAmount(menu.data.list[choice - 1].amount() - num);
			float money = menu.data.list[choice - 1].price() * num;
			Order(name, menu.data.list[choice - 1].name(), money);
		}
	} while (choice != 0);
	if (choice == 0)
		return;
}

void Menu::ViewGoodList()
{
	int i = 1;
	Common::gotoXY(55, 1);
	cout << "Good list:";
	Common::gotoXY(i, 2);
	cout << "    Ten         Gia              Tinh trang";
	for (int k = 0; k < data.list.size(); k++)
	{
		int j = k + 4;
		Common::gotoXY(i, j);
		cout << k + 1;
		Common::gotoXY(i + 4, j);
		cout << data.list[k].name();
		Common::gotoXY(i + 14, j);
		cout << fixed << setprecision(2) << data.list[k].price();
		Common::gotoXY(i + 34, j);
		cout << data.list[k].status();
	}
	Common::gotoXY(1, 27);
	cout << "Nhap 0 de thoat";
	Common::gotoXY(1, 26);
	cout << "Chon san phan ban muon mua: ";
}

void Menu::Order(string customerName, string goodName, float money)
{
	system("cls");
	UserInterface::Screen();
	Common::gotoXY(49, 6);
	cout << "----------HOA DON THANH TOAN----------";
	Common::gotoXY(45, 8);
	cout << "Ten: " << customerName;
	Common::gotoXY(45, 10);
	cout << "San pham: " << goodName;
	Common::gotoXY(45, 12);
	cout << "Thanh tien: " << money;
	Common::gotoXY(40, 14);

	Time t;
	cout << "Thoi gian: " << t.toString();
	Sleep(1000);
	int i;
	Common::gotoXY(30, 26);
	cout << "Nhap '0' de quay tro lai: ";
	cin >> i;
	if (i==0)
		return;
}


// Ham doc thong tin tu file va xem thong tin cua hang (ViewStoreInfo)
void Menu::ViewStoreInfo()
{
	ifstream f;
	f.open("E:\\VSC\\C++\\Project Store\\github\\Console\\StoreInfo.txt");
	string s;
	vector<string> temp;
	while(!f.eof()){
		getline(f, s);
		temp.push_back(s);
	}

	_hotline = temp[0];
	_address = temp[1];
	_moreInfo = temp[2];
	_gmail = temp[3];

	f.close();
	Common::gotoXY(54, 6);
	cout << "_____THONG TIN CUA HANG_____";

	Common::gotoXY(30, 10);
	cout << "Duong day nong: " << _hotline;
	Common::gotoXY(30, 12);
	cout << "Dia chi: " << _address;
	Common::gotoXY(30, 14);
	cout << "Thong tin them: " << _moreInfo;
	Common::gotoXY(30, 16);
	cout << "Neu co bat cu loi nao, vui long gui thong tin ve email " << _gmail;

	int i;
	Common::gotoXY(20, 26);
	cout << "Bam '0' de tro ve menu chinh: ";
	cin >> i;
	if (i==0)
		UserInterface::MainMenu();
}

// Ham doc thong tin tu file feedback va xem so feedback
vector<string> Menu::readFeedbackFile(){
	vector<string> feedback;
	ifstream f;
	f.open("E:\\VSC\\C++\\Project Store\\github\\Console\\feedback.txt");
	while (!f.eof())
	{
		string s;
		getline(f, s);
		feedback.push_back(s);
	}
	f.close();
	return feedback;
}

void Menu::ViewFeedBack()
{
	vector<string>feedback = readFeedbackFile();
	if (feedback.size() == 0)
	{
		system("cls");
		UserInterface::Screen();
		Common::gotoXY(40, 16);
		cout << "Tam thoi khong co danh gia nao!";
	}
	else
	{
		system("cls");
		UserInterface::Screen();
		Common::gotoXY(49, 4);
		cout << "----------DANH GIA CUA KHACH HANG----------";
		int i = 6;
		for (auto e : feedback){
			Common::gotoXY(25, i);
			cout << e;
			i++;
			if (i == 24){
				system("cls");
				UserInterface::Screen();
				Common::gotoXY(49, 4);
				cout << "----------DANH GIA CUA KHACH HANG----------";
				i = 6;
			}
		}
	}

}

void Menu::addFeedback(string feedback, Time t)
{
	vector<string> feedbackList = readFeedbackFile();
	stringstream writer;
	writer << t.toString() << " - " << feedback;
	feedbackList.push_back(writer.str());
	ofstream f;
	f.open("E:\\VSC\\C++\\Project Store\\github\\Console\\feedback.txt", ios::out);
	f << feedbackList[0];
	for (int i = 1; i < feedbackList.size();i++)
	{
		f << endl << feedbackList[i];
	}

	f.close();
}
