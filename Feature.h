#pragma once
#include <cstring>
#include<iostream>
using namespace std;

class Feature
{
private:
	static int fId;
	char * description;
	float cost;
	
public:
	Feature();
	Feature(char * description, float cost);
	Feature(const Feature& f);

	int get_fId();
	char* get_description();
	float get_cost();
	
	void increment_fId();

	void set_fId(int x);
	void set_description(char* x);
	void set_cost(float x);
	Feature& operator=(const Feature& obj);
	~Feature();
	friend ostream& operator<<(ostream& out, const Feature& n);
	ofstream& write(ofstream&);
	ifstream& readFile (ifstream&);


//you can add more members here if required
//add member functions
};
