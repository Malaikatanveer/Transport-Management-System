#include"Name.h"
#include<iostream>
#include <fstream>
using namespace std;

Name::Name()
{
	fName = nullptr;
	lName = nullptr;
}

Name::Name(char* fN, char* lN)
{
	int size = strlen(fN);
	fName = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		fName[i] = fN[i];
	}
	fName[size] = '\0';
	size = strlen(lN);
	lName = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		lName[i] = lN[i];
	}
	lName[size] = '\0';

}
Name::~Name()
{
	delete[]fName;
	delete[]lName;
	fName = nullptr;
	lName = nullptr;
}
Name::Name(const Name& obj)
{
	int size = strlen(obj.fName);
	fName = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		fName[i] = obj.fName[i];
	}
	fName[size] = '\0';
	size = strlen(obj.lName);
	lName = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		lName[i] = obj.lName[i];
	}
	lName[size] = '\0';
}

char* Name::get_lName()
{
	return lName;
}

char* Name::get_fName()
{
	return fName;
}

void Name::set_Name(char * fN, char* lN)
{
	int size = strlen(fN);
	fName = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		fName[i] = fN[i];
	}
	fName[size] = '\0';
	size = strlen(lN);
	lName = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		lName[i] = lN[i];
	}
	lName[size] = '\0';
}

ostream& operator<<(ostream& out, const Name& n) {
	out << n.fName << " " << n.lName;
	return out;
}

ofstream& operator << (ofstream& out, Name& x)
{
	out << x.fName << " ";
	out << x.lName << " ";
	return out;
}

ifstream& operator >> (ifstream& in, Name& x)
{
	if (x.fName == nullptr && x.lName == nullptr)
	{
		char f[15];
		char s[15];
		in.ignore();
		in.getline(f,15,' ');
		in.getline(s,15,' ');
	    x.set_Name(f, s);
	}
	return in;
}

istream& operator >> (istream& in, Name& x)
{
	if (x.fName == nullptr && x.lName == nullptr)
	{
		char f[15];
		char s[15];
		cout << "Enter first name: ";
		in.getline(f, 15, ' ');
		cout << "Enter second name: ";
		in.getline(s, 15, ' ');
		x.set_Name(f, s);
	}
	return in;
}


Name& Name:: operator=(const Name& obj)
{
	if(fName==nullptr && obj.fName!=nullptr && lName==nullptr && obj.lName!=nullptr)
	{
		int l = strlen(obj.fName);
	    this->fName = new char[l];
	    strcpy(this->fName, obj.fName);
		int l2 = strlen(obj.lName);
	    this->lName = new char[l2];
	    strcpy(this->lName, obj.lName);
	}
	else if(fName!=nullptr && obj.fName!=nullptr && lName!=nullptr && obj.lName!=nullptr)
	{
		delete[]fName;
		delete[]lName;
		int l = strlen(obj.fName);
	    this->fName = new char[l];
	    strcpy(this->fName, obj.fName);
		int l2 = strlen(obj.lName);
	    this->lName = new char[l2];
	    strcpy(this->lName, obj.lName);
	}
	return *this;
}
