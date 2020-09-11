#ifndef _DATE_H_
#define _DATE_H_
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	Date(int, int, int);
	string toString();
	static Date parse(string);
	bool tryParse(string, Date& date);
	bool isValid(string);
	static bool isValid(int, int, int);
	static bool isLeapYear(int);
};
#endif // !_DATE_H_
