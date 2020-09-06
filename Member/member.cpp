#include "member.h"
#include <string>
#include <sstream>
#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;

void Member::loginasMember(vector<Member *> mem)
{
    Member *temp;
    string user, pass;
    do
    {
        cout << "Username: ";
        cin >> user;
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
            cout << "Sai ten dang nhap hoac sai mat khau, xin moi nhap lai!!";
        Sleep(1000);
    } while (pass != temp->Password());
    cout << "Dang nhap thanh cong! ";
    system("cls");
}

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

unsigned int Member::usingPoint(bool sure)
{
    if (sure == 1)
    {
        if (_point > 100)
            return (_point * 10000 / 100);
        else
            cout << "Khong co du diem!!";
    }
    else
        return 0;
}

void Member::addMember(string fileName, Member *mem)
{
    ofstream f;
    f.open("member.txt", ios::app);

    f << endl
      << mem->user() << " - " << mem->Password() << " - "
      << mem->ID() << " - " << mem->Name() << " - " << mem->Point()
      << " - " << mem->Level();

    f.close();
}
