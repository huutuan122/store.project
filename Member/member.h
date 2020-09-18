#include <string>
#include <vector>
#include "Tokenizer.h"
#include "../Discount/Discount.h"

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
    string _id;

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

    void setID(string id) { _id = id; }
    string ID() { return _id; }

public: // Constructor
    Member()
    {
        _user = "";
        _name = "";
        _password = "1";
        _point = 0;
        _level = 'B';
        _id = "";
    }

    Member(string user, string id, string name, string password, int point)
    {
        _user = user;
        _name = name;
        _password = password;
        _point = point;
        _id = id;
        if (_point < 100)
            _level = "Bronze";
        else if (_point > 100 && _point < 200)
            _level = "Silve";
        else if (_point > 200 && _point < 300)
            _level = "Gold";
        else
            _level = "Diamond";
    }

public: // Hàm chức năng
    string toString();

public: // Nhóm hàm quản lí thành viên
    // Xoá thành viên
    static void deleteMember(Member *mem);
    // Thêm thành viên
    static void addMember();
    // Lưu danh sách thành viên
    static void saveMemberInfo(vector<Member *> list);
    // Sửa thông tin thành viên
    static void updateMemberInfo(Member *mem);

public: // Nhóm hàm quyền lợi thành viên
    static void accumulatePoint(unsigned int purchase, Member *&member);
    int usingPoint(bool sure);

public: // Nhóm hàm đọc và in màn hình từ file
    static vector<Member *> readMemberFile();
    // Dành cho một người cụ thể
    static void showMemberInfo(Member *&user);
    // Dành cho quản lí
    static void showMemberList();

public: // Nhóm hàm đăng nhập và giao diện
    // Đăng nhập với tư cách hội viên
    static void loginasMember();
    // Đăng kí hội viên
    static void registerMember(Member *&mem);
    // Giao diện của hội viên
    static void MemberMenu(Member *&user);
};

#endif