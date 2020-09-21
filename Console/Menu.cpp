#include "Menu.h"
#include "interface.h"
#include "../Member/member.h"
#include "../Member/member.cpp"
#include "../Employee/Employee.h"
#include "../Employee/Employee.cpp"
#include "../System/system.h"
#include "../System/system.cpp"
#include <vector>
#include "Common.h"
#include <sstream>
#include "../Discount/Discount.h"
#include "../Good/Good.h"
#include "../Bill_Order/Order.cpp"
#include "../Bill_Order/Bill.cpp"
#include "../Utility/util.h"

using namespace std;
// Khoi tao Menu
Menu::Menu()
{
	_hotline = "";
	_address = "";
	_moreInfo = "";
}

Menu::Menu(string hotline, string address, string moreInfo)
{
	_hotline = hotline;
	_address = address;
	_moreInfo = moreInfo;
}

// Nhom ham truy cap khi moi vao Menu (4 ham)

void Menu::Danhgia()
{

	system("cls");
	UserInterface::Screen();
	Common::color(14);
	Menu menu;
	int i;
	do
	{
		menu.ViewFeedBack();

		Common::gotoXY(20, 26);
		cout << "1. Danh gia                   2. Thoat";
		Common::gotoXY(24, 27);
		cout << "Chon mot trong cac muc tren: ";
		cin >> i;

		if (i == 1)
		{
			system("cls");
			UserInterface::Screen();
			Menu menu;
			string feedback;
			Common::gotoXY(20, 14);
			Time now;
			cout << "De lai danh gia cua ban: ";
			Common::gotoXY(30, 16);
			getline(cin, feedback);
			getline(cin, feedback);

			Common::gotoXY(40, 26);
			menu.addFeedback(feedback, now);
		}

	} while (i != 2);
	if (i == 2)
	{
		UserInterface::MainMenu();
	}
}

void Menu::Thongtincuahang()
{
	system("cls");
	UserInterface::Screen();
	Menu menu;
	menu.ViewStoreInfo();
}

void Menu::SignIn()
{

	int choice;
	system("cls");
	UserInterface::Screen();
	Common::color(14);
	Common::gotoXY(49, 4);
	cout << "--------- MENU DANG NHAP ----------";
	Common::gotoXY(40, 6);
	cout << "1.    Dang nhap hoi vien";
	Common::gotoXY(40, 8);
	cout << "2.    Dang nhap nhan vien";
	Common::gotoXY(40, 10);
	cout << "3.    Dang nhap quan li";
	Common::gotoXY(40, 12);
	cout << "4.    Exit";

	Common::gotoXY(50, 14);
	cout << "Chon mot trong cac muc tren: ";
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Member::loginasMember();
			choice = 4;
			break;
		}
		case 2:
		{
			Employee::loginAsEmployee();
			choice = 4;
			break;
		}
		case 3:
		{
			Manager::LoginAsManager();
			choice = 4;
			break;
		}
		case 4:
		{
			UserInterface::MainMenu();
		}
		}
	} while (choice != 4);
}

// Nhom ham khi mua hang o ham Menu::Signin(), Signin As Member
void Menu::Muahang(int page, string name, OrderStore &orderList)
{
	system("cls");
	UserInterface::Screen();
	Common::color(14);
	Common::gotoXY(1, 2);
	Menu menu;
	menu.data = GoodList::readGoodListFromFile("GoodList.txt",  "Rate.txt",  "Comment.txt");
	menu.ViewMuaHang(page);
	Common::gotoXY(4, 25);
	cout << "1. Mua hang		2. Sap xep	3. Phan loai";
	Common::gotoXY(4, 26);
	cout << "4. Xem danh gia		5. Trang truoc		6. Trang ke";
	Common::gotoXY(4, 27);
	cout << "0. Thoat";
	Common::gotoXY(4, 24);
	cout << "Chon mot trong cac lua chon sau: ";
	int choice;
	cin >> choice;
	if (choice == 0)
		return;
	else if (choice == 1)
		Menu::ScreenMuaHang(menu, name, orderList);
	else if (choice == 2)
		Menu::ScreenSapXep(menu, name, orderList);
	else if (choice == 3)
		Menu::ScreenPhanLoai(menu, name, orderList);
	else if (choice == 4)
		Menu::ScreenDanhGia(menu, name, orderList);
	else if (choice == 5)
	{
		if (page == 1)
			Menu::Muahang(1, name, orderList);
		else
			Menu::Muahang(page - 1, name, orderList);
	}
	else if (choice == 6)
	{
		if (page * 20 > menu.data.list.size())
			Menu::Muahang(page, name, orderList);
		else
			Menu::Muahang(page + 1, name, orderList);
	}
}

void Menu::ViewMuaHang(int page)
{
	Common::color(14);
	int i = 1;
	Common::gotoXY(49, 1);
	cout << "Danh sach hang hoa";
	Common::gotoXY(i, 2);
	cout << "    Ten         Gia            So luong        Loai hang         Danh gia";
	int j = 3;
	int cuoi;
	if ((page - 1) * 20 + 20 > data.list.size())
		cuoi = data.list.size();
	else
		cuoi = (page - 1) * 20 + 20;
	for (int k = (page - 1) * 20; k < cuoi; k++)
	{

		j = j + 1;
		Common::gotoXY(i, j);
		cout << k + 1;
		Common::gotoXY(i + 4, j);
		cout << data.list[k].name();
		Common::gotoXY(i + 14, j);
		cout << fixed << setprecision(2) << data.list[k].price();
		Common::gotoXY(i + 34, j);
		if (data.list[k].amount() > 0)
			cout << data.list[k].amount();
		else
			cout << data.list[k].status();

		Common::gotoXY(i + 49, j);
		cout << data.list[k].type();
		Common::gotoXY(i + 69, j);
		cout << data.list[k].averageRate();
	}
}
// Nhóm hàm khi người dùng mua hàm, cần tìm kiếm hay xem tiếp
void Menu::ScreenMuaHang(Menu &menu, string name, OrderStore &orderList)
{

	system("cls");
	UserInterface::Screen();
	Common::color(14);
	menu.ViewMuaHang(1);
	Common::gotoXY(8, 25);
	cout << "Nhap stt san pham ban muon mua: ";
	int choice;
	cin >> choice;
	Common::gotoXY(8, 26);
	cout << "So luong mua: ";
	int num;
	cin >> num;
	if (menu.data.list[choice - 1].amount() - num > 0)
	{
		menu.data.list[choice - 1].setAmount(menu.data.list[choice - 1].amount() - num);
		Good currentGood = menu.data.list[choice - 1];
		ZDate nowd;
		ZTime nowt;
		Order *temp = new Order(currentGood.code(), currentGood.name(), currentGood.price(), num, nowd, nowt, name);
		orderList._list.push_back(temp);
		menu.data.list[choice - 1].setQuantitySold(menu.data.list[choice - 1].quantitySold() + 1);
		GoodList::saveGoodListToFile(menu.data, "GoodList.txt", "Rate.txt",  "Comment.txt");
		Common::gotoXY(6, 27);
		cout << "Ban co muon mua tiep khong? Co (1) hoac Khong (2): ";
		int choice2;
		cin >> choice2;
		if (choice2 == 2)
		{
			system("cls");
			UserInterface::Screen();
			Bill tempBill(orderList, name);
			Common::gotoXY(30, 24);
			cout << "Ban muon dung bao nhieu diem: ";
			int usePoint;
			cin >> usePoint;
			vector<Member *> list = Member::readMemberFile();
			for (auto p : list)
			{
				if (p->Name() == name)
				{
					p->setPoint(p->Point() - usePoint);
				}
			}
			Member::saveMemberInfo(list);
			Common::gotoXY(30, 25);
			cout << "Nhap ma giam gia: ";
			string codeDiscount;
			cin >> codeDiscount;
			bool isUsed = 0;
			double total = Discount::countDiscount(tempBill.total(), codeDiscount, usePoint, isUsed);
			Bill finalBill(name, orderList, total);
			BillStore billList;
			billList.add(finalBill);
			if (isUsed == 1)
			{
				Common::gotoXY(30, 26);
				cout << "Ma giam gia hop le!!";
				Sleep(1000);
			}
			else
			{
				Common::gotoXY(30, 27);
				cout << "Ma giam gia khong hop le, khong giam gia!!";
				Sleep(1000);
			}
			BillFile billFile;
			billFile.write(billList);
			Menu::printBill(name);
		}
		if (choice2 == 1)
			Muahang(1, name, orderList);
	}
	else
	{
		cout << ", khong du hang";
		Sleep(1000);
		Muahang(1, name, orderList);
	}
}

void Menu::ScreenSapXep(Menu &menu, string name, OrderStore &orderList)
{
	system("cls");
	UserInterface::Screen();
	Common::color(14);
	Common::gotoXY(40, 6);
	cout << "Chon mot trong cac lua chon sau: ";
	Common::gotoXY(40, 8);
	cout << "1. Sap xep tu A -> Z";
	Common::gotoXY(40, 10);
	cout << "2. Sap xep tu Z -> A";
	Common::gotoXY(40, 12);
	cout << "3. Sap xep theo gia tang dan";
	Common::gotoXY(40, 14);
	cout << "4. Sap xep theo gia giam dan";
	Common::gotoXY(40, 16);
	cout << "5. Sap xep theo do pho bien";
	Common::gotoXY(40, 18);
	cout << "6. Sap xep theo diem danh gia tang dan";
	Common::gotoXY(40, 20);
	cout << "7. Sap xep theo diem danh gia giam dan";
	Common::gotoXY(40, 22); // e lam 2 o di cho de~ nhin cai console rong 26 lan
	cout << "Nhap su lua chon cua ban: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		menu.data.sortAZ();
		GoodList::saveGoodListToFile(menu.data,  "GoodList.txt","Rate.txt", "Comment.txt");
		break;
	case 2:
		menu.data.sortZA();
		GoodList::saveGoodListToFile(menu.data, "GoodList.txt", "Rate.txt", "Comment.txt");
		break;
	case 3:
		menu.data.sortByPriceAscending();
		GoodList::saveGoodListToFile(menu.data, "GoodList.txt", "Rate.txt", "Comment.txt");
		break;
	case 4:
		menu.data.sortByPriceDescending();
		GoodList::saveGoodListToFile(menu.data, "GoodList.txt", "Rate.txt", "Comment.txt");
		break;
	case 5:
		menu.data.sortByPopular();
		GoodList::saveGoodListToFile(menu.data, "GoodList.txt", "Rate.txt", "Comment.txt");
		break;
	case 6:
		menu.data.sortByRateAscending();
		GoodList::saveGoodListToFile(menu.data, "GoodList.txt", "Rate.txt", "Comment.txt");
		break;
	case 7:
		menu.data.sortByRateDescending();
		GoodList::saveGoodListToFile(menu.data, "GoodList.txt", "Rate.txt", "Comment.txt");
		break;
	default:
		break;
	}
	Menu::Muahang(1, name, orderList);
}

void Menu::ScreenPhanLoai(Menu &menu, string name, OrderStore &orderList)
{
	menu.data.classify();
	GoodList::saveGoodListToFile(menu.data, "GoodList.txt", "Rate.txt", "Comment.txt");
	Menu::Muahang(1, name, orderList);
}

void Menu::ScreenDanhGia(Menu &menu, string name, OrderStore &orderList)
{
	system("cls");
	Common::color(14);
	UserInterface::Screen();
	Common::gotoXY(2, 2);
	menu.data.showList();
	Common::gotoXY(30, 24);
	int i;
	cout << "Chon vi tri san pham muon xem: ";
	cin >> i;
	system("cls");
	Common::color(14);
	UserInterface::Screen();
	Common::gotoXY(2, 4);
	cout << menu.data.list[i - 1].name();
	int j = 5;
	for (auto e : menu.data.list[i - 1].comment())
	{
		Common::gotoXY(5, j);
		cout << e;
		j++;
	}
	Common::gotoXY(30, 24);
	cout << "Nhap 0 de thoat: ";
	int ent;
	cin >> ent;
	Menu::Muahang(1, name, orderList);
}

//In hoá đơn
void Menu::printBill(string customerName)
{
	system("cls");
	UserInterface::Screen();
	Common::color(14);
	BillFile inputBill;
	BillStore billList = inputBill.read();
	Bill myBill = billList.billWithCustomer(customerName);
	Common::gotoXY(49, 6);
	cout << "----------HOA DON THANH TOAN----------";
	Common::gotoXY(45, 8);
	cout << "Ten: " << customerName;
	Common::gotoXY(45, 10);
	cout << "San pham: " << myBill.printItems();
	Common::gotoXY(45, 12);
	cout << "Thanh tien: " << myBill.total();
	Common::gotoXY(40, 14);

	Time t;
	cout << "Thoi gian: " << t.toString();
	Sleep(1000);
	int i;
	Common::gotoXY(30, 26);
	cout << "Nhap '0' de quay tro lai: ";
	cin >> i;
	if (i == 0)
		return;
}

// Ham doc thong tin tu file va xem thong tin cua hang (ViewStoreInfo)
void Menu::ViewStoreInfo()
{
	Common::color(14);
	ifstream f;
	f.open( "StoreInfo.txt");
	string s;
	vector<string> temp;
	while (!f.eof())
	{
		getline(f, s);
		temp.push_back(s);
	}

	_hotline = temp[0];
	_address = temp[1];
	_moreInfo = temp[2];
	_gmail = temp[3];

	f.close();
	Common::gotoXY(54, 6);
	cout << "_____THONG TIN CUA HANG_____";

	Common::gotoXY(30, 10);
	cout << "Duong day nong: " << _hotline;
	Common::gotoXY(30, 12);
	cout << "Dia chi: " << _address;
	Common::gotoXY(30, 14);
	cout << "Thong tin them: " << _moreInfo;
	Common::gotoXY(30, 16);
	cout << "Neu co bat cu loi nao, vui long gui thong tin ve email " << _gmail;

	int i;
	Common::gotoXY(20, 26);
	cout << "Bam '0' de tro ve menu chinh: ";
	cin >> i;
	if (i == 0)
		UserInterface::MainMenu();
}

// Ham doc thong tin tu file feedback va xem so feedback
vector<string> Menu::readFeedbackFile()
{
	vector<string> feedback;
	ifstream f;
	f.open( "feedback.txt");
	while (!f.eof())
	{
		string s;
		getline(f, s);
		feedback.push_back(s);
	}
	f.close();
	return feedback;
}

void Menu::ViewFeedBack()
{
	Common::color(14);
	vector<string> feedback = readFeedbackFile();
	if (feedback.size() == 0)
	{
		system("cls");
		UserInterface::Screen();
		Common::gotoXY(40, 16);
		cout << "Tam thoi khong co danh gia nao!";
	}
	else
	{
		system("cls");
		UserInterface::Screen();
		Common::gotoXY(49, 4);
		cout << "----------DANH GIA CUA KHACH HANG----------";
		int i = 6;
		for (auto e : feedback)
		{
			Common::gotoXY(25, i);
			cout << e;
			i++;
			if (i == 24)
			{
				system("cls");
				UserInterface::Screen();
				Common::gotoXY(49, 4);
				cout << "----------DANH GIA CUA KHACH HANG----------";
				i = 6;
			}
		}
	}
}

void Menu::addFeedback(string feedback, Time t)
{
	vector<string> feedbackList = readFeedbackFile();
	stringstream writer;
	writer << t.toString() << " - " << feedback;
	feedbackList.push_back(writer.str());
	ofstream f;
	f.open("feedback.txt", ios::out);
	f << feedbackList[0];
	for (int i = 1; i < feedbackList.size(); i++)
	{
		f << endl
		  << feedbackList[i];
	}

	f.close();
}
