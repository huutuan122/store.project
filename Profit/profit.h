#ifndef _PROFIT_H_
#define _PROFIT_H_

class Profit
{
    
private:
    int _countBill;

public: // Nhóm hàm tính lợi nhuận
    static unsigned long int totalBillSold();
    static unsigned long int caltotalSalary();
    static unsigned long int totalIncome();
};

#endif