#include "Employee.h"
#include "../Console/Common.h"
#include "../Console/interface.h"
#include <windows.h>
#include <iomanip>
#include "Time.cpp"
#include "../Member/Tokenizer.h"

Employee::Employee(string id, string name, string dob, string tel, string email, string add, double workhour, double totalhour, int level, string pass)
{
	_id = id;
	_name = name;
	_dob = dob;
	_tel = tel;
	_email = email;
	_address = add;
	_password = pass;
	_monthlyworkhour = workhour;
	_level = level;
	_totalworkhour = totalhour;
}

Employee::Employee()
{
	_id = "";
	_name = "";
	_dob = "";
	_tel = "";
	_email = "";
	_address = "";
	_password = "";
	_monthlyworkhour = 0;
	_level = 0;
	_totalworkhour = 0;
}

void Employee::CheckIn(Employee *&a)
{
	a->_begin.getTime();
	int i;
	Common::gotoXY(30, 14);
	cout << "Ban da check in thanh cong!!!";
	Common::gotoXY(40, 20);
	cout << "Nhan '0' de quay lai: ";
	cin >> i;
	if (i == 0)
		return;
}

void Employee::CheckOut(Employee *&a)
{
	a->_end.getTime();
	int i;
	Common::gotoXY(30, 14);
	cout << "Ban da check out thanh cong!!!";
	updateEmployeeInfo(a);
	Common::gotoXY(40, 20);
	cout << "Nhan '0' de quay lai: ";
	cin >> i;
	if (i == 0)
		return;
}

void Employee::calWorkHour(Employee *&a)
{
	a->_monthlyworkhour += (((double)a->_end.Hour() * 60.0 + (double)a->_end.Minute()) - ((double)a->_begin.Hour() * 60.0 + (double)a->_begin.Minute())) / 60.0;
	a->_totalworkhour += (((double)a->_end.Hour() * 60.0 + (double)a->_end.Minute()) - ((double)a->_begin.Hour() * 60.0 + (double)a->_begin.Minute())) / 60.0;
	updateEmployeeInfo(a);
}

void Employee::Leveling(Employee *&a)
{
	a->_level = a->_totalworkhour / 1825;
	updateEmployeeInfo(a);
}

void Employee::calSalary(Employee *&a)
{
	a->_salary = ((a->_level * 2000.0) + 16000.0) * a->_monthlyworkhour;
	Common::gotoXY(45, 12);
	cout << "Luong thang nay cua ban la: " << a->getSalary();
	int i;
	Common::gotoXY(40, 20);
	cout << "Nhan '0' de quay lai: ";
	cin >> i;
	if (i == 0)
		return;
}

string Employee::toString()
{
	stringstream writer;
	writer << _id << "-" << _name << "-" << _dob << "-" << _tel << "-" << _email
		   << "-" << _address << "-" << fixed << setprecision(2) << _monthlyworkhour << "-"
		   << fixed << setprecision(2) << _totalworkhour
		   << "-" << to_string(_level) << "-" << _password;
	return writer.str();
}

void Employee::deleteEmployee(Employee *emp)
{
	int i = 0;
	vector<Employee *> list = Employee::LoadData();
	for (auto p : list)
	{
		if (p->ID() == emp->ID())
		{
			list.erase(list.begin() + i);
		}
		i++;
	}

	for (int i = 0; i < list.size(); i++)
	{
		list[i]->setID(to_string(i + 1));
	}

	SaveEmployeeInfo(list);
}

void Employee::showEmployeeData()
{
	int i = 4;
	Common::gotoXY(52, 2);
	cout << "_______DANH SACH NHAN VIEN_______";
	vector<Employee *> list = Employee::LoadData();
	for (auto p : list)
	{
		Common::gotoXY(15, i);
		cout << p->toString();
		i++;
	}
}

void Employee::showEmployeeInfo(Employee *&employee)
{
	int choice;
	do
	{
		system("cls");
		UserInterface::Screen();
		Common::gotoXY(49, 6);
		cout << "---------- THONG TIN NHAN VIEN ----------";
		Common::gotoXY(36, 8);
		cout << "1)     ID: " << employee->ID();
		Common::gotoXY(36, 10);
		cout << "2)     Ten nhan vien: " << employee->Name();
		Common::gotoXY(36, 12);
		cout << "3)     Ten dang nhap(so dien thoai): " << employee->Tel();
		Common::gotoXY(36, 14);
		cout << "4)     Mat khau: " << employee->Password();
		Common::gotoXY(36, 16);
		cout << "5)     Email: " << employee->Email();
		Common::gotoXY(36, 18);
		cout << "6)     Dia chi: " << employee->Address();
		Common::gotoXY(36, 20);
		cout << "7)     So gio lam trong thang: " << employee->_monthlyworkhour;
		Common::gotoXY(36, 22);
		cout << "8)     Level: " << employee->_level;
		Common::gotoXY(36, 24);
		cout << "9)     Ngay sinh: " << employee->DOB();
		Common::gotoXY(30, 26);
		cout << "Ban muon chinh sua phan nao? Chon mot muc hoac nhan '0' de quay lai: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			Common::gotoXY(40, 26);
			cout << "Khong chinh sua ID duoc!";
			Sleep(1000);
			break;
		}
		case 2:
		{
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(30, 14);
			string s;
			cout << "Nhap ten ban muon chinh sua: ";
			getline(cin, s);
			getline(cin, s);
			Common::gotoXY(40, 26);
			cout << "Sua ten thanh cong!";
			employee->setName(s);
			Sleep(1000);
			break;
		}
		case 3:
		{
			Common::gotoXY(40, 26);
			cout << "Khong chinh sua ten dang nhap duoc!";
			Sleep(1000);
			break;
		}
		case 4:
		{
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(30, 14);
			string s;
			cout << "Nhap mat khau muon chinh sua: ";
			cin >> s;
			Common::gotoXY(40, 26);
			cout << "Sua mat khau thanh cong!";
			employee->setPassword(s);
			Sleep(1000);
			break;
		}
		case 5:
		{
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(30, 14);
			string s;
			cout << "Nhap email muon chinh sua: ";
			cin >> s;
			Common::gotoXY(40, 26);
			cout << "Sua email thanh cong!";
			employee->setEmail(s);
			Sleep(1000);
			break;
		}
		case 6:
		{
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(30, 14);
			string s;
			cout << "Nhap dia chi muon chinh sua: ";
			getline(cin, s);
			getline(cin, s);
			Common::gotoXY(40, 26);
			cout << "Sua dia chi thanh cong!";
			employee->setAddress(s);
			Sleep(1000);
			break;
		}
		case 7:
		{
			Common::gotoXY(40, 26);
			cout << "Khong chinh sua so gio lam duoc!";
			Sleep(1000);
			break;
		}
		case 8:
		{
			Common::gotoXY(40, 26);
			cout << "Khong chinh sua level duoc!";
			Sleep(1000);
			break;
		}
		case 9:
		{
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(30, 14);
			string s;
			cout << "Nhap ngay sinh muon chinh sua: ";
			getline(cin, s);
			getline(cin, s);
			Common::gotoXY(40, 26);
			cout << "Sua ngay sinh thanh cong!";
			employee->setDOB(s);
			Sleep(1000);
			break;
		}
		}
	} while (choice != 0);
	updateEmployeeInfo(employee);
	if (choice == 0)
		return;
}

void Employee::EmployeeMenu(Employee *&a)
{
	int choice;
	bool flag = false;
	do
	{
		system("cls");
		UserInterface::Screen();
		Common::gotoXY(49, 6);
		cout << "---------- MENU NHAN VIEN ----------";
		Common::gotoXY(40, 8);
		cout << "1)     Xem thong tin ca nhan";
		Common::gotoXY(40, 10);
		cout << "2)     Check in";
		Common::gotoXY(40, 12);
		cout << "3)     Check out";
		Common::gotoXY(40, 14);
		cout << "4)     Tinh luong";
		Common::gotoXY(40, 16);
		cout << "0)     Thoat";
		Common::gotoXY(38, 18);
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			showEmployeeInfo(a);
			break;
		}
		case 2:
		{
			system("cls");
			UserInterface::Screen();
			Employee::CheckIn(a);
			flag = true;
			break;
		}
		case 3:
		{
			system("cls");
			UserInterface::Screen();
			if (flag)
			{
				Employee::CheckOut(a);
				Employee::calWorkHour(a);
				Employee::Leveling(a);
				flag = false;
			}
			else
			{
				Common::gotoXY(45, 12);
				cout << "---------- Ban chua Check in ----------";
				Sleep(1000);
			}

			break;
		}
		case 4:
		{
			system("cls");
			UserInterface::Screen();
			Employee::calSalary(a);
			break;
		}
		}
	} while (choice != 0);
	if (choice == 0)
	{
		Menu::SignIn();
	}
}

vector<Employee *> Employee::LoadData()
{
	fstream reader;
	string temp;
	vector<string> tokens;
	vector<Employee *> list;
	reader.open("E:\\VSC\\C++\\Project Store\\github\\Employee\\EmployeeData.txt", ios::in);

	while (!reader.eof())
	{
		getline(reader, temp);
		tokens = TokenizerStr::split(temp, "-");
		Employee *person = new Employee(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], stod(tokens[6]), stod(tokens[7]), stoi(tokens[8]), tokens[9]);
		list.push_back(person);
	}

	reader.close();
	return list;
}

void Employee::loginAsEmployee()
{
	vector<Employee *> list = LoadData();
	Employee *temp = new Employee();
	string user, pass;
	do
	{
		system("cls");
		UserInterface::Screen();
		Common::gotoXY(49, 6);
		cout << "---------- DANG NHAP NHAN VIEN ----------";
		Common::gotoXY(40, 10);
		cout << "So dien thoai: ";
		cin >> user;
		Common::gotoXY(40, 12);
		cout << "Mat khau: ";
		cin >> pass;
		for (auto p : list)
		{
			if (user == p->Tel())
			{
				temp->setAddress(p->Address());
				temp->setDOB(p->DOB());
				temp->setEmail(p->Email());
				temp->setID(p->ID());
				temp->setName(p->Name());
				temp->setPassword(p->Password());
				temp->setTel(p->Tel());
				temp->_level = p->_level;
				temp->_monthlyworkhour = p->_monthlyworkhour;
				temp->_totalworkhour = p->_totalworkhour;
				temp->_salary = p->_salary;
			}
		}

		if (pass != temp->Password())
		{
			Common::gotoXY(38, 14);
			cout << "Sai ten dang nhap hoac sai mat khau, xin moi nhap lai!! " << endl;
			Sleep(1000);
			system("cls");
		}
		else
		{
			Common::gotoXY(49, 14);
			cout << "Dang nhap thanh cong! ";
			Sleep(1000);
		}
		Sleep(1000);

	} while (pass != temp->Password());

	EmployeeMenu(temp);
}

void Employee::updateEmployeeInfo(Employee *a)
{
	vector<Employee *> list = LoadData();

	for (auto p : list)
	{
		if (p->ID() == a->ID())
		{
			p->setTel(a->Tel());
			p->setPassword(a->Password());
			p->setName(a->Password());
			p->setID(a->ID());
			p->setEmail(a->Email());
			p->setDOB(a->DOB());
			p->setAddress(a->Address());
			p->_monthlyworkhour = a->_monthlyworkhour;
			p->_salary = a->_salary;
			p->_totalworkhour = a->_totalworkhour;
			p->_level = a->_level;
		}
	}

	SaveEmployeeInfo(list);
}

void Employee::SaveEmployeeInfo(vector<Employee *> list)
{
	ofstream writer;
	writer.open("E:\\VSC\\C++\\Project Store\\github\\Employee\\EmployeeData.txt", ios::out);

	writer << list[0]->toString();
	for (int i = 1; i < list.size(); i++)
	{
		writer << endl
			   << list[i]->toString();
	}

	writer.close();
}

void Employee::SignUp(vector<Employee *> &list)
{
	Employee *person;
	person->setID(to_string(list.size() + 1));
	string temp;
	string temp2;
	Common::gotoXY(49, 4);
	cout << "----------Hoan tat cac thong tin sau----------" << endl;

	Common::gotoXY(40, 6);
	cout << "Ho va ten: ";
	getline(cin, temp);
	getline(cin, temp);
	person->setName(temp);

	Common::gotoXY(40, 8);
	cout << "Ngay sinh: ";
	getline(cin, temp);
	person->setDOB(temp);

	Common::gotoXY(40, 10);
	cout << "So dien thoai: ";
	getline(cin, temp);
	person->setTel(temp);

	Common::gotoXY(40, 12);
	cout << "Email: ";
	getline(cin, temp);
	person->setEmail(temp);

	Common::gotoXY(40, 14);
	cout << "Dia chi: ";
	getline(cin, temp);
	person->setAddress(temp);

	Common::gotoXY(40, 16);
	cout << "Mat khau: ";
	getline(cin, temp);
	person->setPassword(temp);

	list.push_back(person);
	SaveEmployeeInfo(list);
}
