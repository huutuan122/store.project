#pragma once
#include<ctime>

class Time {
private:
	int _hour;
	int _minute;
	int _second;
public:
	Time();
	Time(int hour, int minute, int second);
	int Hour();
	int Minute();
	int Second();
	void getTime();
};