#include "Date.h"
Date::Date() {
	time_t info = time(NULL);
	tm* now = localtime(&info);
	_day = now->tm_mday;
	_month = 1 + now->tm_mon;
	_year = 1900 + now->tm_year;
}

Date::Date(int d, int m, int y) {
	if (isValid(d, m, y))
	{
		_day = d;
		_month = m;
		_year = y;
	}
	else {
		cout << "Invalid date! Date is set by default!\n";
		time_t info = time(NULL);
		tm* now = localtime(&info);
		_day = now->tm_mday;
		_month = 1 + now->tm_mon;
		_year = 1900 + now->tm_year;
	}
}

string Date::toString() {
	stringstream out;
	out << setfill('0') << setw(2) << _day << "/" << setw(2) << _month << "/" << setw(2) << _year << "\n";
	return out.str();
}

Date Date::parse(string date) {
	Date temp;
	temp._day = stoi(date.substr(0, date.find("/")));
	date = date.substr(date.find("/") + 1, date.size());
	temp._month = stoi(date.substr(0, date.find("/")));
	date = date.substr(date.find("/") + 1, date.size());
	temp._year = stoi(date);
	if (!isValid(temp._day, temp._month, temp._year)) throw 0;
	return temp;
}

bool Date::tryParse(string date, Date& result) {
	bool flag = true;
	if (isValid(date)) {
		result._day = stoi(date.substr(0, date.find("/")));
		date = date.substr(date.find("/") + 1, date.size());
		result._month = stoi(date.substr(0, date.find("/")));
		date = date.substr(date.find("/") + 1, date.size());
		result._year = stoi(date);
	}
	else {
		cout << "Invalid date!\n";
		flag = false;
	}
	return flag;
}

bool Date::isValid(string date) {
	Date temp;
	bool flag = true;

	temp._day = stoi(date.substr(0, date.find("/")));
	date = date.substr(date.find("/") + 1, date.size());
	temp._month = stoi(date.substr(0, date.find("/")));
	date = date.substr(date.find("/") + 1, date.size());
	temp._year = stoi(date);

	flag = isValid(temp._day, temp._month, temp._year);

	return flag;
}

bool Date::isValid(int d, int m, int y) {
	bool flag = true;

	int daysInMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(y)) daysInMonth[2] = 29;

	if (y < 1900) flag = false;
	if (m <= 12) {
		if (d > daysInMonth[m]) flag = false;
	}
	else
		flag = false;

	return flag;
}

bool Date::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}