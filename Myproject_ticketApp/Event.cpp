#include <iostream>
#include "Location.cpp"
using namespace std;

class Event {
	char* eventName;
	int hour;
	int minutes;
	int dd;
	int mm;
	int yyyy;

public:
	static int MIN_NR_LETTERS;
	static int MIN_VALUE;
	static int MAX_HOUR;
	static int MAX_MINUTES;
	static int MIN_VALUE_2;
	static int MAX_DAY;
	static int MAX_MONTH;

public:

	//SETTERS AND GETTERS
	//Don't forget to validate

	//Event name
	void setEventName(const char* newName) {
		if (this->eventName != nullptr) {
			delete[] this->eventName;
			this->eventName = nullptr;
		}
		this->eventName = new char[strlen(newName) + 1];
		strcpy_s(this->eventName, strlen(newName) + 1, newName);

	}

	char* getEventName() {
		
		char* copy;
		copy = new char[strlen(this->eventName) + 1];
		strcpy_s(copy, strlen(this->eventName) + 1, this->eventName);

		return copy;
	}

	/////////////////////////TIME//////////////////
	
	//Hour
	void setHour(int newHour) {
		if (newHour >= MIN_VALUE && newHour <= MAX_HOUR) {
			this->hour = newHour;
		}
		else {
			throw exception("Invalid hour value");
		}
	}

	int getHour() {
		return this->hour;
	}

	//Minutes
	void setMinutes(int newMinutes) {
		if (newMinutes >= MIN_VALUE && newMinutes <= MAX_MINUTES) {
			this->minutes = newMinutes;
		}
		else {
			throw exception("Invalid minutes value");
		}
		
	}

	int getMinutes() {
		return this->minutes;
	}

	///////////////////////////DATE///////////////////////
	
	//day
	void setDay(int newDay) {
		if (newDay >= MIN_VALUE_2 && newDay <= MAX_DAY) {
			this->dd = newDay;
		}
		else {
			throw exception("Invalid day value");
		}
	}

	int getDay() {
		return this->dd;
	}

	//month
	void setMonth(int newMonth) {
		if (newMonth >= MIN_VALUE_2 && newMonth <= MAX_MONTH) {
			this->mm = newMonth;
		}
		else {
			throw exception("Invalid month value");
		}
	}

	int getMonth() {
		return this->mm;
	}

	//year
	void setYear(int newYear) {
		if (newYear >= MIN_VALUE)
			this->yyyy = newYear;
		else
			throw exception("Invalid year value");
	}

	int getYear() {
		return this->yyyy;
	}

	//Function for setting the date
	void settingTheDate(int day, int month, int year) {
		this->setDay(day);
		this->setMonth(month);
		this->setYear(year);
	}

	//cred ca imi trebuie ostream si istream operator pentru afisarea si citirea datelor

};

int Event::MIN_NR_LETTERS = 2;
int Event::MIN_VALUE = 0;
int Event::MAX_HOUR = 23;
int Event::MAX_MINUTES = 59;
int Event::MIN_VALUE_2 = 1;
int Event::MAX_DAY = 31;
int Event::MAX_MONTH = 12;