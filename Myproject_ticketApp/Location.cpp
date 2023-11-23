#include <iostream>
using namespace std;

class Location {

	char* name = nullptr;
	string address = "";
	string zoneName = "";
	int maxSeats;
	int nrRows;
	//int nrCol;
	//int* seatsPerRow;

public:
	static int MIN_NR_LETTERS;
	static int MIN_CAPACITY;

public:

	//GETTERS
	//SETTERS  + VALIDATION
	
	//name
	char* getLocationName() {

		char* copy;
		copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);

		return copy;
	}

	void setLocationName(const char* newName) {
		if (this->name != NULL) {                //verify if there is smth at that address
			delete[] this->name;
			this->name = nullptr;
		}
		
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
		
	}

	//address
	string getLocationAddress() {
		return this->address;
	}

	void setLocationAddress(string newAddress) {
		if (newAddress == "" || newAddress.length() < Location::MIN_NR_LETTERS) {
			throw exception("Location address too short");
		}
		else {
			this->address = newAddress;
		}
	}

	//zone name
	string getZoneName() {
		return this->zoneName;
	}

	void setLocationZone(string newZone) {
		if (newZone == "" || newZone.length() < Location::MIN_NR_LETTERS) {
			throw exception("Zone name too short");
		}
		else {
			this->zoneName = newZone;
		}
	}

	//maximum number of seats
	int getMaxNrOfSeats() {
		return this->maxSeats;
	}

	void setMaxNrOfSeats(int newMax) {
		if (newMax <= Location::MIN_CAPACITY) {
			throw exception("The capacity is too small");
		}
		this->maxSeats = newMax;
	}

	//number of rows
	int getMaxNrOfRows() {
		return this->nrRows;
	}

	void setNrOfRows(int newValue) {
		if (newValue <= Location::MIN_CAPACITY) {
			throw exception("The capacity is too small");
		}
		this->nrRows = newValue;
	}


	


	//Default constructor
	Location() {
		
	}


};

int Location::MIN_NR_LETTERS = 5;
int Location::MIN_CAPACITY = 10;