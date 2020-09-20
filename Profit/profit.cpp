#include "profit.h"
#include <fstream>
#include "../Member/Tokenizer.h"
#include "../Employee/Employee.h"
#include "../Utility/util.h"

using namespace std;

unsigned long int Profit::totalBillSold()
{
    unsigned long int S = 0;
    ifstream f;
    f.open(Util::path() + "\\Bill_Order\\TotalBill.txt");
    while (!f.eof())
    {
        string s;
        getline(f, s);
        vector<string> str = TokenizerStr::split(s, " - ");
        S += stoi(str[1]);
    }

    f.close();
    return S;
}

unsigned long int Profit::caltotalSalary()
{
    unsigned long int S = 0;
    vector<Employee *> list = Employee::LoadData();
    for (auto p : list)
    {
        S += p->getSalary();
    }

    return S;
}

unsigned long int Profit::totalIncome()
{
    return totalBillSold() - caltotalSalary();
}