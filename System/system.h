#include "../Member/member.h"
#include "../Employee/Employee.h"
#include "../Utility/Date.h"
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

public: // Setter - Getter
    void setUser(string user) { _username = user; }
    string Username() { return _username; }

    void setPassword(string pass) { _password = pass; }
    string Password() { return _password; }

    void setName(string name) { _name = name; }
    string Name() { return _name; }

public: // Constructor
    Manager()
    {
        _username = "";
        _password = "";
        _name = "Nguyen Van A";
    }

public:
    string toString();
    static void LoginAsManager();
    static vector<Manager *> readManagerFile(string fileName);
    static void ManagerMenu();
    static void EmployeeSystem();
    static void MemberSystem();
    static void TotalIncome();
};

#endif