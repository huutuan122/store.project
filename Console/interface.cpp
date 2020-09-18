#include "interface.h"
#include "Menu.h"
#include "Access.h"
#include "Common.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void UserInterface::Screen()
{
    Common::color(9);
    for (int i = 1; i < 119; i++)
    {
        Common::gotoXY(i, 0);
        cout << "_";
        Common::gotoXY(i, 28);
        cout << "_";
    }
    for (int i = 1; i < 29; i++)
    {
        Common::gotoXY(0, i);
        cout << "|";
    }
    for (int i = 1; i < 29; i++)
    {
        Common::gotoXY(119, i);
        cout << "|";
    }
}

void UserInterface::MainMenu() // Level 1
{
    system("cls");
    Screen();
    Common::color(14);
    Common::gotoXY(53, 3);
    cout << "______MENU______";
    Common::gotoXY(40, 6);
    cout << "1.   Mua hang";
    Common::gotoXY(40, 8);
    cout << "2.   Dang nhap";
    Common::gotoXY(40, 10);
    cout << "3.   Danh gia";
    Common::gotoXY(40, 12);
    cout << "4.   Thong tin cua hang";
    Common::gotoXY(40, 14);
    cout << "5.   Thoat";

    Common::gotoXY(50, 16);
    cout << "Nhap lua chon: ";
    Choice();

    Common::gotoXY(0, 30);
    cout << endl;
    return;
}

// 5 lua chon cua main menu
void UserInterface::Choice()
{
    int enter;
    cin >> enter;
    // Level 1
    do
    {
        switch (enter)
        {
        case 1:
            break;
        case 2:
        {
            Menu::SignIn();
            enter = 5;
            break;
        }
        case 3:
            Access::Danhgia();
            system("cls");
            enter = 5;
            break;
        case 4:
            Access::ThongTinCuaHang();
            system("cls");
            enter = 5;
            break;
        }
    } while (enter != 5);
    if (enter == 5)
        return;
}