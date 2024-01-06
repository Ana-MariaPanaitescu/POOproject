#pragma once

#include <iostream>
#include <string>

using namespace std;

enum ClientType { STUDENT = 1, CHILD = 2, ADULT = 3, RETIRED = 4 };


class Ticket {

	ClientType clientType = ClientType::CHILD;
	int clientAge = 1;
	int nrRow = 1;
	int nrSeat = 1;
	float price = 1.0;

public:
	const int id;                    
	const static int MIN_VALUE;
	static int nrOfTickets;

private:
	static int getNrOfTickets();
	static void increaseByOneTicket();

public:
	string getClientTypeName();
	ClientType getClientType();
	
	int getAge();
	void setAge(int newValue);
	int getRowNr();
	void setRowNr(int newValue);
	int getSeatNr();
	void setSeatNr(int newValue);
	float getPrice();
	void setPrice(float newPrice);
	
	Ticket();
	Ticket(ClientType clientType, int age, int row, int seat, float price);

	Ticket(const Ticket& source);
	Ticket& operator=(const Ticket& source);

	~Ticket();

	void printTicketInfo();

	friend ostream& operator<<(ostream& console, Ticket& source);


};

