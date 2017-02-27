#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
<<<<<<< HEAD
		
		record = new Baby[SIZE];

		for (int i = 0; i < SIZE; i++)
		{
			record[i] = Baby("", 0);

		}
=======
		// TO BE COMPLETED
>>>>>>> origin/project1LATEST_jazesq_leahlsmith
	}

	// destructor
	~MedicalRecord() {
<<<<<<< HEAD
		
		delete[] record;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
=======
		// TO BE COMPLETED
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string baby_data_small) {
		ifstream myfile("baby_data_small.txt");

		if (myfile.is_open()) {
			cout << "Successfully opened file " << baby_data_small << endl;
>>>>>>> origin/project1LATEST_jazesq_leahlsmith
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
<<<<<<< HEAD
			throw invalid_argument("Could not open file " + filename);
=======
			throw invalid_argument("Could not open file " + baby_data_small);
>>>>>>> origin/project1LATEST_jazesq_leahlsmith
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {
		return "COMPLETE ME"; // TO BE COMPLETED
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return -1; // TO BE COMPLETED
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		return -1; // TO BE COMPLETED
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		return -1; // TO BE COMPLETED
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
<<<<<<< HEAD
		
		newEntry = b;

		for (int i = 0; i < SIZE; i++)
		{
			record[i] = newEntry;
		}
	}


	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions
 
	
	
	Baby newEntry; //used in addEntry();
	Baby * record; //ptr in array of the entire fcn

	const int SIZE = 1000000; // used for arrazy size
=======
		// TO BE COMPLETED
	}

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions
>>>>>>> origin/project1LATEST_jazesq_leahlsmith

};
