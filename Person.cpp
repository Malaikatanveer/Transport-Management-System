#include"Person.h"
#include<iostream>
using namespace std;

Person::Person()
{
	Age = 0;
	Nid = 0;

}
Person::Person(char* fName, char* lName, int day, int month, int year, int Age, int Nid) :pName(fName, lName), DOB(day, month, year)
{
	this->Age = Age;
	this->Nid = Nid;
}

Person::Person(const Person& obj) : pName(obj.pName), DOB(obj.DOB)
{
	this->Age = obj.Age;
	this->Nid = obj.Nid;
}

Person::~Person()
{
	//destructor
}

Name Person::get_pName()
{
	return pName;
}

Date Person::get_DOB()
{
	return DOB;
}

void Person::set_pName(char* fName, char* lName)
{
	pName.set_Name(fName, lName);
}

void Person::set_DOB(int d, int m, int y)
{
	DOB.set_date(d, m, y);
}
void Person::set_Age(int x)
{
	this->Age = x;
}
void Person::set_Nid(int x)
{
	this->Nid = x;
}

ostream& operator << (ostream& out, const Person& n)
{
	out << "Name: " << n.pName << endl;
	out << "DOB: " << n.DOB << endl;
	out << "Nid: " << n.Nid << endl;
	out << "Age: " << n.Age << endl;
	return out;
}

ifstream& Person::read(ifstream& fin)
{
	fin >> pName;
	fin >> DOB;
	fin >> Nid;
	fin >> Age;
	return fin;                     
}

ofstream& Person:: write(ofstream& fout)
{
	fout << pName;
	fout << DOB;
	fout << Nid;
	fout << Age;
	return fout;
}


istream& operator >> (istream& in, Person& n)
{
	in >> n.pName;
	in >> n.DOB;
	cout << "Enter National ID: ";
	in >> n.Nid;
	cout << endl;
	cout << "Enter your Age: ";
	in >> n.Age;
	cout << endl;
	return in;                     
}

int Person::get_Age()
{
	return Age;
}

int Person::get_Nid()
{
	return Nid;
}


Person& Person:: operator=(const Person& obj)
{
	pName = obj.pName;
	DOB = obj.DOB;
	Age = obj.Age;
	Nid = obj.Nid;
	return *this;
}
