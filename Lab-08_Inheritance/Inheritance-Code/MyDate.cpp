//
//  LabDate.cpp
//  dateClass_Lab03_Val-MemberFunct
//
//  Created by Alberto Colon on 8/26/23.
//  Deffinitions for the Member functions.

#include "MyDate.h"
#include <iostream>

using namespace std;

// Here will be written the definitions for all the member functions of the LabDate Class, declared on the header file.

// Here is the Constructor with argument since there is no need for the Default Constructor when using Constructor with default arguments.
MyDate::MyDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

MyDate::MyDate(const MyDate& aDate) 
{
    this->day = aDate.day;
    this->month = aDate.month;
    this->year = aDate.year;
}

MyDate::~MyDate()
{
    
}

// Here are the Mutators & Accesors member functions
void MyDate::setDay(int day)
{
    this->day = day;
}

void MyDate::setMonth(int month)
{
    this->month = month;
}

void MyDate::setYear(int year)
{
    this->year = year;
}

int MyDate::getDay() const
{
    return(this->day);
}

int MyDate::getMonth() const
{
    return(this->month);
}

int MyDate::getYear() const
{
    return(this->year);
}

// Additional member functions
void MyDate::showDay() const
{
    cout << this->day;
}

void MyDate::showMonth() const
{
    cout << this->month;
}

void MyDate::showYear() const
{
    cout << ((this->isAC()) ? this->year:-(this->year)) << ((this->isAC()) ? " " : " BC");
}

void MyDate::showDate() const
{
    cout << this->month << '/' << this->day << '/' << ((this->isAC()) ? this->year:-(this->year)) << ((this->isAC()) ? " " : " BC") << endl;
}

void MyDate::setBC()
{
    if (this->year > 0)
        this->year *= -1;
}

void MyDate::setAC()
{
    if (this->year < 0)
        this->year *= -1;
}

bool MyDate::isBC() const
{
    return(this->year < 0);
}

bool MyDate::isAC() const
{
    return(this->year > 0);
}

bool MyDate::isLeapYear() const
{
    return((this->year % 400 == 0) || (this->year % 100 != 0 && this->year % 4 == 0));
}

// ***************************************************************************************************************************************************************************
// *************************************************** Instance Functions with logic for the days, months and years **********************************************************
// ***************************************************************************************************************************************************************************

void MyDate::askDay()
{
    bool validFeb, valid30, valid31;
    
    cout << "Enter a Day: ";
    cin >> this->day;
    
    validFeb = ((this->month == 2) && ((this->isLeapYear() && this->day <=29) || (!(this->isLeapYear()) && this->day <= 28)) && (this->day > 0));
    
    valid30 = ((this->month != 2) && ((this->month % 2 == 0 && this->month <= 6) || (this->month % 2 != 00 && this->month >= 9)) && (this->day > 0 && this->day <= 30));
    
    valid31 = ((this->month != 2) && ((this->month % 2 == 0 && this->month <= 8) || (this->month % 2 != 00 && this->month >= 7)) && (this->day > 0 && this->day <= 31));
    
    while (!validFeb && !valid30 && !valid31)
    {
        cout << "ERROR: Invalid value." << endl << endl;
        cout  << "Enter a day: ";
        cin >> this->day;
            
        validFeb = ((this->month == 2) && ((this->isLeapYear() && this->day <=29) || (!(this->isLeapYear()) && this->day <= 28)) && (this->day > 0));
            
        valid30 = ((this->month != 2) && ((this->month % 2 == 0 && this->month <= 6) || (this->month % 2 != 00 && this->month >= 9)) && (this->day > 0 && this->day <= 30));
            
        valid31 = ((this->month != 2) && ((this->month % 2 == 0 && this->month <= 8) || (this->month % 2 != 00 && this->month >= 7)) && (this->day > 0 && this->day <= 31));
    }
}

void MyDate::askMonth()
{
    cout << "Enter the month: ";
    cin >> this->month;
    
    while (this->month < 1 || this->month >12)
    {
        cout << "ERROR: Invalid value." << endl << endl;
        cin >> this->month;
    }
}

void MyDate::askYear()
{
    char d;
    cout << "Enter the year: ";
    cin >> this->year;
    
    while (this->year <= 0)
    {
        cout << "ERROR: Invalid value." << endl << endl;
        cout << "Enter the year: ";
        cin >> this->year;
    }
    
    cout << endl << "If year is AC press 1 (otherwise is BC): ";
    cin >> d;
    if (d != '1')
        this->setBC();
}

void MyDate::askDate()
{
    this->askYear();
    this->askMonth();
    this->askDay();
}

// ***************************************************************************************************************************************************************************
// *************************************************** Instance Functions with logic for the days, months and years **********************************************************
// ***************************************************************************************************************************************************************************

ostream & operator<<(ostream & out, const MyDate & aDate)
{
    aDate.showDate();
    
    return(out);
}

istream & operator>>(istream & in, MyDate & aDate)
{
    aDate.askDate();
    return(in);
}

MyDate & MyDate::operator=(const MyDate & aDate)
{
    this->day = aDate.day;
    this->month = aDate.month;
    this->year = aDate.year;
    
    return(*this);
}

bool MyDate::operator==(const MyDate & aDate) const
{
    return(this->day == aDate.day && this->month == aDate.month && this->year == aDate.year);
}

bool MyDate::operator!=(const MyDate & aDate) const
{
    return(!((*this) == aDate));
}

bool MyDate::operator >(const MyDate & aDate) const
{
    return((this->year > aDate.year) || (this->year == aDate.year && this->month > aDate.month) || (this->year == aDate.year && this->month == aDate.month && this->day > aDate.day));
}

bool MyDate::operator <(const MyDate & aDate) const
{
    return(!((*this) > aDate || (*this) == aDate));
}

