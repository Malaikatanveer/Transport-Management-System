#pragma once
#include <iostream>
#include"Service.h"
#include <cstring>
#include"Person.h"
#include<fstream>
using namespace std;

class Driver : public Person
{
private:
	static int dId;
	char** LicencesList;
	Service** serviceHistory;
	int LL_size;
	float overallRanking;
	float salary;
	int experience;
	int status; // 1 for free, 2 if booked and 3 if canceled
	int SH_size;
public:
	Driver();
	Driver(int dId, char** LicencesList, int LL_size, float overallRanking, float salary, int experience, int status, int SH_size, Service** serviceHistory);
	Driver(char** LicencesList, int LL_size, int experience, char* fName, char* lName, int day, int month, int year, int Age, int Nid);
	Driver(const Driver& x);
	//operator (prints complete information of Driver)

	static void increment_dId();

	int get_dId();
	char** get_LicencesList();
	int get_LL_size();
	float get_overallRanking();
	float get_salary();
	int get_experience();
	int get_status();
	Service** get_serviceHistory();
	int get_SH_size();
	void set_dId(int d);
	void set_LicencesList(char* L);
	void set_LL_size(int x);
	void set_overallRanking(float x);
	void set_salary(float x);
	void set_experience(float x);
	void set_status(int x);
	void set_serviceHistory(Service* s);
	void Database();
	ifstream& readFile(ifstream& in);
	//void calculateReadsize();
	ofstream& write(ofstream &out);
	Driver& operator=(const Driver& obj);
	~Driver();
};
