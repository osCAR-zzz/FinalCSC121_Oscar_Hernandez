#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

Person::Person()
{
	fname = lname = " ";
	weight = 0;
	cout << "Constructor Called" << endl;
}

Person::~Person()
{
	cout << "Person object being destroyed. Done!" << endl;

}

Person::Person(const string& firstName, const string& lastName, double personWeight)
{
	fname = firstName;
	lname = lastName;
	weight = personWeight;

	cout << "\n OverLoaded constructor called.\n" << endl;
}

void WriteReadSort::increaseArrCapacity()
{
	capacity *= 2;
	Person* newPeople = new Person[capacity];

	for (int i = 0; i < count; i++)
	{
		newPeople[i] = people[i];
	}

	delete[] people;
	people = newPeople;
}

//sort the dynamic array
void WriteReadSort::selectionSort()
{
	for (int i = 0; i < count - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < count; j++)
		{
			if (people[j].getWeight() < people[min].getWeight())
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(people[i], people[min]);
		}
	}
}

WriteReadSort::WriteReadSort()
{
	people = nullptr;
	count = 0;
	capacity = 15;

	people = new Person[capacity];
}

WriteReadSort::~WriteReadSort()
{
	delete[] people;
}

//read from names.txt file and write in binary file

void WriteReadSort::WritePerson(const string& namesFilep, const string& peopleDataFilep, const string& peopleTextFilep)
{
	ifstream namesFile("people.dat");
	ofstream peopleDataFile(peopleDataFilep, ios::out | ios::binary);
	ofstream peopleTextFile(peopleTextFilep);

	cout << "names.txt. opened" << endl;
	//checks if files are valid
	if (!namesFile)
	{
		cout << "Failed to open file: " << endl;

		return;
	}
	
	if (!peopleDataFile.is_open() || !peopleTextFile.is_open())
	{
		cout << "Failed to open data files. " << endl;
		
		return;
	}
	
	string firstName, lastName;
	double weight = 0;
	int index = 0;

	//Reads names adn weight from names.txt and people.dat 
	while (namesFile >> firstName >> lastName)
	{
		// checks if array needs to increase capacity
		if (index >= capacity)
		{
			increaseArrCapacity();
		}
		people[index] = Person(firstName, lastName, weight);

		while (peopleDataFile.write(reinterpret_cast<char*>(&weight), sizeof(double)))
		{
			peopleTextFile << firstName << " " << lastName << "/n";

			index++;

			count = index;
		}
		namesFile.close();
		peopleDataFile.close();
		peopleTextFile.close();
	}
}

void ReadPerson(const string& peopleDataFilep, const string& peopleTextFilep)
{
	ifstream namesFile("names.txt");
	ifstream peopleTextFile(peopleTextFilep);
}

void WriteReadSort::SortPerson(const string& sortedPeopleFilep)
{
	selectionSort();

	cout << "Sorted people by weight: \n";

	for (int i = 0; i < count; i++)
	{
		people[i].display();
	}

	ofstream sortedPeopleFile(sortedPeopleFilep);
	if (!sortedPeopleFile.is_open())
	{
		cout << "Failed to open file: " << sortedPeopleFilep << endl;

		return;
	}

	for (int i = 0; i < count; i++)
	{
		sortedPeopleFile << people[i].getName() << " " << people[i].getLastName() << " " 
			<< people[i].getWeight() << "\n" << endl;
	}

	sortedPeopleFile.close();

}

void WriteReadSort::CalculateAvgWt()
{

	double totWeight = 0;

	double aveWeight = 0;

	for (int i = 0; i < count; i++)
	{
		totWeight += people[i].getWeight() + 10;
	}

	aveWeight = totWeight / count;

	cout << " \n Weights above the average (" << aveWeight << "lbs): \n";

	for (int i = 0; i < count; i++)
	{
		if (people[i].getWeight() > aveWeight)
		{
			people[i].display();
		}
	}

}