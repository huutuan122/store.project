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

public: // Hàm chức năng
    // Đọc file thông tin của quản lí
    static vector<Manager *> readManagerFile(string fileName);
    string toString();

public: // Hàm giao diện quản lí
    // Menu của quản lí khi đăng nhập xong
    static void ManagerMenu();
    // Đăng nhập với tư cách quản lí
    static void LoginAsManager();

public: // Hàm công việc của quản lí
    // Quản lí nhân viên
    static void EmployeeSystem();
    // Quản lí hội viên
    static void MemberSystem();
    // Quản lí thu nhập cửa hàng
    static void TotalIncome();
};

#endif