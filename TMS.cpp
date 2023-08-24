#include"TMS.h"
using namespace std;

TMS::TMS()
{
	Customer_arr = nullptr;
	c_size = 0;
	Driver_arr = nullptr;
	d_size = 0;
    Vehicle_arr=nullptr;
	v_size = 0;
	pending = nullptr;
	pending_size = 0;
}

void TMS::AddNewCustomer()
{
	++c_size;
	Customer** temp = new Customer*[c_size];
	for (int i = 0; i < c_size - 1; i++)
	{
		temp[i] = new Customer;
		temp[i][0] = Customer_arr[i][0];
		Customer_arr[i] = nullptr;
	}
	char fName[20]; char lName[20]; int day; int month; int year; int Age; int Nid;
	cout << "Enter first name: ";
	cin.getline(fName,20);
	cout << endl;
	cout << "Enter last name: ";
	cin.getline(lName,20);
	//cin.ignore();
	cout << endl;
	cout << "DOB" << endl;
	cout << "Enter day: ";
	cin  >> day;
	cout << endl;
	cout << "Enter month: ";
	cin  >> month;
	cout << endl;
	cout << "Enter year: ";
	cin  >> year;
	cout << endl;
	cout << "Enter Age: ";
	cin  >> Age;
	cout << endl;
	cout <<"Enter Nid: ";
	cin  >> Nid;
	cout << endl;
	Customer c(fName, lName, day, month, year, Age, Nid);
	cout << "Your Customer ID: " << c.get_cId();
	Customer_arr[c_size-1] = new Customer;
	Customer_arr[c_size-1][0] = c;
	/*temp[c_size - 1] = &c;
	Customer_arr = temp;
	temp = nullptr;*/
	//c.Database();
}

void TMS::AddNewDriver()
{
	++d_size;
	Driver** temp = new Driver*[d_size];
	for (int i = 0; i < d_size - 1; i++)
	{
		temp[i] = new Driver;
		temp[i][0]=	Driver_arr[i][0];
		Driver_arr[i] = nullptr;
	}
	int LL_size; int experience; char fName[20]; char lName[20]; int day; int month; int year; int Age; int Nid;

	cin.ignore();
	cout << "Enter first name: ";
	cin.getline(fName, 20);
	cout << endl;
	cout << "Enter last name: ";
	cin.getline(lName, 20);
	//cin.ignore();
	cout << endl;
	cout << "DOB" << endl;
	cout << "Enter day: ";
	cin  >> day;
	cout << endl;
	cout << "Enter month: ";
	cin  >> month;
	cout << endl;
	cout << "Enter year: ";
	cin  >> year;
	cout << endl;
	cout << "Enter Age: ";
	cin  >> Age;
	cout << endl;
	cout << "Enter Nid: ";
	cin  >> Nid;
	cout << endl;
	cout << "Enter the number of licences you have: ";
	cin  >> LL_size;
	cout << endl;
	char** LicencesList = new char* [LL_size];
	for (int i = 0; i < LL_size; i++)
	{
		LicencesList[i] = new char[20];
	}
	for(int i = 0;i<LL_size;i++)
	{
		cout << "Enter the name of license: ";
		cin.ignore();
		cin.getline(LicencesList[i],20);
		cout << endl;
	}
	//cin.ignore();
	cout << "Enter your experience: ";
	cin >> experience;
	cout <<endl;
	Driver d(LicencesList, LL_size, experience, fName, lName, day, month, year, Age, Nid);
	Driver_arr[d_size-1] = new Driver;
	Driver_arr[d_size-1][0] = d;
	/*temp[d_size - 1] = &d;
	Driver_arr = temp;
	temp = nullptr;*/
	//call database function
}
void TMS::PrintAllVehicles()
{
    for(int i=0;i<v_size;i++)
	{
		cout << Vehicle_arr[i]->get_vId() << "  " << Vehicle_arr[i]->get_vName() << "  "<<Vehicle_arr[i]->get_registrationNo()<<endl;
	}


}
void TMS::PrintAllCustomers()
{
	for(int i = 0;i<c_size;i++)
	{
		cout << Customer_arr[i]->get_cId() << "		" << Customer_arr[i]->get_pName() << endl;
	}

	//ifstream fin;
	//fin.open("Service.txt");
	//if (!fin)
	//	cout << "Cannot open file\n";
	//int ID;
	//while (!fin.eof())
	//{
	//	fin >> ID;
	//	if(ID == 0)
	//		fin.ignore(100000, '\n');
			
	//	if (ID != -12)
	//	{
	//		if (ID != prev_id)
	//		{

	//			cout << "Customer ID is: " << ID <<"	";
	//			char f[15];
	//			char s[15];
	//			fin.ignore();
	//			fin.getline(f,15,' ');
	//			fin.getline(s,15,' ');
	//			fin.ignore(100000, '\n');
	//			cout << "Name: " << f << " " << s << endl;
	//			prev_id = ID;
	//		}
	//	}
	//	else
	//		fin.ignore(100000,'\n');
	//}
	//fin.close();
}

void TMS::AddNewVehicle()
{
	++v_size;
	Vehicle** temp = new Vehicle * [v_size];
	for (int i = 0; i < v_size - 1; i++)
	{
		temp[i] = new Vehicle;
		temp[i][0] = Vehicle_arr[i][0];
		Vehicle_arr[i] = nullptr;
	}

	int registration;
	float mileage;
	char licenceType[20];
	bool status;
	char fueltype[20];
	int day; int month; int year;
	cout << "Enter Vehicle Register number: ";
	cin >> registration;
	cout << endl;
	cout << "Average mileage: ";
	cin >> mileage;
	cout << endl;
	cout << "Enter license type:";
	cin.ignore();
	cin.getline(licenceType, 20);
	cout << endl;
	cout << "Enter status(0 or 1): ";
	cin >> status;
	cout << endl;
	cout << "Enter fuel type: ";
	cin.ignore();
	cin.getline(fueltype, 20);
	cout << endl;
	cout << "Manufacturng date: " << endl;
	cout << "Enter day: ";
	cin >> day;
	cout << endl;
	cout << "Enter month: ";
	cin >> month;
	cout << endl;
	cout << "Enter year: ";
	cin >> year;
	cout << endl;
	Date d(day, month, year);
	char description[50];
	float cost; int f_size; char category; char v_name[20];
	cout << "Enter the number of features: ";
	cin >> f_size;
	cout << endl;
	Feature* f = new Feature[f_size];
	
	for (int i = 0; i < f_size; i++)
	{
		cout << "Enter the discription of " << i + 1 << " feature: ";
		cin.ignore();
		cin.getline(description, 50);
		cout << "Enter the cost of the feature: ";
		cin >> cost;
		cout << endl;
		f[i].set_description(description);
		f[i].set_cost(cost);

	}
	cout << "Enter vehicle category (R or D or B): ";
	cin >> category;
	cout << endl;
	cout << "Enter the name of vehicle: ";
	cin.ignore();
	cin.getline(v_name, 20);
	cout << endl;
	Vehicle v(registration,mileage,licenceType,status,fueltype,d,f_size,f,category,v_name);
	Vehicle_arr[v_size - 1] = new Vehicle;
	Vehicle_arr[v_size-1][0] = v;
	/*temp[v_size - 1] = &v;
	Vehicle_arr = temp;
	temp = nullptr;*/
	



}

void TMS::RemoveDriver(int dId)
{
	int s;
	for (int i = 0; i < c_size; i++)
	{
		int x = Driver_arr[i]->get_dId();
		if(dId == x)
		{
			delete Driver_arr[i];
			for(s = i; s < c_size - 1; s++)
			{
				Driver_arr[s] = Driver_arr[s++];
			}
		}
	}
}

void TMS::RemoveVehicle(int vId)
{
	int temp = 0;
	for (int i = 0; i < v_size; i++)
	{
		int x = Vehicle_arr[i]->get_vId();
		if (vId == x)
		{
			delete Vehicle_arr[i];
			for (temp = i; temp < v_size - 1; temp++)
			{
				Vehicle_arr[temp] = Vehicle_arr[temp++];
			}
		}
	}
}

void TMS::PrintAllDrivers()
{
	for(int i = 0;i < d_size; i++)
	{
		cout << Driver_arr[i]->get_dId() << "		" << Driver_arr[i]->get_pName() << endl;
	}
}

void TMS ::Print_serviceHistory_vehicle(int vId)
{
	for(int i = 0; i < v_size; i++)
	{
		if(Vehicle_arr[i]->get_vId() == vId)
		{
			cout << Vehicle_arr[i];
		}
	}
}


void TMS::Print_customer(int cId)
{
    for(int i=0;i<c_size;i++)
	{
		if(Customer_arr[i]->get_cId()==cId)
		{
			cout << "Customer ID: " << cId << endl;
			cout << "Customer name: " << Customer_arr[i]->get_pName() << endl;
			cout<<"Service history is: "<<endl;
			int s = Customer_arr[i]->get_size();
			Service** temp = Customer_arr[i]->get_bookingHistory();
			for (int k = 0; k < s; k++)
			{
				temp[k]->print(cout);
			}	    
		}
	}
}

void TMS:: Print_history_driver(int dId)
{
	for (int i = 0; i < d_size; i++)
	{
	      if(Driver_arr[i]->get_dId()==dId)
		  {
			  cout << "Driver ID: " << dId << endl;
			  cout << "Driver name: " << Driver_arr[i]->get_pName() << endl;
			  cout << "Service history is: " << endl;
			  int s = Driver_arr[i]->get_SH_size();
			  Service** temp=Driver_arr[i]->get_serviceHistory();
			  for(int k=0;k<s;k++)
			  {
				  temp[k]->print(cout);
			  }
		  }
    }
}

void TMS::Print_Drivers_aboveRanking()
{
	for (int i = 0; i < d_size; i++)
	{
		if (Driver_arr[i]->get_overallRanking() > 4.5)
		{
			cout << "Driver ID: " << Driver_arr[i]->get_dId() << "   ";
			cout << "Driver name: " << Driver_arr[i]->get_pName() << "   ";
			cout << "Driver Ranking: " << Driver_arr[i]->get_overallRanking() << endl;
		}
	}
}

void TMS:: Print_dirver_licences()
{
      for(int i=0; i<d_size; i++)
	  {
			if(Driver_arr[i]->get_LL_size()>1)
			{
				cout << "Driver name: " << Driver_arr[i]->get_pName() << endl;
				cout << "Driver ID: " << Driver_arr[i]->get_dId() << endl;
				int s = Driver_arr[i]->get_LL_size();
				cout << "Driver's License list: " << endl;
				char** temp = Driver_arr[i]->get_LicencesList();
				for(int j=0;j<s;j++)
				{
					cout << Driver_arr[i]->get_LicencesList()[j] << endl;
				}
			}
	  }
}

void TMS:: Print_updated_salary()
{
	for (int i = 0; i < d_size; i++)
	{
		if (Driver_arr[i]->get_overallRanking() > 4.5)
		{
			int salary = Driver_arr[i]->get_salary();
			int new_salary = salary + (15 / 100 * salary);
			Driver_arr[i]->set_salary(new_salary);
			cout << "Updated Salary of " << Driver_arr[i]->get_pName() << ": " << Driver_arr[i]->get_salary() << endl;
		}
	}
}

void TMS::Service_Request()
{
	int chosen_cId;
	cout << "Enter your Customer ID: ";
	cin >> chosen_cId;
	int choice = 0;
	while (choice != -1)
	{
		cout << "Enter the request type: " << endl;
		cout << "1- Ride\n";
		cout << "2- Delivery\n";
		cin >> choice;
		Vehicle** v_sorted = bubblesort(Vehicle_arr, v_size);
		Driver** d_sorted = bubblesort(Driver_arr, d_size);
		if (choice == 1)
		{
			for (int i = 0; i < v_size; i++)
			{
				if((v_sorted[i]->get_category() == 'R'|| v_sorted[i]->get_category() == 'B') && v_sorted[i]->get_status() == false)
				{
					cout << "vId: " << v_sorted[i]->get_vId() << "  ";
					cout << "Registration No.: " << v_sorted[i]->get_registrationNo() << "  ";
					cout << "Vehicle Name: " << v_sorted[i]->get_vName() << "  ";
				}

				if (Driver_arr[i]->get_status() == 1)
				{
					cout << "dId: " << Driver_arr[i]->get_dId() << "  ";
					cout << "Driver name: " << Driver_arr[i]->get_pName() << "  ";
					cout << "Driver ranking: " << Driver_arr[i]->get_overallRanking() << endl;
				}
			}
		}
		else if (choice == 2)
		{
			for (int i = 0; i < v_size; i++)
			{
				if ((v_sorted[i]->get_category() == 'D' || v_sorted[i]->get_category() == 'B') && v_sorted[i]->get_status() == false)
				{
					cout << "vId: " << v_sorted[i]->get_vId() << "  ";
					cout << "Registration No.: " << v_sorted[i]->get_registrationNo() << "  ";
					cout << "Vehicle Name: " << v_sorted[i]->get_vName() << "  ";
					cout << "Vehicle Ranking: " << v_sorted[i]->get_overallRanking() << endl;
				}

				if (d_sorted[i]->get_status() == 1)
				{
					cout << "dId: " << d_sorted[i]->get_dId() << "  ";
					cout << "Driver name: " << d_sorted[i]->get_pName() << "  ";
					cout << "Driver ranking: " << d_sorted[i]->get_overallRanking() << endl;
				}
			}
		}
		else
			cout << "invalid input\n";      
	}
	int chosen_vId;
	int chosen_dId;
	float fare = 0.0f;
	cout << "Enter the Vehicle ID of selected vehicle: ";
	cin  >> chosen_vId;
	cout << endl;
	cout << "Enter the Driver ID of selected Driver: ";
	cin  >> chosen_dId;
	cout << endl;
	if (choice == 1)
	{
		Service* s1 = new Ride;
		s1->set_cId(chosen_cId);
		s1->set_dId(chosen_dId);
		s1->set_vId(chosen_vId);
		Ride* ptr = dynamic_cast<Ride*>(s1);
		ptr->read(cin);		
		set_pending(s1);
		int dis = s1->get_distance();		
		int l = strlen(ptr->get_rideType());
		char * rt = new char[l];
		strcpy(rt, ptr->get_rideType());
		
		char* ch=nullptr;
		float feature_cost=0.0f;
		for (int i = 0; i < v_size; i++)
		{
			if (chosen_vId == Vehicle_arr[i]->get_vId())
			{
				int q = strlen(Vehicle_arr[i]->get_fueltype());
				ch = new char[q];
				strcpy(ch, Vehicle_arr[i]->get_fueltype());
				feature_cost = Vehicle_arr[i]->Features_cost();			
			}
		}
		int check = strcmp(ch,"petrol");    //assuming two types of fuel types
		int check2 = strcmp(ch, "diesel");
		int check3 = strcmp(rt, "intercity");    //assuming two types of fuel types
		int check4 = strcmp(rt, "intracity");
		float fuelcost = 0.0f;
		float f = 0;
		if (check3 == 1)
		{
			f = 50;
		}
		else if (check4 == 1)
		{
			f = 100;
		}
	
		if(check==1)
		{
			fuelcost = 55.0;
			s1->set_fuelrate(fuelcost);
		}
		else if(check2==1)
		{
			fuelcost = 77.0;
			s1->set_fuelrate(fuelcost);
		}
		int exp; float rank;
		for (int i = 0; i < d_size; i++)
		{
			if (chosen_dId == Driver_arr[i]->get_dId())
			{
				exp = Driver_arr[i]->get_experience();
				rank= Driver_arr[i]->get_overallRanking();
			}
		}
		exp = exp * 4;    //multiplying rank and experience to get the cost of fair
		rank = rank * 5;
		fare = (dis * fuelcost) + exp + rank + feature_cost + f;
		cout << "Calculated Fare: " << fare << endl;
	}
	else if(choice==2)
	{
		
		/*char* ch;*/
		Service* s1 = new Delivery;
		s1->set_cId(chosen_cId);
		s1->set_dId(chosen_dId);
		s1->set_vId(chosen_vId);
		Delivery* ptr2 = dynamic_cast<Delivery*>(s1);
		ptr2->read(cin);		
		set_pending(s1);
		int dis = s1->get_distance();
		Delivery* ptr = dynamic_cast<Delivery*>(s1);
	
		int l = strlen(ptr->get_deliveryType());
		char * rt = new char[l];
		strcpy(rt, ptr->get_deliveryType());;
		int check = strcmp(ptr2->get_deliveryType(), "intercity");    //assuming two types of fuel types
		int check2 = strcmp(ptr2->get_deliveryType(), "intracity");
		float fuelcost = 0.0f;
		float fare = 0;
		if (check == 1)
		{
			fare = 50;
		}
		else if (check2 == 1)
		{
			fare = 10;
		}
		fare = fare + dis * 2;
	}

	cout << "Fare=" << fare;
}

void TMS::set_pending(Service* p)
{
	++pending_size;
	Service** temp= new Service * [pending_size];
	for (int i = 0; i < pending_size - 1; i++)
	{
		temp[i] = pending[i];
		pending[i] = nullptr;
	}
	temp[pending_size - 1] = p;
	pending = temp;
	temp = nullptr;
}

void TMS:: Complete_service()
{
	int d_id;
	cout << "Enter Driver ID: ";
	cin  >> d_id;
	cout << endl;
	int c_id = 0, index;
	int v_id;
	for (int i = 0; i < d_size; i++)
	{
		if (pending[i]->get_dId() == d_id && pending[i]->get_status() == false)
		{
			pending[i]->set_status(true);
			c_id = pending[i]->get_cId();
			v_id = pending[i]->get_vId();
			index = i;
		}
	}
	
	float dr=0.0f, vr=0.0f;
	cout << "Enter the Driver Ranking: ";
	cin  >> dr;
	cout << endl;
	cout << "Enter the Driver Ranking: ";
	cin  >> vr;
	cout << endl;
	for(int i = 0; i < c_size; i++)
	{
		if(c_id == Customer_arr[i]->get_cId())
		{
			Customer_arr[i]->set_bookingHistory(pending[index]);
		}
	}

	for(int i = 0; i < d_size; i++)
	{
		if(d_id == Driver_arr[i]->get_dId())
		{
			Driver_arr[i]->set_serviceHistory(pending[index]);
			Driver_arr[i]->set_overallRanking(dr);
		}
	}

	for(int i = 0; i < v_size; i++)
	{
		if(v_id == Vehicle_arr[i]->get_vId())
		{
			Vehicle_arr[i]->set_serviceHistory(pending[index]);
			Vehicle_arr[i]->set_overallRanking(vr);
		}
	}

	delete pending[index];
	pending[index] = nullptr;
	for(int i = index; i < pending_size - 1; i++)
	{
		pending[i] = pending[i++];
	}
}



ofstream& TMS::write(ofstream & out)
{
	out << c_size << " " << v_size << " " << d_size <<" "<<pending_size<< endl;
	for (int i = 0; i < c_size; i++)
	{
		Customer_arr[i]->write(out);
		//out << endl;
	}
	for (int i = 0; i < v_size; i++)
	{
		Vehicle_arr[i]->write(out);
		//out << endl;
	}
	for (int i = 0; i < d_size; i++)
	{
		Driver_arr[i]->write(out);
		//out << endl;
	}
	for (int i = 0; i < pending_size; i++)
	{
		pending[i]->write(out);
		//out << endl;
	}
	return out;
}

void TMS::Customers_same_vehicle__ride()
{
	if (c_size == 1)
		return;
	for (int i = 0; i < c_size-1; i++)
	{
		for (int j = 0; j < Customer_arr[i]->get_size(); j++)
		{
			if (Customer_arr[i]->get_bookingHistory()[j]->get_bookingDate() == Customer_arr[i + 1]->get_bookingHistory()[j]->get_bookingDate())
			{
				Customer_arr[i]->print(cout);
			}
		}
	}
}










