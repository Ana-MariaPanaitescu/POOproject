//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Location {
//
//	char* name = nullptr;
//	string address = "-";
//	string zoneName = "-";
//	int maxSeats = 2;  //manages the total nr of seats per each row
//	int nrRows = 2;
//	bool** occupiedSeats = nullptr;
//
//public:
//	static int MIN_NR_LETTERS;
//	static int MIN_CAPACITY;
//
//public:
//	//PUBLIC INTERFACE
//
//	//GETTERS
//	//SETTERS  + VALIDATION!!!!!!!!!!
//
//	//name
//	char* getLocationName() {
//
//		char* copy;
//		copy = new char[strlen(this->name) + 1];
//		strcpy_s(copy, strlen(this->name) + 1, this->name);
//
//		return copy;
//	}
//
//	void setLocationName(const char* newName) {
//		if (this->name != NULL) {                //verify if there is smth at that address
//			delete[] this->name;
//			this->name = nullptr;
//		}
//
//		this->name = new char[strlen(newName) + 1];
//		strcpy_s(this->name, strlen(newName) + 1, newName);
//
//	}
//
//	//address
//	string getLocationAddress() {
//		return this->address;
//	}
//
//	void setLocationAddress(string newAddress) {
//		if (newAddress == "" || newAddress.length() < Location::MIN_NR_LETTERS) {
//			throw exception("Location address too short");
//		}
//		else {
//			this->address = newAddress;
//		}
//	}
//
//	//zone name
//	string getZoneName() {
//		return this->zoneName;
//	}
//
//	void setLocationZone(string newZone) {
//		if (newZone == "") {
//			throw exception("Zone name too short");
//		}
//		else {
//			this->zoneName = newZone;
//		}
//	}
//
//	//maximum number of seats per row
//	int getMaxNrOfSeats() {
//		return this->maxSeats;
//	}
//
//	void setMaxNrOfSeats(int newMax) {
//		if (newMax < Location::MIN_CAPACITY) {
//			throw exception("The capacity is too small");
//		}
//		this->maxSeats = newMax;
//	}
//
//	//number of rows
//	int getMaxNrOfRows() {
//		return this->nrRows;
//	}
//
//	void setNrOfRows(int newValue) {
//		if (newValue < Location::MIN_CAPACITY) {
//			throw exception("The capacity is too small");
//		}
//		this->nrRows = newValue;
//	}
//
//	//Default constructor
//	Location() : occupiedSeats(nullptr){
//		this->setLocationName("No name");
//		this->setLocationAddress("No address");
//		this->setLocationZone("No chosen zone");
//		this->setMaxNrOfSeats(1);
//		this->setNrOfRows(1);
//	}
//
//	//CONSTRUCTOR
//	Location(const char* name, const string address, const string zoneName, const int maxSeatsPerRow, const int nrRows) :occupiedSeats(new bool* [nrRows]) {
//		this->setLocationName(name);
//		this->setLocationAddress(address);
//		this->setLocationZone(zoneName);
//		this->setMaxNrOfSeats(maxSeatsPerRow);
//		this->setNrOfRows(nrRows);
//
//		//Initialize the matrix
//		for (int i = 0; i < nrRows; i++) {
//			occupiedSeats[i] = new bool[maxSeatsPerRow];
//			for (int j = 0; j < maxSeatsPerRow; j++) {
//				occupiedSeats[i][j] = false;  // 0 means seat is not occupied
//			}
//		}
//
//	}
//
//	//Constructor with some arguments (name, address, seatsPerRow, nrRows)
//	Location(const char* name, const string address, const int maxSeatsPerRow, const int nrRows) : occupiedSeats(new bool* [nrRows]) {
//		this->setLocationName(name);
//		this->setLocationAddress(address);
//		this->setMaxNrOfSeats(maxSeatsPerRow);
//		this->setNrOfRows(nrRows);
//
//		//Initialize the matrix
//		for (int i = 0; i < nrRows; i++) {
//			occupiedSeats[i] = new bool[maxSeatsPerRow];
//			for (int j = 0; j < maxSeatsPerRow; j++) {
//				occupiedSeats[i][j] = false;  // 0 means seat is not occupied
//			}
//		}
//	}
//
//	////Constructor that initialize the occupiedSeats array
//	//Location(const char* name, const string address, const string zoneName, const int maxSeatsPerRow, const int nrRows) :occupiedSeats(new bool* [nrRows]) {
//
//	//	//Initialize the matrix
//	//	for (int i = 0; i < nrRows; i++) {
//	//		occupiedSeats[i] = new bool[maxSeatsPerRow];
//	//		for (int j = 0; j < maxSeatsPerRow; j++) {
//	//			occupiedSeats[i][j] = false;  // 0 means seat is not occupied
//	//		}
//	//	}
//	//}
//
//	//COPY CONSTRUCTOR
//	Location(const Location& source) {
//		if (source.name == nullptr) {
//			throw exception("Empty name. You don't have what to copy here");
//		}
//
//		this->name = new char[strlen(source.name) + 1];
//		strcpy_s(this->name, strlen(source.name) + 1, source.name);
//
//		this->address = source.address;
//		this->zoneName = source.zoneName;
//		this->maxSeats = source.maxSeats;
//		this->nrRows = source.nrRows;
//
//		// Copy the occupiedSeats matrix
//		this->occupiedSeats = new bool* [this->nrRows];
//		for (int i = 0; i < this->nrRows; i++) {
//			this->occupiedSeats[i] = new bool[this->maxSeats];
//			for (int j = 0; j < this->maxSeats; j++) {
//				this->occupiedSeats[i][j] = source.occupiedSeats[i][j];
//			}
//		}
//
//	}
//
//	//OPERATORS
//
//	//operator=
//	Location& operator=(const Location& source) {
//		//this (destination)
//		//source (source)
//
//		if (this != &source) {
//		    // Deallocate existing resources
//			if (this->name != nullptr) {
//				delete[] this->name;
//				this->name = nullptr;
//			}
//			for (int i = 0; i < this->nrRows; i++) {
//				delete[] this->occupiedSeats[i];
//			}
//			delete[] this->occupiedSeats;
//
//			// Copy values from source
//			if (source.name != nullptr) {
//				this->name = new char[strlen(source.name) + 1];
//				strcpy_s(this->name, strlen(source.name) + 1, source.name);
//			}
//			this->address = source.address;
//			this->zoneName = source.zoneName;
//			this->maxSeats = source.maxSeats;
//			this->nrRows = source.nrRows;
//
//			// Copy the occupiedSeats matrix
//			this->occupiedSeats = new bool* [this->nrRows];
//			for (int i = 0; i < this->nrRows; i++) {
//				this->occupiedSeats[i] = new bool[this->maxSeats];
//				for (int j = 0; j < this->maxSeats; j++) {
//					this->occupiedSeats[i][j] = source.occupiedSeats[i][j];
//				}
//			}
//		}
//		return *this;
//
//	}
//
//	//DESTRUCTOR
//	//Check the destructor
//	~Location() {
//		if (this->name != nullptr) {
//			delete[] this->name;
//			this->name = nullptr;
//		}
//		//Deallocate the matrix
//		for (int i = 0; i < this->nrRows; i++) {
//			delete[] this->occupiedSeats[i];
//		}
//		delete[] this->occupiedSeats;
//	}
//
//	//FUNCTIONS
//
//	//Print information
//	void printLocationInfo() {
//		cout << endl << "--------------------------------";
//		cout << endl << "Location name: " << this->getLocationName();
//		cout << endl << "Location address: " << this->getLocationAddress();
//		cout << endl << "Zone: " << this->getZoneName();
//		cout << endl << "Maximum capacity: " << this->getMaxNrOfSeats();
//		cout << endl << "Total number of rows: " << this->getMaxNrOfRows();
//	}
//
//	//Function to see if a seat is occupied or not
//	bool isSeatOccupied(int row, int seat) {
//		// 1 means seat is occupied, 0 means seat is not occupied
//		return occupiedSeats[row - 1][seat - 1];
//	}
//
//	//Function to occupy a seat
//	void occupySeat(int row, int seat) {
//		// Mark the seat as occupied (1)
//		occupiedSeats[row - 1][seat - 1] = true;
//	}
//
//	//FRIENDS
//	friend ostream& operator<<(ostream& console,Location& source);
//	friend void operator>>(istream& input, Location& location);
//};
//
//
