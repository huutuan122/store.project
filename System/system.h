#include "Member/member.h"
#include "Employee/Employee.h"
#include "Utility/Date.h"
#include <vector>
#include <string>
using namespace std;

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

class Manager
{
private: // Attributes
    string _username;
    string _password;
    string _name;
    string _dob;

public: // Setter - Getter
    void setUser(string user) { _username = user; }
    string Username() { return _username; }

    void setPassword(string pass) { _password = pass; }
    string Password() { return _password; }

    void setName(string name) { _name = name; }
    string Name() { return _name; }

    void setDob(string dob) { _dob = dob; }
    string Dob() { return _dob; }

public: // Constructor
    Manager()
    {
        _username = "";
        _password = "";
        _name = "Nguyen Van A";
        _dob = "12/02/2001";
    }
};

class Login
{
public:
    virtual void login() = 0;
};

class LoginAsManager : public Login
{
public:
    static void login(vector<Manager *> manager);
};

class LoginAsMember : public Login
{
public:
    static void login(vector<Member *> mem);
};

class LoginAsEmployee : public Login
{
public:
    static void login();
};

#endif