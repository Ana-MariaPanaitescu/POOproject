#include <iostream>
#include <string>
#include <fstream>
#include "TicketandLocation.cpp"
#include "Event.cpp"

int Location::MIN_NR_LETTERS = 3;
int Location::MIN_CAPACITY = 1;

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

	//INTERFACE

	int number;

	cout << endl << "WELCOME TO THE TICKETING MENU";
	cout << endl;
	cout << endl << "If you want to read tickets data from the file press 1";
	cout << endl << "If you want to insert your ticket data from the code press 2";
	cout << endl << "If you want to insert data from console press 3";
	cout << endl << "If you want to exit press 4";
	cout << endl;

	cin >> number;

	ofstream outputFile("TicketsData.txt", ios::out | ios::app);   //writing in a text file
	ifstream inputFile("ReportTickets.txt", ios::in);
	
	//Create a ticket and location data and also an event data
	Location romexpo("Romexpo", "Aviatorilor, Nr.74", "VIP", 50, 50);
	Ticket maria("Maria Aldici", ADULT, 47, 8, 1, 65.00, romexpo);
	Event spectacolCirc("Le Cirque Du Soleil", 9, 5, 5, 8, 2024);




	if (number == 1) {
		//Reading from the Report tickets
		if (inputFile.is_open()) {
			cout << endl << "The ReportTickets.txt is available";

			cout << "\n\n" << "TICKETS DATA IS DISPLAYED HERE: ";
			cout << "\n";
				
			cout << endl << "-----TICKET DATA-----";

			string clientName;
			char buffer[100];
			inputFile.getline(buffer, 100);
			clientName = string(buffer);
			cout << endl << "Client name is: " << clientName;

			cout << endl << "Client Type (1 - student, 2 - child, 3 - adult, 4 - retired): ";
			int clientTypeInt;
			inputFile >> clientTypeInt;
			ClientType type = static_cast<ClientType>(clientTypeInt);
			cout << type;

			int age;
			inputFile >> age;
			cout << endl << "The client age is: " << age;

			int row;
			inputFile >> row;
			cout << endl << "Row: " << row << "    ";

			int seat;
			inputFile >> seat;
			cout << "Seat: " << seat;

			float price;
			inputFile >> price;
			cout << endl << "The ticket price was: " << price;

			inputFile.ignore();
			string locationName;
			char buffer2[100];
			inputFile.getline(buffer2, 100);
			locationName = string(buffer2);
			cout << endl << "Location: " << locationName;

			string address;
			char buffer3[200];
			inputFile.getline(buffer3, 200);
			address = string(buffer3);
			cout << endl << "Address: " << address;

			string category;
			char buffer4[50];
			inputFile.getline(buffer4, 50);
			category = string(buffer4);
			cout << endl << "Category: " << category;

			string eventName;
			char buffer5[100];
			inputFile.getline(buffer5, 100);
			eventName = string(buffer5);
			cout << endl << "Event name: " << eventName;

			int hour;
			inputFile >> hour;
			cout << endl << "-----TIME-----";
			if (hour >= 0 && hour < 10) {
				cout << endl << '0' << hour;
			}
			else
				cout << endl << hour;

			int minutes;
			inputFile >> minutes;
			if (minutes >= 0 && minutes < 10) {
				cout << ":" << '0' << minutes;
			}
			else {
				cout << ":" << minutes;
			}

			cout << endl << "-----DATE-----";

			int day;
			inputFile >> day;
			if (day > 0 && day < 10)
				cout << endl << "0" << day << "/";
			else
				cout << endl << day << "/";

			int month;
			inputFile >> month;
			if (month > 0 && month < 10)
				cout << "0" << month << "/";
			else
				cout << month << "/";

			int year;
			inputFile >> year;
			cout << year;

			//cout << endl << day << "/" << month << "/" << year;
			
			inputFile.close();
		}
		else {
			cout << endl << "********The ReportTickets.txt is missing";
		}
		
	}
	else {
		if (number == 2) {
			if (outputFile.is_open()) {
				cout << endl << "The TicketsData.txt file has been created. We can use it";
			}
			//We insert another ticket but not from the console
			outputFile << endl << "NEW TICKET";
			outputFile << romexpo;
			outputFile << maria;
			outputFile << spectacolCirc;
			
			outputFile.close();
		}
		
		else {
			if (number == 3) {
				if (outputFile.is_open()) {
					cout << endl << "INSERT YOUR TICKET DATA" << endl;

					cout << endl << "Insert the client details";
					cout << endl << "--------------------------";
					Ticket userTicket;
					cin >> userTicket;  // Overloaded >> operator to read ticket data from the keyboard

					cout << endl << "Insert the location details";
					cout << endl << "----------------------------";

					Location eventLocation;
					cin >> eventLocation;

					cout << endl << "Insert the event detail";
					cout << endl << "------------------------";

					Event event;
					cin >> event;

					// Save the user's ticket data to the file

					outputFile << endl << "NEW TICKET";
					outputFile << eventLocation;
					outputFile << userTicket;
					outputFile << event;

					cout << endl << "Ticket data saved successfully." << endl;
				}



			
			}
			else {
				if (number == 4) {
					cout << endl << "Press any key on the keyboard to exit";
					return 0;
				}
				else {
					cout << endl << "Invalid option. Please press 1, 2, 3 or 4";
					cout << endl << "Press any key and try again";
				}
			}
		}
	}


	



/////////////////////////////////////////////
	// Example usage
	//Location cinemaLocation("Cinema", "123 Main St", "VIP", 10, 10);
	//Ticket lola("Lola White", CHILD, 7, 3, 5, 10.0, cinemaLocation);

	//if (lola.isSeatAvailable()) { //daca intoarece 0 => e liber altfel nu
	//	// If the seat is available, occupy it
	//	lola.occupySeat();
	//	cout << "Seat is available. Proceed with the ticket purchase." << endl;
	//}
	//else {
	//	cout << "Seat is already occupied. Please choose another seat." << endl;
	//}
	//

	//Ticket myTicket("John Doe", ADULT, 25, 3, 5, 15.0, cinemaLocation);

	//	// Check if the seat is available
	//	if (myTicket.isSeatAvailable()) {
	//		cout << "Seat is available. Proceed with the ticket purchase." << endl;
	//	}
	//	else {
	//		cout << "Seat is already occupied. Please choose another seat." << endl;
	//	}



	//TESTING PHASE
	/*Location l1;
	l1.printLocationInfo();

	Location l2("Sala Palatului", "Strada Primaverii, Nr.82", "Category B", 50, 50);
	l2.printLocationInfo();

	//Location l3 = l2;  //copy constructor
	//l3.printLocationInfo();

	//l1 = l3;  //  l1.operator=(l3)      
	//l1.printLocationInfo();

	//Event e0;
	//Event e1("Musicalul Mamma Mia", 17, 30, 8, 12, 2023);
	//e1.displayingDate();
	//e1.displayingTime();
	//e1.printEventInfo();

	Event e2("Le Cirque Du Soleil", 9, 5, 5, 8, 2024);
	e2.printEventInfo();

	//e2 = e1;
	//e2.printEventInfo();
	//Event e3 = e2;
	//e3.printEventInfo();

	Ticket t1;
	//t1.printTicketInfo();

	Location l4("Romexpo", "Aviatorilor", 50, 50);

	//Ticket t2("Alex Paunescu", STUDENT, 20, 5, 19, 50.30, l2);
	//t2.printTicketInfo();

	//t2 = t1;
	//t2.printTicketInfo();

	Ticket adult("Gabriela Aldici", ADULT, 47, 8, 1, 65.00, l2);
	//adult.printTicketInfo();

	//Ticket adult2("Vica Moraru", ADULT, 47, 8, 1, 65.00, l2);


	//cout << adult;
	//cout << e2;
	//cout << l2;

	//cin >> adult;
	//cout << adult;

	//cin >> e2;
	//cout << e2;

	//cin >> l2;
	//cout << l2;*/


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
		console << '0' << event.getHour();
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
	input.ignore();
	input.getline(ticket.clientName, 100); //istream& getline (char* s, streamsize n )     exemplu:  cin.getline(s , 11);    

	cout << endl << "Enter the client type";
	cout << endl << "Insert (1 - student, 2 - child, 3 - adult, 4 - retired): ";
	int type, age, row, seat;
	float price;
	input >> type;
	ticket.clientType = static_cast<ClientType>(type);

	cout << endl << "The client age is: ";
	input.ignore();
	input >> age;
	ticket.setAge(age);

	cout << endl << "The row selected is: ";
	input.ignore();
	input >> row;
	ticket.setRowNr(row);

	cout << endl << "The selected seat is: ";
	input.ignore();
	input >> seat;
	ticket.setSeatNr(seat);

	cout << endl << "Price of the ticket: ";
	input.ignore();
	input >> price;
	ticket.setPrice(price);
}

void operator>>(istream& input, Event& event) {
	cout << endl << "Insert the event's name: ";
	input.ignore();
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
	input.ignore();
	string locName;
	getline(input, locName);
	location.setLocationName(locName.c_str());

	cout << endl << "Enter location address: ";
	//input.ignore();
	string address;
	getline(input, address);
	location.setLocationAddress(address);

	cout << endl << "Enter zone name(Category A, Category B,..., VIP): ";
	//input.ignore();
	string zone;
	getline(input, zone);
	location.setLocationZone(zone);
	//cout << "Debug: Length of zone name: " << zone.length() << endl;

	cout << endl << "Enter max. nr. of seats per row: ";
	//input.ignore();
	int maxSeatsPerRow;
	input >> maxSeatsPerRow;
	location.setMaxNrOfSeats(maxSeatsPerRow);

	cout << endl << "Enter nr. of rows:";
	//input.ignore();
	int rows;
	input >> rows;
	location.setNrOfRows(rows);
}

