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


//  Level 2
void Menu::SignIn()
{
	int choice;
	system("cls");
	UserInterface::Screen();
	Common::gotoXY(40, 6);
	cout << "1.    Dang nhap hoi vien";
	Common::gotoXY(40, 8);
	cout << "2.    Dang nhap nhan vien";
	Common::gotoXY(40, 10);
	cout << "3.    Dang nhap quan li";
	Common::gotoXY(40, 12);
	cout << "4.    Exit";

	Common::gotoXY(50, 13);
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
				Employee::EmployeeMenu();
				choice = 4;
				break;
			}
			case 3:
			{
				Manager::LoginAsManager();
				choice = 4;
				break;
			}
			case 4: {
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
		cout << "There is currently no feedback!";
	else
	{
		cout << "Feedback:\n";
		for (auto e : _feedback)
			cout << e << endl;
	}
}

void Menu::addFeedback(string feedback)
{
	_feedback.push_back(feedback);
}

void Menu::Exit()
{
	Exit();
}