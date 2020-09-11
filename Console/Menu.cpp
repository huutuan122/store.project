#include"Menu.h"
#include "interface.h"
#include "../Member/member.h"
#include "../Member/member.cpp"
#include "../Employee/Employee.h"
#include "../Employee/Employee.cpp"
#include <vector>
#include "Common.h"


Menu::Menu() {
	_hotline = "";
	_address = "";
	_moreInfo = "";
}

Menu::Menu(string hotline, string address, string moreInfo) {
	_hotline = hotline;
	_address = address;
	_moreInfo = moreInfo;
}

void Menu::SignIn() {
	Common::gotoXY(40, 6);
	cout << "1.    Dang nhap hoi vien";
	Common::gotoXY(40, 8);
	cout << "2.    Dang nhap nhan vien";
	Common::gotoXY(40, 10);
	cout << "3.    Dang nhap quan li";

	Common::gotoXY(50, 13);
	cout << "Chon mot trong cac muc tren: ";
	int choice;
	cin >> choice;
	if (choice == 1){
		Member::loginasMember();
	}
	if (choice == 2){
		Employee::EmployeeMenu();
	}
	// if (choice == 2);
	// if (choice == 3);
}

void Menu::ViewGoodList() {
	cout << "Good list:\n";
	cout << _data.showList();
}

void Menu::Order() {
	cout << "Order:\n";// Nhap ham order vao day
}

void Menu::ViewStoreInfo() {
	cout << "Hotline: " << _hotline << endl
		<< "Address: " << _address << endl
		<< "More Information: " << _moreInfo << endl;
}

void Menu::ViewFeedBack() {
	if (_feedback.size() == 0)cout << "There is currently no feedback!";
	else {
		cout << "Feedback:\n";
		for (auto e : _feedback)cout << e << endl;
	}
}

void Menu::addFeedback(string feedback) {
	_feedback.push_back(feedback);
}

void Menu::Exit() {
	Exit();
}