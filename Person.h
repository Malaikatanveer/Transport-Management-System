#pragma once
#include"DateTime.h"
#include"Name.h"
#include<iostream>
#include <fstream>
using namespace std;

class Person 
{
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;
public:
	//add following functions in this class //Getter, Setters 
	//Destructor, Default and Parametrized Constructor, Copy Constructor, Output  operator (print information of person) 
	Person();
	Person(char* fName, char* lName, int day, int month, int year, int Age, int Nid);
	Person(const Person& obj);
	virtual ~Person();
	Name get_pName();
	Date get_DOB();
	int get_Nid();
	int get_Age();
	void set_pName(char*,char*);
	void set_DOB(int,int,int);
	void set_Age(int);
	void set_Nid(int);
	virtual ostream& print(ostream& out)const
	{
		out << "Name: " << pName << endl;
		out << "DOB: " << DOB << endl;
		out << "Nid: " << Nid << endl;
		out << "Age: " << Age << endl;
		out << endl;
		return out;
	}
	void save(int x=0)
	{
		ofstream fout;
		if(x==0)
		   fout.open("Service.txt", ios::app);
		else if(x==1)
			fout.open("Driver.txt", ios::app);
		fout << pName;
		fout << DOB<<" ";
		fout << Nid<<" ";
		fout << Age << endl;
		
		fout.close();
	}
	Person& operator=(const Person& obj);
	friend ostream& operator << (ostream& out, const Person& n);
	friend istream& operator >> (istream& in, Person& n);
	ifstream& read(ifstream& fin);
	ofstream& write(ofstream& fout);
};
