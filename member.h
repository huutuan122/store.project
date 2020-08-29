#include <string>
using namespace std;

#ifndef _MEMBER_H_
#define _MEMBER_H_

class member
{
private:
    string _user;
    string _id;
    string _name;
    int _point;

public: // getter - setter
    void setUser(string user) { _user = user; }
    string user() { return _user; }
    void setID(string id) { _id = id; }
    string ID() { return _id; }
    void setName(string name) { _name = name; }
    string Name() { return _name; }
    void setPoint(int point) { _point = point; }
    int Point() { return _point; }

public:
    void accumulatePoint(unsigned int purchase);
};

#endif