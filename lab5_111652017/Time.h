#ifndef __TIME_H__
#define __TIME_H__

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;

public:
	Time(): hour(0), minute(0), second(0) {}
	Time(int hour, int minute, int second): hour(hour), minute(minute), second(second) {}

	// Operator overloading 
	Time operator+(Time other);
	Time operator-(Time other);

	bool operator==(const Time &other);
	bool operator!=(const Time &other);

	// Input and output overloading
	friend istream& operator>>(istream& in, Time& time);
	friend ostream& operator<<(ostream& out, const Time& time);
};

istream& operator>>(istream&, Time&);
ostream& operator<<(ostream&, const Time&);

#endif // !__TIME_H__