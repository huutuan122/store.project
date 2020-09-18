#include "Employee.h"
#include "../Console/Common.h"
#include "../Console/interface.h"
#include <windows.h>
#include <iomanip>
#include "Time.cpp"

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

void Employee::CheckIn()
{
	_begin.getTime();
}

void Employee::CheckOut()
{
	_end.getTime();
}

void Employee::calWorkHour()
{
	_monthlyworkhour += (((double)_end.Hour() * 60.0 + (double)_end.Minute()) - ((double)_begin.Hour() * 60.0 + (double)_begin.Minute())) / 60.0;
	_totalworkhour += (((double)_end.Hour() * 60.0 + (double)_end.Minute()) - ((double)_begin.Hour() * 60.0 + (double)_begin.Minute())) / 60.0;
}

void Employee::Leveling()
{
	_level = _totalworkhour / 1825;
}

void Employee::calSalary()
{
	_salary = ((_level * 2000.0) + 16000.0) * _monthlyworkhour;
}

void Employee::SignUp(vector<Employee> &list)
{
	Employee person;
	person.setID(to_string(list.size() + 1));
	string temp;
	string temp2;
	Common::gotoXY(49, 4);
	cout << "----------Hoan tat cac thong tin sau----------" << endl;

	Common::gotoXY(40, 6);
	cout << "Ho va ten: ";
	getline(cin, temp);
	getline(cin, temp);
	person.setName(temp);

	Common::gotoXY(40, 8);
	cout << "Ngay sinh: ";
	getline(cin, temp);
	person.setDOB(temp);

	Common::gotoXY(40, 10);
	cout << "So dien thoai: ";
	getline(cin, temp);
	person.setTel(temp);

	Common::gotoXY(40, 12);
	cout << "Email: ";
	getline(cin, temp);
	person.setEmail(temp);

	Common::gotoXY(40, 14);
	cout << "Dia chi: ";
	getline(cin, temp);
	person.setAddress(temp);

	Common::gotoXY(40, 16);
	cout << "Mat khau: ";
	getline(cin, temp);
	person.setPassword(temp);

	list.push_back(person);
	SaveData(list, person);
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

void Employee::deleteEmployee(Employee emp)
{
	int i = 0;
	vector<Employee> list = Employee::LoadData();
	for (auto p : list)
	{
		if (p.ID() == emp.ID())
		{
			list.erase(list.begin() + i);
		}
		i++;
	}

	for (int i = 0; i < list.size(); i++)
	{
		list[i].setID(to_string(i + 1));
	}

	fstream writer;
	writer.open("E:\\VSC\\C++\\Project Store\\github\\Employee\\EmployeeData.txt", ios::out);
	writer << list[0].toString();
	for (int i = 1; i < list.size(); i++)
	{
		writer << endl
			   << list[i].toString();
	}

	writer.close();
}

void Employee::showEmployeeData()
{
	int i = 4;
	Common::gotoXY(52, 2);
	cout << "_______DANH SACH NHAN VIEN_______";
	vector<Employee> list = Employee::LoadData();
	for (auto p : list)
	{
		Common::gotoXY(15, i);
		cout << p.toString();
		i++;
	}
}

void Employee::SaveData(vector<Employee> list, Employee a)
{
	fstream writer;
	writer.open("E:\\VSC\\C++\\Project Store\\github\\Employee\\EmployeeData.txt", ios::out);
	if (!writer)
	{
		cout << "Khong mo duoc file";
		exit;
	}

	for (auto p: list){
		if (p.ID() == a.ID()){
			p.setTel(a.Tel());
			p.setPassword(a.Password());
			p.setName(a.Password());
			p.setID(a.ID());
			p.setEmail(a.Email());
			p.setDOB(a.DOB());
			p.setAddress(a.Address());
			p._monthlyworkhour = a._monthlyworkhour;
			p._salary = a._salary;
			p._totalworkhour = a._totalworkhour;
			p._level = a._level;
		}
	}


	writer << list[0].toString();
	for (int i = 1; i < list.size(); i++)
	{
		writer << endl
			   << list[i].toString();
	}

	writer.close();
}

vector<string> split(string a, string separator)
{
	vector<string> tokens;
	int startPos = 0;
	while (true)
	{
		int foundPos = a.find(separator, startPos);
		if (foundPos != string::npos)
		{
			tokens.push_back(a.substr(startPos, foundPos - startPos));
			startPos = foundPos + separator.length();
		}
		else
		{
			tokens.push_back(a.substr(startPos, a.length() - startPos));
			break;
		}
	}
	return tokens;
}

vector<Employee> Employee::LoadData()
{
	fstream reader;
	string temp;
	vector<string> tokens;
	vector<Employee> list;
	reader.open("E:\\VSC\\C++\\Project Store\\github\\Employee\\EmployeeData.txt", ios::in);
	if (!reader)
	{
		cout << "Khong the mo file!";
		exit;
	}
	while (!reader.eof())
	{
		getline(reader, temp);
		tokens = split(temp, "-");
		Employee person(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], stod(tokens[6]), stod(tokens[7]), stoi(tokens[8]), tokens[9]);
		list.push_back(person);
	}

	reader.close();
	return list;
}

int Employee::isAccess(vector<Employee> list, Employee& a)
{
	int point = -1;
	string username;
	string password;
	system("cls");
	UserInterface::Screen();
	Common::gotoXY(49, 3);
	cout << "---------- DANG NHAP NHAN VIEN ----------" << endl;
	Common::gotoXY(40, 6);
	cout << "Nhap so dien thoai: ";
	cin >> username;
	Common::gotoXY(40, 8);
	cout << "Nhap mat khau: ";
	cin >> password;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].Tel() == username)
		{
			if (list[i].Password() == password)
			{
				a.setTel(list[i].Tel());
				a.setPassword(list[i].Password());
				a.setName(list[i].Password());
				a.setID(list[i].ID());
				a.setEmail(list[i].Email());
				a.setDOB(list[i].DOB());
				a.setAddress(list[i].Address());
				a._monthlyworkhour = list[i]._monthlyworkhour;
				a._salary = list[i]._salary;
				a._totalworkhour = list[i]._totalworkhour;
				a._level = list[i]._level;
				
				point = i;
			}
		}
	}
	return point;
}

void Employee::editInfo(Employee& a)
{
	string oldpass;
	string newpass;
	string temp;
	int choice;
	system("cls");
	UserInterface::Screen();
	Common::gotoXY(46, 6);
	cout << "---------- Thong tin ca nhan ----------" << endl;
	Common::gotoXY(40, 10);
	cout << "1) Ho va Ten: " << a.Name();
	Common::gotoXY(40, 12);
	cout << "2) Ngay sinh: " << a.DOB();
	Common::gotoXY(40, 14);
	cout << "3) So dien thoai: " << a.Tel();
	Common::gotoXY(40, 16);
	cout << "4) Email: " << a.Email();
	Common::gotoXY(40, 18);
	cout << "5) Dia chi: " << a.Address();
	Common::gotoXY(40, 20);
	cout << "6) So gio lam trong thang: " << a._monthlyworkhour;
	Common::gotoXY(40, 22);
	cout << "7) Level: " << a._level;
	Common::gotoXY(40, 24);
	cout << "8) Mat khau: *********";
	Common::gotoXY(35, 26);
	cout << "Ban muon chinh sua thong tin nao? (Nhap '0' de thoat) ";
	do
	{
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(53, 10);
			cout << "Nhap Ho va Ten: ";
			getline(cin, temp);
			Common::gotoXY(53, 12);
			Sleep(100);
			a.setName(temp);
			cout << "Da chinh sua thanh cong!";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		}
		case 2:
		{
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(53, 10);
			cout << "Nhap ngay sinh: ";
			getline(cin, temp);
			getline(cin, temp);
			a.setDOB(temp);
			Common::gotoXY(53, 10);
			Sleep(1000);
			cout << "Da chinh sua thanh cong!";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		}
		case 3:
		{
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(53, 10);
			cout << "Nhap so dien thoai: ";
			cin >> temp;
			a.setTel(temp);
			Common::gotoXY(53, 10);
			Sleep(1000);
			cout << "Da chinh sua thanh cong!";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		}
		case 4:
		{
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(53, 10);
			cout << "Nhap email: ";
			getline(cin, temp);
			a.setEmail(temp);
			Sleep(1000);
			Common::gotoXY(53, 10);
			cout << "Da chinh sua thanh cong!";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		}
		case 5:
		{
			system("cls");
			UserInterface::Screen();
			Common::gotoXY(53, 10);
			cout << "Nhap dia chi: ";
			getline(cin, temp);
			getline(cin, temp);
			a.setAddress(temp);
			Sleep(1000);
			Common::gotoXY(53, 10);
			cout << "Da chinh sua thanh cong!";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		}
		case 6:
		{
			system("cls");
			UserInterface::Screen();
			Sleep(1000);
			Common::gotoXY(53, 10);
			cout << "---------- Co lam thi moi co an ----------";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		}
		case 7:
		{
			system("cls");
			UserInterface::Screen();
			Sleep(1000);
			Common::gotoXY(53, 10);
			cout << "---------- Co lam thi moi co an ----------";
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		}
		case 8:
		{
			do
			{
				system("cls");
				UserInterface::Screen();
				Sleep(1000);
				Common::gotoXY(45, 10);
				cout << "Nhap mat khau cu: ";
				getline(cin, oldpass);
				if (oldpass != a._password)
				{
					Common::gotoXY(53, 12);
					cout << "---------- Mat khau cu khong khop! ----------" << endl;
				}
				else
					break;
			} while (oldpass != a._password);

			if (oldpass == a._password)
			{
				Common::gotoXY(40, 14);
				cout << "Mat khau dung!";
				Sleep(1000);
				do
				{
					system("cls");
					UserInterface::Screen();
					Common::gotoXY(45, 12);
					cout << "Nhap mat khau moi: ";
					getline(cin, newpass);
					Common::gotoXY(45, 14);
					cout << "Xac nhan mat khau moi: ";
					getline(cin, temp);
					if (newpass != temp)
					{
						Common::gotoXY(40, 16);
						cout << "---------- Mat khau khong khop ----------";
						Sleep(1000);
					}
					else{
						a.setPassword(newpass);
						break;
					}
				} while (newpass != temp);
				if (newpass == temp)
				{
					Common::gotoXY(40, 24);
					cout << "Da thay doi mat khau thanh cong!";
					a._password = newpass;
				}
			}
			Common::gotoXY(35, 26);
			cout << "Nhan 0 de quay lai: ";
			break;
		}
		}
	} while (choice != 0);
	vector<Employee> list = LoadData();
	SaveData(list, a);
}

void Employee::EmployeeMenu(Employee& a)
{
	int choice;
	bool flag = false;
	vector<Employee> list;
	list = Employee::LoadData();
	int pos = Employee::isAccess(list, a);
	do
	{
		Sleep(1000);
		if (pos != -1)
		{
			UserInterface::Screen();
			Common::gotoXY(35, 10);
			cout << "---------- Dang nhap thanh cong! ----------";

			do
			{
				system("cls");
				UserInterface::Screen();
				Common::gotoXY(49, 6);
				cout << "---------- MENU NHAN VIEN ----------";
				Common::gotoXY(40, 8);
				cout << "1) Xem thong tin ca nhan";
				Common::gotoXY(40, 10);
				cout << "2) Check in";
				Common::gotoXY(40, 12);
				cout << "3) Check out";
				Common::gotoXY(40, 14);
				cout << "4) Tinh luong";
				Common::gotoXY(40, 16);
				cout << "5) Thoat";
				Common::gotoXY(38, 18);
				cout << "Nhap lua chon: ";
				cin >> choice;
				cin.ignore();
				switch (choice)
				{
				case 1:
				{
					if (flag)
					{
						system("cls");
						UserInterface::Screen();
						Common::gotoXY(45, 12);
						cout << "---------- Ban da Check in roi ----------";
					}
					else
						list[pos].editInfo(a);
					break;
				}
				case 2:
				{
					list[pos].CheckIn();
					flag = true;
					break;
				}
				case 3:
				{
					if (flag)
					{
						list[pos].CheckOut();
						list[pos].calWorkHour();
						list[pos].Leveling();
						flag = false;
					}
					else
					{
						Common::gotoXY(45, 12);
						cout << "---------- Ban chua Check in ----------";
					}
					break;
				}
				case 4:
				{
					list[pos].calSalary();
					Common::gotoXY(45, 12);
					cout << "Luong thang nay cua ban la: " << list[pos].getSalary() << endl;
					break;
				}
				}
			} while (choice != 5);
			if (choice == 5)
			{
				Menu::SignIn();
				pos = -1;
			}
		}
		else
		{
			Common::gotoXY(35, 10);
			cout << "---------- Sai ten dang nhap hoac mat khau! ----------";
			Sleep(1000);
			pos = Employee::isAccess(list, a);
		}
	} while (pos != -1);

	Employee::SaveData(list, a);
}
