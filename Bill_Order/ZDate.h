#ifndef _ZDATE_H_
#define _ZDATE_H_
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
class ZDate
{
private:
    int _day;
    int _month;
    int _year;

public:
    ZDate();
    ZDate(int, int, int);
    string toString();
    static ZDate parse(string);
    bool tryParse(string, ZDate &date);
    bool isValid(string);
    static bool isValid(int, int, int);
    static bool isLeapYear(int);
};
#endif // !_ZDATE_H_
