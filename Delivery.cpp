#include"Delivery.h"
#include<iostream>
using namespace std;

Delivery::Delivery()
{
	goodsWeight = 0.0f;
	goodsType = nullptr;
	deliveryType = nullptr;
}

Delivery::Delivery(float goodsWeight, char* goodsType, char * deliveryType,char* source, char* destination, float distance, int day, int month, int year, int hour, int min, int sec, bool status, float fuelrate, int cId, int dId, int vId):Service(source, destination, distance, day, month, year, hour, min, sec, status, fuelrate, cId, dId, vId)
{
	this->goodsWeight = goodsWeight;
	int size = strlen(goodsType);
	this->goodsType = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->goodsType[i] = goodsType[i];
	}
	this->goodsType[size] = '\0';
	int size2 = strlen(deliveryType);
	this->deliveryType = new  char[size2 + 1];
	for (int i = 0; i < size2; i++)
	{
		this->deliveryType[i] = deliveryType[i];
	}
	this->deliveryType[size2] = '\0';

}


Delivery::Delivery(const Delivery & obj) : Service(obj)
{
    goodsWeight=obj.goodsWeight;
	int s = strlen(obj.goodsType);
	this->goodsType = new char[s + 1];
	for(int i=0;i<s;i++)
	{
		this->goodsType[i]=obj.goodsType[i];
	}
	this->goodsType[s] = '\0';
	int s2 = strlen(obj.deliveryType);
	this->deliveryType = new char[s2 + 1];
	for(int i=0;i<s2;i++)
	{
		this->deliveryType[i]=obj.deliveryType[i];
	}
	this->deliveryType[s2] = '\0';
}


 Delivery:: ~Delivery()
 {
	  	 delete[]goodsType; 
		 goodsType = nullptr;
	     delete[]deliveryType; 
		 deliveryType = nullptr;
 }

float Delivery::get_goodsWeight()
{
	return goodsWeight;
}

char* Delivery::get_goodsType()
{
	return goodsType;
}

char* Delivery::get_deliveryType()
{
	return deliveryType;
}

void Delivery::set_goodsWeight(float x)
{
	{
		goodsWeight = x;
	}
}

void Delivery::set_goodsType(char* goodsType)
{
	if(this->goodsType != nullptr)
    {
	   delete[] this->goodsType ;
	}

	int size = strlen(goodsType);
	this->goodsType = new char[size+1];
	for (int i = 0; i < size; i++)
	{
			this->goodsType[i] = goodsType[i];
	}
	this->goodsType[size] = '\0';
}


 void Delivery ::set_deliveryType(char* rideType)
 {
    if(this->deliveryType != nullptr)
    {
	    delete[] this->deliveryType ;
    }

    int size = strlen(rideType);
    this->deliveryType = new char[size+1];
    for (int i = 0; i < size; i++)
    {
		    this->deliveryType[i] = deliveryType[i];
    }
    this->deliveryType[size] = '\0';
 }



void Delivery::Database(int x,int y)
{
	ofstream fout;
	if (y == 0)
	{
		Service::Database(2);
		fout.open("Service.txt", ios::app);
	}
	else if (y == 1)
	{
		Service::Database(2,1);
		fout.open("Driver.txt", ios::app);
	}
	fout << goodsWeight << " ";
	fout << goodsType << " ";
	fout << deliveryType << " ";
	if(y==0)
	   fout << endl;

	fout.close();
}

ostream& Delivery::print(ostream& out)const
{
	Service::print(out);
	out <<"Goods Weight: "<< goodsWeight << endl;
	out << "Goods Type: " << goodsType << endl;
	out << "Delivery type: " << deliveryType << endl;
	out << endl;
	return out;
}
	


ifstream& Delivery::readFile(ifstream& in)
{
	//ifstream fin;
	Service::readFile(in);
	in >> goodsWeight;
	char goods[15];
	in.ignore();
	in.getline(goods, 15, ' ');
	//fin.ignore();
	set_goodsType(goods);
	char DeliveryT[15];
	in.getline(deliveryType,' ');
	return in;
}

istream& Delivery:: read(istream& in)
{

	char s[20];
	char d[20];
	float dis;
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
	float gw; char gt[20]; char dt[20];
	cout << "Enter Goods Weight: "; 
	in >> gw;
	this->set_goodsWeight(gw);
	cout << endl;
	cout << "Enter Goods Type: ";
	in.getline(gt,20);
	this->set_goodsType(gt);
	cout << endl;
	cout << "Enter Delivery type: ";
	in.getline(dt, 20);
	this->set_deliveryType(dt);
	cout << endl;
	return in;
	//cId
   //dId
   //vId
   // yeh khud set karo
}

ofstream& Delivery::write(ofstream& out)
{
	Service::write(out);
	out << goodsWeight << " " << goodsType << " " << deliveryType<<endl;
	return out;
}

Delivery& Delivery::operator=(const Delivery& obj)
{
	if(goodsType == nullptr && deliveryType == nullptr)
	{
		goodsWeight=obj.goodsWeight;
		int s = strlen(obj.goodsType);
		this->goodsType = new char[s + 1];
		for(int i=0;i<s;i++)
		{
			this->goodsType[i]=obj.goodsType[i];
		}
		this->goodsType[s] = '\0';
		int s2 = strlen(obj.deliveryType);
		this->deliveryType = new char[s2 + 1];
		for(int i=0;i<s2;i++)
		{
			this->deliveryType[i]=obj.deliveryType[i];
		}
		this->deliveryType[s2] = '\0';
	}

	else if(goodsType != nullptr && deliveryType != nullptr)
	{
		delete[] goodsType;
		delete[] deliveryType;
		goodsWeight=obj.goodsWeight;
		int s = strlen(obj.goodsType);
		this->goodsType = new char[s + 1];
		for(int i=0;i<s;i++)
		{
			this->goodsType[i]=obj.goodsType[i];
		}
		this->goodsType[s] = '\0';
		int s2 = strlen(obj.deliveryType);
		this->deliveryType = new char[s2 + 1];
		for(int i=0;i<s2;i++)
		{
			this->deliveryType[i]=obj.deliveryType[i];
		}
		this->deliveryType[s2] = '\0';
	}
	return *this;
}