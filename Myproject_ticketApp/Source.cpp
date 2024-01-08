#include <iostream>
#include <string>
#include "Location.cpp"
#include "Event.cpp"
#include "Ticket.cpp"
//#include "Ticket.h"

int Location::MIN_NR_LETTERS = 3;
int Location::MIN_CAPACITY = 2;

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
	
	Location l1;
	l1.printLocationInfo();

	Location l2("Sala Palatului", "Strada Primaverii, Nr.82", "Category B", 5000, 50);
	//l2.printLocationInfo();

	Location l3 = l2;  //copy constructor

	//l3.printLocationInfo();

	l1 = l3;  //  l1.operator=(l3)      
	l1.printLocationInfo();

	//Event e0;
	Event e1("Musicalul Mamma Mia", 17, 30, 8, 12, 2023);
	//e1.displayingDate();
	//e1.displayingTime();
	e1.printEventInfo();

	Event e2("Le Cirque Du Soleil", 9, 5, 5, 8, 2024);
	//e2.printEventInfo();

	//e2 = e1;
	//e2.printEventInfo();
	//Event e3 = e2;
	//e3.printEventInfo();

	Ticket t1;
	t1.printTicketInfo();

	Location l4("Romexpo", "Aviatorilor", 50, 50);

	Ticket t2("Alex Paunescu", STUDENT, 20, 5, 19, 50.30);
	t2.printTicketInfo();

	//t2 = t1;
	//t2.printTicketInfo();

	Ticket adult("Gabriela Aldici", ADULT, 47, 8, 1, 65.00);
	//adult.printTicketInfo();

	//cout << adult;
	//cout << e2;
	//cout << l2;

	cin >> adult;
	cout << adult;

	//cin >> e2;
	//cout << e2;

	//cin >> l2;
	//cout << l2;
	

}


ostream& operator<<(ostream& console, Ticket& source) {
	
	console << "\n\n" << "Ticket data: ";
	console << endl << "Id client: " << source.id;
	console << endl << "Client name: " << source.getClientName();
	console << endl << "ClientType: " << source.getClientTypeName();
	console << endl << "Client age: " << source.getAge();
	console << endl << "Row: " << source.getRowNr() << "  " << "Seat: " << source.getSeatNr();
	console << endl << "Price: " << source.getPrice();
	
	return console;
}

ostream& operator<<(ostream& console, Event& event) {
	console << "\n\nThe event data is:";
	console << endl << "Name: " << event.getEventName();
	console << endl << "Date: " << event.getDay() << "/" << event.getMonth() << "/" << event.getYear();
	console << endl << "Time: ";
	if (event.getHour() >= 0 && event.getHour() < 10) {
		console  << '0' << event.getHour();
	}
	else {
		console << event.getHour();
	}

	if (event.getMinutes() >= 0 && event.getMinutes() < 10) {
		console << ":" << '0' << event.getMinutes();
	}
	else {
		console << ":" << event.getMinutes();
	}
	return console;
}

ostream& operator<<(ostream& console, Location& location) {
	console << "\n\n" << "The location data is:";
	console << endl << "Name: " << location.getLocationName();
	console << endl << "Address: " << location.getLocationAddress();
	console << endl << "Zone Name: " << location.getZoneName();
	console << endl << "Nr. of rows: " << location.getMaxNrOfRows();
	console << endl << "Nr. of seats: " << location.getMaxNrOfSeats();
	return console;
}

void operator>>(istream& input, Ticket& ticket) {
	cout << endl << "Enter the name of the client: ";
	//char name[100];
	input.getline(ticket.clientName, 100); //istream& getline (char* s, streamsize n )     exemplu:  cin.getline(s , 11);    
	
	cout << endl << "Enter the client type";
	cout << endl << "Insert (1 - student, 2 - child, 3 - adult, 4 - retired): ";
	int type, age, row, seat;
	float price;
	input >> type;
	ticket.clientType = static_cast<ClientType>(type);
	
	cout << endl << "The client age is: ";
	input >> age;
	ticket.setAge(age);
	
	cout << endl << "The row selected is: ";
	input >> row;
	ticket.setRowNr(row);
	
	cout << endl << "The selected seat is: ";
	input >> seat;
	ticket.setSeatNr(seat);
	
	cout << endl << "Price of the ticket: ";
	input >> price;
	ticket.setPrice(price);
}

void operator>>(istream& input, Event& event) {
	cout << endl << "Insert the event's name: ";
	string name;
	getline(input, name);
	event.setEventName(name.c_str());
	//c_str() is used with string objects to obtain a pointer to a null terminated array of characters. The pointer is a type of const char*
	
	int hour, minutes, day, month, year;
	cout << endl << "TIME(hour:minutes) ";
	cout << endl << "Hour: ";
	input >> hour;
	event.setHour(hour);
	cout << endl << "Minutes: ";
	input >> minutes;
	event.setMinutes(minutes);
	
	cout << endl << "DATE(dd/mm/yyyy) ";
	cout << endl << "Day: ";
	input >> day;
	event.setDay(day);
	cout << endl << "Month: ";
	input >> month;
	event.setMonth(month);
	cout << endl << "Year: ";
	input >> year;
	event.setYear(year);
}

void operator>>(istream& input, Location& location) {
	cout << "\n\n" << "Location name is: ";
	string locName;
	getline(input, locName);
	location.setLocationName(locName.c_str());

	cout << endl << "Enter location address: ";
	string address;
	getline(input, address);
	location.setLocationAddress(address);

	cout << endl << "Enter zone name(Category A, Category B,..., VIP): ";
	string zone;
	getline(input, zone);
	location.setLocationZone(zone);
	//cout << "Debug: Length of zone name: " << zone.length() << endl;

	cout << endl << "Enter max. nr. of seats: ";
	int maxSeats;
	input >> maxSeats;
	location.setMaxNrOfSeats(maxSeats);

	cout << endl << "Enter nr. of rows:";
	int rows;
	input >> rows;
	location.setNrOfRows(rows);
}

