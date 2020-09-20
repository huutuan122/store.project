#pragma once
#include <ctime>
#include <sstream>
#include <string>

class Time
{
private:
	int _hour;
	int _minute;
	int _second;
	int _day;
	int _month;
	int _year;

public:
	Time();
	Time(int hour, int minute, int second);
	int Hour();
	int Minute();
	int Second();
	void getTime();
	string toString()
	{
		stringstream out;
		out << _day << "/" << _month << "/" << _year << " - "
			<< _hour << ":" << _minute << ":" << _second;
		return out.str();
	}
};