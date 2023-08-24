#include<iostream>
using namespace std;
#include"Ride.h"

Ride::Ride()
{
    noofPassengers = 0;
    rideType = nullptr;
    DriverRanking = 0.0f;
    VehicleRanking = 0.0f;

}

Ride::Ride(int noofPassengers, char* rideType, float DriverRanking, float VehicleRanking, char* source, char* destination, float distance, int day, int month, int year, int hour, int min, int sec, bool status, float fuelrate, int cId, int dId, int vId):Service(source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId)
{
    
    this->noofPassengers = noofPassengers;
    int size = strlen(rideType);
    this->rideType = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        this->rideType[i] = rideType[i];
    }
    this->rideType[size] = '\0';
    this->DriverRanking = DriverRanking;
    this->VehicleRanking = VehicleRanking;


}


Ride:: Ride(const Ride & obj) : Service(obj)
{
    this->noofPassengers = obj.noofPassengers;
    this->DriverRanking = obj.DriverRanking;
    this->VehicleRanking = obj.VehicleRanking;
    int size = strlen(obj.rideType);
    this->rideType = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        this->rideType[i] = obj.rideType[i];
    }
    this->rideType[size] = '\0';

}

void Ride::set_DriverRanking(float n)
{
    if(n>=0 && n<=5)
    {
        DriverRanking = n;
    }
    else
    {
        cout << "Error: Driver Ranking is not within range(0 to 5)";
    }
}

void Ride::set_VehicleRanking(float n)
{
    if(n>=0 && n<=5)
    {
        VehicleRanking = n;
    }
    else
    {
        cout << "Error: Vehicle Ranking is not within range(0 to 5)";
    }
}


int Ride::get_noofPassengers()
{
    return noofPassengers;
}

float Ride:: get_DriverRanking()
{
    return DriverRanking;
}

float Ride::get_VehicleRanking()
{
    return VehicleRanking;
}

 Ride::~Ride()
{
     delete[] rideType;
     rideType = nullptr;
}

 void Ride::set_rideType(char* rideType)
 {
    if(this->rideType != nullptr)
    {
	    delete[] this->rideType ;
    }

    int size = strlen(rideType);
    this->rideType = new char[size+1];
    for (int i = 0; i < size; i++)
    {
		    this->rideType[i] = rideType[i];
    }
    this->rideType[size] = '\0';
 }



char* Ride :: get_rideType()
{
     return rideType;
}

ostream& Ride::print(ostream& out)const
{
    Service::print(out);
    out << "No. of Passengers: " << noofPassengers << endl;
    out << "Ride Type: " << rideType << endl;
    out << "Driver Ranking: "<< DriverRanking << endl;
    out << "Vehicle Ranking: " << VehicleRanking << endl; 
    out << endl;
    return out;
}

void Ride::Database(int x,int y)
{
    ofstream fout;
    if (y == 0)
    {
        Service::Database(1);
        fout.open("Service.txt", ios::app);
    }
    else if (y == 1)
    {
        Service::Database(1,1);
        fout.open("Driver.txt", ios::app);
    }
    fout << noofPassengers << " ";
    fout << rideType << " ";
    fout << DriverRanking << " ";
    fout << VehicleRanking << " ";
    if(y==0)
      fout << endl;
    
    fout.close();
}

ifstream& Ride::readFile(ifstream& in)
{
    Service::readFile(in);
    in >> noofPassengers;
    char ride[15];
    in.ignore();
    in.getline(ride, 15, ' ');
    //fin.ignore();
    set_rideType(ride);
    in >> DriverRanking;
    in >> VehicleRanking;
    return in;
}

//ifstream& Ride::read(ifstream& in)
//{
//    //ifstream fin;
//    Service::read(in);
//    in >> noofPassengers;
//    char ride[15];
//    in.ignore();
//    in.getline(ride, 15, ' ');
//    //fin.ignore();
//    set_rideType(ride);
//    in >> DriverRanking;
//    in >> VehicleRanking;
//    in.close();
//    return in;
//}

istream& Ride::read(istream& in)
{
    char s[20]; char d[20]; float dis;
    Date bookingD;
    Time bookingT;
    cout << "Enter Source: ";
    in.getline(s, 20);
    cout << "Enter destination: ";
    in.getline(d, 20);
    this->set_source(s);
    this->set_destination(d);
    cout << "Enter the distance: ";
    in >> dis;
    cout << endl;
    this->set_distance(dis);
    cout << "Enter Date: ";
    in >> bookingD;
    cout << endl;
    cout << "Enter Time: ";
    in >> bookingT;
    cout << endl;
    this->set_bookingDate(bookingD);
    this->set_bookingTime(bookingT);
    cout << "Enter number of passangers: ";
    in >> noofPassengers;
    cout << endl;
    cout << "Enter ride type: ";
    in.getline(rideType, 20);
    return in;
    //cId
    //dId
    //vId
    //DriverRanking
    //Vehicle ranking 
    // yeh khud set karo


}

ofstream& Ride::write(ofstream& out)
{
    Service::write(out);
    out << noofPassengers << " " << rideType << " " << VehicleRanking << " "<<DriverRanking<<endl;
    return out;
}

 Ride& Ride::operator=(const Ride& obj)
 {
    if(rideType==nullptr)
    {
        noofPassengers = obj.noofPassengers;
        DriverRanking = obj.DriverRanking;
        VehicleRanking = obj.VehicleRanking;
        int size = strlen(obj.rideType);
        rideType = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            rideType[i] = obj.rideType[i];
        }
        rideType[size] = '\0';
    }
    else if(rideType!=nullptr)
    {
        delete[] rideType;
        noofPassengers = obj.noofPassengers;
        DriverRanking = obj.DriverRanking;
        VehicleRanking = obj.VehicleRanking;
        int size = strlen(obj.rideType);
        rideType = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            rideType[i] = obj.rideType[i];
        }
        rideType[size] = '\0';
    }
    return *this;
 }