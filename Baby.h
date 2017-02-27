#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby::Baby():name(""),weight(0){  // default constructor

		/*name = "";
		weight = 0;*/

	};

	Baby::Baby(string s, int w) : name(s), weight(w)
	{
		// constructor
		/*while ((name == "") && (weight == 0))
		{
			name = s;
			weight = w;

		}*/
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