#pragma once
#include"Ride.h"
#include"Delivery.h"
#include"Customer.h"
#include"Driver.h"
#include"Vehicle.h"
#include<fstream>
#include<iostream>
using namespace std;

template <typename T>
T** bubblesort(T** arr, int s)
{
	for (int i = 0; i < s - 1; i++)
	{
		for (int j = 0; j < s - i - 1; j++)
		{
			if (arr[j]->get_overallRanking() < arr[j + 1]->get_overallRanking())
			{
				T* temp = new T;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}


class TMS:public Ride,public Delivery
{
	Customer** Customer_arr;
	int c_size;
	Driver** Driver_arr;
	int d_size;
	Vehicle** Vehicle_arr;
	int v_size;
	Service** pending;
	int pending_size;
public:
	TMS();
	void set_Customer_arr(const Customer& obj);
	void set_Driver_arr(const Driver& obj);
	void set_Vehicle_arr(const Vehicle& obj);
	void AddNewCustomer();  
	void RemoveDriver(int);   
	void RemoveVehicle(int); 
	void AddNewVehicle();   
	void AddNewDriver(); 
	void PrintAllCustomers();   
	void PrintAllDrivers();   
	void PrintAllVehicles();  //Print complete list of vehicles with details by their category.
	void Print_serviceHistory_vehicle(int);   //Print complete details and service history of a particular vehicle, (Provide vehicle ID)
	void Print_customer(int);  //-------;//Print complete history of a particular customer (Provide customer ID)
	void Print_history_driver(int);  //--------//Print complete history of a driver including services. (Provide driver ID)
	void Print_Drivers_aboveRanking(); //--------//Print list of all drivers who have ranking above 4.5.
	void Print_dirver_licences();  //------//Print list of all drivers who have multiple licenses and their license information too.
	void Print_updated_salary();  //------
	void Service_Request();
	void Cancel_Request(int,int);
	void Complete_service();  //Complete a service (Provide service ID)
	void Customers_same_vehicle__ride();  // Print details of all Customers, who used the same vehicle in a ride service on a different date.
	void Print_drivers_completed_delivery();  //Print the List of all Drivers who completed delivery services on same days.
	void Pending_services_onADate();   //Print details of all pending services on a particular date.
	void Pending_services_ofDriver();  //Print details of all pending services of a particular driver.
	void Cancelled_services();  //Print details of all canceled services by a customer.
	void set_pending(Service *);
	ofstream& write(ofstream&);
	

};

