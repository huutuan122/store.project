#include "system.h"
#include <windows.h>
#include "../Console/Common.h"
#include "../Console/interface.h"
#include "../Member/Tokenizer.h"
#include <string>
#include <sstream>
#include <vector>
#include "../Discount/Discount.h"
#include "../Profit/profit.h"
#include "../Profit/profit.cpp"
#include "../Utility/util.h"
using namespace std;

// Hàm chức năng
string Manager::toString()
{
    stringstream writer;
    writer << _username << " - " << _password << " - " << _name;
    return writer.str();
}

vector<Manager *> Manager::readManagerFile()
{
    ifstream f;
    f.open( "manager.txt");

    vector<Manager *> list;

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

// Hàm giao diện quản lí
void Manager::LoginAsManager()
{
    Common::color(14);
    vector<Manager *> manager = readManagerFile();
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
    Common::color(14);
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
    cout << "4.   Them khuyen mai";
    Common::gotoXY(40, 16);
    cout << "5.   Hang hoa";
    Common::gotoXY(40, 18);
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
            Manager::EmployeeSystem();
            choice = 0;
            break;
        }

        case 2:
        {
            Manager::MemberSystem();
            choice = 0;
            break;
        }

        case 3:
        {
            Manager::TotalIncome();
            choice = 0;
            break;
        }

        case 4:
        {
            Discount::addVoucher();
            choice = 0;
            break;
        }

        case 5:
        {
            Manager::GoodManagement();
            choice = 0;
            break;
        }
        case 0:
        {
            Menu::SignIn();
            break;
        }
        default:
        {
            choice = 0;
        }
        }
    } while (choice != 0);
}

// Hàm công việc quản lí
void Manager::EmployeeSystem()
{
    int choice;
    Common::color(14);
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
            // vector<Employee *> list = Employee::LoadData();
            Employee::SignUp();
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
            vector<Employee *> list = Employee::LoadData();
            Employee::showEmployeeData();
            Employee temp;
            string i;
            Common::gotoXY(30, 24);
            cout << "Chon ID nhan vien muon xoa: ";
            cin >> i;
            for (auto p : list)
            {
                if (p->ID() == i)
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
    Common::color(14);
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
    system("cls");
    UserInterface::Screen();
    Common::color(14);
    Common::gotoXY(49, 6);
    cout << "---------DOANH THU THANG----------";
    Common::gotoXY(35, 10);
    cout << "Tong tien luong nhan vien la: " << Profit::caltotalSalary();
    Common::gotoXY(35, 12);
    cout << "Tong tien hoa don thu ve la: " << Profit::totalBillSold();
    Common::gotoXY(35, 14);
    cout << "Tong tien thu ve duoc (chua tinh tien dau tu) la: " << Profit::totalIncome();

    Common::gotoXY(35, 26);
    cout << "Nhan '0' de quay lai: ";
    int i;
    cin >> i;

    if (i == 0)
        Manager::ManagerMenu();
}

void Manager::GoodManagement()
{
    int choice;
    Menu menu;
    Common::color(14);
    menu.data = GoodList::readGoodListFromFile("GoodList.txt",  "Rate.txt", "Comment.txt");
    system("cls");
    UserInterface::Screen();
    Common::gotoXY(51, 6);
    cout << "______QUAN LI SAN PHAM______";
    Common::gotoXY(40, 8);
    cout << "1.    Them san pham";
    Common::gotoXY(40, 10);
    cout << "2.    Xoa san pham";
    Common::gotoXY(40, 12);
    cout << "3.    Xem danh sach san pham";
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

            menu.data.addGood();

            Common::gotoXY(35, 22);
            GoodList::saveGoodListToFile(menu.data, "GoodList.txt",  "Rate.txt", "Comment.txt");
            cout << "Nhan 0 de quay lai menu quan li: ";

            break;
        }
        case 2:
        {
            system("cls");
            UserInterface::Screen();
            menu.data.showList();
            Common::gotoXY(30, 24);
            int i;
            cout << "Chon vi tri thanh vien muon xoa: ";
            cin >> i;
            if (i > 0)
                menu.data.erase(i - 1);
            else
            {
                Common::gotoXY(35, 25);
                cout << "Khong co san pham thu 0";
            }
            GoodList::saveGoodListToFile(menu.data,  "GoodList.txt", "Rate.txt",  "Comment.txt");
            Common::gotoXY(35, 26);
            cout << "Da xoa xong, nhan 0 de quay lai menu quan li: ";

            break;
        }
        case 3:
        {
            int choice2 = -1;
            int page = 1;
            do
            {
                system("cls");
                UserInterface::Screen();

                menu.ViewMuaHang(page);
                Common::gotoXY(4, 27);
                cout << "1. Trang truoc     2. Trang ke        0. Thoat";
                Common::gotoXY(4, 26);
                cout << "Chon mot trong cac lua chon sau: ";
                cin >> choice2;
                system("cls");
                UserInterface::Screen();
                if (choice2 == 1)
                {
                    if (page != 1)
                        page--;
                }
                else if (choice2 == 2)
                {
                    if (page * 20 < menu.data.list.size())
                    {
                        page++;
                    }
                }

            } while (choice2 != 0);
            Common::gotoXY(20, 20);
            cout << "Nhan '0' de tro lai: ";
            break;
        }
        }
    } while (choice != 0);

    if (choice == 0)
    {
        Manager::ManagerMenu();
    }
}