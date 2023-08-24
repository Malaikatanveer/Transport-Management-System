
#include"Driver.h"
using namespace std;

int Driver::dId = 0;

Driver::Driver()
{
	increment_dId();
	LicencesList = nullptr;
	LL_size = 0;
	overallRanking = 0;
	salary = 0;
	experience = 0;
	status = 0;
	serviceHistory = nullptr;
	SH_size = 0;
}

Driver::Driver(char** LicencesList, int LL_size, int experience, char* fName, char* lName, int day, int month, int year, int Age, int Nid) : Person(fName, lName, day, month, year,Age, Nid)
{
	increment_dId();
	this-> LL_size = LL_size;
	this->LicencesList = new char*[LL_size];
	for(int i = 0; i< LL_size; i++)
	{
		int l = strlen(LicencesList[i]);
		this->LicencesList[i] = new char[l];
		strcpy(this->LicencesList[i],LicencesList[i]);
	}
	this->experience = experience;

}

Driver::Driver(int dId, char** LicencesList,int LL_size, float overallRanking, float salary, int experience, int status, int SH_size, Service** serviceHistory)
{
	this->dId = dId;
	this->LL_size = LL_size;
	this->LicencesList = new char*[LL_size];
	for(int i = 0; i< LL_size; i++)
	{
		int l = strlen(LicencesList[i]);
		this->LicencesList[i] = new char[l];
		strcpy(this->LicencesList[i],LicencesList[i]); //deep copy or addresses?
	}
	//this->noofLicences = noofLicences;
	this->overallRanking = overallRanking;
	this->salary = salary;
	this->experience = experience;
	this->status = status;
	this->SH_size = SH_size;
	this->serviceHistory = new Service * [SH_size];
	for (int i = 0; i < SH_size; i++)
	{
		this->serviceHistory[i] = serviceHistory[i];
	}
}

Driver::Driver(const Driver& x)
{
	dId = x.dId;
	LL_size = x.LL_size;
	LicencesList = new char *[LL_size];
	for (int i = 0; i < LL_size; i++)
	{
		LicencesList[i] = x.LicencesList[i];
	}
	overallRanking = x.overallRanking;
	salary = x.salary;
	experience = x.experience;
	status = x.status;
	SH_size = x.SH_size;
	serviceHistory = new Service* [SH_size];
	for (int i = 0; i < SH_size; i++)
	{
		serviceHistory[i] = x.serviceHistory[i];
	}
}

void Driver::increment_dId()
{
	dId++;
}

int Driver::get_dId()
{
	return dId;
}

char** Driver::get_LicencesList()
{
	return LicencesList;
}

int Driver::get_LL_size()
{
	return LL_size;
}

float Driver::get_overallRanking()
{
	return overallRanking;
}

float Driver::get_salary()
{
	return salary;
}
int Driver:: get_SH_size()
{
	return SH_size;
}
int Driver::get_experience()
{
	return experience;
}

int Driver::get_status()
{
	return status;
}

Service** Driver::get_serviceHistory()
{
	return serviceHistory;
}


void Driver::set_dId(int d)
{
	dId = d;
}

void Driver::set_LicencesList(char* L)
{
	++LL_size;
	char** temp = new char *[LL_size];
	int s = strlen(L);
	for(int i = 0; i<LL_size - 1; i++)
	{
		strcpy(temp[i], LicencesList[i]);
		LicencesList[i] = nullptr;
	}
	temp[LL_size - 1] = L;
	LicencesList = temp;
	temp = nullptr;
}

void Driver::set_LL_size(int x)
{
	LL_size = x;
}

void Driver::set_overallRanking(float x)
{
	overallRanking = x;
}

void Driver::set_salary(float x)
{
	salary = x;
}

void Driver::set_experience(float x)
{
	experience = x;
}

void Driver::set_status(int x)
{
	status = x;
}

void Driver::set_serviceHistory(Service* s)
{
	++SH_size;
	Service** temp = new Service * [SH_size];
	for (int i = 0; i < SH_size - 1; i++)
	{
		temp[i] = serviceHistory[i];
		serviceHistory[i] = nullptr;
	}
	temp[SH_size - 1] = s;
	serviceHistory = temp;
	temp = nullptr;
}

Driver::~Driver()
{
	for (int i = 0; i < LL_size; i++)
	{
		delete[] LicencesList[i];
	}
	delete LicencesList;
	for (int i = 0; i < SH_size; i++)
	{
		delete[] serviceHistory;
	}
	delete serviceHistory;
	LicencesList = nullptr;
	serviceHistory = nullptr;
}

void Driver::Database()
{
	ofstream fout;
	fout.open("Driver.txt", ios::app);
	fout << dId << " ";

	fout.close();
	Person::save(1);

	for (int i = 0; i < SH_size; i++)
	{
		serviceHistory[i]->Database(0,1);
		fout.open("Driver.txt", ios::app);
		fout << LL_size << " ";
		for (int i = 0; i < LL_size; i++)
			fout << LicencesList[i] << " ";
		fout << experience << endl;
		fout.close();
	}
	
}

//ifstream& Driver::read()
//{
//	calculateReadsize();
//	serviceHistory = new Service * [SH_size];
//	/*bookingHistory = new Service * [size];
//	for (int i = 0; i < size; i++)
//	{
//		bookingHistory[i] = nullptr;
//	}*/
//	ifstream fin;
//	fin.open("Driver.txt", ios::in);
//	if (!fin)
//		cout << "Cannot open the file for read\n";
//	else
//	{
//
//		int id = 0, count = 0;
//		char type;
//		char type2;
//
//		while (id != -1)
//		{
//			//if (fin.eof()) 
//			//	break;
//
//			fin >> id;
//			//fin.ignore(500, '\n');
//			if (id == dId)
//			{
//				++count;
//				if (count == 1)
//				{
//					Person::read(fin);
//					Person::print(cout);
//
//					//return fin;
//				}
//				else
//				{
//					for (int i = 0; i < SH_size; i++)
//					{
//						fin >> type;
//						fin >> type2;
//						if (type == 'R' || type == 'D' && (type2 >= 48 && type2 <= 57))
//						{
//							long pos = fin.tellg();
//							fin.seekg(pos - 1);
//							if (type == 'R')
//								serviceHistory[i] = new Ride;
//							else if (type == 'D')
//								serviceHistory[i] = new Delivery;
//							/*for (int j = 0; j < size; j++)*/
//							serviceHistory[i]->read(fin);
//							fin >> LL_size;
//							LicencesList = new char*[LL_size];
//							for (int i = 0; i < LL_size; i++)
//								fin.getline(LicencesList[i], 20);
//							fin >> experience;
//							serviceHistory[i]->set_dId(id);
//							serviceHistory[i]->print(cout);
//							return fin;
//						}
//					}
//				}
//				/*else
//				{
//
//				}*/
//			}
//			else
//				fin.ignore(500, '\n');
//
//		}
//	}
//	fin.close();
//	return fin;
//}
//
//void Driver::calculateReadsize()
//{
//	ifstream fin;
//	fin.open("Driver.txt");
//	if (!fin)
//		cout << "Cannot open the file for read\n";
//	int id = 0, count = 0;
//	char type;
//	char type2;
//	while (id != -1)
//	{
//		fin >> id;
//		if (id == dId)
//		{
//			fin >> type;
//			fin >> type2;
//			if ((type == 'R' || type == 'D') && (type2 >= 48 && type2 <= 57))
//			{
//				SH_size++;
//			}
//			else
//				fin.ignore(500, '\n');
//
//		}
//		else
//			fin.ignore(500, '\n');
//	}
//	fin.close();
//
//}

ofstream& Driver::write(ofstream &out)
{
	out << dId << " " << LL_size << " ";
	for (int i = 0; i < LL_size; i++)
		out << LicencesList[i];
	out<< " " << overallRanking << " " << salary << " " << experience << " " << status << " " << SH_size;
	for (int i = 0; i < SH_size; i++)
	{
		serviceHistory[i]->write(out);
		out << endl;
	}
	return out;
}



Driver& Driver:: operator=(const Driver& obj)
{
    if(LicencesList==nullptr && obj.LicencesList!=nullptr && serviceHistory==nullptr && obj.serviceHistory!=nullptr)
	{
		dId = obj.dId;
		LL_size = obj.LL_size;
		LicencesList = new char *[LL_size];
		for (int i = 0; i < LL_size; i++)
		{
			strcpy(LicencesList[i], obj.LicencesList[i]);
		}
		overallRanking = obj.overallRanking;
		salary = obj.salary;
		experience = obj.experience;
		status = obj.status;
		SH_size = obj.SH_size;
		serviceHistory = new Service* [SH_size];
		for (int i = 0; i < SH_size; i++)
		{
			serviceHistory[i] = obj.serviceHistory[i];
		}
	}
	else if(LicencesList!=nullptr && obj.LicencesList!=nullptr && serviceHistory!=nullptr && obj.serviceHistory!=nullptr)
	{
		for(int i=0;i<LL_size;i++)
		{
			delete[]LicencesList[i];
		}
		for(int i=0;i<SH_size;i++)
		{
			delete[]serviceHistory[i];
		}
		dId = obj.dId;
		LL_size = obj.LL_size;
		LicencesList = new char *[LL_size];
		for (int i = 0; i < LL_size; i++)
		{
			strcpy(LicencesList[i], obj.LicencesList[i]);
		}
		overallRanking = obj.overallRanking;
		salary = obj.salary;
		experience = obj.experience;
		status = obj.status;
		SH_size = obj.SH_size;
		serviceHistory = new Service* [SH_size];
		for (int i = 0; i < SH_size; i++)
		{
			serviceHistory[i] = obj.serviceHistory[i];
		}
	}
	return *this;
}

ifstream& Driver::readFile(ifstream& in)
{
	in >> dId >> LL_size;
	in.ignore();
	for (int i = 0; i < LL_size; i++)
		in.getline(LicencesList[i], 20);
	in >> overallRanking;
	in >> salary; 
	in >> experience; 
	in >> status; 
	in >> SH_size;	
	for (int i = 0; i < SH_size; i++)
	{
		serviceHistory[i]->readFile(in);
		
	}
	return in;
}