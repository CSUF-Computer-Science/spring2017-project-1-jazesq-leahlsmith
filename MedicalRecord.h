#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor

	MedicalRecord() {

		record = new Baby[SIZE];

		for (int i = 0; i < SIZE; i++)
		{
			record[i] = Baby("", 0);

		}
		// TO BE COMPLETED
	}

	// destructor
	~MedicalRecord() {

		delete[] record;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string baby_data_small) {
		ifstream myfile("baby_data_small.txt");

		if (myfile.is_open()) {
			cout << "Successfully opened file " << baby_data_small << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
				
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + baby_data_small);

	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {
		return "COMPLETE ME"; // TO BE COMPLETED
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return numOfEntries; //declared as private mem var
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		
		int lowCount = 0;
		for (int i=0; i < numOfEntries; i++)
		{
			if (record[i].getWeight() < 2500)
			{
				lowCount++;
			}
		}
		return lowCount;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		int numWithS = 0;
		for (int i = 0; i < SIZE; i++)
		{
			if (record[i].getName() == s)
			{
				numWithS++;
			}
		}
		return numWithS;
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {

		newEntry = b;

		for (int i = 0; i < SIZE; i++)
		{
			record[i] = newEntry;
		}
		numOfEntries++;
	}

	Baby newEntry; //used in addEntry();
	Baby * record; //ptr in array of the entire fcn

	const int SIZE = 1000000; // used for arrazy size
	int numOfEntries=0; // for birth count 

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions
};