#ifndef _INTERFACE_H_
#define _INTERFACE_H_

class Common
{
public:
    static void fixConsoleWindow();
    static void gotoXY(int, int);
    static void hideCursor(bool);
    static void removeScrollbar();
    static void setSize();
};

class UserInterface
{
public:
    static void Menu();
};

#endif