

#include"Feature.h"
using namespace std;

int Feature::fId = 0;

Feature::Feature()
{
	increment_fId();
	description = nullptr;
	cost = 0;

}
Feature::Feature(char * description, float cost)
{
	increment_fId();
	int l = strlen(description);
	this->description = new char[l];
	strcpy(this->description, description);
	this->cost = cost;
	
}

Feature::Feature(const Feature& f)
{
	int l = strlen(f.description);
	this->description = new char[l];
	strcpy(this->description, f.description);
	cost = f.cost;
	
}

void Feature::increment_fId()
{
	fId++;
}

int Feature::get_fId()
{
	return fId;
}

char* Feature::get_description()
{
	return description;
}

float Feature::get_cost()
{
	return cost;
}


void Feature::set_fId(int x)
{
	fId = x;
}
void Feature::set_description(char* x)
{
	int l = strlen(x);
	description = new char[l];
	strcpy(description, x);
}

void Feature::set_cost(float x)
{
	cost = x;
}


Feature::~Feature()
{
	if(description!=nullptr)
	{
		delete description;
		description = nullptr;
	}
}

ostream& operator<<(ostream& out, const Feature& n)
{
	out << "fId: " << n.fId << endl;
	out << "Description: " << n.description << endl;
	out << "Cost: " << n.cost << endl;
	return out;
}

ofstream& Feature::write(ofstream& out)
{
	out << fId << " ";
	out << description << " ";
	out << cost << " ";
	return out;
}
	
ifstream& Feature ::readFile (ifstream& in)
{
	in >> fId;
	in.ignore();
	in.getline(description, 50);
	in >> cost;
	return in;
}



Feature& Feature:: operator=(const Feature& obj)
{
	if(description==nullptr && obj.description!=nullptr)
	{
		int l = strlen(obj.description);
	    this->description = new char[l];
	    strcpy(this->description, obj.description);
	    cost = obj.cost;
	}
	else if(description!=nullptr && obj.description!=nullptr)
	{
		delete[]description;
		int l = strlen(obj.description);
	    this->description = new char[l];
	    strcpy(this->description, obj.description);
	    cost = obj.cost;
	}
	return *this;
}
