#include "interface.h"
#include "Menu.h"
#include "Menu.cpp"
#include "Common.h"
#include <Windows.h>
#include <iostream>

using namespace std;

// Ve khung cho Console
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

void UserInterface::DrawName()
{
    Screen();
    Common::gotoXY(3, 3);
    Common::color(14);
    cout << "  /$$$$$$  /$$$$$$$  /$$   /$$ /$$ /$$$$$$$     /$$$$$$ /$$$$$$$$  /$$$$$$$  /$$$$$$  /$$$$$$$";
    Common::gotoXY(3, 4);
    cout << " /$$____/ /$$___  $$| $$  | $$| $$| $$__  $$   | $$    |__  $$__/ /$$___  $$| $$___$$| $$____/";
    Common::gotoXY(3, 5);
    cout << "| $$     | $$   \\ $$| $$  | $$| $$| $$  \\ $$    \\  $$$    | $$   | $$   \\ $$| $$$$$/ | $$$$$$$";
    Common::gotoXY(3, 6);
    cout << "| $$     | $$   | $$|  $$/ $$/| $$| $$  | $$      \\  $$   | $$   | $$   | $$| $$_ $$ | $$____/";
    Common::gotoXY(3, 7);
    cout << "|  $$$$$$|  $$$$$$$/  \\  $$ / | $$| $$$$$$$     /$$$$$$   | $$   |  $$$$$$$/| $$ \\ $$| $$$$$$$";
    Common::gotoXY(3, 8);
    cout << " \\______/ \\_______/    \\__/   |__/|_______/    |______/   |__/    \\_______/ |__/  \\_/|_______/";
}

void UserInterface::DrawIcon()
{
    Screen();
    Common::color(14);
    Common::gotoXY(60, 15);
    cout << "                  $$$$$$$$$$$";
    Common::gotoXY(60, 16);
    cout << "                $$           $$";
    Common::gotoXY(60, 17);
    cout << "               $$             $$";
    Common::gotoXY(60, 18);
    cout << "             $$$$$$$$$$$$$$    $$";
    Common::gotoXY(60, 19);
    cout << "            $$            $$   $$";
    Common::gotoXY(60, 20);
    cout << "           $$             $$   $$$$$";
    Common::gotoXY(60, 21);
    cout << "            $$            $$   $$  $$";
    Common::gotoXY(60, 22);
    cout << "             $$$$$$$$$$$$$$    $$   $$";
    Common::gotoXY(60, 23);
    cout << "          	     $$	            $$   $$";
    Common::gotoXY(60, 24);
    cout << "                $$             $$   $$";
    Common::gotoXY(60, 25);
    cout << "                $$             $$   $$";
    Common::gotoXY(60, 26);
    cout << "                $$             $$  $$";
    Common::gotoXY(60, 27);
    cout << "                $$             $$$$";
}

// Menu chinh khi nguoi dung khoi chay
void UserInterface::MainMenu() // Level 1
{
    system("cls");
    Screen();
    Common::color(14);
    Common::gotoXY(53, 3);
    cout << "______MENU______";
    Common::gotoXY(40, 6);
    cout << "1.   Thong tin cua hang";
    Common::gotoXY(40, 8);
    cout << "2.   Dang nhap";
    Common::gotoXY(40, 10);
    cout << "3.   Danh gia";
    Common::gotoXY(40, 12);
    cout << "4.   Dang ki hoi vien";
    Common::gotoXY(40, 14);
    cout << "5.   Thoat";

    Common::gotoXY(50, 16);
    cout << "Nhap lua chon: ";
    Choice();
    // return;
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
            Menu::Thongtincuahang();
            enter = 5;
            break;
        case 2:
        {
            Menu::SignIn();
            enter = 5;
            break;
        }
        case 3:
        {
            Menu::Danhgia();
            enter = 5;
            break;
        }
        case 4:
        {
            Member *mem = new Member();
            Member::registerMember(mem);

            enter = 5;
            break;
        }
        }
    } while (enter != 5);
    if (enter == 5)
        return;
}