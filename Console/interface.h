#ifndef _INTERFACE_H_
#define _INTERFACE_H_

class Common
{
public:
    static void fixConsoleWindow();
    static void gotoXY(int, int);
    static void color(int);
};

class Access
{
public:
    static void Muahang();
    static void Dangnhap();
};

class UserInterface
{
public:
    static void Choice();
    static void Screen();
    static void MainMenu();
};

#endif