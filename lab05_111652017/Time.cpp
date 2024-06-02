#include "Time.h"
#include <string>
#include <sstream>

Time Time::operator+(Time other)
{
	// TODO: perform + opearion overloading
	second += other.second;
	if(second >= 60){
		minute += 1;
		second -= 60;
	}

	// minute
	minute += other.minute;
	if(minute >= 60){
		hour += 1;
		minute -= 60;
	}

	// hour
	hour += other.hour;
	// cout << "time.hour: " << hour << "\ntime.minute: " << minute << "\ntime.second: " << second << "\n";
	return *this;
}

Time Time::operator-(Time other)
{
	// TODO: perform - opearion overloading

	// second
	if(second >= other.second){
		second -= other.second;
	}
	else{
		minute -= 1;
		second += 60;
		second -= other.second;
	}

	// minute
	if(minute >= other.minute){
		minute -= other.minute;
	}
	else{
		hour -= 1;
		minute += 60;
		minute -= other.minute;
	}

	// hour
	if(hour < other.hour){
		hour = minute = second = 0;
	}
	else{
		hour -= other.hour;
	}
	return *this;
}

bool Time::operator==(const Time& other)
{
	// TODO: perform == opearion overloading
	return ((hour == other.hour) and (minute == other.minute) and (second == other.second));
}

bool Time::operator!=(const Time& other)
{
	// TODO: perform != opearion overloading
	return ((hour != other.hour) or (minute != other.minute) or (second != other.second));
}

istream& operator>>(istream& in, Time& time)
{
	// TODO: perform input overloading
    char colon;
	in >> time.hour >> colon >> time.minute >> colon >> time.second;
	// cout << "time.hour: " << time.hour << "\ntime.minute" << time.minute << "\ntime.second" << time.second << "\n";
	return in;
}

ostream& operator<<(ostream& out, const Time& time)
{
	// TODO: perform output overloading
	// cout << "time.hour: " << time.hour << "time.minute" << time.minute << "time.second" << time.second << "\n";
	out << setfill('0') << setw(2) << time.hour 	<< ":" 
		<< setfill('0') << setw(2) << time.minute 	<< ":" 
		<< setfill('0') << setw(2) <<  time.second	<< endl;
	return out;
}