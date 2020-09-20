#include "ZTime.h"

int ZTime::hour() { return _hour; }
int ZTime::minute() { return _minute; }
int ZTime::second() { return _second; }

void ZTime::setHour(int value) { _hour = value; }
void ZTime::setMinute(int value) { _minute = value; }
void ZTime::setSecond(int value) { _second = value; }

ZTime::ZTime()
{
    time_t info = time(NULL);
    tm *now = localtime(&info);
    _hour = now->tm_hour;
    _minute = now->tm_min;
    _second = now->tm_sec;
}

ZTime::ZTime(int h, int m, int s)
{
    if (h < 0 || m < 0 || s < 0 || h > 23 || m > 59 || s > 60)
    {
        cout << "Invalid time! Time is set by default!\n";
        time_t info = time(NULL);
        tm *now = localtime(&info);
        _hour = now->tm_hour;
        _minute = now->tm_min;
        _second = now->tm_sec;
    }
    else
    {
        _hour = h;
        _minute = m;
        _second = s;

        if (_second == 60)
        {
            _minute++;
            _second = 0;
            if (_minute == 60)
            {
                _hour++;
                _minute = 0;
                if (_hour == 24)
                {
                    _hour = 0;
                }
            }
        }
    }
}

string ZTime::displayIn24hFormat()
{
    stringstream out;
    out << setfill('0') << setw(2) << _hour << ":" << setw(2) << _minute << ":" << setw(2) << _second;
    return out.str();
}

string ZTime::displayIn12hFormat()
{
    string format;
    stringstream out;

    if (_hour > 11)
    {
        _hour -= 12;
        format = "PM";
    }
    else
        format = "AM";

    out << setfill('0') << setw(2) << _hour << ":" << setw(2) << _minute << ":" << setw(2) << _second << " " << format;

    return out.str();
}

ZTime ZTime::parse(string time)
{
    ZTime temp;
    temp._hour = stoi(time.substr(0, time.find(":")));
    time = time.substr(time.find(":") + 1, time.size());
    temp._minute = stoi(time.substr(0, time.find(":")));
    time = time.substr(time.find(":") + 1, time.size());
    temp._second = stoi(time);
    if (temp._hour < 0 || temp._minute < 0 || temp._second < 0 || temp._hour > 23 || temp._minute > 59 || temp._second > 60)
    {
        cout << "Invalid time!\n";
        throw 0;
    }
    return temp;
}

bool ZTime::tryParse(string time, ZTime &result)
{
    bool flag = true;
    try
    {
        if (!isValid(time))
            throw 0;
        else
        {
            result._hour = stoi(time.substr(0, time.find(":")));
            time = time.substr(time.find(":") + 1, time.size());
            result._minute = stoi(time.substr(0, time.find(":")));
            time = time.substr(time.find(":") + 1, time.size());
            result._second = stoi(time);
        }
    }
    catch (const int &ex)
    {
        cout << "Invalid time!\n";
        flag = ex;
    }
    return flag;
}

bool ZTime::isValid(string time)
{
    int temp;
    bool flag = true;
    temp = stoi(time.substr(0, time.find(":")));
    if (temp > 23 || temp < 0)
        flag = false;
    time = time.substr(time.find(":") + 1, time.size());
    temp = stoi(time.substr(0, time.find(":")));
    if (temp > 59 || temp < 0)
        flag = false;
    time = time.substr(time.find(":") + 1, time.size());
    temp = stoi(time);
    if (temp > 60 || temp < 0)
        flag = false;
    return flag;
}
