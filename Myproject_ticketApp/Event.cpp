#include <iostream>
#include <string>

using namespace std;

class Event {
	char* eventName = nullptr;
	int hour = 0;
	int minutes = 0;
	int dd = 0;
	int mm = 0;
	int yyyy = 0;

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

	//Default construct
private:
	Event() {

	}

public:
	//Constructor
	Event(const char* name, int hour, int mnt, int day, int month, int year) {
		this->setEventName(name);
		this->setHour(hour);
		this->setMinutes(mnt);
		this->setDay(day);
		this->setMonth(month);
		this->setYear(year);
	}
	
	//Copy constructor
	Event(const Event& source) {
		if (source.eventName == nullptr) {
			throw exception("Empty name. You don't have what name to copy");
		}
		else {
			//allocate space for the new name copied
			this->eventName = new char[strlen(source.eventName) + 1];
			strcpy_s(this->eventName, strlen(source.eventName) + 1, source.eventName);
		}

		this->hour = source.hour;
		this->minutes = source.minutes;
		this->dd = source.dd;
		this->mm = source.mm;
		this->yyyy = source.yyyy;
	}

	//operator=
	Event& operator=(const Event& source) {
		if (source.eventName != nullptr) {
			if (this->eventName != nullptr) {
				delete[] this->eventName;
				this->eventName = nullptr;
			}
			this->eventName = new char[strlen(source.eventName) + 1];
			strcpy_s(this->eventName, strlen(source.eventName) + 1, source.eventName);
		}

		this->hour = source.hour;
		this->minutes = source.minutes;
		this->dd = source.dd;
		this->mm = source.mm;
		this->yyyy = source.yyyy;

		return *this;                 //to get the value at that address
	}

	//Destructor
	~Event() {
		if (this->eventName != nullptr) {
			delete[] this->eventName;
			this->eventName = nullptr;
		}
	}
	
	//alte functii

	///////////////////////FUNCTIONS////////////////////

	//Function for setting the date
	void displayingDate() {

		cout << "\n\n" << this->getDay() << "/";
		cout << this->getMonth() << "/";
		cout << this->getYear();
	}

	//Function for setting the time
	void displayingTime() {   //h - hours  m - minutes
		// I want 23:00 or 18:05 

		if (this->hour >= 0 && this->hour < 10) {
			cout << "\n" << '0' << this->hour;
		}
		else {
			cout << "\n" << this->hour;
		}

		if (this->minutes >= 0 && this->minutes < 10) {
			cout << ":" << '0' << this->minutes;
		}
		else {
			cout << ":" << this->minutes;
		}

	}
	//cred ca imi trebuie ostream si istream operator pentru afisarea si citirea datelor
	//implementeaza operatorii

	//Functie pentru afisarea datelor
	void printEventInfo() {
		cout << "\n";
		cout << endl << "The event's name is: " << this->getEventName();
		//cout << endl << "..............";
		displayingDate();
		displayingTime();
		cout << endl << "..............";
	}
	

	//FRIENDS
	friend ostream& operator<<(ostream& console, Event& source);
	friend void operator>>(istream& input, Event& event);

};

//int Event::MIN_NR_LETTERS = 2;
//int Event::MIN_VALUE = 0;
//int Event::MAX_HOUR = 23;
//int Event::MAX_MINUTES = 59;
//int Event::MIN_VALUE_2 = 1;
//int Event::MAX_DAY = 31;
//int Event::MAX_MONTH = 12;




