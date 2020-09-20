#ifndef _DISCOUNT_
#define _DISCOUNT_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "../Good/Good.h"
using namespace std;

class Discount
{

public:
	// Nhóm hàm đọc file discount và in ra màn hình
	// Đọc file CodeDiscount.txt
	static map<string, string> getDiscountFile();
	// Hiển thị ra màn hình các ưu đãi từ file
	static void showVoucher();
	// Dành cho quản lí để thêm ưu đãi
	static void addVoucher();

	// Hàm tính tổng lợi được giảm
	static float countDiscount(float price, string codeDiscount, int UsePoint, bool &codeIsValid);
};

#endif // !_DISCOUNT_
