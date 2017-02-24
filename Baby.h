#pragma once
#include <iostream>
#include <string>


using namespace std;

// class that contains information related to a single birth or baby name
class Baby {

public:

	// do we need the function declarations??? 



	Baby(){  // default constructor

		name = " ";
		weight = 0;
		
	}

	Baby(string s, int w) : name(s), weight(w) { // constructor


		name = s;
		weight = w;
	}

	// a "getter" method
	int getWeight() {

		return weight;
	}

	// a "getter" method
	string getName() {

		return name;

	}

private:
	string name;
	int weight;
};