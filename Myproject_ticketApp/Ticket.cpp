#include <iostream>

using namespace std;

enum ClientType { STUDENT = 1, CHILD = 2, ADULT = 3, RETIRED = 4 };

//Idee: genereaza tickete UNICE pe baza numelui clientului + tip + nr bilet
//exemplu: iau prima litera din nume, o transform in numar cu ajutorul ascii code, lipesc de ea tipul clientului(1,2,3,4) si la sfarsit lipesc de ea id-ul(care e generat in fuctie nu nr de bilete)
class Ticket {
	
	ClientType clientType = ClientType::CHILD;
	int clientAge = 1;
	int nrRow = 1;
	int nrSeat = 1;
	float price = 1.0;
	
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

	void setAge(int newValue){
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
	Ticket() :id(Ticket::MIN_VALUE) {

		Ticket::increaseByOneTicket();
	}

	//Constructor
	Ticket(ClientType clientType, int age, int row, int seat, float price):id(Ticket::nrOfTickets) {
		Ticket::increaseByOneTicket();
		this->clientType = clientType;
		this->setAge(age);
		this->setRowNr(row);
		this->setSeatNr(seat);
		this->setPrice(price);
	}

	//Copy constructor
	Ticket(const Ticket& source): id(source.id){
		this->clientType = source.clientType;
		this->clientAge = source.clientAge;
		this->nrRow = source.nrRow;
		this->nrSeat = source.nrSeat;
		this->price = source.price;

	}
	//operator=
	Ticket& operator=(const Ticket& source) {

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
		cout << endl << "Client type: " << this->getClientTypeName();
		cout << endl << "Client age:" << this->getAge();
		cout << endl << "Row number: " << this->getRowNr();
		cout << endl << "Seat number: " << this->getSeatNr();
		cout << endl << "Price paid: " << this->getPrice();
	}

	//FRIENDS
	friend ostream& operator<<(ostream& console, Ticket& source);

};

//nu merge :((      daca pun Ticket&      nu merge nici fara, iar a aparut eroarea  LNK2005

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



//idea: I want to generate ids for the maximum capacity of the location(maximum seats)
//I need to use the maximum capacity from the location class, don't know for sure how
