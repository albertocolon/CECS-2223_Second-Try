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

/*Person::Person(string firstName = "", string lastName = "", const MyDate birthDate = MyDate(), string ssN = "")
{
    
}
*/

Person::Person(const Person & aPerson)
{
    
}

// Destructor
/*virtual Person::~Person()
{
    
}*/

// Assign Operator
Person & Person::operator =(const Person & aPerson)
{
    
}

// Equal Operator
bool Person::operator ==(const Person & aPerson) const
{
    
}

bool Person::operator !=(const Person & aPerson) const
{
    
}

// Getters & Setters
string Person::getFirstName() const
{
    
}

string Person::getLastName() const
{
    
}

const MyDate & Person::getBirthDate() const
{
    
}

string Person::getSSN() const
{
    
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
    
}

istream & operator >>(istream & in, Person & aPerson)
{
    
}
