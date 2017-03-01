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

		numOfEntries = 0;

	}

	// destructor
	~MedicalRecord() {

		delete[] record;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
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
			throw invalid_argument("Could not open file " + filename);

	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {


		string nameArray[1000];
		for (int i = 0; i < 1000; i++)
		{
			nameArray[i] = "";
		}

		int nameTotal = 0;
		for (int i = 0; i < numOfEntries; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				if (record[i].name == nameArray[j])
				{
					break;
				}
				else if (nameArray[j] == "")
				{
					nameArray[j] = record[i].getName();
					nameTotal++;
					break;
				}
			}
		}
		int nameIndex;
		int popularCount = 0;
		for (int i = 0; i < nameTotal; i++)
		{
			int tempCount = numberOfBabiesWithName(nameArray[i]);

			if (tempCount > popularCount)
			{
				nameIndex = i;
				popularCount = tempCount;
			}

		}
		return nameArray[nameIndex];
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
			if (record[i].name == s)
			{
				numWithS++;
			}
		}
		return numWithS;
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {

	
			record[numOfEntries].name = b.name;
			record[numOfEntries].weight = b.weight;

		numOfEntries++;
	}

	Baby newEntry; //used in addEntry();
	Baby * record; //ptr in array of the entire fcn

	const int SIZE = 1000000; // used for arrazy size
	int numOfEntries; // for birth count 

	
};
