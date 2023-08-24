
#include"Vehicle.h"
#include<iostream>
using namespace std;

//---------------------Vehicle finctions---------------------------
int Vehicle::vId = 0;
Vehicle::Vehicle()
{
	increment_vId();
	registrationNo = 0;
	avgMileage = 0.0f;
	LicenceType = nullptr;
	status = true;
	fueltype = nullptr;
	overallRanking = 0.0;
	serviceHistory = nullptr;
	size = 0;
	/*s_category = 0;
	Category = nullptr;*/
	category = '\0';

}

Vehicle::Vehicle(int x, float y, char* lt, bool s, char* ft, Date d, int f_size, Feature* f, char category, char* v_name)
{
	increment_vId();
	registrationNo = x;
	avgMileage = y;
	int l = strlen(lt);
	this->LicenceType = new char[l];
	strcpy(this->LicenceType, lt);
	status = s;
	int l2 = strlen(ft);
	this->fueltype = new char[l2];
	strcpy(this->fueltype, ft);
	manufacturingDate = d;
	list = f;
	this->category = category;
	this->feature_size = f_size;
	for (int i = 0; i < f_size; i++)
	{
		list[i] = f[i];
	}
	this->vn_size = strlen(v_name);
	this->vName = new char[vn_size];
	strcpy(vName, v_name);
}

Vehicle::Vehicle(int x, float y, char* lt, bool s, char* ft, float rank, Date d, int f_size, Feature* f, Service** obj, int S, char category, char* v_name, int vn_size)
{
	increment_vId();
	registrationNo = x;
	avgMileage = y;
	int l = strlen(lt);
	this->LicenceType = new char[l];
	strcpy(this->LicenceType, lt);
	status = s;
	int l2 = strlen(ft);
	this->fueltype = new char[l2];
	strcpy(this->fueltype, ft);
	overallRanking = rank;
	manufacturingDate = d;
	size = S;
	list = f;
	this->serviceHistory = new Service * [size];
	for (int i = 0; i < size; i++)
	{
		this->serviceHistory[i] = obj[i];
	}
	this->category = category;
	this->feature_size = f_size;
	for (int i = 0; i < f_size; i++)
	{
		list[i] = f[i];
	}
	this->vn_size = vn_size;
	this->vName = new char[vn_size];
	strcpy(vName, v_name);
}


Vehicle::Vehicle(const Vehicle& v)
{
	this->registrationNo = v.registrationNo;
	this->size = v.size;
	this->avgMileage = v.avgMileage;
	int l = strlen(LicenceType);
	this->LicenceType = new char[l];
	strcpy(this->LicenceType, v.LicenceType);
	this->status = v.status;
	int l2 = strlen(fueltype);
	this->fueltype = new char[l2];
	strcpy(this->fueltype, v.fueltype);
	this->overallRanking = v.overallRanking;
	this->manufacturingDate = v.manufacturingDate;
	//list = new Feature[1];
	//this->list = v.list;
	//this->s_category = v.s_category;
	this->serviceHistory = new Service * [size];
	for (int i = 0; i < size; i++)
	{
		this->serviceHistory[i] = v.serviceHistory[i];
	}
	this->category = v.category;
	/*this->s_category = v.s_category;
	for(int i=0;i<s_category;i++)
	{
		this->Category[i] = v.Category[i];
	}*/
	this->feature_size = v.feature_size;
	for (int i = 0; i < v.feature_size; i++)
	{
		list[i] = v.list[i];
	}
	this->vn_size = v.vn_size;
	this->vName = new char[vn_size];
	strcpy(vName, v.vName);

}


Date Vehicle::get_manufacturingDate()
{
	return manufacturingDate;
}

bool Vehicle::get_status()
{
	return status;
}

float Vehicle::get_overallRanking()
{
	return overallRanking;
}

char* Vehicle::get_vName()
{
	return vName;
}
char* Vehicle::get_fueltype()
{
	return fueltype;
}

char* Vehicle::get_LicenceType()
{
	return LicenceType;
}

void Vehicle::increment_vId()
{
	vId++;
}

int Vehicle::get_registrationNo()
{
	return registrationNo;
}

float Vehicle::get_avgMileage()
{
	return get_avgMileage();
}

char Vehicle::get_category()
{
	return category;
}

int Vehicle::get_feature_size()
{
	return feature_size;
}
//Feature Vehicle::get_list()
//{
//	return list;
//}

Service** Vehicle::get_serviceHistory()
{
	return serviceHistory;
}

void Vehicle::set_registrationNo(int x)
{
	registrationNo = x;
}

void Vehicle::set_avgMileage(float x)
{
	avgMileage = x;
}

void Vehicle::set_LicenceType(char* x)
{

	int size = strlen(x);
	LicenceType = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		LicenceType[i] = x[i];
	}
	LicenceType[size] = '\0';

}
void Vehicle::set_status(bool x)
{
	status = x;
}

void Vehicle::set_fueltype(char* x)
{
	int size = strlen(x);
	fueltype = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		fueltype[i] = x[i];
	}
	fueltype[size] = '\0';
}

void Vehicle::set_overallRanking(float x)
{
	overallRanking = x;
}

void Vehicle::set_manufacturingDate(const Date& obj)
{
	manufacturingDate = obj;
}

//void Vehicle:: set_list(const Feature& obj)
//{
//	list = obj;
//}

void Vehicle::set_serviceHistory(Service* khidmat)
{
	++size;
	Service** temp = new Service * [size];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = serviceHistory[i];
		serviceHistory[i] = nullptr;
	}
	temp[size - 1] = khidmat;
	serviceHistory = temp;
	temp = nullptr;
}

//void Vehicle::set_Category(Service* khidmat)
//{
//	++s_category;
//	Service** temp= new Service * [s_category];
//	for (int i = 0; i < s_category - 1; i++)
//	{
//		temp[i] = Category[i];
//		Category[i] = nullptr;
//	}
//	temp[s_category - 1] = khidmat;
//	Category = temp;
//	temp = nullptr;
//}
//
//Service** Vehicle::get_Category()
//{
//	return Category;
//}

int Vehicle::get_vId()
{
	return vId;
}

ostream& operator << (ostream& out, const Vehicle& n)
{
	out << "Vehicle Name: " << n.vName << endl;
	out << "Vehicle Register number: " << n.registrationNo << endl;
	out << "Average mileage: " << n.avgMileage << endl;
	out << "License type:" << n.LicenceType << endl;
	out << "Status(0 or 1): " << n.status << endl;
	out << "Fuel type: " << n.fueltype << endl;
	out << " Overall Ranking: " << n.overallRanking << endl;
	out << "Manufacturing Date: " << n.manufacturingDate << endl;
	out << "Service History: " << endl;
	for (int i = 0; i < n.size; i++)
	{
		out << n.serviceHistory[i] << endl;
	}
	for (int i = 0; i < n.feature_size; i++)
	{
		out << n.list[i] << endl;
	}
	out << "Category: " << n.category << endl;
	return out;
}

float Vehicle::Features_cost()
{
	float cost = 0;
	for (int i = 0; i < feature_size; i++)
	{
		cost = cost + list[i].get_cost();
	}
	return cost;
}

ofstream& Vehicle::write(ofstream& out)
{
	out << vName << "  ";
	out << registrationNo << "  ";
	out << avgMileage << "  ";
	out << LicenceType << "  ";
	out << status << "  ";
	out << fueltype << "  ";
	out << overallRanking << "  ";
	out << manufacturingDate << "  ";
	out << category;
	for (int i = 0; i < size; i++)
	{
		serviceHistory[i]->write(out) << endl;
	}
	for (int i = 0; i < feature_size; i++)
	{
		list[i].write(out) << endl;
	}
	return out;
}


Vehicle& Vehicle:: operator=(const Vehicle& v)
{
	if (LicenceType == nullptr && v.LicenceType != nullptr && list == nullptr && v.list != nullptr && fueltype == nullptr && v.fueltype != nullptr && serviceHistory == nullptr && v.serviceHistory != nullptr && vName == nullptr && v.vName != nullptr)
	{
		this->registrationNo = v.registrationNo;
		this->size = v.size;
		this->avgMileage = v.avgMileage;
		this->status = v.status;
		this->overallRanking = v.overallRanking;
		this->manufacturingDate = v.manufacturingDate;
		//this->list = v.list;
		this->category = v.category;
		this->feature_size = v.feature_size;
		this->vn_size = v.vn_size;
		int l = strlen(LicenceType);
		this->LicenceType = new char[l];
		strcpy(this->LicenceType, v.LicenceType);
		int l2 = strlen(fueltype);
		this->fueltype = new char[l2];
		strcpy(this->fueltype, v.fueltype);
		this->serviceHistory = new Service * [size];
		for (int i = 0; i < size; i++)
		{
			this->serviceHistory[i] = v.serviceHistory[i];
		}
		for (int i = 0; i < v.feature_size; i++)
		{
			list[i] = v.list[i];
		}
		this->vName = new char[vn_size];
		strcpy(vName, v.vName);
	}
	else  if (LicenceType != nullptr && v.LicenceType != nullptr && list != nullptr && v.list != nullptr && fueltype != nullptr && v.fueltype != nullptr && serviceHistory != nullptr && v.serviceHistory != nullptr && vName != nullptr && v.vName != nullptr)

	{
		delete[] LicenceType;
		delete[]list;
		delete[]fueltype;
		delete[]vName;
		for (int i = 0; i < size; i++)
		{
			delete[]serviceHistory[i];
		}
		delete[]serviceHistory;
		this->registrationNo = v.registrationNo;
		this->size = v.size;
		this->avgMileage = v.avgMileage;
		int l = strlen(LicenceType);
		this->LicenceType = new char[l];
		strcpy(this->LicenceType, v.LicenceType);
		this->status = v.status;
		int l2 = strlen(fueltype);
		this->fueltype = new char[l2];
		strcpy(this->fueltype, v.fueltype);
		this->overallRanking = v.overallRanking;
		this->manufacturingDate = v.manufacturingDate;
		//this->list = v.list;
		this->serviceHistory = new Service * [size];
		for (int i = 0; i < size; i++)
		{
			this->serviceHistory[i] = v.serviceHistory[i];
		}
		this->category = v.category;
		this->feature_size = v.feature_size;
		for (int i = 0; i < v.feature_size; i++)
		{
			list[i] = v.list[i];
		}
		this->vn_size = v.vn_size;
		this->vName = new char[vn_size];
		strcpy(vName, v.vName);
	}
	return *this;
}

Vehicle::~Vehicle()
{
	delete[] LicenceType;
	delete[]list;
	delete[]fueltype;
	delete[]vName;
	for (int i = 0; i < size; i++)
	{
		delete[]serviceHistory[i];
	}
	delete[]serviceHistory;
	LicenceType = nullptr;
	list = nullptr;
	fueltype = nullptr;
	vName = nullptr;
	serviceHistory = nullptr;
}

ifstream& Vehicle::readFile(ifstream& in)
{
	in.getline(vName, 20);
	in >> registrationNo;
	in >> avgMileage;
	in.ignore();
	in.getline(LicenceType, 20);
	in >> status;
	in.ignore();
	in.getline(fueltype, 20);
	in >> overallRanking;
	in >> manufacturingDate;
	in >> category;
	for (int i = 0; i < size; i++)
	{
		serviceHistory[i]->readFile(in);
	}
	for (int i = 0; i < feature_size; i++)
	{
		list[i].readFile(in);
	}
	return in;

}