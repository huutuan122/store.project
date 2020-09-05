#include"Employee.h"

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

double Employee::MonthlyWorkHours() {
	return _monthlyworkhour;
}

int Employee::Level() {
	return _level;
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
	reader.open("EmployeeData.txt", ios::in);
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

int Employee::isAccess(vector<Employee> list) {
	string username;
	string password;
	cout << "---------- Dang nhap ----------" << endl;
	cout << "Nhap so dien thoai: ";
	getline(cin, username);
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
	
}

string hidePassword(string pass) {
	string result;
	for (char c : pass)
		result += "*";
	return result;
}

void Employee::editInfo(vector<Employee> &list, int pos) {
	string oldpass;
	string newpass;
	string temp;
	int choice;
	cout << "---------- Thong tin ca nhan ----------" << endl;
	cout << "1) Ho va Ten: " << list[pos].Name() << endl;
	cout << "2) Ngay sinh: " << list[pos].DOB() << endl;
	cout << "3) So dien thoai: " << list[pos].Tel() << endl;
	cout << "4) Email: " << list[pos].Email() << endl;
	cout << "5) Dia chi: " << list[pos].Address() << endl;
	cout << "6) So gio lam trong thang: " << list[pos].MonthlyWorkHours() << endl;
	cout << "7) Level: " << list[pos].Level() << endl;
	cout << "8) Mat khau: " << hidePassword(list[pos].Password()) << endl;
	do {
		cout << "Ban muon chinh sua thong tin nao? (Nhap '0' de thoat) ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			cout << "Nhap Ho va Ten: ";
			getline(cin, temp);
			list[pos].setName(temp);
			break;
		case 2:
			cout << "Nhap ngay sinh: ";
			getline(cin, temp);
			list[pos].setDOB(temp);
			break;
		case 3:
			cout << "Nhap so dien thoai: ";
			getline(cin, temp);
			list[pos].setTel(temp);
			break;
		case 4:
			cout << "Nhap email: ";
			getline(cin, temp);
			list[pos].setEmail(temp);
			break;
		case 5:
			cout << "Nhap dia chi: ";
			getline(cin, temp);
			list[pos].setAddress(temp);
			break;
		case 6:
			cout << "---------- Co lam thi moi co an ----------" << endl;
			break;
		case 7:
			cout << "---------- Co lam thi moi co an ----------" << endl;
			break;
		case 8:
			cout << "Nhap mat khau cu: ";
			getline(cin, oldpass);
			if (oldpass != list[pos].Password()) {
				cout << "---------- Mat khau cu khong khop! ----------" << endl;
				break;
			}
			else {
				cout << "Nhap mat khau moi: ";
				getline(cin, newpass);
				cout << "Xac nhan mat khau moi: ";
				getline(cin, temp);
				if (newpass != temp) {
					cout << "---------- Mat khau khong khop ----------" << endl ;
					break;
				}
				else
					list[pos].setPassword(newpass);
			}
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
		cout << "---------- Dang nhap thanh cong! ----------" << endl;
		int choice;
		
		do {
			cout << "---------- MENU ----------" << endl;
			cout << "1) Xem thong tin ca nhan" << endl;
			cout << "2) Check in" << endl;
			cout << "3) Check out" << endl;
			cout << "4) Tinh luong" << endl;
			cout << "5) Thoat" << endl;
			cout << "Nhap lua chon: ";
			cin >> choice;
			cin.ignore();
			switch (choice) {
			case 1:
				if (flag)
					cout << "---------- Ban da Check in roi ----------" << endl;
				else
					Employee::editInfo(list,pos);
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
				else
					cout << "---------- Ban chua Check in ----------" << endl;
				break;
			case 4:
				list[pos].calSalary();
				cout << "Luong thang nay cua ban la: " << list[pos].getSalary() << endl;
				break;
			}
		} while (choice != 5);
	}
	else
		cout << "---------- Sai ten dang nhap hoac mat khau! ----------";
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

