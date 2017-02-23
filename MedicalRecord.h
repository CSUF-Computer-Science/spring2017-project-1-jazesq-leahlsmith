#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		// creates record with nothing in it

		Baby * record;
		record = new Baby[0];
	}

	//made another ctor with filename since default ctors cant take parameters 
	MedicalRecord(string filename) {

		fstream file;
		file.open(filename, ios::in);

		Baby * record;
		int size = numberOfBirths();

		record = new Baby[size];
	}

	// destructor
	~MedicalRecord() {
		// deletes array of the medical records
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
		return "COMPLETE ME"; // TO BE COMPLETED
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		// return -1; // TO BE COMPLETED
		
		int numOfBirths = 0;
		//opens file, i think???
		string filenameagain;
		fstream file(filenameagain);
		// while the line isnt empty, the num of births is tallied and you can also use this number for the array size in the ctor 
		string str;
		while (getline( filenameagain, str))
		{
			if (!str.empty())
				numOfBirths++;
		}
		//return final tally of lines
		return numOfBirths;

		
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
		
		newEntry = b;
		string filename;
		
		// read file (use getline)
		getline(filename, newEntry, ' ')

	
	}

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions

	Baby newEntry; //used in addEntry()
	
};
