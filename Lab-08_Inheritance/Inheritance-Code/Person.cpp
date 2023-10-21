//
//  Person.cpp
//  Lab-08_Inheritance_CECS-2223_FA-23
//
//  Created by Alberto Colon on 10/7/23.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "MyDate.h"
#include "Person.h"

using namespace std;

// Person Class definitions

Person::Person(string firstName, string lastName, const MyDate birthDate, string ssN)
    : firstName(firstName), lastName(lastName), birthDate(birthDate), ssN(ssN) {}


Person::Person(const Person & aPerson)
{
    
}

// Destructor
Person::~Person() {}

// Assign Operator
Person & Person::operator =(const Person & aPerson)
{
    this->firstName = aPerson.firstName;
    this->lastName = aPerson.lastName;
    this->birthDate = aPerson.birthDate;
    return(*this);
}

// Equal Operator
bool Person::operator ==(const Person & aPerson) const
{
    return(this->firstName == aPerson.firstName && this->lastName == aPerson.lastName && this->birthDate == aPerson.birthDate && this->ssN == aPerson.ssN);
}

bool Person::operator !=(const Person & aPerson) const
{
    return(this->firstName != aPerson.firstName && this->lastName != aPerson.lastName && this->birthDate != aPerson.birthDate && this->ssN != aPerson.ssN);
}

// Getters & Setters
string Person::getFirstName() const
{
    return(this->firstName);
}

string Person::getLastName() const
{
    return(this->lastName);
}

const MyDate & Person::getBirthDate() const
{
    return (this->birthDate);
}

string Person::getSSN() const
{
    return(this->ssN);
}

void Person::setFirstName(string firstName)
{
    
}

void Person::setLastName(string lastName)
{
    
}

void Person::setBirthDate(const MyDate & birtDate)
{
    
}

void Person::setSSN(string ssN)
{
    
}

ostream & operator <<(ostream & out, const Person & aPerson)
{
    out << "Nombre: " << aPerson.firstName << endl
    << "Last name: " << aPerson.lastName << endl
    << "Date of birth: " << aPerson.birthDate << endl
    << "Social Security Number: " << aPerson.ssN << endl;
    
    return(out);
}

istream & operator >>(istream & in, Person & aPerson)
{
    cout << " Enter the name of the person: ";
    in >> aPerson.firstName;
    
    cout << " Enter the last name of the person: ";
    in >> aPerson.lastName;
    
    cout << " Enter the date of birth of the person: ";
    in >> aPerson.birthDate;
    
    cout << " Enter the Social Security Number of the person: ";
    in >> aPerson.ssN;
    
    return(in);
    
}
