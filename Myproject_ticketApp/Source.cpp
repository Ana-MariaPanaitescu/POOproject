#include <iostream>
#include <string>
#include "Location.cpp"

int Location::MIN_NR_LETTERS = 5;
int Location::MIN_CAPACITY = 10;

int main() {
	

	//Am putea sa facem o functie care iti cauta evenimentul
	Location l1;
	l1.printLocationInfo();

	Location l2("Sala Palatului", "Strada Primaverii, Nr.82", "Category B", 5000, 50);
	//l2.printLocationInfo();

	Location l3 = l2;  //copy constructor

	l3.printLocationInfo();

}