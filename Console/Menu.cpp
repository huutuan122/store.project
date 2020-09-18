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
#include <iomanip>

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
				Employee a;
				Employee::EmployeeMenu(a);
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
	int i = 1;
	Common::gotoXY(55, 1);
	cout << "Good list:";
	Common::gotoXY(i, 2);
	cout << "    Ten         Gia              Tinh trang";
	for (int k = 0; k < data.list.size();k++)
	{
		int j = k + 4;
		Common::gotoXY(i, j);
		cout << k + 1;
		Common::gotoXY(i+4, j);
		cout << data.list[k].name();
		Common::gotoXY(i+14, j);
		cout << fixed << setprecision(2) << data.list[k].price();
		Common::gotoXY(i+34, j);
		cout << data.list[k].status();
	}
	Common::gotoXY(1, 27);
	cout << "Nhap 0 de thoat";
	Common::gotoXY(1, 26);
	cout << "Chon san phan ban muon mua: ";
	int choice;
	cin >> choice;
	if(choice==0)
		UserInterface::MainMenu();
	
		
}

void Menu::Order()
{
	cout << "Order:\n"; // Nhap ham order vao day
}

void Menu::ViewStoreInfo()
{
	Common::gotoXY(54, 6);
	cout << "_____THONG TIN CUA HANG_____";
	Common::gotoXY(54, 7);
	cout << "Hotline: ";
	Common::gotoXY(54, 8);
	cout << "Address: " << _address;
	Common::gotoXY(54, 9);
	cout << "More Information: " << _moreInfo << endl;
}

void Menu::ViewFeedBack()
{
	if (_feedback.size() == 0){
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
	writer << t.toString() << "	"<< feedback;
	_feedback.push_back(writer.str());
	ofstream f;
	f.open("E:\\VSC\\C++\\Project Store\\github\\Console\\feedback.txt");
	for (auto p: _feedback){
		f << p << endl;
	}


	f.close();
}

void Menu::Exit()
{
	Exit();
}

void Menu::Purchase(int position, Member* member){
	data.list[position].setAmount(data.list[position].amount() - 1);
	
}