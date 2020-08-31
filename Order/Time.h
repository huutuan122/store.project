#ifndef _TIME_H_
#define _TIME_H_
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

class Time {
private:
	int _hour, _minute, _second;
public:
	int hour();
	void setHour(int);
	int minute();
	void setMinute(int);
	int second();
	void setSecond(int);
public:
	Time();
	Time(int, int, int);
	string displayIn24hFormat();
	string displayIn12hFormat();
	Time parse(string);
	bool tryParse(string, Time &result);
	bool isValid(string);
};


#endif // !_TIME_H_
