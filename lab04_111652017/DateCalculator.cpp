#include "DateCalculator.h"

using namespace std;

void DateCalculator::readFile(const char *fileName) {
	// TODO: Read the data from the txt file.
	// 
	// Hint: You can use get() to get a character in ifstream.
	//       You can use getline() to get one line in the txt file.
	//       You can use stoi() to change variable type from string to int
	ifstream inFile(fileName);
	string line;
	while(getline(inFile, line)){
		if (line.empty()) {
            break;
        }
		// 2000/01/01 + 299
		year = stoi(line.substr(0, 4));
		month = stoi(line.substr(5, 2));
		day = stoi(line.substr(8, 4));
		char sign = line[11];
		int changeDays = stoi(line.substr(13));
		if(sign == '+') add(changeDays);
		else minus(changeDays);
		showDay();
	}
}

void DateCalculator::add(int changeDays) {
	// TODO: Calculate the date add the changeDays.
	int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(isLeapYear(year)) month_days[2] = 29;
	while(changeDays){
		day++;
		if(day > month_days[month]){
			month++;
			day = 1;
		}
		if(month == 13){
			year++;
			if(isLeapYear(year)) month_days[2] = 29;
			month = 1;
		}
		changeDays--;
	}
}

void DateCalculator::minus(int changeDays) {
	// TODO: Calculate the date minus the changeDays.
	int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(isLeapYear(year)) month_days[2] = 29;
	while(changeDays){
		if(day >= 2){
			day--;
		}
		else if(month > 1){
			month--;
			day = month_days[month];
		}
		else{
			year--;
			if(isLeapYear(year)) month_days[2] = 29;
			month = 12;
			day	= 31;
		}
		changeDays--;
	}
}

bool DateCalculator::isLeapYear(int year) {
	// TODO: Determine whether the input year is a leap year.
	if(year % 4 != 0) return false;
	if(year % 4 == 0 and year % 100 != 0) return true;
	if(year % 100 == 0 and year % 400 != 0) return false;
	return true;
}

void DateCalculator::showDay() {
	// TODO: The function output the date on the screen.
	// 
	// Hint: You can use setw() to set the length of the number.
	//       You can use setfill('c') to fill 'c' to the empty space.
	//       Two functions of above is in iomanip header file. 
	cout << setw(4) << setfill('0') << year << "/";
	cout << setw(2) << setfill('0') << month << "/";
	cout << setw(2) << setfill('0') << day << "\n";
}