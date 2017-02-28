#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby::Baby():name(""),weight(0){  // default constructor

	};

	Baby::Baby(string s, int w) : name(s), weight(w)
	{

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

	friend class MedicalRecord;
};