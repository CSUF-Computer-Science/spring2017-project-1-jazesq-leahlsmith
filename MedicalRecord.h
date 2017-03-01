#pragma once
#include <string>
#include <stdexcept>
#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {

		record = new Baby[SIZE]; // array created on the heap
		numOfEntries = 0; // number of babies on record set to 0

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
// done in 2 steps
//STEP 1: CREATE ARRAY OF UNIQUE NAMES FROM FILE
		string nameArray[1000]; 
		
		//initialize array to blank names
		for (int i = 0; i < 1000; i++)
		{
			nameArray[i] = "";
		} 

		int uniqueNameTotal = 0; // holds the number of unique names in the record
		for (int i = 0; i < numOfEntries; i++) // loops through record[] 
		{
			for (int j = 0; j < 1000; j++) // loop used to compare record[i] to nameArray[j]
			{
				// loop through the record[i] and compare to nameArray[j]
				// if the name is already found in nameArray[j] then break out of loop 
				if (record[i].name == nameArray[j]) 				{
					break;
				}
				// loop populates nameArray[j] with first name and subsequent empty array slots
				else if (nameArray[j] == "")
				{
				// if name in record[i] is not in nameArray[j] then add it to nameArray[j]
				// then increment total number of unique names
					nameArray[j] = record[i].getName();
					uniqueNameTotal++;
					break;
				}
			}
		}
		
//STEP 2: loop through nameArray[] and find name with highest occurance using numberOfBabiesWithName(); 
		
		int popularCount = 0; // holds the number of babies with name being tested
		int indexOfPopularName; // holds the index in nameArray[] of the most popular name
		
		for (int i = 0; i < uniqueNameTotal; i++) // loops through nameArray[]
		{
			int tempCount = numberOfBabiesWithName(nameArray[i]); 
			
			//if the number of babies with name of the current array index is higher than the popularCount then:
			// 1. update the popularCount to the number of babies with the name
			// 2. update the index of the most popular name to this index
			if (tempCount > popularCount)
			{
				popularCount = tempCount;
				indexOfPopularName = i;
			}

		}
		// return the name located in the most popular index
		return nameArray[indexOfPopularName];
	}


		

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		
		return numOfEntries; //declared as private member variable below, updated in addEntry()
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		
		int lowCount = 0; // count of babies with low weight
		for (int i=0; i < numOfEntries; i++)
		{
			//if weight is under 2500 increment the count
			if (record[i].getWeight() < 2500)
			{
				lowCount++;
			}
		}
		// return final count 
		return lowCount;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		
		int numWithS = 0; // holds the number of babies with specified name 
		for (int i = 0; i < SIZE; i++)
		{
			// if baby has specified name increment the count
			if (record[i].name == s)
			{
				numWithS++;
			}
		}
		// return final count
		return numWithS;
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {

			record[numOfEntries].name = b.name;
			record[numOfEntries].weight = b.weight;

		numOfEntries++; // keeps track of the number of births
	}

	Baby newEntry; //used in addEntry();
	Baby * record; //ptr in array of the entire fcn

	const int SIZE = 1000000; // used for arrazy size
	int numOfEntries; // for birth count 

	
};
