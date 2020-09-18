#include "interface.h"
#include "Menu.h"
#include "Menu.cpp"
#include <windows.h>
#include "../Employee/Time.h"

using namespace std;

#ifndef _ACCESS_H_
#define _ACCESS_H_

class Access
{
public:
    static void Muahang();

    static void Dangnhap()
    {
        system("cls");
        UserInterface::Screen();
        Menu::SignIn();
    }

    static void Danhgia()
    {
        system("cls");
        UserInterface::Screen();
        Menu menu;
        menu.ViewFeedBack();
        int i;
        Common::gotoXY(1, 26);
        cout << "1. Danh gia                   2. Thoat";
        Common::gotoXY(1, 27);
        cout << "Chon mot trong cac muc tren: ";
        cin >> i;

        if (i == 1)
        {
            system("cls");
            UserInterface::Screen();
            Menu menu;
            string feedback;
            Common::gotoXY(40, 14);
            Time now;
            cout << "De lai danh gia cua ban: ";
            Common::gotoXY(30, 16);

            menu.addFeedback(feedback, now);
        }
        else
            UserInterface::MainMenu();
    }

    static void ThongTinCuaHang()
    {
        system("cls");
        UserInterface::Screen();
        Menu menu;
        menu.ViewStoreInfo();
        Common::gotoXY(1, 27);
        system("pause");
    }
};

#endif