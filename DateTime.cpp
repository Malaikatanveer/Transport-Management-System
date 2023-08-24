#include<iostream>
#include"DateTime.h"
using namespace std;

Date:: Date()
{
	day=0;
	month = 0;
	year=0;
}
Date:: Date(int d,int m,int y)
{
	day = d;
	month=m;
	year = y;
}
Date::Date(const Date & obj)
{
	this->day = obj.day;
	this->month=obj.month;
	this->year = obj.year;
}

bool Date::operator==(const Date& n)
{
	if (day == n.day && month == n.month && year == n.year)
		return true;
	else
		return false;
}
Date:: ~Date()
{
   //destructor
}


int Date :: get_day()
{
    return day;
}
int Date :: get_month()
{
    return month;
}
int Date:: get_year()
{
	return year;
}

void Date:: set_month(int m)
{
	month = m;
}
void Date ::set_day(int d)
{
	day = d;
}
void Date::set_year(int y)
{
	year = y;
}
void Date:: set_date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
ostream& operator<<(ostream & out, const Date & n)
{
	out << n.day << " / " << n.month << " / " << n.year ;
	return out;
}

ofstream& operator<<(ofstream & fout, const Date & n)
{
	fout << n.day << " " << n.month << " " << n.year ;
	return fout;
}

ifstream& operator >>(ifstream& fin,  Date& n)
{
	fin >> n.day >> n.month >> n.year;
	return fin;
}
 
istream& operator >> (istream & in, Date & n)
{
	cout << "Enter the Day: ";
	in >> n.day;
	cout << endl;
	cout << "Enter the Month: ";
	in >> n.month;
	cout << endl;
	cout << "Enter the Year: ";
	in >> n.year;
	cout << endl;
	return in;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Time::Time()
{
	hour=0;
	min=0;
	sec=0;
}
Time:: Time(int h,int m,int s)
{
	hour=h;
	min=m;
	sec=s;
}
Time::Time(const Time & obj)
{
	this->hour=obj.hour;
	this->min=obj.min;
	this->sec=obj.sec;
}

//ifstream& operator>>(ifstream& fin, const Time& n)
//{
//	
//	fin >> n.hour >> n.min >> n.sec;
//	return fin;
//}
Time::~Time()
{
    //destructor (useless)
}
void Time::set_hour(int h)
{
	hour = h;
}

void Time::set_min(int m)
{
	min = m;
}

void Time::set_sec(int s)
{
	sec = s;
}

void Time::set_time(int h,int m,int s)
{
	hour = h;
	min = m;
	sec = s;
}

int Time:: get_hour()
{
	return hour;
}
int Time ::get_min()
{
	return min;
}
int Time:: get_sec()
{
	return sec;
}

ostream& operator<<(ostream & out, const Time & n)
{
	out << n.hour << " : " << n.min << " : " << n.sec ;
	return out;
}

istream& operator>>(istream& in, Time& n)
{
	cout << "Enter hour: ";
	in >> n.hour;
	cout << "Enter min: ";
	in >> n.min;
	cout << "Enter sec: ";
	in >> n.sec;
	return in;
}
//ofstream& operator<<(ofstream & out, const Time & n)
//{
//	out << n.hour << " " << n.min << " " << n.sec ;
//	return out;
//}

