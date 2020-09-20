#ifndef _ZTIME_H_
#define _ZTIME_H_
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

class ZTime
{
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
    ZTime();
    ZTime(int, int, int);
    string displayIn24hFormat();
    string displayIn12hFormat();
    static ZTime parse(string);
    bool tryParse(string, ZTime &result);
    bool isValid(string);
};

#endif // !_ZTIME_H_
