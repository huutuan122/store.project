#include "Date.h"
#include "Tokenizer.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string Date::toString(int i)
{
    stringstream writer;
    if (i == 1)
        writer << _day << "/" << _month << "/" << _year;
    else
        writer << _month << "/" << _day << "/" << _year;
    return writer.str();
}

Date Date::parse(string str)
{
    vector<int> arr = Tokenizer::convertToInt(str,"/");

    Date a;
    a.setDay(arr[0]);
    a.setMonth(arr[1]);
    a.setYear(arr[2]);

    return a;
}

bool Date::isLeapYear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool Date::tryParse(string str, Date &date)
{
    date = parse(str);
    int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isValid = true;

    if (isLeapYear(date._year))
        months[2] = 29;

    if (date._month > 12 || date._month < 0)
        isValid = false;
    else if (date._day > 31 || date._day < 0)
        isValid = false;
    else if (date._day > months[date._month])
        isValid = false;

    return isValid;
}

bool Date::isValid(string str)
{
    Date a;
    return tryParse(str, a);
}
