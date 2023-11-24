#include <iostream>
#include <string>
#include "Location.cpp"
#include "Event.cpp"

int Location::MIN_NR_LETTERS = 5;
int Location::MIN_CAPACITY = 10;

int Event::MIN_NR_LETTERS = 2;
int Event::MIN_VALUE = 0;
int Event::MAX_HOUR = 23;
int Event::MAX_MINUTES = 59;
int Event::MIN_VALUE_2 = 1;
int Event::MAX_DAY = 31;
int Event::MAX_MONTH = 12;


int main() {
	

	//Am putea sa facem o functie care iti cauta evenimentul
	Location l1;
	l1.printLocationInfo();

	Location l2("Sala Palatului", "Strada Primaverii, Nr.82", "Category B", 5000, 50);
	//l2.printLocationInfo();

	Location l3 = l2;  //copy constructor

	//l3.printLocationInfo();

	l1 = l3;  //  l1.operator=(l3)      
	l1.printLocationInfo();

	Event e1;
	e1.settingTheDate(4, 12, 2023);
	e1.settingTheTime(4, 5);

}