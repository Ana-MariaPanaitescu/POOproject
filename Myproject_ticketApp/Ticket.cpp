#include <iostream>
using namespace std;

enum ClientType { STUDENT = 1, CHILD = 2, ADULT = 3, RETIRED = 4 };

class Ticket {
	
	ClientType type;
	int clientAge;
	int* soldTickets;
	int noTickets = 0;
	
	//int row;
	//int seatNr;
	//bool availableSeat;
	//as face o clasa zona care sa imi stocheze locurile + daca e liber sau ocupat
	
	//int maxNrOfTickets;
	//in functie de varsta sa afisez pe bilet ClientType, si pretul(pretul difera de la client la client)

public:
	const int id;

};

//idea: I want to generate ids for the maximum capacity of the location(maximum seats)
//I need to use the maximum capacity from the location, don't know for sure how
