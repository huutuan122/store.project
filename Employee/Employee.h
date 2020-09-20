
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "../Utility/Time.h"

using namespace std;
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

class Employee
{

private: // Attributes
	string _name;
	string _id;
	string _dob;
	string _email;
	string _tel;
	string _address;
	string _password;
	int _level;
	double _monthlyworkhour;
	double _totalworkhour;
	int level = _totalworkhour;
	double _salary;
	Time _begin;
	Time _end;

public: // Constructor
	Employee();
	Employee(string, string, string, string, string, string, double, double, int, string);

public: // setter - getter (Encapsulation)
	string Name() { return _name; }
	void setName(string name) { _name = name; }
	string ID() { return _id; }
	void setID(string id) { _id = id; }
	string DOB() { return _dob; }
	void setDOB(string dob) { _dob = dob; }
	string Email() { return _email; }
	void setEmail(string mail) { _email = mail; }
	string Tel() { return _tel; }
	void setTel(string tel) { _tel = tel; }
	string Address() { return _address; }
	void setAddress(string add) { _address = add; }
	string Password() { return _password; }
	void setPassword(string pass) { _password = pass; }
	double getSalary() {
		_salary = ((_level * 2000.0) + 16000.0) * _monthlyworkhour;
		return _salary;
	 }

public: // Nhóm hàm tính thời gian làm việc và lương
	// Tính thời gian làm việc trong một ngày (từ lúc checkin đến lúc checkout)
	static void calWorkHour(Employee *&a);
	// Sau khi làm việc 200 tiếng sẽ được lên level kế tiếp
	static void Leveling(Employee *&a);
	// Thời gian bắt đầu làm tính theo đồng hồ
	static void CheckIn(Employee *&a);
	// Thời gian kết thúc tính theo đồng hồ
	static void CheckOut(Employee *&a);
	// Tính lương trong tháng theo thời gian làm việc và cấp độ nhân viên
	static void calSalary(Employee *&a);

	// Hàm chức năng
	string toString();

public: // Hàm giao diện của nhân viên
	// Hàm đăng nhập với tư cách nhân viên
	static void loginAsEmployee();
	// Thông tin menu của nhân viên
	static void EmployeeMenu(Employee *&a);

public: // Nhóm hàm hiển thị dữ liệu đọc từ file
	// Đọc dữ liệu từ file EmployeeData.txt
	static vector<Employee *> LoadData();
	// In ra cả danh sách nhân viên
	static void showEmployeeData();
	// In ra thông tin của một nhân viên cụ thể
	static void showEmployeeInfo(Employee *&a);

public: // Nhóm hàm quản lí nhân viên
	// Đăng kí cho nhân viên nào đó
	static void SignUp();
	// Xoá nhân viên ra khỏi danh sách nhân viên
	static void deleteEmployee(Employee *emp);
	// Cập nhập lại danh sách nhân viên khi kết thúc phiên làm việc
	static void SaveEmployeeInfo(vector<Employee *> list);
	// Thay đổi thông tin nhân viên nhất định
	static void updateEmployeeInfo(Employee *a);
};

#endif