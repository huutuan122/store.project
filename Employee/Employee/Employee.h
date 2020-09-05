#pragma once
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<fstream>
#include"Time.h"

using namespace std;

class Employee {
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
	Employee(string id, string name, string dob, string tel, string email, string add, double workour, double totalhour, int level, string pass);
	string Name();
	void setName(string name);
	string ID();
	void setID(string id);
	string DOB();
	void setDOB(string dob);
	string Email();
	void setEmail(string mail);
	string Tel();
	void setTel(string tel);
	string Address();
	void setAddress(string add);
	string Password();
	void setPassword(string pass);
	double getSalary();
	double MonthlyWorkHours();
	int Level();
public:
	void calWorkHour();
	void Leveling();
	void CheckIn();
	void CheckOut();
	static void EmployeeMenu();
	static void editInfo(vector<Employee> &list, int pos);
	static int isAccess(vector<Employee> list);
	static void SignUp(vector<Employee>& list);
	static vector<Employee> LoadData();
	static void SaveData(vector<Employee> list);
	string toString();
	void calSalary();
};
