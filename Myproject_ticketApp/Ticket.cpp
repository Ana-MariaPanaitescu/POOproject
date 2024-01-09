//#include "Ticket.h"
//#include <iostream>
//#include <string>
//#include "Location.cpp"
//
//using namespace std;
//
//enum ClientType { STUDENT = 1, CHILD = 2, ADULT = 3, RETIRED = 4 };
//
////class Location;  // declaration to let the compiler know that Location is a class;
//
////Idee: genereaza tickete UNICE pe baza numelui clientului + tip + nr bilet
////exemplu: iau prima litera din nume, o transform in numar cu ajutorul ascii code, lipesc de ea tipul clientului(1,2,3,4) si la sfarsit lipesc de ea id-ul(care e generat in fuctie de nr de bilete)
//
//class Ticket {
//	
//	char clientName[100] = "";
//	ClientType clientType = ClientType::CHILD;
//	int clientAge = 1;
//	int nrRow = 1;
//	int nrSeat = 1;
//	float price = 1.0;
//	Location loc;        //reference/pointer to the relevant Location object
//
//	//int* soldTickets;
//	//int noTickets = 0;
//	
//	//int row;
//	//int seatNr;
//	//bool availableSeat;
//	//as face o clasa zona care sa imi stocheze locurile + daca e liber sau ocupat
//	
//	//int maxNrOfTickets;
//	//in functie de varsta sa afisez pe bilet ClientType, si pretul(pretul difera de la client la client)
//
//public:
//	const int id;                     //we use it to generate ids for the clients
//	const static int MIN_VALUE;
//	static int nrOfTickets;           //used to count the tickets
//
//private:
//
//	//STATIC METHODS
//	static int getNrOfTickets() {
//		return nrOfTickets;
//	}
//	static void increaseByOneTicket() {
//		nrOfTickets += 1;
//	}
//
//public:
//	
//	//SETTERS + VALIDATION
//	//GETTERS
//
//	//Client name
//	char* getClientName() {
//		return this->clientName;
//	}
//
//	void setClientName(const char* newName) {
//		if (strlen(newName) >= 100)
//			throw exception("Client name is too long");
//		else
//			strcpy_s(this->clientName, newName);
//	}
//
//	//Client type
//	//function for displaying the name
//	string getClientTypeName() {
//		switch (this->clientType)
//		{
//		case STUDENT:
//			return "Student";
//		case CHILD:
//			return "Child";
//		case ADULT:
//			return "Adult";
//		case RETIRED:
//			return "Retired";
//		}
//	}
//
//	ClientType getClientType() {
//		return this->clientType;
//	}
//
//	//Age
//	int getAge() {
//		return this->clientAge;
//	}
//
//	void setAge(int newValue){
//		if (newValue <= MIN_VALUE)
//			throw exception("Invalid age");
//		else
//		this->clientAge = newValue;
//	}
//
//	//Row
//	int getRowNr() {
//		return this->nrRow;
//	}
//
//	void setRowNr(int newValue) {
//		if (newValue < MIN_VALUE)
//			throw exception("Invalid row number");
//		else
//			this->nrRow = newValue;
//	}
//
//	//Seat
//	int getSeatNr() {
//		return this->nrSeat;
//	}
//
//	void setSeatNr(int newValue) {
//		if (newValue <= MIN_VALUE)
//			throw exception("Invalid seat number");
//		else
//			this->nrSeat = newValue;
//	}
//
//	//Price
//	float getPrice() {
//		return this->price;
//	}
//
//	void setPrice(float newPrice) {
//		if (newPrice <= MIN_VALUE)
//			throw exception("No such price value");
//		else
//			this->price = newPrice;
//	}
//
//	//Default ctor
//	Ticket() :id(Ticket::MIN_VALUE), loc("None", "No address", 2, 2) {
//
//		Ticket::increaseByOneTicket();
//	}
//
//	//Constructor
//	Ticket(const char* name, ClientType clientType, int age, int row, int seat, float price, const char* locName, string locAddress, int maxSeatsPerRow, int rows)
//		:id(Ticket::nrOfTickets), loc(locName,locAddress, maxSeatsPerRow, rows)
//	{
//		Ticket::increaseByOneTicket();
//		this->setClientName(name);
//		this->clientType = clientType;
//		this->setAge(age);
//		this->setRowNr(row);
//		this->setSeatNr(seat);
//		this->setPrice(price);
//	}
//
//	Ticket(const char* name, ClientType clientType, int age, int row, int seat, float price, Location& receivedLocation)
//		:id(Ticket::nrOfTickets), loc(receivedLocation)
//	{
//		Ticket::increaseByOneTicket();
//		this->setClientName(name);
//		this->clientType = clientType;
//		this->setAge(age);
//		this->setRowNr(row);
//		this->setSeatNr(seat);
//		this->setPrice(price);
//	}
//
//	//Copy constructor
//	Ticket(const Ticket& source): id(source.id), loc(source.loc){
//		strcpy_s(this->clientName, source.clientName);
//		this->clientType = source.clientType;
//		this->clientAge = source.clientAge;
//		this->nrRow = source.nrRow;
//		this->nrSeat = source.nrSeat;
//		this->price = source.price;
//
//	}
//	//operator=
//	Ticket& operator=(const Ticket& source) {
//		strcpy_s(this->clientName, source.clientName);
//		this->clientType = source.clientType;
//		this->clientAge = source.clientAge;
//		this->nrRow = source.nrRow;
//		this->nrSeat = source.nrSeat;
//		this->price = source.price;
//
//		return *this;
//	}
//	
//	//Destructor
//	~Ticket() {
//
//	}
//
//	////FUNCTIONS
//	void printTicketInfo() {
//		cout << endl << "------------------------";
//		cout << endl << "Id client is: " << this->id;
//		cout << endl << "Client name: " << this->getClientName();
//		cout << endl << "Client type: " << this->getClientTypeName();
//		cout << endl << "Client age:" << this->getAge();
//		cout << endl << "Row number: " << this->getRowNr();
//		cout << endl << "Seat number: " << this->getSeatNr();
//		cout << endl << "Price paid: " << this->getPrice();
//	}
//
//	//Function to check if the seat is available
//	// 1 - if it is available  0 - if it is not
//
//	bool isSeatAvailable(){ 
//		return !loc.isSeatOccupied(this->nrRow, this->nrSeat);
//	}
//
//	//bool isSeatAvailable() {   // 1 - if it is available  0 - if it is not
//	//	int ok = 0;
//	//	if (this->nrRow >= 1 && this->nrRow <= location.getMaxNrOfRows()
//	//		&& this->nrSeat >= 1 && this->nrSeat <= location.getMaxNrOfSeats() &&
//	//		!location.isSeatOccupied(nrRow, nrSeat))
//	//		ok = 1;
//	//	return ok;
//	//}
//
//
//
//	//FRIENDS
//	friend ostream& operator<<(ostream& console, Ticket& source);
//	friend void operator>>(istream& input, Ticket& ticket);
//
//};





//idea: I want to generate ids for the maximum capacity of the location(maximum seats)
//I need to use the maximum capacity from the location class, don't know for sure how


/////////////////////////////////////////////////// WHEN WORKING WITH HEADER THIS IS THE CPP	


//	int Ticket::getNrOfTickets() {
//		return nrOfTickets;
//	}
//	void Ticket::increaseByOneTicket() {
//		nrOfTickets += 1;
//	}
//
//
//string Ticket::getClientTypeName() {
//	switch (this->clientType)
//	{
//	case STUDENT:
//		return "Student";
//	case CHILD:
//		return "Child";
//	case ADULT:
//		return "Adult";
//	case RETIRED:
//		return "Retired";
//	}
//}
//
//ClientType Ticket::getClientType() {
//	return this->clientType;
//}
//
////Age
//int Ticket::getAge() {
//	return this->clientAge;
//}
//
//void Ticket::setAge(int newValue) {
//	if (newValue <= MIN_VALUE)
//		throw exception("Invalid age");
//	else
//		this->clientAge = newValue;
//}
//
////Row
//int Ticket::getRowNr() {
//	return this->nrRow;
//}
//
//void Ticket::setRowNr(int newValue) {
//	if (newValue < MIN_VALUE)
//		throw exception("Invalid row number");
//	else
//		this->nrRow = newValue;
//}
//
////Seat
//int Ticket::getSeatNr() {
//	return this->nrSeat;
//}
//
//void Ticket::setSeatNr(int newValue) {
//	if (newValue <= MIN_VALUE)
//		throw exception("Invalid seat number");
//	else
//		this->nrSeat = newValue;
//}
//
////Price
//float Ticket::getPrice() {
//	return this->price;
//}
//
//void Ticket::setPrice(float newPrice) {
//	if (newPrice <= MIN_VALUE)
//		throw exception("No such price value");
//	else
//		this->price = newPrice;
//}
//
////Default ctor
//Ticket::Ticket() :id(Ticket::MIN_VALUE) {
//
//	Ticket::increaseByOneTicket();
//}
//
////Constructor
//Ticket::Ticket(ClientType clientType, int age, int row, int seat, float price) :id(Ticket::nrOfTickets) {
//	Ticket::increaseByOneTicket();
//	this->clientType = clientType;
//	this->setAge(age);
//	this->setRowNr(row);
//	this->setSeatNr(seat);
//	this->setPrice(price);
//}
//
////Copy constructor
//Ticket::Ticket(const Ticket& source) : id(source.id) {
//	this->clientType = source.clientType;
//	this->clientAge = source.clientAge;
//	this->nrRow = source.nrRow;
//	this->nrSeat = source.nrSeat;
//	this->price = source.price;
//
//}
////operator=
//Ticket& Ticket::operator=(const Ticket& source) {
//
//	this->clientType = source.clientType;
//	this->clientAge = source.clientAge;
//	this->nrRow = source.nrRow;
//	this->nrSeat = source.nrSeat;
//	this->price = source.price;
//
//	return *this;
//}
//
////Destructor
//Ticket::~Ticket() {
//
//}
//
//////FUNCTIONS
//void Ticket::printTicketInfo() {
//	cout << endl << "------------------------";
//	cout << endl << "Id client is: " << this->id;
//	cout << endl << "Client type: " << this->getClientTypeName();
//	cout << endl << "Client age:" << this->getAge();
//	cout << endl << "Row number: " << this->getRowNr();
//	cout << endl << "Seat number: " << this->getSeatNr();
//	cout << endl << "Price paid: " << this->getPrice();
//}
//
//ostream& operator<<(ostream& console, Ticket& source) {
//
//	console << "\n\n" << "Ticket data: ";
//	console << endl << "Id client: " << source.id;
//	console << endl << "ClientType: " << source.getClientTypeName();
//	console << endl << "Client age: " << source.getAge();
//	console << endl << "Row: " << source.getRowNr() << "  " << "Seat: " << source.getSeatNr();
//	console << endl << "Price: " << source.getPrice();
//
//	return console;
//}




