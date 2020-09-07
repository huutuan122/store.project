#include "interface.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void Common::fixConsoleWindow()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Common::gotoXY(int X, int Y)
{
    COORD coord;
    coord.X = X;
    coord.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// void gotoPrint(int x, int y, char msg[STRLEN])
// {
//     //while(1){  //printf iff flag_busy is true
//     flag_gotoxy = false;
//     if (flag_gotoxy == false)
//     {
//         gotoxy(x, y);
//         printf("%s", msg);
//     }
//     flag_gotoxy = true;
//     //}
// }

void Common::setSize()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 115 * 10, 70 * 10, TRUE);
}

void UserInterface::Menu()
{

    for (int i = 1; i < 119; i++)
    {
        Common::gotoXY(i, 0);
        cout << "_";
        Common::gotoXY(i, 30);
        cout << "_";
    }

    for (int i = 1; i < 30; i++)
    {
        Common::gotoXY(0, i);
        cout << "|";
        Common::gotoXY(120, i);
        cout << "|";
    }
}