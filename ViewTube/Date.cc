#include "Date.h"

// default constructor
Date::Date(){
	setDate(1901,1,1);
}

// constructor
Date::Date(int y, int m, int d){
	setDate(y,m,d);
}

// copy constructor 
Date::Date(const Date& d){
	setDate(d.year,d.month,d.day);
}

// set method for day
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

// set method for month
void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

// set method for year
void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

// set method for date
void Date::setDate(int y, int m, int d){
	setMonth(m);
	setDay(d);
	setYear(y);
}

// set method for date
void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day);
}

// getters
int Date::getDay() const{ return day; }
int Date::getMonth() const{ return month; }
int Date::getYear() const{ return year; }
string Date::getMonthName() const{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[month-1];
}

// method to check if this Date comes before the Date parameter
bool Date::lessThan(const Date& d) const{
	if (year < d.year)return true;
	if (year > d.year) return false;

	if (month < d.month)return true;
	if (month > d.month) return false;

	return (day < d.day);
}

// other
void Date::print() const{
	cout << getMonthName() << " " << day << ", " << year;
}

int Date::getMaxDay() const{
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}
