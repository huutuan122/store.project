#include <iostream>
#include "interface.h"
#include <windows.h>

using namespace std;

int main(){
    Common::fixConsoleWindow();
    UserInterface::Menu();

    cout << endl;
    system("pause");
    return 0;
}