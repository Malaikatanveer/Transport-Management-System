#include<iostream>
using namespace std;
#include"Service.h"
#include<fstream>

Service::Service()
{
	source=nullptr;
	destination = nullptr;
	distance = 0.0f;
	status = false;
	fuelrate = 0.0f;
	cId = 0;
	dId = 0;
	vId = 0;
}

Service::Service(char* source, char* destination, float distance, int day, int month, int year, int hour, int min, int sec, bool status, float fuelrate, int cId, int dId, int vId) :bookingDate(day, month, year), bookingTime(hour, min, sec)
{
	int size = strlen(source);
	this->source = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		this->source[i] = source[i];
	}
	this->source[size] = '\0';
	size = strlen(destination);
	this->destination = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		this->destination[i] = destination[i];
	}
	this->destination[size] = '\0';

	this->distance = distance;

	this->status = status;

	this->fuelrate = fuelrate;

	this->cId = cId;
	this->vId = vId;
	this->dId = dId;
}

Service::Service(const Service & obj)
{
	int size = strlen(obj.source);
	this->source = new char[size];
	for (int i = 0; i < size; i++)
	{
		this->source[i] = obj.source[i];
	}
	this->source[size] = '\0';
	size = strlen(obj.destination);
	this->destination = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		this->destination[i] = obj.destination[i];
	}
	this->destination[size] = '\0';


	this->distance = obj.distance;
	this->status = obj.status;
	this->fuelrate = obj.fuelrate;
	this->cId = obj.cId;
	this->dId = obj.dId;
	this->vId=obj.vId;
	this->bookingDate = obj.bookingDate;
	this->bookingTime = obj.bookingTime;
}


char* Service::get_source()
{
	return source;
}

char* Service::get_destination()
{
	return destination;
}

float Service::get_distance()
{
	return distance;
}

Date Service::get_bookingDate()
{
	return bookingDate;
}

Time Service::get_bookingTime()
{
	return bookingTime;
}

bool Service::get_status()
{
	return status;
}

float Service::get_fuelrate()
{
	return fuelrate;
}

int Service::get_cId()
{
	return cId;
}

int Service::get_dId()
{
		return dId;
}

int Service::get_vId()
{
		return vId;
}

void  Service::set_cId(int x)
{
     cId=x;
}

void Service:: set_dId(int x)
{
     dId=x;
}

void Service::set_vId(int x)
{
	vId = x;
}

void Service:: set_fuelrate(float x)
{
	fuelrate = x;
}

void Service::set_status(bool x)
{
	status = x;
}

void Service::set_distance(float d)
{
	distance = d;
}



void Service::set_source(char* source)
{
	if(this->source != nullptr)
	{
		delete[] this->source;
	}
	int size = strlen(source);
	this->source = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		this->source[i] = source[i];
	}
	this->source[size] = '\0';
}

void Service::set_destination(char* destination)
{
   if(this->destination != nullptr)
   {
	   delete[] this->destination;
   }

   int size = strlen(destination);
   this->destination = new char[size+1];
   for (int i = 0; i < size; i++)
   {
		  this->destination[i] = destination[i];
   }
   this->destination[size] = '\0';

}

Service::~Service()
{
	delete[] source;
	delete[] destination;
	source = nullptr;
	destination=nullptr;
}

//ostream& Service::operator << (ostream& out, const Service& n)
//{
//	out << "source: " << n.source << endl;
//	out << "destination: " << n.destination << endl;
//	out << "distance: " << n.distance << endl;
//	out << "status: " << n.status << endl;
//	out << "fuelrate: " << n.fuelrate << endl;
//	out << "cId: " << n.cId << endl;
//	out << "dId: " << n.dId << endl;
//	out << "vId: " << n.vId << endl;
//	return out;
//}

ostream& Service::print(ostream& out)const
{
	out << "source: " << source << endl;
	out << "destination: " << destination << endl;
	out << "distance: " << distance << endl;
	out << "status: " << status << endl;
	out << "fuelrate: " << fuelrate << endl;
	out << "Booking Date: " << bookingDate<<endl;
	out << "Booking Time: " << bookingTime<<endl;
	out << "cId: " << cId << endl;
	out << "dId: " << dId << endl;
	out << "vId: " << vId << endl;
	return out;
}

ofstream& Service::write(ofstream& out)
{
	out << source << " ";
	out << destination<< " ";
	out << distance<< " ";
	out << status << " ";
	out << fuelrate << " ";
	out << bookingDate << " ";
	out << bookingTime << " ";
	out << cId << " ";
	out << dId << " ";
	out << vId << " ";
	return out;
}

ifstream& Service::readFile(ifstream& in)
{
	char s[20];
	char d[20];
	in >> dId;
	in >> vId;
	in.ignore();
	in.getline(s, 20, ' ');
	set_source(s);
	in.getline(d, 20, ' ');
	set_destination(d);
	in >> distance;
	in >> status;
	in >> fuelrate;
	in >> bookingDate;
	in >> bookingTime;
	return in;
}

void Service::Database(int x,int y)
{
	ofstream fout;
	if (y == 0)
	{
		fout.open("Service.txt", ios::app);

		fout << cId << " ";
		if (x == 1)
			fout << "R ";
		else if (x == 2)
			fout << "D ";
		fout << dId << " ";
	}
	else if (y == 1)
	{
		
		fout.open("Driver.txt", ios::app);

		fout << dId << " ";
		if (x == 1)
			fout << "R ";
		else if (x == 2)
			fout << "D ";
		fout << cId << " ";
	}
	
	fout << vId << " ";
	fout << source << " ";
	fout << destination << " ";
	fout << distance<< " ";
	fout << status << " ";
	fout << fuelrate  << " ";
	fout << bookingDate << " ";
	fout << bookingTime << " ";
	
	fout.close();

}

//ifstream& Service::read(istream & fin)
//{
//	char s[20];
//	char d[20];
//	fin >> dId;
//	fin >> vId;
//	fin.ignore();
//	fin.getline(s, 20, ' ');
//	set_source(s);
//	fin.getline(d, 20, ' ');
//	set_destination(d);
//	fin >> distance;
//	fin >> status;
//	fin >> fuelrate;
//	fin >> bookingDate;
//	fin >> bookingTime;
//	return fin;
	
//	fin.close();
//	return fin;
//}

void Service::set_bookingDate(const Date& d)
{
	bookingDate = d;
}

void Service::set_bookingTime(const Time& t)
{
	bookingTime = t;
}




Service& Service:: operator=(const Service& obj)
{
    if(this!=&obj)
	{
		source = new char[*(obj.source)];
		strcpy(source, obj.source);
		destination = new char[*(obj.destination)];
		strcpy(destination, obj.destination);
		distance = obj.distance;
		status = obj.status;
		bookingDate = obj.bookingDate;
		bookingTime = obj.bookingTime;
		fuelrate = obj.fuelrate;
	    cId = obj.cId;
		dId = obj.dId;
	    vId = obj.vId;
	}
	else if(this->source==nullptr && this->destination== nullptr && source==nullptr && destination==nullptr)
	{
		source = new char[*(obj.source)];
		strcpy(source, obj.source);
		destination = new char[*(obj.destination)];
		strcpy(destination, obj.destination);
	    distance = obj.distance;
		bookingDate = obj.bookingDate;
		bookingTime = obj.bookingTime;
		status = obj.status;
		fuelrate = obj.fuelrate;
	    cId = obj.cId;
		dId = obj.dId;
	    vId = obj.vId;

	}
	else if(this->source!=nullptr && this->destination!= nullptr && source!=nullptr && destination!=nullptr)
	{
		delete[]source;
		delete[]destination;
		distance = obj.distance;
		bookingDate = obj.bookingDate;
		bookingTime = obj.bookingTime;
		status = obj.status;
		fuelrate = obj.fuelrate;
	    cId = obj.cId;
		dId = obj.dId;
	    vId = obj.vId;
		delete source;
		source = nullptr;
		int l = strlen(obj.source);
		source = new char[l];
		for(int i=0;i<l;i++)
		{
			source[i]=obj.source[i];
		}
		delete destination;
		destination = nullptr;
		int l2 = strlen(obj.destination);
		for(int i=0;i<l2;i++)
		{
			destination[i] = obj.destination[i];
		}
	}
	return *this;
}
