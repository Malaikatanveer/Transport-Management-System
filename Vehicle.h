//#pragma once
#pragma once
#include <cstring>
#include<iostream>
#include"Name.h"
#include"Feature.h"
#include"DateTime.h"
#include"Service.h"

class Vehicle //type: ride/delivery ->small/large ->intercity/intracity
{
	static int vId;
	int registrationNo;
	float avgMileage;
	char * LicenceType; // License required for driving the vehicle
	Feature* list;
	char * fueltype;
	Service ** serviceHistory;
	char* vName;
	bool status; // false for free, true if booked in a service already
	int vn_size;
	float overallRanking;
	Date manufacturingDate;
	//Feature * list;
	int feature_size;
	int size;
	char category;
	//Add services address in the array for tracking complete information of service.
	//you can add more members here if required
	//add member functions
public:
	Vehicle();
	Vehicle(int x, float y, char* lt, bool s, char* ft, float rank, Date d,int f_size ,Feature* f, Service** obj, int S, char category, char * v_name, int vn_size);
	Vehicle(int x, float y, char* lt, bool s, char* ft, Date d, int f_size, Feature* f, char category, char* v_name);
	Vehicle(const Vehicle& v);
	int get_registrationNo();
	float get_avgMileage();
	void increment_vId();
	char * get_LicenceType(); // License required for driving the vehicle
	bool get_status(); // false for free, true if booked in a service already
	char * get_fueltype();
	float get_overallRanking();
	Date get_manufacturingDate();
	//Feature get_list();
	Service** get_serviceHistory();
	int get_vId();
	char* get_vName();
	char get_category();
	int get_feature_size();
	//setters
	void set_registrationNo(int);
	void set_avgMileage(float);
    void set_LicenceType(char*); // License required for driving the vehicle
	void set_status(bool); // false for free, true if booked in a service already
	void set_fueltype(char*);
	void set_overallRanking(float);
	void set_manufacturingDate(const Date& obj);
	//void set_list(const Feature& obj);
	void set_serviceHistory(Service*);
	//void set_vName(char*);
	//void set_Category(Service* khidmat);
	friend ostream& operator << (ostream& out, const Vehicle& n);
	float Features_cost();
	ifstream& readFile(ifstream &);
	ofstream& write(ofstream&);
	Vehicle& operator=(const Vehicle& v);
	~Vehicle();

};
//add Complete Hierarchy of vehicles based on their types and functions



