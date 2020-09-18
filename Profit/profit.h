#ifndef _PROFIT_H_
#define _PROFIT_H_

class Salary
{
public:
    virtual unsigned long int getSalary() = 0;
};

class Profit
{
private:
    int _countBill;

public:
    static unsigned long int totalBillSold();
    static unsigned long int caltotalSalary();
    static unsigned long int totalIncome();
};

#endif