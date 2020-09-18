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
	GoodList _data;
	string _hotline;
	string _address;
	string _moreInfo;
	Time time;
	vector<string> _feedback;

public:
	string hotline() { return _hotline; }
	string address() { return _address; }
	string moreInfo() { return _moreInfo; }
	void setHotline(string value) { _hotline = value; }
	void setAddress(string value) { _address = value; }
	void setMoreInfo(string value) { _moreInfo = value; }

public:
	Menu();
	Menu(string hotline, string address, string moreInfo);
	static void SignIn();
	void ViewGoodList();
	void Order();
	void ViewStoreInfo();
	void ViewFeedBack();
	void Exit();
	void addFeedback(string feedback, Time t);

	static void Danhgia();
	static void Thongtincuahang();
	static void Muahang();
};

#endif // !_MENU_