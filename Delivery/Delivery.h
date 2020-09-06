#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

class Delivery {
private:
	string _deliId;
	string _orderId;
	string _tel;
	string _street;
	string _ward;
	string _district;
	double _fee;
	string _status;
public:
	Delivery();
	Delivery(string, string, string, string, string, string, double, string);
	string DeliId() { return _deliId; }
	void setDeliId(string id) { _deliId = id; }
	string OrderId() { return _orderId; }
	void setOrderId(string id) { _orderId = id; }
	string Street() { return _street; }
	void setStreet(string street) { _street = street; }
	string Ward() { return _ward; }
	void setWard(string ward) { _ward = ward; }
	string District() { return _district; }
	void setDistrict(string district) { _district = district; }
	string Tel() { return _tel; }
	void setTel(string tel) { _tel = tel; }
	double Fee() { return _fee; }
	void setFee(double fee) { _fee = fee; }
	string Status() { return _status; }
	void setStatus(string status) { _status = status; }
public:
	static void createDeliOrder(vector<Delivery>& list, string orderId);
	string toString();
	static void SaveData(vector<Delivery>list);
	static vector<Delivery> LoadData();
};