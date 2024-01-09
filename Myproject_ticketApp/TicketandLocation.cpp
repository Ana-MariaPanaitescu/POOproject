#include <iostream>
#include <string>

using namespace std;

enum ClientType { STUDENT = 1, CHILD = 2, ADULT = 3, RETIRED = 4 };

class Location {

	char* name = nullptr;
	string address = "-";
	string zoneName = "-";
	int maxSeats = 2;  //manages the total nr of seats per each row
	int nrRows = 2;
	bool** occupiedSeats = nullptr;

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
		if (newZone == "") {
			throw exception("Zone name too short");
		}
		else {
			this->zoneName = newZone;
		}
	}

	//maximum number of seats per row
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
	Location() : occupiedSeats(nullptr) {
		this->setLocationName("No name");
		this->setLocationAddress("No address");
		this->setLocationZone("No chosen zone");
		this->setMaxNrOfSeats(1);
		this->setNrOfRows(1);
	}

	//CONSTRUCTOR
	Location(const char* name, const string address, const string zoneName, const int maxSeatsPerRow, const int nrRows) :occupiedSeats(new bool* [nrRows]) {
		this->setLocationName(name);
		this->setLocationAddress(address);
		this->setLocationZone(zoneName);
		this->setMaxNrOfSeats(maxSeatsPerRow);
		this->setNrOfRows(nrRows);

		//Initialize the matrix
		for (int i = 0; i < nrRows; i++) {
			occupiedSeats[i] = new bool[maxSeatsPerRow];
			for (int j = 0; j < maxSeatsPerRow; j++) {
				occupiedSeats[i][j] = false;  // 0 means seat is not occupied
			}
		}

	}

	//Constructor with some arguments (name, address, seatsPerRow, nrRows)
	Location(const char* name, const string address, const int maxSeatsPerRow, const int nrRows) : occupiedSeats(new bool* [nrRows]) {
		this->setLocationName(name);
		this->setLocationAddress(address);
		this->setMaxNrOfSeats(maxSeatsPerRow);
		this->setNrOfRows(nrRows);

		//Initialize the matrix
		for (int i = 0; i < nrRows; i++) {
			occupiedSeats[i] = new bool[maxSeatsPerRow];
			for (int j = 0; j < maxSeatsPerRow; j++) {
				occupiedSeats[i][j] = false;  // 0 means seat is not occupied
			}
		}
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

		// Copy the occupiedSeats matrix
		this->occupiedSeats = new bool* [this->nrRows];
		for (int i = 0; i < this->nrRows; i++) {
			this->occupiedSeats[i] = new bool[this->maxSeats];
			for (int j = 0; j < this->maxSeats; j++) {
				this->occupiedSeats[i][j] = source.occupiedSeats[i][j];
			}
		}

	}

	//OPERATORS

	//operator=
	Location& operator=(const Location& source) {
		//this (destination)
		//source (source)

		if (this != &source) {
			// Deallocate existing resources
			if (this->name != nullptr) {
				delete[] this->name;
				this->name = nullptr;
			}
			if (this->occupiedSeats != nullptr) {
				for (int i = 0; i < this->nrRows; i++) {
					delete[] this->occupiedSeats[i];
				}
				delete[] this->occupiedSeats;
				this->occupiedSeats = nullptr;
			}

			// Copy values from source
			if (source.name != nullptr) {
				this->name = new char[strlen(source.name) + 1];
				strcpy_s(this->name, strlen(source.name) + 1, source.name);
			}
			this->address = source.address;
			this->zoneName = source.zoneName;
			this->maxSeats = source.maxSeats;
			this->nrRows = source.nrRows;

			// Copy the occupiedSeats matrix
			this->occupiedSeats = new bool* [this->nrRows];
			for (int i = 0; i < this->nrRows; i++) {
				this->occupiedSeats[i] = new bool[this->maxSeats];
				for (int j = 0; j < this->maxSeats; j++) {
					this->occupiedSeats[i][j] = source.occupiedSeats[i][j];
				}
			}
		}
		return *this;

	}

	//DESTRUCTOR
	//Check the destructor
	~Location() {
		if (this->name != nullptr) {
			delete[] this->name;
			this->name = nullptr;
		}
		//Deallocate the matrix
		if (this->occupiedSeats != nullptr) {
			for (int i = 0; i < this->nrRows; i++) {
				delete[] this->occupiedSeats[i];
			}
			delete[] this->occupiedSeats;
			this->occupiedSeats = nullptr;
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

	//Function to see if a seat is occupied or not
	bool isSeatOccupied(int row, int seat) {
		// 1 means seat is occupied, 0 means seat is not occupied
		return occupiedSeats[row - 1][seat - 1];
	}

	//Function to occupy a seat
	void occupySeat(int row, int seat) {
		// Mark the seat as occupied (1)
		occupiedSeats[row - 1][seat - 1] = true;
	}

	//FRIENDS
	friend ostream& operator<<(ostream& console, Location& source);
	friend void operator>>(istream& input, Location& location);
};


//////////////////////////TIcket class /////////////////////////////////


class Ticket {

	char clientName[100] = "";
	ClientType clientType = ClientType::CHILD;
	int clientAge = 1;
	int nrRow = 1;
	int nrSeat = 1;
	float price = 1.0;
	Location loc;        //reference/pointer to the relevant Location object

	//int* soldTickets;
	//int noTickets = 0;

	//int row;
	//int seatNr;
	//bool availableSeat;
	//as face o clasa zona care sa imi stocheze locurile + daca e liber sau ocupat

	//int maxNrOfTickets;
	//in functie de varsta sa afisez pe bilet ClientType, si pretul(pretul difera de la client la client)

public:
	const int id;                     //we use it to generate ids for the clients
	const static int MIN_VALUE;
	static int nrOfTickets;           //used to count the tickets

private:

	//STATIC METHODS
	static int getNrOfTickets() {
		return nrOfTickets;
	}
	static void increaseByOneTicket() {
		nrOfTickets += 1;
	}

public:

	//SETTERS + VALIDATION
	//GETTERS

	//Client name
	char* getClientName() {
		return this->clientName;
	}

	void setClientName(const char* newName) {
		if (strlen(newName) >= 100)
			throw exception("Client name is too long");
		else
			strcpy_s(this->clientName, newName);
	}

	//Client type
	//function for displaying the name
	string getClientTypeName() {
		switch (this->clientType)
		{
		case STUDENT:
			return "Student";
		case CHILD:
			return "Child";
		case ADULT:
			return "Adult";
		case RETIRED:
			return "Retired";
		}
	}

	ClientType getClientType() {
		return this->clientType;
	}

	//Age
	int getAge() {
		return this->clientAge;
	}

	void setAge(int newValue) {
		if (newValue <= MIN_VALUE)
			throw exception("Invalid age");
		else
			this->clientAge = newValue;
	}

	//Row
	int getRowNr() {
		return this->nrRow;
	}

	void setRowNr(int newValue) {
		if (newValue < MIN_VALUE)
			throw exception("Invalid row number");
		else
			this->nrRow = newValue;
	}

	//Seat
	int getSeatNr() {
		return this->nrSeat;
	}

	void setSeatNr(int newValue) {
		if (newValue <= MIN_VALUE)
			throw exception("Invalid seat number");
		else
			this->nrSeat = newValue;
	}

	//Price
	float getPrice() {
		return this->price;
	}

	void setPrice(float newPrice) {
		if (newPrice <= MIN_VALUE)
			throw exception("No such price value");
		else
			this->price = newPrice;
	}

	//Default ctor
	Ticket() :id(Ticket::MIN_VALUE), loc("None", "No address", 2, 2) {

		Ticket::increaseByOneTicket();
	}

	//Constructor
	Ticket(const char* name, ClientType clientType, int age, int row, int seat, float price, const char* locName, string locAddress, int maxSeatsPerRow, int rows)
		:id(Ticket::nrOfTickets), loc(locName, locAddress, maxSeatsPerRow, rows)
	{
		Ticket::increaseByOneTicket();
		this->setClientName(name);
		this->clientType = clientType;
		this->setAge(age);
		this->setRowNr(row);
		this->setSeatNr(seat);
		this->setPrice(price);
	}

	Ticket(const char* name, ClientType clientType, int age, int row, int seat, float price, Location& receivedLocation)
		:id(Ticket::nrOfTickets), loc(receivedLocation)
	{
		Ticket::increaseByOneTicket();
		this->setClientName(name);
		this->clientType = clientType;
		this->setAge(age);
		this->setRowNr(row);
		this->setSeatNr(seat);
		this->setPrice(price);
	}

	//Copy constructor
	Ticket(const Ticket& source) : id(source.id), loc(source.loc) {
		strcpy_s(this->clientName, source.clientName);
		this->clientType = source.clientType;
		this->clientAge = source.clientAge;
		this->nrRow = source.nrRow;
		this->nrSeat = source.nrSeat;
		this->price = source.price;

	}
	//operator=
	Ticket& operator=(const Ticket& source) {
		strcpy_s(this->clientName, source.clientName);
		this->clientType = source.clientType;
		this->clientAge = source.clientAge;
		this->nrRow = source.nrRow;
		this->nrSeat = source.nrSeat;
		this->price = source.price;

		return *this;
	}

	//Destructor
	~Ticket() {

	}

	////FUNCTIONS
	void printTicketInfo() {
		cout << endl << "------------------------";
		cout << endl << "Id client is: " << this->id;
		cout << endl << "Client name: " << this->getClientName();
		cout << endl << "Client type: " << this->getClientTypeName();
		cout << endl << "Client age:" << this->getAge();
		cout << endl << "Row number: " << this->getRowNr();
		cout << endl << "Seat number: " << this->getSeatNr();
		cout << endl << "Price paid: " << this->getPrice();
	}

	//Function to check if the seat is available
	// 1 - if it is available  0 - if it is not

	bool isSeatAvailable() {
		return !loc.isSeatOccupied(this->nrRow, this->nrSeat);
	}

	//bool isSeatAvailable() {   // 1 - if it is available  0 - if it is not
	//	int ok = 0;
	//	if (this->nrRow >= 1 && this->nrRow <= location.getMaxNrOfRows()
	//		&& this->nrSeat >= 1 && this->nrSeat <= location.getMaxNrOfSeats() &&
	//		!location.isSeatOccupied(nrRow, nrSeat))
	//		ok = 1;
	//	return ok;
	//}



	//FRIENDS
	friend ostream& operator<<(ostream& console, Ticket& source);
	friend void operator>>(istream& input, Ticket& ticket);

};
