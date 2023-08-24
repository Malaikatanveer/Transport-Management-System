#pragma once
#include<iostream>
#include<fstream>
#include"DateTime.h"
using namespace std;
class Service
{
	char * source;
	char * destination;
	float distance; //in km
	Date bookingDate;
	Time bookingTime;
	bool status; // false for pending, true if complete
	float fuelrate;

	int cId; // Customer Id who booked the ride
	int dId; // Driver Id
	int vId; // vehicle Id
	//you can add more members here if required
	//add member functions
public:
	Service();
	Service(char* source, char* destination, float distance, int day, int month, int year, int hour, int min, int sec, bool status, float fuelrate, int cId, int dId, int vId);
	Service(const Service& obj);
	char* get_source();
	char* get_destination();
	float get_distance();
	Date get_bookingDate();
	Time get_bookingTime();
	bool get_status();
	float get_fuelrate();
	int get_cId();
	int get_dId(); 
	int get_vId();
	void set_source(char* source);
	void set_destination(char* destination);
	void set_cId(int); 
	void set_dId(int); 
	void set_vId(int);
	void set_fuelrate(float);
	void set_status(bool);
	void set_distance(float d);
	void set_bookingDate(const Date& d);
	void set_bookingTime(const Time& t);
	virtual ~Service();
    //friend ostream& operator << (ostream& out, const Service& n);
	virtual ostream& print(ostream& out)const;
	virtual void Database(int =0,int=0);
	//virtual ifstream& read(ifstream &);
	virtual ofstream& write(ofstream&);
	//friend ofstream& operator << (ofstream& out, Service & x);
	//friend ifstream& operator >> (ifstream& in, Service & x);
	Service& operator=(const Service& obj);
	ifstream& readFile(ifstream& in);


};


