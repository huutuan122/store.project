#include "interface.h"
#include "Menu.h"
#include "Menu.cpp"
#include <windows.h>

using namespace std;

#ifndef _ACCESS_H_
#define _ACCESS_H_

class Access
{
public:
    static void Muahang();
    static void Dangnhap(){
        system("cls");
        UserInterface::Screen();
        Menu::SignIn();
    }
};

#endif