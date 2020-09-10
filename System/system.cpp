#include "system.h"
#include <windows.h>

using namespace std;

void LoginAsMember::login(vector<Member *> mem)
{
    Member *temp = new Member();
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
        {
            cout << "Sai ten dang nhap hoac sai mat khau, xin moi nhap lai!! " << endl;
            Sleep(1000);
            system("cls");
        }
        else
            cout << "Dang nhap thanh cong! ";
        Sleep(1000);

    } while (pass != temp->Password());
}

void LoginAsManager::login(vector<Manager *> manager)
{
    Manager *temp = new Manager();
    string user, pass;
    do
    {
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;
        for (auto p : manager)
        {
            if (user == p->Username())
            {
                temp->setUser(p->Username());
                temp->setPassword(p->Password());
            }
        }

        if (pass != temp->Password())
        {
            cout << "Sai ten dang nhap hoac sai mat khau, xin moi nhap lai!! " << endl;
            Sleep(1000);
            system("cls");
        }
        else
            cout << "Dang nhap thanh cong! ";
        Sleep(1000);

    } while (pass != temp->Password());
}