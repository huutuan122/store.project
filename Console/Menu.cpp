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

// Access Function

void Menu::Danhgia()
{
	system("cls");
	UserInterface::Screen();
	Menu menu;
	menu.ViewFeedBack();
	int i;
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
		Common::gotoXY(40, 14);
		Time now;
		cout << "De lai danh gia cua ban: ";
		Common::gotoXY(30, 16);
		getline(cin, feedback);
		getline(cin, feedback);

		Common::gotoXY(40, 26);
		menu.addFeedback(feedback, now);
	}
	else
		UserInterface::MainMenu();
}

void Menu::Thongtincuahang()
{
	system("cls");
	UserInterface::Screen();
	Menu menu;
	menu.ViewStoreInfo();
	Common::gotoXY(1, 27);
	system("pause");
}

void Menu::Muahang()
{

	system("cls");
	UserInterface::Screen();
	Menu menu;
	Common::gotoXY(1, 2);
	menu.data = GoodList::readGoodListFromFile("D:\\Final\\store.project\\Good\\GoodList.txt", "D:\\Final\\store.project\\Good\\Rate.txt", "D:\\Final\\store.project\\Good\\Comment.txt");
	menu.ViewGoodList();
}
//  Level 2
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

void Menu::ViewGoodList()
{
	cout << "Good list:\n";
	cout << _data.showList();
}

void Menu::Order()
{
	cout << "Order:\n"; // Nhap ham order vao day
}

void Menu::ViewStoreInfo()
{
	Common::gotoXY(54, 6);
	cout << "_____THONG TIN CUA HANG_____";

	cout << "Hotline: ";
	cout << "Address: " << _address;
	cout << "More Information: " << _moreInfo << endl;
}

void Menu::ViewFeedBack()
{
	if (_feedback.size() == 0)
	{
		Common::gotoXY(40, 16);
		cout << "There is currently no feedback!";
	}
	else
	{
		cout << "Feedback:\n";
		for (auto e : _feedback)
			cout << e << endl;
	}
}

void Menu::addFeedback(string feedback, Time t)
{
	stringstream writer;
	writer << t.toString() << "	" << feedback;
	_feedback.push_back(writer.str());
	ofstream f;
	f.open("E:\\VSC\\C++\\Project Store\\github\\Console\\feedback.txt");
	for (auto p : _feedback)
	{
		f << p << endl;
	}

	f.close();
}

void Menu::Exit()
{
	Exit();
}