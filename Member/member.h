#include <string>
#include <vector>
#include "Tokenizer.h"
using namespace std;

#ifndef _MEMBER_H_
#define _MEMBER_H_

class Member
{
private:
    string _user;
    string _name;
    string _password;
    int _point;
    string _level;

public: // getter - setter
    void setUser(string user) { _user = user; }
    string user() { return _user; }

    void setName(string name) { _name = name; }
    string Name() { return _name; }

    string Password() { return _password; }
    void setPassword(string value) { _password = value; }
    
    void setPoint(int point) { _point = point; }
    int Point() { return _point; }

    void setLevel(string level) { _level = level; }
    string Level() { return _level; }

public:
    Member()
    {
        _user = "";
        _name = "";
        _password = "1";
        _point = 0;
        _level = 'B';
    }

    Member(string user, string id, string name, string password, int point)
    {
        _user = user;
        _name = name;
        _password = password;
        _point = point;
        if (_point < 100)
            _level = "Bronze";
        else if (_point > 100 && _point < 200)
            _level = "Silve";
        else if (_point > 200 && _point < 300)
            _level = "Gold";
        else
            _level = "Diamond";
    }

public:
    static void loginasMember(vector<Member *> mem);
    string toString();
    void accumulatePoint(unsigned int purchase);
    int usingPoint(bool sure);
    static void addMember(string fileName, Member *mem);
    void updateMemberInfo(string fileName, Member *&mem);
    static vector<Member *> readMemberFile(string fileName){
        ifstream f;
        f.open(fileName);
        vector<Member *> list;
        string s;
        while (!f.eof())
        {
            getline(f, s);
            vector<string> getStr;
            string sep = " - ";
            getStr = TokenizerStr::split(s, sep);
            Member *temp = new Member();
            temp->setUser(getStr[0]);
            temp->setPassword(getStr[1]);
            temp->setName(getStr[2]);

            int point = stoi(getStr[3]);
            temp->setPoint(point);

            temp->setLevel(getStr[4]);

            list.push_back(temp);
        }
        f.close();

        return list;
    }
    static void registerMember(Member*& mem);
};

#endif