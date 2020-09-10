#include "interface.h"
#include <Windows.h>
#include <iostream>
#include "Common.h"

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

void Common::color(int cl)
{
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, cl);
}