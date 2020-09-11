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

using namespace std;

vector<Member *> Member::readMemberFile(string fileName)
{
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

void Member::loginasMember()
{
    vector<Member *> mem = Member::readMemberFile("E:\\VSC\\C++\\Project Store\\github\\Member\\member.txt");
    Member *temp = new Member();
    string user, pass;
    do
    {
        system("cls");
        UserInterface::Screen();
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
            Common::gotoXY(38, 14);
            cout << "Dang nhap thanh cong! ";
        }
        Sleep(1000);

    } while (pass != temp->Password());

    // system("cls");
}

string Member::toString()
{
    stringstream writer;
    writer << _user << " - " << _password << " - "
           << _name << " - " << _point << " - " << _level;
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

int Member::usingPoint(bool sure)
{
    if (sure == 1)
    {
        if (_point > 100)
            return (_point * 10000 / 100);
        else
            cout << "Khong co du diem!!";
    }
    return 0;
}

void Member::addMember(string fileName, Member *mem)
{
    ofstream f;
    f.open("member.txt", ios::app);

    f << endl
      << mem->user() << " - " << mem->Password() << " - "
      << " - " << mem->Name() << " - " << mem->Point()
      << " - " << mem->Level();

    f.close();
}

// vector<Member *> Member::readMemberFile(string fileName)
// {

// }

void Member::registerMember(Member *&mem)
{
    string s;
    cout << "Nhap ten dang nhap: ";
    cin >> s;
    mem->setUser(s);
    cout << "Nhap mat khau: ";
    cin >> s;
    mem->setPassword(s);
    cout << "Dang nhap thanh cong! " << endl;
    Sleep(1000);

    cout << "Nhap ten cua ban: ";
    getline(cin, s);
    getline(cin, s);
    mem->setName(s);
    cout << "Diem tich luy ban dau cua ban la 0, cap do thanh vien la Dong!!" << endl;
    mem->setPoint(0);
    mem->setLevel("Bronze");
    system("cls");
}