#include <string>
#include <ctime>
using namespace std;

#ifndef _DATE_H_
#define _DATE_H_

class Date
{
private: // Attributes
    int _day;
    int _month;
    int _year;

public: //Getter - Setter
    void setDay(int value) { _day = value; }
    void setMonth(int value) { _month = value; }
    void setYear(int value) { _year = value; }
    int getDay() { return _day; }
    int getMonth() { return _month; }
    int getYear() { return _year; }

public: // Constructor
    Date()
    {
        time_t info = time(NULL);
        tm *now = localtime(&info);
        _day = now->tm_mday;
        _month = now->tm_mon + 1;
        _year = now->tm_year + 1900;
    }

    Date(int day, int month, int year)
    {
        _day = day;
        _month = month;
        _year = year;
    }

public: // Methods
    string toString(int);
    static Date parse(string);
    static bool tryParse(string, Date &);
    static bool isValid(string);
    static bool isLeapYear(int);
};

#endif