#include <iostream>
#include "Console/interface.h"
#include "Console/Common.cpp"
#include "Console/interface.cpp"

#include <windows.h>

using namespace std;

int main()
{
    Common::fixConsoleWindow();
    UserInterface::MainMenu();

    cout << endl;
    system("pause");
    return 0;
}