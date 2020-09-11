#include "system.h"
#include <windows.h>
#include "../Console/Common.h"
#include "../Console/interface.h"
#include "../Member/Tokenizer.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string Manager::toString()
{
    stringstream writer;
    writer << _username << " - " << _password << " - " << _name;
    return writer.str();
}

vector<Manager *> Manager::readManagerFile(string fileName)
{
    ifstream f;
    f.open(fileName);

    vector<Manager *> list;

    if (!f)
    {
        Common::gotoXY(40, 10);
        cout << "Khong the mo file quan li!";
    }

    string s;
    while (!f.eof())
    {
        Manager *manager = new Manager();
        getline(f, s);
        vector<string> str = TokenizerStr::split(s, " - ");
        manager->setUser(str[0]);
        manager->setPassword(str[1]);
        manager->setName(str[2]);

        list.push_back(manager);
    }

    f.close();
    return list;
}

void Manager::LoginAsManager()
{
    vector<Manager *> manager = readManagerFile("E:\\VSC\\C++\\Project Store\\github\\System\\manager.txt");
    Manager *temp = new Manager();
    string user, pass;
    do
    {
        system("cls");
        UserInterface::Screen();
        Common::gotoXY(55, 6);
        cout << "____HE THONG QUAN LI____";
        Common::gotoXY(40, 10);
        cout << "Username: ";
        cin >> user;
        Common::gotoXY(40, 12);
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
            Common::gotoXY(35, 16);
            cout << "Sai ten dang nhap hoac sai mat khau, xin moi nhap lai!! " << endl;
            Sleep(1000);
        }
        else
            break;
        Sleep(1000);

    } while (pass != temp->Password());
    Sleep(1000);
    Common::gotoXY(50, 16);
    cout << "Dang nhap thanh cong! ";
    Sleep(1000);
    ManagerMenu();
}

void Manager::ManagerMenu()
{
    system("cls");
    UserInterface::Screen();
    int choice;
    Common::gotoXY(51, 6);
    cout << "________MENU QUAN LI________";
    Common::gotoXY(40, 8);
    cout << "1.   Nhan vien";
    Common::gotoXY(40, 10);
    cout << "2.   Thanh vien";
    Common::gotoXY(40, 12);
    cout << "3.   Doanh thu thang";
    Common::gotoXY(40, 14);
    cout << "4.   Danh muc san pham";
    Common::gotoXY(40, 16);
    cout << "0.   Exit";

    Common::gotoXY(38, 20);
    cout << "Chon mot trong cac muc tren: ";

    do
    {
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            EmployeeSystem();
            choice = 0;
            break;
        }

        case 2:
        {
            MemberSystem();
            choice = 0;
            break;
        }

        case 3:
        {
            TotalIncome();
            choice = 0;
            break;
        }

        case 4:
        {
            break;
        }

        case 0:
        {
            Menu::SignIn();
        }
        }
    } while (choice != 0);
}

void Manager::EmployeeSystem()
{

    int choice;

    system("cls");
    UserInterface::Screen();
    Common::gotoXY(51, 6);
    cout << "______QUAN LI NHAN VIEN______";
    Common::gotoXY(40, 8);
    cout << "1.    Them nhan vien";
    Common::gotoXY(40, 10);
    cout << "2.    Xoa nhan vien";
    Common::gotoXY(40, 12);
    cout << "3.    Xem danh sach nhan vien";
    Common::gotoXY(40, 14);
    cout << "0.    Exit";
    Common::gotoXY(36, 16);
    cout << "Chon mot trong cac muc tren: ";
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            UserInterface::Screen();
            vector<Employee> list = Employee::LoadData();
            Employee::SignUp(list);
            Employee::SaveData(list);
            Common::gotoXY(35, 20);
            cout << "Them nhan vien thanh cong!";
            Sleep(1000);
            Common::gotoXY(35, 22);
            cout << "Nhan 0 de quay lai menu quan li: ";
            break;
        }
        case 2:
        {
            system("cls");
            UserInterface::Screen();
            vector<Employee> list = Employee::LoadData();
            Employee::showEmployeeData();
            Employee temp;
            string i;
            Common::gotoXY(30, 24);
            cout << "Chon ID nhan vien muon xoa: ";
            cin >> i;
            for (auto p : list)
            {
                if (p.ID() == i)
                {
                    Employee::deleteEmployee(p);
                }
            }
            Common::gotoXY(35, 26);
            cout << "Da xoa xong, nhan 0 de quay lai menu quan li: ";

            break;
        }
        case 3:
        {
            system("cls");
            UserInterface::Screen();
            Employee::showEmployeeData();
            Common::gotoXY(35, 26);
            cout << "Nhan 0 de quay lai menu quan li: ";
            break;
        }
        }
    } while (choice != 0);
    if (choice == 0)
    {
        Manager::ManagerMenu();
    }
}

void Manager::MemberSystem()
{
    int choice;

    system("cls");
    UserInterface::Screen();
    Common::gotoXY(51, 6);
    cout << "______QUAN LI THANH VIEN______";
    Common::gotoXY(40, 8);
    cout << "1.    Them thanh vien";
    Common::gotoXY(40, 10);
    cout << "2.    Xoa thanh vien";
    Common::gotoXY(40, 12);
    cout << "3.    Xem danh sach thanh vien";
    Common::gotoXY(40, 14);
    cout << "0.    Exit";
    Common::gotoXY(36, 16);
    cout << "Chon mot trong cac muc tren: ";
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            UserInterface::Screen();

            Member::addMember();

            Common::gotoXY(35, 22);
            cout << "Nhan 0 de quay lai menu quan li: ";
            break;
        }
        case 2:
        {
            system("cls");
            UserInterface::Screen();
            Member *mem = new Member();
            vector<Member *> list = Member::readMemberFile();
            Member::showMemberList();
            string i;
            Common::gotoXY(30, 24);
            cout << "Chon ID thanh vien muon xoa: ";
            cin >> i;
            for (auto p : list)
            {
                if (p->ID() == i)
                {
                    Member::deleteMember(p);
                }
            }
            Common::gotoXY(35, 26);
            cout << "Da xoa xong, nhan 0 de quay lai menu quan li: ";

            break;
        }
        case 3:
        {
            system("cls");
            UserInterface::Screen();
            Member::showMemberList();

            Common::gotoXY(35, 26);
            cout << "Nhan 0 de quay lai menu quan li: ";
            break;
        }
        }
    } while (choice != 0);
    if (choice == 0)
    {
        Manager::ManagerMenu();
    }
}

void Manager::TotalIncome()
{
}
