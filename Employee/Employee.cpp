#include"Employee.h"
#include "../Console/Common.h"
#include "../Console/interface.h" 
#include <windows.h>
#include "Time.cpp"

using namespace std;

Employee::Employee(){
	_monthlyworkhour = 0;
	_totalworkhour = 0;
}

Employee::Employee(string id, string name, string dob, string tel, string email, string add, double workour, double totalhour, int level, string pass) {
	_name = name;
	_id = id;
	_dob = dob;
	_email = email;
	_tel = tel;
	_address = add;
	_password = pass;
	_monthlyworkhour = workour;
	_totalworkhour = totalhour;
	_level = level;
}

string Employee::Name() {
	return _name;
}

void Employee::setName(string name) {
	_name = name;
}

string Employee::ID() {
	return _id;
}

void Employee::setID(string id) {
	_id = id;
}

string Employee::DOB() {
	return _dob;
}

void Employee::setDOB(string dob) {
	_dob = dob;
}

string Employee::Email() {
	return _email;
}

void Employee::setEmail(string mail) {
	_email = mail;
}

string Employee::Tel() {
	return _tel;
}

void Employee::setTel(string tel) {
	_tel = tel;
}

string Employee::Address() {
	return _address;
}

void Employee::setAddress(string add) {
	_address = add;
}

string Employee::Password() {
	return _password;
}

void Employee::setPassword(string pass) {
	_password = pass;
}

double Employee::getSalary() {
	return _salary;
}

void Employee::SignUp(vector<Employee>& list) {
	Employee person;
	person.setID(to_string(list.size() + 1));
	string temp;
	string temp2;
	cout << "---------- Hoan tat cac thong tin sau ----------" << endl;
	cout << "Ho va ten: ";
	getline(cin, temp);
	person.setName(temp);
	cout << "Ngay sinh: ";
	getline(cin, temp);
	person.setDOB(temp);
	cout << "So dien thoai: ";
	getline(cin, temp);
	person.setTel(temp);
	cout << "Email: ";
	getline(cin, temp);
	person.setEmail(temp);
	cout << "Dia chi: ";
	getline(cin, temp);
	person.setAddress(temp);
	cout << "Mat khau: ";
	getline(cin, temp);
	person.setPassword(temp);
	list.push_back(person);
}

string Employee::toString() {
	stringstream writer;
	writer << _id << "-" << _name << "-" << _dob << "-" << _tel << "-" << _email
		   << "-" << _address << "-" << to_string(_monthlyworkhour) << "-" << to_string(_totalworkhour)
		   << "-" << to_string(_level) << "-" << _password;
	return writer.str();
}

void Employee::SaveData(vector<Employee> list) {
	fstream writer;
	writer.open("EmployeeData.txt", ios::out);
	if (!writer) {
		cout << "Khong mo duoc file";
		exit;
	}
	writer << list[0].toString();
	for (int i = 1; i < list.size();i++ ) {
		writer << endl << list[i].toString();
	}

	writer.close();
}

vector<string> split(string a, string separator) {
	vector<string> tokens;
	int startPos = 0;
	while (true) {
		int foundPos = a.find(separator, startPos);
		if (foundPos != string::npos) {
			tokens.push_back(a.substr(startPos, foundPos - startPos));
			startPos = foundPos + separator.length();
		}
		else {
			tokens.push_back(a.substr(startPos, a.length() - startPos));
			break;
		}
	}
	return tokens;
}

vector<Employee> Employee::LoadData() {
	fstream reader;
	string temp;
	vector<string> tokens;
	vector<Employee> list;
	reader.open("E:\\VSC\\C++\\Project Store\\github\\Employee\\EmployeeData.txt", ios::in);
	if (!reader) {
		cout << "Khong the mo file!";
		exit;
	}
	while (!reader.eof())
	{
		getline(reader, temp, '\n');
		tokens = split(temp, "-");
		Employee person(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], stod(tokens[6]), stod(tokens[7]), stoi(tokens[8]), tokens[9]);
		list.push_back(person);
	}

	reader.close();
	return list;
}

int Employee::isAccess(vector<Employee> list)
{
	string username;
	string password;
	system("cls");
	UserInterface::Screen();
	Common::gotoXY(49, 3);
	cout << "---------- Dang nhap ----------" << endl;
	Common::gotoXY(40, 6);
	cout << "Nhap so dien thoai: ";
	getline(cin, username);
	getline(cin, username);
	Common::gotoXY(40, 8);
	cout << "Nhap mat khau: ";
	getline(cin, password);
	for (int i = 0; i < list.size(); i++) {
		if (list[i].Tel() == username) {
			if (list[i].Password() == password) {
				return i;
			}
			else {
				return -1;
			}
		}
		else
			return -1;
	}
	return 1;
}

void Employee::editInfo() {
	string oldpass;
	string newpass;
	string temp;
	int choice;
	system("cls");
	UserInterface::Screen();
	Common::gotoXY(46, 6);
	cout << "---------- Thong tin ca nhan ----------" << endl;
	Common::gotoXY(40, 10);
	cout << "1) Ho va Ten: " << _name;
	Common::gotoXY(40, 12);
	cout << "2) Ngay sinh: " << _dob ;
	Common::gotoXY(40, 14);
	cout << "3) So dien thoai: " << _tel ;
	Common::gotoXY(40, 16);
	cout << "4) Email: " << _email ;
	Common::gotoXY(40, 18);
	cout << "5) Dia chi: " << _address;
	Common::gotoXY(40, 20);
	cout << "6) So gio lam trong thang: " << _monthlyworkhour;
	Common::gotoXY(40, 22);
	cout << "7) Level: " << _level;
	Common::gotoXY(40, 24);
	cout << "8) Mat khau: *********";
	Common::gotoXY(35, 26);
	cout << "Ban muon chinh sua thong tin nao? (Nhap '0' de thoat) ";
	do {
	
		
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(53, 10);
			cout << "Nhap Ho va Ten: ";
			getline(cin, temp);
			getline(cin, temp);
			_name = temp;
			Common::gotoXY(53, 10);
			Sleep(100);
			cout << "Da chinh sua thanh cong!";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		case 2:
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(53, 10);
			cout << "Nhap ngay sinh: ";
			getline(cin, temp);
			getline(cin, temp);
			_dob = temp;
			Common::gotoXY(53, 10);
			Sleep(1000);
			cout << "Da chinh sua thanh cong!";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		case 3:
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(53, 10);
			cout << "Nhap so dien thoai: ";
			getline(cin, temp);
			getline(cin, temp);
			_tel = temp;
			Common::gotoXY(53, 10);
			Sleep(1000);
			cout << "Da chinh sua thanh cong!";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		case 4:
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(53, 10);
			cout << "Nhap email: ";
			getline(cin, temp);
			getline(cin, temp);
			_email = temp;
			Sleep(1000);
			Common::gotoXY(53, 10);
			cout << "Da chinh sua thanh cong!";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		case 5:
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(53, 10);
			cout << "Nhap dia chi: ";
			getline(cin, temp);
			getline(cin, temp);
			_address = temp;
			Sleep(1000);
			Common::gotoXY(53, 10);
			cout << "Da chinh sua thanh cong!";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		case 6:
			system("cls");
			UserInterface::Screen();
			Sleep(1000);
			Common::gotoXY(53, 10);
			cout << "---------- Co lam thi moi co an ----------" ;
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		case 7:
			system("cls");
			UserInterface::Screen();
			Sleep(1000);
			Common::gotoXY(53, 10);
			cout << "---------- Co lam thi moi co an ----------";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		case 8:
			do{
				system("cls");
				UserInterface::Screen();
				Sleep(1000);
				Common::gotoXY(45, 10);
				cout << "Nhap mat khau cu: ";
				getline(cin, oldpass);
				if (oldpass != _password){
				Common::gotoXY(53, 12);
				cout << "---------- Mat khau cu khong khop! ----------" << endl;
				}
				else
					break;
			} while (oldpass != _password);

			if (oldpass == _password)
			{
				Common::gotoXY(40, 14);
				cout << "Mat khau dung!";
				Sleep(1000);
				do{
					system("cls");
					UserInterface::Screen();
					Common::gotoXY(45, 12);
					cout << "Nhap mat khau moi: ";
					getline(cin, newpass);
					Common::gotoXY(45, 14);
					cout << "Xac nhan mat khau moi: ";
					getline(cin, temp);
					if (newpass != temp) {
						Common::gotoXY(40, 16);
						cout << "---------- Mat khau khong khop ----------";
						Sleep(1000);
					}
					else
						break;
				} while (newpass != temp);
				if (newpass == temp){
					Common::gotoXY(40, 24);
					cout << "Da thay doi mat khau thanh cong!";
					_password = newpass;
				}
			}
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		}
	} while (choice != 0);
}

void Employee::EmployeeMenu() {
	bool flag = false;
	vector<Employee> list;
	list = Employee::LoadData();
	int pos = Employee::isAccess(list);
	if (pos != -1) {
		UserInterface::Screen();
		Common::gotoXY(35, 10);
		cout << "---------- Dang nhap thanh cong! ----------";
		int choice;
		
		do {
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(49, 6);
			cout << "---------- MENU ----------";
			Common::gotoXY(40, 8);
			cout << "1) Xem thong tin ca nhan" ;
			Common::gotoXY(40, 10);
			cout << "2) Check in" ;
			Common::gotoXY(40, 12);
			cout << "3) Check out" ;
			Common::gotoXY(40, 14);
			cout << "4) Tinh luong";
			Common::gotoXY(40, 16);
			cout << "5) Thoat";
			Common::gotoXY(38, 18);
			cout << "Nhap lua chon: ";
			cin >> choice;
			cin.ignore();
			switch (choice) {
			case 1:
				if (flag){
					system("cls");
					UserInterface::Screen();
					Common::gotoXY(45, 12);
					cout << "---------- Ban da Check in roi ----------";
				}
				else
					list[pos].editInfo();
				break;
			case 2:
				list[pos].CheckIn();
				flag = true;
				break;
			case 3:
				if (flag) {
					list[pos].CheckOut();
					list[pos].calWorkHour();
					list[pos].Leveling();
					flag = false;
				}
				else{
					Common::gotoXY(45, 12);
					cout << "---------- Ban chua Check in ----------";
				}
				break;
			case 4:
				list[pos].calSalary();
				Common::gotoXY(45, 12);
				cout << "Luong thang nay cua ban la: " << list[pos].getSalary() << endl;
				break;
			}
		} while (choice != 5);
	}
	else{
		Common::gotoXY(35, 10);
		cout << "---------- Sai ten dang nhap hoac mat khau! ----------";
	}
	Employee::SaveData(list);
}

void Employee::CheckIn() {
	_begin.getTime();
}

void Employee::CheckOut() {
	_end.getTime();
}

void Employee::calWorkHour() {
	_monthlyworkhour += (((double)_end.Hour() * 60.0 + (double)_end.Minute()) - ((double)_begin.Hour() * 60.0 + (double)_begin.Minute())) / 60.0;
	_totalworkhour += (((double)_end.Hour() * 60.0 + (double)_end.Minute()) - ((double)_begin.Hour() * 60.0 + (double)_begin.Minute())) / 60.0;
}

void Employee::Leveling() {
	_level = _totalworkhour / 1825;
}

void Employee::calSalary() {
	_salary = ((_level * 2000.0) + 16000.0) * _monthlyworkhour;
}

