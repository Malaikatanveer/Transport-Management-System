#pragma once
#include<fstream>
#include<iostream>
#include<conio.h>
using namespace std;
void removeEOF(int x=0)
{
	/*fstream fin;
	
	fin.open("Service.txt");
	if (!fin)
		cout << "Cannot open file\n";
	int x = 0;
	while (x != -1)
	{
		fin >> x;
		fin.ignore(500, '\n');
	}
	long pos = fin.tellg();
	fin.seekg(pos - 1);
	fin << " ";
	fin.close();*/
	
	/*ofstream fout;
	fout.open("Service.txt",ios::app);
	if (!fout)
		cout << "Cannot open file\n";
	
	ifstream fin;
	fin.open("Service.txt");
	if (!fin)
		cout << "Cannot open file\n";
	int x = 0;
	while (x != -1)
	{
		fin.ignore(500, '\n');
		fin >> x;
		
	}
	long pos=fout.tellp();
	fout.seekp(-1,std::ios_base::end);
	fout << '#';
	fout.close();
	fin.close();*/

	//ofstream fout;
	//fout.open("Service.txt", ios::app);
	//if (!fout)
	//	cout << "Cannot open file\n";
	///*fout.seekp(-1);*/
	////fout << '@';
	////fout.close();
	//int x = 0;
	//int c = 0;
	//if (c == -1)  //check for backspace
	//{
	//    fout.seekp(-1, std::ios_base::end);
	//	fout << "@";
	//}
	//fout.close();

	ofstream fout;
	if(x==0)
	  fout.open("Service.txt", ios::app);
	else if(x==1)
		fout.open("Driver.txt", ios::app);
	if (!fout)
		cout << "Cannot open file\n";
	fout << 2<<endl;
	fout.close();
}

void placeEOF(int x=0)
{
	ofstream fout;
	if (x == 0)
		fout.open("Service.txt", ios::app);
	else if (x == 1)
		fout.open("Driver.txt", ios::app);
	fout << -1;
	fout.close();
}