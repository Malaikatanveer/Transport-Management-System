#pragma once
#include "Service.h"
#include<iostream>
using namespace std;

class Ride: public Service
{
int noofPassengers; // false for pending, true if complete
char * rideType; // intercity, intracity
float DriverRanking; // 0 to 5 scale (worst to best)
float VehicleRanking; // 0 to 5 scale (worst to best)
//you can add more members here if required
//add member functions
public:
    Ride();
    Ride(int,char*,float,float, char* source, char* destination, float distance, int day, int month, int year, int hour, int min, int sec, bool status, float fuelrate, int cId, int dId, int vId);
    Ride(const Ride & obj);
    ~Ride();
    int get_noofPassengers();
    char* get_rideType();
    float get_DriverRanking();
    float get_VehicleRanking();

    void set_DriverRanking(float n);
    void set_VehicleRanking(float n);
    void set_rideType(char* rideType);
    void Database(int=0,int=0);
    //ifstream& read(ifstream &);
    istream& read(istream& in);
    ostream& print(ostream& out)const;
    ifstream& readFile(ifstream& in);
    //ofstream& write(ofstream& out);
    Ride& operator=(const Ride& obj);
    ofstream& write(ofstream& out);
	//friend ofstream& operator << (ofstream& out, Ride& x);
	//friend ifstream& operator >> (ifstream& in, Ride& x);

    
};

