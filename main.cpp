#include<iostream>
using namespace std;
#include"Name.h"
#include"Customer.h"
#include"Service.h"
#include"Ride.h"
#include"Person.h"
#include"Delivery.h"
#include"TMS.h"
#include <fstream>

//0 customer (defualt)
//1 driver

//void main()
//{
//	//char fName1[] = "Malaika";
//	//char lName1[] = "Tanveer";
//	//char DType[] = "intercity";
//	//Customer c2(fName1, lName1, 20, 9, 2001, 19, 829374);
//	//char rideType1[] = "intracity";
//	//char source1[] = "Lahore";
//	//char destination1[] = "Islamabad";
//	//Ride r1(4, rideType1, 1.0, 1.0, source1, destination1, 500.0, 17, 6, 2021, 22, 50, 30, 0, 87.6, c2.get_cId(), 200, 300);
//	//char goodsType1[] = "Drugs";
//	//Delivery d1(10.8, goodsType1, DType, source1, destination1, 500.0, 17, 6, 2021, 22, 50, 30, 0, 87.6, c2.get_cId(), 200, 300);
//	//Service** s1=new Service*[2];
// //   s1[0] = &r1;
//	//s1[1] = &d1;
//	//c2.set_bookingHistory(s1[0]);
//	//c2.set_bookingHistory(s1[1]);
//	//c2.print(cout);
//	//c2.Database();
//
//	//char fName[] = "Wardah";
//	//char lName[] = "Maqbool";
//	//Customer c1(fName, lName, 2, 3, 2002, 21, 192864);
//	//char rideType[] = "intergalctic";
//	//
//	//char source[] = "Lahore";
//	//char destination[] = "Andromeda_Galaxy";
//	//Ride r0(4, rideType, 1.0, 1.0, source, destination, 670.0, 19, 6, 2021, 22, 50, 30, 0, 87.6, c1.get_cId(), 200, 300);
//	//char goodsType[] = "Hope";
//	//Delivery d0(100000, goodsType, DType, source, destination, 142.0, 17, 3, 2019, 22, 50, 30, 0, 87.6, c1.get_cId(), 200, 300);
//	//Service** s0 = new Service * [2];
//	//s0[0] = &r0;
//	//s0[1] = &d0;
//	//c1.set_bookingHistory(s0[0]);
//	//c1.set_bookingHistory(s0[1]);
//	//c1.print(cout);
//	//c1.Database();
//	//placeEOF();
//	//Customer c3;
//	//c3.set_cId(1);
//	//cout << "---------------------Customer 3------------------------\n";
//	//c3.read();
//	//removeEOF();
//
//	///*Customer c4(c1);
//	//c4.Database();*/
//
//	///*TMS T;
//	//T.PrintAllCustomers();*/
//
//	///*int ll_size = 2;
//	//char** Licences = new char* [ll_size];
//	//for (int i = 0; i < ll_size; i++)
//	//{
//	//	Licences[i] = new char;
//	//}
//	//strcpy(Licences[0], "HTV");
//	//strcpy(Licences[1], "LTV");
//	//char fName1[] = "Malaika";
//	//char lName1[] = "Tanveer";
//	//char rideType1[] = "intracity";
//	//char source1[] = "Lahore";
//	//char destination1[] = "Islamabad";
//	//Driver d1(Licences, ll_size, 10, fName1, lName1, 20, 9, 2001, 19, 829374);
//	//Ride r1(4, rideType1, 1.0, 1.0, source1, destination1, 500.0, 17, 6, 2021, 22, 50, 30, 0, 87.6, 16, d1.get_dId(), 300);
//	//char goodsType1[] = "Drugs";
//	//Delivery deliver(10.8, goodsType1, source1, destination1, 500.0, 17, 6, 2021, 22, 50, 30, 0, 87.6,17, d1.get_dId(), 300);
//	//Service** s1 = new Service * [2];
//	//s1[0] = &r1;
//	//s1[1] = &deliver;
//	//d1.set_serviceHistory(s1[0]);
//	//d1.set_serviceHistory(s1[1]);
//	//d1.print(cout);
//	//d1.Database();
//	//placeEOF(1);
//	//cout << "---------------------Customer 3------------------------\n";
//	//Driver d2;
//	//d2.set_dId(1);
//	//d2.read();
//	//removeEOF(1);*/
//
//
//
//	TMS T;
//	T.AddNewCustomer();
//	cout << "_____________________\n";
//	T.AddNewDriver();
//	cout << "_____________________\n";
//	T.AddNewVehicle();
//	cout << "_____________________\n";
//	T.Service_Request();
//	cout << "_____________________\n";
//	T.Complete_service();
//	ofstream fout;
//	fout.open("TMS.txt");
//	T.write(fout);
//	fout.close();
//
//
//}


int main()
{
	cout << "                                                 TRANSPORT MANAGEMENT SYSTEM                                                ";
	cout << endl;
	cout << endl;
	cout << endl;

	int choice = -1;
	while (choice != 0)
	{
		cout << "Enter: " << endl;
		cout << " 0 - To exit the program." << endl;
		cout << " 1 - To add a new customer." << endl;
		cout << " 2 - To add a driver." << endl;
		cout << " 3 - To remove a driver." << endl;
		cout << " 4 - To add a vehicle." << endl;
		cout << " 5 - To remove a vehicle." << endl;
		cout << " 6 - To print a list of all customers." << endl;
		cout << " 7 - To print List of All drivers." << endl;
		cout << " 8 - To print complete list of vehicles with details by their category." << endl;
		cout << " 9 - To print complete details and service history of a particular vehicle." << endl;
		cout << "10 - To print complete history of a particular customer." << endl;
		cout << "11 - To print complete history of a driver including services." << endl;
		cout << "12 - To print list of all drivers who have ranking above 4.5." << endl;
		cout << "13 - To print list of all drivers who have multiple licenses." << endl;
		cout << "14 - To print updated salary of all drivers based on their updated ranking." << endl;
		cout << "15 - To add a Service request" << endl;
		cout << "16 - To cancel a booking." << endl;
		cout << "17 - To complete a service." << endl;
		cout << "18 - To print details of all Customers, who used the same vehicle in a ride service on a different date." << endl;
		cout << "19 - To Print the List of all Drivers who completed delivery services on same days." << endl;
		cout << "20 - To print details of all pending services on a particular date." << endl;
		cout << "21 - To print details of all pending services of a particular driver." << endl;
		cout << "22 - To print details of all canceled services by a customer." << endl;

		cin  >> choice;
		TMS T;
		switch (choice)
		{
		case 1:
			T.AddNewCustomer();
			break;

		case 2:
			T.AddNewDriver();
			break;

		case 3:
		{
			int dId;
			cout << "Enter the Driver ID: ";
			cin >> dId;
			cout << endl;
			T.RemoveDriver(dId);
			break;
		}
		case 4:
			T.AddNewVehicle();
			break;

		case 5:
		{
			int vId;
			cout << "Enter the Vehicle ID: ";
			cin >> vId;
			cout << endl;
			T.RemoveDriver(vId);
			break;
		}

		case 6:
			T.PrintAllCustomers();
			break;

		case 7:
			T.PrintAllDrivers();
			break;

		case 8:
			T.PrintAllVehicles();
			break;

		case 9:
		{
			int vId;
			cout << "Enter the Vehicle ID: ";
			cin >> vId;
			cout << endl;
			T.Print_serviceHistory_vehicle(vId);
			break;
		}

		case 10:
		{
			int cId;
			cout << "Enter the Customer ID: ";
			cin >> cId;
			cout << endl;
			T.Print_customer(cId);
			break;
		}

		case 11:
		{
			int dId;
			cout << "Enter the Driver ID: ";
			cin >> dId;
			cout << endl;
			T.Print_history_driver(dId);
			break;
		}
		case 12:
		{
			T.Print_Drivers_aboveRanking();
			break;
		}
		case 13:
		{
			T.Print_dirver_licences();
			break;
		}
		case 14:
		{
			T.Print_updated_salary();
			break;
		}
		case 15:
		{
			T.Service_Request();
			break;
		}
		case 16:
		{
			//cancel booking
			break;
		}
		case 17:
		{
			T.Service_Request();
			break;
		}
		case 18:
		{
			T.Pending_services_onADate();
			break;
		}
		case 19:
		{
			break;
		}
		case 20:
		{
			break;
		}
		case 21:
		{
			break;
		}
		case 22:
		{
			break;

		}
		default:
		{
			cout << "Invalid input\n";
		}

		}

	}

}