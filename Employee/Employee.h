
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "../Employee/Time.h"

using namespace std;
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

class Employee
{
private:
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

public:
	Employee();
	Employee(string, string, string, string, string, string, double, double, int, string);
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
	double getSalary() { return _salary; }

public:
	static void calWorkHour(Employee *&a);
	static void Leveling(Employee* &a);
	static void CheckIn(Employee* &a);
	static void CheckOut(Employee* &a);
	static void calSalary(Employee* &a);
	string toString();
	static void showEmployeeData();
	static void EmployeeMenu(Employee *&a);
	static void showEmployeeInfo(Employee *&a);
	static vector<Employee *> LoadData();
	static void SignUp(vector<Employee *> &list);
	static void deleteEmployee(Employee* emp);
	static void SaveEmployeeInfo(vector<Employee*> list);
	static void updateEmployeeInfo(Employee* a);
	static void loginAsEmployee();
};

#endif