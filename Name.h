#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class Name {
private:
	char* fName;
	char* lName;
public:
	Name();
	Name(char* fN, char* lN);
	Name(const Name& obj);
	//add following functions //Getter, Setters 
	//Destructor, Default Constructor, Copy Constructor, 
	friend ostream& operator << (ostream& out, const Name& n);
	friend ofstream& operator << (ofstream& out, Name& x);
	friend ifstream& operator >> (ifstream& in, Name& x);
	friend istream& operator >> (istream& in, Name& x);
	char* get_lName();
	char* get_fName();
	void set_Name(char * fName, char* lName);
	Name& operator=(const Name& obj);
	~Name();
};
