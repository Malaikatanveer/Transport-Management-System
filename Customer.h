#pragma once
#include"Person.h"
#include"Service.h"
#include <cstring>
#include<iostream>
#include"Ride.h"
#include"Delivery.h"
using namespace std;
class Customer : public Person {
private:
	
	static int cId;
	// Unique and assigned first time when customer makes first service request 
	int size = 0;
	Service** bookingHistory;
	//Maintain and Update history of customer for each service (ride or goods  transportation order) by adding address of service in dynamic array. 
	//you can add more members here if required 
public:
	//add following functions in this class //Getter, Setters 
	//Destructor, Default and Parametrized Constructor, Copy Constructor, Output  operator (print complete information of customer including history if any) 
	Customer();
	Customer(int, Service**,int);
	Customer(char* fName, char* lName, int day, int month, int year, int Age, int Nid);
	Customer(const Customer& obj);
	void set_cId(int);
	void set_bookingHistory(Service*);
	Service** get_bookingHistory();
	int get_cId();
	int get_size();
	//friend ostream& operator<< (ostream& out, const Customer & n);
	void Database();
	static void increment_cId();
	//int calculateReadsize();
	virtual ostream& print(ostream& out)const
	{
		out << "cId: " << cId << endl;
		Person::print(out);
		out << "Booking History:" << endl;
		for (int i = 0; i < size; i++)
		{
			 bookingHistory[i][0].print(out);
		}
		return out;
	}
	ifstream& read();
	ofstream& write(ofstream & out);
	void calculateReadsize();
	Customer& operator=(const Customer& obj);
	~Customer();
	ifstream& readFile(ifstream& in);

}; 
