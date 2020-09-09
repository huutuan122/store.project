#include"Menu.h"

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
	cout << "Choose one of the following:\n"
		<< "1. Sign in as a member\n"
		<< "2. Sign in as a employee\n"
		<< "3. Sign is as a manager\n";
	int choice;
	cin >> choice;
	if (choice == 1);// Luc tong hop lai thi ghi ham sign in vao day
	if (choice == 2);
	if (choice == 3);
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