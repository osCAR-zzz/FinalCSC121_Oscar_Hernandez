#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//my class for person
class Person 
{
	//private members 
private:


public:

	string fname, lname;
	double weight;

	//default constructor
	Person();
	//destructor
	~Person();

	//overloaded constructor
	Person(const string& firstName, const string& lastName, double personWeight);

	//getter methods
	const string getName()
	{
		return fname;
	}
	const string getLastName()
	{
		return lname;
	}
	const double getWeight()
	{
		return weight;
	}
	// setter methods
	void setName(const string& newName)
	{
		fname = newName;
	}
	void setLastName(const string& newLastName) 
	{
		lname = newLastName;
	}
	void setWeight(double newWeight)
	{
		weight = newWeight;
	}

// displays the first name, last name and weight of the individuals
	void display()
	{
		cout << "First Name: " << fname << ", Last Name: " << lname << ", Weight: " << weight << " lb" << endl;
	}
};

//class WriteReadSort
class WriteReadSort
{
private:
	//pointer to dynamically allocate the array of Person Objects
	Person* people;
	int count = 0;
	int capacity = 0;

	void increaseArrCapacity();
	void selectionSort();
public:
	WriteReadSort();
	~WriteReadSort();
	void WritePerson(const string& namesFilep, const string& peopleDataFilep, const string& peopleTextFilep);
	void friend ReadPerson(const string& peopleDataFilep, const string& peopleTextFilep);
	void SortPerson(const string& sortedPeopleFilep);
	void CalculateAvgWt();

};