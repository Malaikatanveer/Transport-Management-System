#pragma once
#include<iostream>
#include <fstream>
using namespace std;
class Date
{ 
int day; 
int month; 
int year; 
//add constructurs getter setters and stream output function, which output date in  given format day / Mon / Year 
public:
    Date();
	Date(int, int, int);
	Date(const Date & obj);
	~Date();
    int get_day();
    int get_month();
    int get_year();
    void set_month(int);
    void set_day(int);
    void set_year(int);
    void set_date(int, int, int);
    friend ostream& operator<<(ostream & out, const Date & n);
	friend istream& operator >> (istream& in, Date& n);
	friend ofstream& operator <<(ofstream & fout, const Date & n);
	friend ifstream& operator >>(ifstream& fin,  Date& n);
	bool operator==(const Date& n);
}; 


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Time
{ 
int hour; 
int min; 
int sec; 
//add constructurs getter setters and stream output function, which output time in  given format Hr : Min : Sec
public:
	Time();
	Time(int, int, int);
	Time(const Time& obj);
	int get_hour();
	int get_min();
	int get_sec();
	void set_time(int, int, int);
	void set_hour(int);
	void set_min(int);
	void set_sec(int);
	friend ostream& operator<<(ostream & out, const Time & n);
	friend istream& operator>>(istream& in,  Time& n);
	friend ofstream& operator<<(ofstream& out, const Time& n)
	{
		out << n.hour << " " << n.min << " " << n.sec;
		return out;
	}
	friend ifstream& operator>>(ifstream& fin,  Time& n)
	{
		
		fin >> n.hour >> n.min >> n.sec;
		return fin;
	}
	~Time();

};
