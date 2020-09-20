#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

class Good
{
private: // Atributes 
	string _name;
	string _code;
	float _price;
	int _amount;
	vector<float> _rate;
	vector<string> _cmt;
	string _description;
	string _type;
	int _quantitySold;

public: // setter-getter
	string name() { return _name; }
	string code() { return _code; }
	float price() { return _price; }
	int amount() { return _amount; }
	vector<float> rate() { return _rate; }
	vector<string> comment() { return _cmt; }
	string description() { return _description; }
	string type() { return _type; }
	int quantitySold() { return _quantitySold; }
	void setName(string value) { _name = value; }
	void setCode(string value) { _code = value; }
	void setPrice(float value) { _price = value; }
	void setAmount(int value) { _amount = value; }
	void setQuantitySold(int value) { _quantitySold = value; }
	void setDescription(string value) { _description = value; }
	void setType(string value) { _type = value; }

public: // Constructor
	Good();
	Good(string name, string code, float price, int amount, string description, string type);

public: // Chức năng
	// Update sản phẩm
	void update(string name, float price, int amount, string description, string type, int quantitySold);
	// Thêm nhận xét ở dạng bình luận
	void addComment(string comment);
	// Hiển thị danh sách Comment
	string listOfComment();
	// Xoá một comment
	void deleteComment(int position);
	// Thêm nhận xét ở dạng đánh giá
	void addRate(float rate);
	// Hiển thị danh sách đánh giá
	string listOfRate();
	// Xoá một đánh giá
	void deleteRate(int position);
	// Đánh giá trung bình
	float averageRate();
	// Tình trạng hàng hoá
	string status();
};

class GoodList
{
public:
	vector<Good> list;

public: // Hỗ trợ sắp xếp
	static bool compNameAZ(Good a, Good b);
	static bool compNameZA(Good a, Good b);
	static bool compPriceAs(Good a, Good b);
	static bool compPriceDes(Good a, Good b);
	static bool compBestSeller(Good a, Good b);
	static bool compRateAs(Good a, Good b);
	static bool compRateDes(Good a, Good b);
	static bool compClassify(Good a, Good b);

public: // Nhóm hàm quản lí danh sách sản phẩm
	// Lấy kích thước của danh sách
	int size() { return list.size(); }
	// Lấy một sản phẩm ở vị trí nhất định
	Good goodAt(int position);
	// Cập nhật lại sản phẩm ở vị trí xác định
	void updateGood(Good newgood, int position);
	// Thêm sản phẩm vào cuối danh sách
	void addGood();
	void add(Good newGood);
	// Xoá một sản phẩm ở vị trí xác định
	void erase(int position);
	// Chuyển sản phẩm ở vị trí xác định lên trên
	void moveUp(int position);
	// Chuyển sản phẩm ở vị trí xác định xuống dưới
	void moveDown(int position);
	// Sản phẩm bán chạy nhất
	Good bestSeller();
	// Danh sách sản phẩm đang có
	void showList();

public: //Sắp xếp sản phẩm theo yêu cầu
	void sortAZ();
	void sortZA();
	void sortByPriceAscending();
	void sortByPriceDescending();
	void sortByPopular();
	void sortByRateAscending();
	void sortByRateDescending();
	void classify();
	vector<Good> search(string GoodName);
	map<string, vector<Good>> classifyMap();
	string listClassify();

	// Công cụ đọc ghi file
	static GoodList readGoodListFromFile(string fileGood, string fileRate, string fileComment);
	static void saveGoodListToFile(GoodList list, string fileGood, string fileRate, string fileComment);
};
