#include "member.h"
#include <string>
#include <sstream>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "../Member/Tokenizer.h"
#include "../Console/interface.h"
#include "../Console/Common.h"
#include "../Discount/Discount.cpp"
#include "../Bill_Order/Order.h"
#include "../Bill_Order/Bill.h"
#include "../Utility/util.h"

using namespace std;

// Hàm chức năng
string Member::toString()
{
    stringstream writer;
    writer << _id << " - " << _user << " - " << _password << " - "
           << _name << " - " << _point << " - " << _level;
    return writer.str();
}

// Nhóm hàm quản lí
void Member::deleteMember(Member *mem)
{
    int i = 0;
    vector<Member *> list = readMemberFile();
    for (auto p : list)
    {
        if (p->ID() == mem->ID())
        {
            list.erase(list.begin() + i);
        }
        i++;
    }

    for (int i = 0; i < list.size(); i++)
    {
        list[i]->setID(to_string(i + 1));
    }

    saveMemberInfo(list);
}

void Member::addMember()
{
    Common::color(14);
    Member *mem = new Member();
    vector<Member *> list = readMemberFile();
    Common::gotoXY(49, 4);
    cout << "----------Hoan tat cac thong tin sau----------" << endl;

    mem->setID(to_string(list.size() + 1));
    string str;
    Common::gotoXY(40, 6);
    cout << "Nhap ten dang nhap: ";
    cin >> str;
    mem->setUser(str);

    Common::gotoXY(40, 8);
    cout << "Nhap mat khau: ";
    cin >> str;
    mem->setPassword(str);

    Common::gotoXY(40, 10);
    cout << "Nhap ten: ";
    getline(cin, str);
    getline(cin, str);
    mem->setName(str);

    Sleep(1000);
    Common::gotoXY(40, 12);
    cout << "Them thanh cong!";
    mem->setPoint(0);
    mem->setLevel("Bronze");

    list.push_back(mem);
    saveMemberInfo(list);
}

void Member::saveMemberInfo(vector<Member *> list)
{
    ofstream f;
    f.open(Util::path() + "\\Member\\member.txt", ios::out);

    f << list[0]->toString();
    for (int i = 1; i < list.size(); i++)
    {
        f << endl
          << list[i]->toString();
    }

    f.close();
}

void Member::updateMemberInfo(Member *member)
{
    vector<Member *> list = readMemberFile();
    for (auto p : list)
    {
        if (p->user() == member->user())
        {
            p->setID(member->ID());
            p->setLevel(member->Level());
            p->setName(member->Name());
            p->setPassword(member->Password());
            p->setPoint(member->Point());
        }
    }

    saveMemberInfo(list);
}

// Nhóm hàm đọc và in màn hình từ file
vector<Member *> Member::readMemberFile()
{
    ifstream f;
    f.open(Util::path() + "\\Member\\member.txt");
    vector<Member *> list;
    string s;

    while (!f.eof())
    {
        getline(f, s);
        vector<string> getStr;
        string sep = " - ";
        getStr = TokenizerStr::split(s, sep);
        Member *temp = new Member();
        temp->setID(getStr[0]);
        temp->setUser(getStr[1]);
        temp->setPassword(getStr[2]);
        temp->setName(getStr[3]);

        int point = stoi(getStr[4]);
        temp->setPoint(point);

        temp->setLevel(getStr[5]);

        list.push_back(temp);
    }
    f.close();

    return list;
}

void Member::showMemberInfo(Member *&member)
{
    Common::color(14);
    int choice;

    do
    {
        system("cls");
        UserInterface::Screen();
        Common::gotoXY(49, 6);
        cout << "---------- THONG TIN THANH VIEN ----------";
        Common::gotoXY(36, 10);
        cout << "1)     ID: " << member->ID();
        Common::gotoXY(36, 12);
        cout << "2)     Ten hoi vien: " << member->Name();
        Common::gotoXY(36, 14);
        cout << "3)     Ten dang nhap: " << member->user();
        Common::gotoXY(36, 16);
        cout << "4)     Mat khau: " << member->Password();
        Common::gotoXY(36, 18);
        cout << "5)     Diem hoi vien: " << member->Point();
        Common::gotoXY(36, 20);
        cout << "6)     Hang hoi vien: " << member->Level();
        Common::gotoXY(30, 24);
        cout << "Ban muon chinh sua phan nao? Chon mot muc hoac nhan '0' de quay lai: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Common::gotoXY(40, 26);
            cout << "Khong chinh sua ID duoc!";
            Sleep(1000);
            break;
        }
        case 2:
        {
            system("cls");
            UserInterface::Screen();
            Common::gotoXY(30, 14);
            string s;
            cout << "Nhap ten ban muon chinh sua: ";
            getline(cin, s);
            getline(cin, s);
            Common::gotoXY(40, 26);
            cout << "Sua ten thanh cong!";
            member->setName(s);
            Sleep(1000);
            break;
        }
        case 3:
        {
            Common::gotoXY(40, 26);
            cout << "Khong chinh sua ten dang nhap duoc!";
            Sleep(1000);
            break;
        }
        case 4:
        {
            system("cls");
            UserInterface::Screen();
            Common::gotoXY(30, 14);
            string s;
            cout << "Nhap mat khau muon chinh sua: ";
            cin >> s;
            Common::gotoXY(40, 26);
            cout << "Sua mat khau thanh cong!";
            member->setPassword(s);
            Sleep(1000);
            break;
        }
        case 5:
        {
            Common::gotoXY(40, 26);
            cout << "Khong chinh sua diem hoi vien duoc!";
            Sleep(1000);
            break;
        }
        case 6:
        {
            Common::gotoXY(40, 26);
            cout << "Khong chinh sua hang hoi vien duoc!";
            Sleep(1000);
            break;
        }
        }
    } while (choice != 0);
    updateMemberInfo(member);
    if (choice == 0)
        return;
}

void Member::showMemberList()
{
    Common::color(14);
    vector<Member *> list = readMemberFile();
    int i = 4;
    Common::gotoXY(52, 2);
    cout << "_______DANH SACH NHAN VIEN_______";
    for (auto p : list)
    {
        Common::gotoXY(15, i);
        cout << p->toString();
        i++;
    }
}

// Nhóm hàm đăng nhập và giao diện

void Member::loginasMember()
{
    Common::color(14);
    vector<Member *> mem = Member::readMemberFile();
    Member *temp = new Member();
    string user, pass;
    do
    {
        system("cls");
        UserInterface::Screen();
        Common::gotoXY(49, 6);
        cout << "---------- DANG NHAP HOI VIEN ----------";
        Common::gotoXY(40, 10);
        cout << "Username: ";
        cin >> user;
        Common::gotoXY(40, 12);
        cout << "Password: ";
        cin >> pass;
        for (auto p : mem)
        {
            if (user == p->user())
            {
                temp->setUser(p->user());
                temp->setPassword(p->Password());
                temp->setID(p->ID());
                temp->setLevel(p->Level());
                temp->setName(p->Name());
                temp->setPoint(p->Point());
            }
        }

        if (pass != temp->Password())
        {
            Common::gotoXY(38, 14);
            cout << "Sai ten dang nhap hoac sai mat khau, xin moi nhap lai!! " << endl;
            Sleep(1000);
            system("cls");
        }
        else
        {
            Common::gotoXY(49, 14);
            cout << "Dang nhap thanh cong! ";
        }
        Sleep(1000);

    } while (pass != temp->Password());

    Member::MemberMenu(temp);
}

void Member::MemberMenu(Member *&user)
{
    Common::color(14);
    OrderStore orderList;
    int choice;
    do
    {
        system("cls");
        UserInterface::Screen();
        Common::gotoXY(49, 6);
        cout << "---------- MENU THANH VIEN ----------";
        Common::gotoXY(40, 8);
        cout << "1)     Mua hang";
        Common::gotoXY(40, 10);
        cout << "2)     Xem uu dai";
        Common::gotoXY(40, 12);
        cout << "3)     Xem thong tin hoi vien";
        Common::gotoXY(40, 14);
        cout << "0)     Thoat";
        Common::gotoXY(38, 18);
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Menu::Muahang(1, user->Name(), orderList);
            break;
        }
        case 2:
        {
            Discount::showVoucher();
            break;
        }
        case 3:
        {
            Member::showMemberInfo(user);
            break;
        }
        }
    } while (choice != 0);
    if (choice == 0)
    {
        Menu::SignIn();
    }
    // delete orderList;
}

void Member::registerMember(Member *&mem)
{
    system("cls");
    UserInterface::Screen();
    Common::color(14);
    vector<Member *> list = readMemberFile();
    string s;
    Common::gotoXY(49, 6);
    cout << "----------DANG KY HOI VIEN----------";
    Common::gotoXY(40, 10);
    cout << "Nhap ten dang nhap: ";
    cin >> s;
    mem->setUser(s);
    Common::gotoXY(40, 12);
    cout << "Nhap mat khau: ";
    cin >> s;
    mem->setPassword(s);
    Common::gotoXY(40, 14);
    cout << "Dang ky thanh cong! " << endl;
    Sleep(1000);
    Common::gotoXY(40, 16);
    cout << "Nhap ten cua ban: ";
    getline(cin, s);
    getline(cin, s);
    mem->setName(s);
    Common::gotoXY(40, 18);
    cout << "Diem tich luy ban dau cua ban la 0, cap do thanh vien la Dong!!";
    Sleep(1000);
    mem->setPoint(0);
    mem->setLevel("Bronze");
    mem->setID(to_string(list.size() + 1));
    list.push_back(mem);
    saveMemberInfo(list);
    Common::gotoXY(30, 26);
    int i;
    cout << "Nhan '0' de tro lai: ";
    cin >> i;
    if (i == 0)
        UserInterface::MainMenu();
}

// Nhóm hàm quyền lợi của hội viên
void Member::accumulatePoint(unsigned int purchase, Member *&member)
{
    int point = purchase / 10000 * 1;
    member->setPoint(member->Point() + point);
    point = member->Point();
    if (point > 100 && point < 200)
        member->setLevel("Silver");
    else if (point > 200 && point < 300)
        member->setLevel("Gold");
    else
        member->setLevel("Diamond");
}

int Member::usingPoint(bool sure)
{
    Common::color(14);
    if (sure == 1)
    {
        if (_point > 100)
            return (_point * 10000 / 100);
        else
            cout << "Khong co du diem!!";
    }
    return 0;
}
