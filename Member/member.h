#include <string>
#include <vector>
using namespace std;

#ifndef _MEMBER_H_
#define _MEMBER_H_

class Member
{
private:
    string _user;
    string _id;
    string _name;
    string _password;
    int _point;
    char _level;

public: // getter - setter
    void setUser(string user) { _user = user; }
    string user() { return _user; }

    void setID(string id) { _id = id; }
    string ID() { return _id; }

    void setName(string name) { _name = name; }
    string Name() { return _name; }

    string Password() { return _password; }
    void setPassword(string value) { _password = value; }
    void setPoint(int point) { _point = point; }
    int Point() { return _point; }
    char Level() { return _level; }

public:
    Member()
    {
        _user = "";
        _id = "";
        _name = "";
        _password = "1";
        _point = 0;
        _level = 'B';
    }

    Member(string user, string id, string name, string password, int point)
    {
        _user = user;
        _id = id;
        _name = name;
        _password = password;
        _point = point;
        if (_point < 100)
            _level = 'B';
        else if (_point > 100 && _point < 200)
            _level = 'S';
        else if (_point > 200 && _point < 300)
            _level = 'G';
        else
            _level = 'D';
    }

public:
    static void loginasMember(vector<Member *> mem);
    string toString();
    void accumulatePoint(unsigned int purchase);
    unsigned int usingPoint(bool sure);
    void addMember(string fileName, Member *mem);
    void updateMemberInfo(string fileName, Member *&mem);
};

#endif