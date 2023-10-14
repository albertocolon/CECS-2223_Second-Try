//
//  Person.h
//  Lab-08_Inheritance_CECS-2223_FA-23
//
//  Created by Alberto Colon on 10/7/23.
//

#ifndef Person_h
#define Person_h
#include <iostream>
#include <string>
#include <iomanip>
#include "MyDate.h"

using namespace std;

class Person
{
protected:
    string firstName;
    string lastName;
    MyDate birthDate;
    string ssN;
    
public:
    // Constructors. I use the Constructor with parameters initialized in order to skip making the Default Constructor
    Person(string firstName = "", string lastName = "", const MyDate birthDate = MyDate(), string ssN = "");
    Person(const Person & aPerson);
    // Destructor
    virtual ~Person();
    
    // Assign Operator
    Person & operator =(const Person & aPerson);
    
    // Equal Operator
    bool operator ==(const Person & aPerson) const;
    bool operator !=(const Person & aPerson) const;
    
    // Getters & Setters
    string getFirstName() const;
    string getLastName() const;
    const MyDate & getBirthDate() const;
    string getSSN() const;
    
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setBirthDate(const MyDate & birtDate);
    void setSSN(string ssN);
    
    friend ostream & operator <<(ostream & out, const Person & aPerson);
    friend istream & operator >>(istream & in, Person & aPerson);
    
};

#endif /* Person_h */
