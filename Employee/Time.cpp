#include "../Employee/Time.h"

Time::Time() {}

void Time::getTime()
{
	time_t info = time(NULL);
#pragma warning(suppress : 4996)
	tm *now = localtime(&info);
	_hour = now->tm_hour;
	_minute = now->tm_min;
	_second = now->tm_sec;
	_day = now->tm_mday;
	_month = now->tm_mon;
	_year = now->tm_year;
}

Time::Time(int hour, int minute, int second)
{
	_hour = hour;
	_minute = minute;
	_second = second;
}

int Time::Hour()
{
	return _hour;
}
int Time::Minute()
{
	return _minute;
}

int Time::Second()
{
	return _second;
}