#include "system.h"
#include <windows.h>
#include "../Console/Common.h"
#include "../Console/interface.h"
#include "../Member/Tokenizer.h"
#include <string>
#include <sstream>

using namespace std;

string Manager::toString(){
    stringstream writer;
    writer << _username << " - " << _password << " - " << _name;
    return writer.str();
}

vector<Manager*> Manager::readManagerFile(string fileName){
    ifstream f;
    f.open(fileName);

    vector<Manager *> list;
    

    if (!f){
        Common::gotoXY(40, 10);
        cout << "Khong the mo file quan li!";
    }

    string s;
    while(!f.eof()){
        Manager *manager = new Manager();
        getline(f, s);
        vector<string> str = TokenizerStr::split(s, " - ");
        manager->setUser(str[0]);
        manager->setPassword(str[1]);
        manager->setName(str[2]);

        list.push_back(manager);
    }

    f.close();
    return list;
}

void Manager::LoginAsManager()
{
    vector<Manager *> manager = readManagerFile("E:\\VSC\\C++\\Project Store\\github\\System\\manager.txt");
    Manager *temp = new Manager();
    string user, pass;
    do
    {
        system("cls");
        UserInterface::Screen();
        Common::gotoXY(55, 6);
        cout << "____He thong quan li____";
        Common::gotoXY(40, 10);
        cout << "Username: ";
        cin >> user;
        Common::gotoXY(40, 12);
        cout << "Password: ";
        cin >> pass;
        for (auto p : manager)
        {
            if (user == p->Username())
            {
                temp->setUser(p->Username());
                temp->setPassword(p->Password());
            }
        }

        if (pass != temp->Password())
        {
            Common::gotoXY(35, 16);
            cout << "Sai ten dang nhap hoac sai mat khau, xin moi nhap lai!! " << endl;
            Sleep(1000);
        }
        else
            break;
        Sleep(1000);

    } while (pass != temp->Password());
    Common::gotoXY(35, 16);
    cout << "Dang nhap thanh cong! ";
}