#ifndef _MENU_
#define _MENU_
#include <iostream>
#include <string>
#include <vector>
#include "../Good/Good.h"
#include "../Employee/Time.h"

using namespace std;

class Menu
{
private:
	string _hotline;
	string _address;
	string _moreInfo;
	string _gmail;
	Time time;
	vector<string> _feedback;
public: // Lưu lại thông tin danh sách hàng
	GoodList data;

public:
	string hotline() { return _hotline; }
	string address() { return _address; }
	string moreInfo() { return _moreInfo; }
	void setHotline(string value) { _hotline = value; }
	void setAddress(string value) { _address = value; }
	void setMoreInfo(string value) { _moreInfo = value; }

public: // Constructor
	Menu();
	Menu(string hotline, string address, string moreInfo);

public: // Methods
// Nhóm hàm ở Menu chính
	static void Danhgia();
	static void Thongtincuahang();
	static void SignIn();

// Hàm ở phần mua hàng của member (mục SignIn thứ nhất, trong hàm SignIn phía trên)
	static void Muahang(string name);
	void ViewGoodList();
	static void Order(string customerName, string goodName, float money);

// Hàm đọc thông tin cửa hàng từ file và in ra màn hình
	void ViewStoreInfo();

// Hàm đọc và ghi lại nhận xét của người dùng
	static vector<string> readFeedbackFile();
	void ViewFeedBack();
	void addFeedback(string feedback, Time t);
};

#endif // !_MENU_