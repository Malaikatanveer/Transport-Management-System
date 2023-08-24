#pragma once
#include"Service.h"
#include<iostream>
using namespace std;
class Delivery : public Service
{
	float goodsWeight; // Weight of goods in Kg 
	char* goodsType; //type of goods food, furniture, petroleum, chemicals, etc. //you can add more members here if required 
	//add member functions 
	char * deliveryType; // intercity, intracity

public:
	Delivery();
	Delivery(float goodsWeight, char* goodsType,char * deliveryType, char* source, char* destination, float distance, int day, int month, int year, int hour, int min, int sec, bool status, float fuelrate, int cId, int dId, int vId);
	Delivery(const Delivery& obj);
	float get_goodsWeight();
	char* get_deliveryType();
	char* get_goodsType();
	void set_goodsWeight(float x);
	void set_goodsType(char* goodsType);
    void set_deliveryType(char* deliveryType);
	ifstream& readFile(ifstream& in);	
	istream& read(istream& in);
	virtual ostream& print(ostream& out)const;
	void Database(int=0,int=0);
	ofstream& write(ofstream& out);
	Delivery& operator=(const Delivery& obj);
   ~Delivery();

};
