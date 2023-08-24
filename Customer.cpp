#include"Customer.h"
using namespace std;
#include<iostream>

int Customer::cId = 0;

Customer::Customer()
{
	increment_cId();
	size = 0;
	bookingHistory = nullptr;
}

Customer::Customer(char* fName, char* lName, int day, int month, int year, int Age, int Nid) : Person(fName, lName, day, month, year,Age, Nid)
{
	increment_cId();
}

Customer::Customer(int cId, Service** bookingHistory, int size)
{
	this->cId = cId;
	this->bookingHistory = new Service * [size];
	for (int i = 0; i < size; i++)
	{
		this->bookingHistory[i] = bookingHistory[i];
	}
}


Customer::Customer(const Customer& obj):Person(obj)
{
	this->cId = obj.cId;
	this->size = obj.size;
	this->bookingHistory = new Service * [size];
	for(int i=0;i<size;i++)
	{
		this->bookingHistory[i] = obj.bookingHistory[i];
	}
}

void Customer::set_bookingHistory(Service* khidmat)
{
	++size;
	Service** temp= new Service * [size];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = bookingHistory[i];
		bookingHistory[i] = nullptr;
	}
	temp[size - 1] = khidmat;
	bookingHistory = temp;
	temp = nullptr;
}

Service** Customer::get_bookingHistory()
{
	return bookingHistory;
}

int Customer::get_cId()
{
	return cId;
}

int Customer:: get_size()
{
	return size;
}

void Customer::set_cId(int x)
{
	cId = x;
}

Customer::~Customer()
{
	delete[] bookingHistory;
	bookingHistory = nullptr;
}

//ostream& operator<< (ostream& out, const Customer & n)
//{ 
	
//	out << "cId: " << n.cId << endl;
//	out << "Booking History:" << endl;
//	for(int i = 0; i < n.size; i++)
//	{
//		n.bookingHistory[i][0].print();
//	}
//	return out;
//}

void Customer::Database()
{
	ofstream fout;
	fout.open("Service.txt", ios::app);
	fout << cId << " ";

	fout.close();
	Person::save();
	
	for (int i = 0; i < size; i++)
	{
		bookingHistory[i]->Database();
	}
	
}

void Customer::increment_cId()
{
	cId++;
}

ofstream& Customer::write(ofstream &out)
{
	out << cId << " " << size << " ";
	for (int i = 0; i < size; i++)
	{
		bookingHistory[i]->write(out);
		out << endl;
	}
	return out;
}

ifstream& Customer::readFile(ifstream& in)
{

	in >> cId >> size;
	for (int i = 0; i < size; i++)
	{
		bookingHistory[i]->readFile(in);
		
	}
	return in;
}

Customer& Customer ::operator=(const Customer& obj)
{

   if(bookingHistory==nullptr && obj.bookingHistory!=nullptr)
   {
		cId = obj.cId;
		size = obj.size;
		bookingHistory = new Service * [size];
		for(int i = 0 ; i < size; i++)
		{
			this->bookingHistory[i] = obj.bookingHistory[i];
		}
   }

   else if(bookingHistory!=nullptr && obj.bookingHistory!=nullptr)
   {
	   for (int i = 0; i <size; i++)
	   {
		   delete[]bookingHistory[i];
	   }
	    delete[]bookingHistory;
	    cId = obj.cId;
		size = obj.size;
		delete bookingHistory;
		bookingHistory = nullptr;
		bookingHistory = new Service * [size];
		for(int i = 0 ; i < size; i++)
		{
			this->bookingHistory[i] = obj.bookingHistory[i];
		}
   }
   return *this;
}


