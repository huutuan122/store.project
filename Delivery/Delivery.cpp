#include"Delivery.h"

vector<string> split(string a, string separator) {
	vector<string> tokens;
	int startPos = 0;
	while (true) {
		int foundPos = a.find(separator, startPos);
		if (foundPos != string::npos) {
			tokens.push_back(a.substr(startPos, foundPos - startPos));
			startPos = foundPos + separator.length();
		}
		else {
			tokens.push_back(a.substr(startPos, a.length() - startPos));
			break;
		}
	}
	return tokens;
}

Delivery::Delivery() {

}

Delivery::Delivery(string deliId, string orderId, string tel, string street, string ward, string district, double fee, string status) {
	_deliId = deliId;
	_orderId = orderId;
	_tel = tel;
	_street = street;
	_ward = ward;
	_district = district;
	_fee = fee;
	_status = status;
}

void Delivery::createDeliOrder(vector<Delivery>& list, string orderId) {
	Delivery deli;
	string tel, street, ward, district;
	deli.setDeliId(to_string(list.size() + 1));
	deli.setOrderId(orderId);
	cout << "Nhap so dien thoai khach hang: ";
	cin.ignore();
	getline(cin, tel);
	deli.setTel(tel);
	cout << "Nhap dia chi" << endl;
	cout << "So nha, ten duong: ";
	getline(cin, street);
	deli.setStreet(street);
	cout << "Phuong: ";
	getline(cin, ward);
	deli.setWard(ward);
	cout << "Quan: ";
	getline(cin, district);
	deli.setDistrict(district);
	if (district == "1" || district == "3" || district == "4" || district == "5" || district == "6" || district == "10" || district == "11")
		deli.setFee(20000);
	else
		deli.setFee(50000);
	deli.setStatus("NO");
	list.push_back(deli);
}

string Delivery::toString() {
	string s = " - ";
	stringstream writer;
	writer << _deliId << s << _orderId << s << _tel << s << _street << s << _ward << s << _district << s << _fee << s << _status;
	return writer.str();
}

void Delivery::SaveData(vector<Delivery> list) {
	fstream out;
	out.open("DeliveryData.txt", ios::out);
	if (!out) {
		cout << "Khong the mo file!";
		exit;
	}
	out << list.size();
	for (auto a : list) {
		out << endl << a.toString();
	}
	out.close();
}

vector<Delivery> Delivery::LoadData() {
	fstream in;
	int num;
	vector<string> token;
	vector<Delivery> list;
	string temp;
	in.open("DeliveryData.txt", ios::in);
	if (!in) {
		cout << "Khong the mo file!";
		exit;
	}
	getline(in, temp, '\n');
	num = stoi(temp);
	for (int i = 0; i < num; i++) {
		getline(in, temp, '\n');
		token = split(temp, " - ");
		Delivery a(token[0], token[1], token[2], token[3], token[4], token[5], stod(token[6]), token[7]);
		list.push_back(a);
	}
	in.close();
	return list;
}