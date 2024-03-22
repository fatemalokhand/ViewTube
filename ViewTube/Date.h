#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date{
		
	public:
		// constructor
		Date();
		Date(int year, int month, int day);
		
		// copy constructor
		Date(const Date&);
		
		// setters
		void setDay(int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);
		
		// getters
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		string getMonthName() const;
		
		// other
		bool lessThan(const Date&) const;
		void print() const;
	
	private:
		// function
		int getMaxDay() const;	
	
		// member variables
		int day;
		int month;
		int year;
};

#endif