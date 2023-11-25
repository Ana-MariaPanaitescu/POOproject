#include <iostream>
#include <string>
#include "Location.cpp"
#include "Event.cpp"
#include "Ticket.cpp"

int Location::MIN_NR_LETTERS = 5;
int Location::MIN_CAPACITY = 10;

int Event::MIN_NR_LETTERS = 2;
int Event::MIN_VALUE = 0;
int Event::MAX_HOUR = 23;
int Event::MAX_MINUTES = 59;
int Event::MIN_VALUE_2 = 1;
int Event::MAX_DAY = 31;
int Event::MAX_MONTH = 12;

int Ticket::nrOfTickets = 0;
const int Ticket::MIN_VALUE = 0;


int main() {
	
	//Testing phase
	//imi trebuie: operators, one dynamically allocated numeric vector, one constant field, one method static
	//overload operators << and >> 
	//another 2 overloaded operator for each class

	//one statically defined array, one dynamically array
	//at least one class defines static field for each class
	//at least one class defines a constant field
	//each class at least 2 generic methods for processing/displaying
	//each class at least 2 ctors with parameters, a copy ctor, a destructor, operator=
	// >> and << for each class
	// and other operators
	
	//Location l1;
	//l1.printLocationInfo();

	//Location l2("Sala Palatului", "Strada Primaverii, Nr.82", "Category B", 5000, 50);
	////l2.printLocationInfo();

	//Location l3 = l2;  //copy constructor

	////l3.printLocationInfo();

	//l1 = l3;  //  l1.operator=(l3)      
	//l1.printLocationInfo();

	////Event e0;
	//Event e1("Musicalul Mamma Mia", 17, 30, 8, 12, 2023);
	////e1.displayingDate();
	////e1.displayingTime();
	//e1.printEventInfo();

	//Event e2("Le Cirque Du Soleil", 9, 5, 5, 8, 2024);
	//e2.printEventInfo();

	//e2 = e1;
	//e2.printEventInfo();
	//Event e3 = e2;
	//e3.printEventInfo();

	Ticket t1;
	t1.printTicketInfo();

	Ticket t2(STUDENT, 20, 5, 19, 50.30);
	t2.printTicketInfo();

}