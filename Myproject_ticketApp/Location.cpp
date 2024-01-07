#include <iostream>
#include <string>

using namespace std;

class Location {

	char* name = nullptr;
	string address = "-";
	string zoneName = "-";
	int maxSeats;  //manages the total nr of seats per each row
	int nrRows;
	//bool** occupiedSeats;

public:
	static int MIN_NR_LETTERS;
	static int MIN_CAPACITY;

public:
	//PUBLIC INTERFACE

	//GETTERS
	//SETTERS  + VALIDATION!!!!!!!!!!

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
		if (newMax < Location::MIN_CAPACITY) {
			throw exception("The capacity is too small");
		}
		this->maxSeats = newMax;
	}

	//number of rows
	int getMaxNrOfRows() {
		return this->nrRows;
	}

	void setNrOfRows(int newValue) {
		if (newValue < Location::MIN_CAPACITY) {
			throw exception("The capacity is too small");
		}
		this->nrRows = newValue;
	}

	//Default constructor
	Location() {
		this->setLocationName("No name");
		this->setLocationAddress("No address");
		this->setLocationZone("No chosen zone");
		this->setMaxNrOfSeats(10);
		this->setNrOfRows(10);
	}

	//CONSTRUCTOR
	Location(const char* name, const string address, const string zoneName, const int maxCapacity, const int nrRows) {
		this->setLocationName(name);
		this->setLocationAddress(address);
		this->setLocationZone(zoneName);
		this->setMaxNrOfSeats(maxCapacity);
		this->setNrOfRows(nrRows);
	}

	//COPY CONSTRUCTOR
	Location(const Location& source) {
		if (source.name == nullptr) {
			throw exception("Empty name. You don't have what to copy here");
		}

		this->name = new char[strlen(source.name) + 1];
		strcpy_s(this->name, strlen(source.name) + 1, source.name);

		this->address = source.address;
		this->zoneName = source.zoneName;
		this->maxSeats = source.maxSeats;
		this->nrRows = source.nrRows;

	}

	//OPERATORS

	//operator=
	Location& operator=(const Location& source) {
		//this (destination)
		//source (source)
		if (source.name != nullptr) {
			if (this->name != nullptr) {
				delete[] this->name;
				this->name = nullptr;
			}
			this->name = new char[strlen(source.name) + 1];
			strcpy_s(this->name, strlen(source.name) + 1, source.name);
		}

		this->address = source.address;
		this->zoneName = source.zoneName;
		this->maxSeats = source.maxSeats;
		this->nrRows = source.nrRows;

		return *this;

	}

	//DESTRUCTOR
	~Location() {
		if (this->name != nullptr) {
			delete[] this->name;
			this->name = nullptr;
		}
	}

	//FUNCTIONS

	//Print information
	void printLocationInfo() {
		cout << endl << "--------------------------------";
		cout << endl << "Location name: " << this->getLocationName();
		cout << endl << "Location address: " << this->getLocationAddress();
		cout << endl << "Zone: " << this->getZoneName();
		cout << endl << "Maximum capacity: " << this->getMaxNrOfSeats();
		cout << endl << "Total number of rows: " << this->getMaxNrOfRows();
	}


	//FRIENDS
	friend ostream& operator<<(ostream& console,Location& source);
	friend void operator>>(istream& input, Location& location);
};


