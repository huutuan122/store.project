#include"Good.h"

int main() {
	/*GoodList list;

	Good good1("DNT", "01", 10000, 35, "Dac nhan tam", "Sach");
	good1.addComment("Xin vai l the haha");
	good1.addRate(5.0);
	good1.addRate(4.5);
	Good good2("TC", "02", 30000, 55, "Truyen cuoi", "Sach");
	good2.addComment("Xin vai");
	good2.addRate(4.5);
	Good good3("BMW", "05", 3500000, 3, "Xe mui tran", "Xe");
	good3.addComment("Good haha");
	good3.addRate(4.5);
	Good good4("Acer", "04", 2500000, 5, "Laptop xin", "Laptop");
	good4.addComment("Xin the omg");
	good4.addRate(3.5);

	list.add(good1);
	list.add(good2);
	list.add(good3);
	list.add(good4);*/
	
	GoodList list=App::readGoodListFromFile("GoodList.txt", "Rate.txt", "Comment.txt");
	cout << list.size() << endl;
	for (auto good : list.list)
		cout << good.name() << "-"
		<< good.code() << "-"
		<< good.price() << "-"
		<< good.amount() << "-"
		<< good.description() << "-"
		<< good.type() << endl;
	cout << list.size() << endl;
	for (auto good : list.list) {
		cout << good.code();
		vector<string> cmt = good.comment();
		for (auto e : cmt)cout << "-" << e;
		cout << endl;
	}
	cout << list.size() << endl;
	for (auto good : list.list) {
		cout << good.code();
		vector<float> cmt = good.rate();
		for (auto e : cmt)cout << "-" << e;
		cout << endl;
	}
	
	return 0;
}