#ifndef __DATE_CALCULATOR_H__
#define __DATE_CALCULATOR_H__

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class DateCalculator
{
private:
	int year;
	int month;
	int day;

public:
	DateCalculator(): year(1970), month(1), day(1) {}
	DateCalculator(int year, int month, int day): year(year), month(month), day(day) {}

	void readFile(const char *filename);
	void add(int changeDays);
	void minus(int changeDays);
	bool isLeapYear(int year);
	void showDay();
};

#endif // __DATE_CALCULATOR_H__