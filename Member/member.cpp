#include "member.h"
#include <string>
#include <sstream>

using namespace std;

string Member::toString()
{
    stringstream writer;
    writer << _user << " _ " << _password << " _ "
           << _name << " _ " << _point << " _ " << _level;
    return writer.str();
}

void Member::accumulatePoint(unsigned int purchase)
{
    _point = purchase / 10000 * 1;
    if (_point > 100 && _point < 200)
        _level = 'S';
    else if (_point > 200 && _point < 300)
        _level = 'G';
    else
        _level = 'D';
}
