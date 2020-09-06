#include "member.h"
#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    Member *temp = new Member();
    vector<Member *> mem;
    mem = Member::readMemberFile("member.txt");

    Member::registerMember(temp);
    mem.push_back(temp);
    Member::addMember("member.txt", temp);

    system("pause");
    return 1;
}