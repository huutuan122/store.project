#include <iostream>
#include "Console/interface.h"
#include "Console/Common.cpp"
#include "Console/interface.cpp"

#include <windows.h>

using namespace std;

int main()
{
    Common::fixConsoleWindow();
    UserInterface::DrawName();
    UserInterface::DrawIcon();
    Common::gotoXY(30, 24);
    system("pause");
    UserInterface::MainMenu();
    Common::gotoXY(30, 24);
    system("pause");
    return 0;
}
