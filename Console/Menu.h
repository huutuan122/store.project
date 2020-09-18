#ifndef _MENU_
#define _MENU_
#include <iostream>
#include <string>
#include <vector>
#include "../Good/Good.h"
#include "../Employee/Time.h"
#include "../Member/member.h"

using namespace std;

class Menu
{
private:
	string _hotline;
	string _address;
	string _moreInfo;
	Time time;
	vector<string> _feedback;
public:
	GoodList data;
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
	void Purchase(int position, Member* member);
};

#endif // !_MENU_