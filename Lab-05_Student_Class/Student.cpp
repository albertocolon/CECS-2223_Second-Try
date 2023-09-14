//
//  Student.cpp
//  studentClass_Lab05
//
//  Created by Alberto Colon on 9/9/23.
//

#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

// ************************************************************
// *********************** Definitions ************************
// ************************************************************

// Defining Constructor wit default argumnts.
Student::Student(const char* street, const char* city, const char* state, const char* studentName, long id)
{
    street = new char[strlen(this->street) + 1];
    strcpy(this->street, street);
    
    city = new char[strlen(this->city) + 1];
    strcpy(this->city, city);
    
    state = new char[strlen(this->state) + 1];
    strcpy(this->state, state);
    
    studentName = new char[strlen(this->studentName) + 1];
    strcpy(this->studentName, studentName);
    
    this->id = id;
        
}

// Defining Copy Constructor.
Student::Student(const Student &other)
{
    this->street = new char[strlen(other.street) + 1];
    strcpy(this->street, other.street);
    
    this->city = new char[strlen(other.city) + 1];
    strcpy(this->city, other.city);
    
    this->state = new char[strlen(other.state) + 1];
    strcpy(this->state, other.state);
    
    this->studentName = new char[strlen(other.studentName) + 1];
    strcpy(this->studentName, other.studentName);
    
    this->id = other.id;
}

// Defining the Destructor.
Student::~Student()
{
    delete[] street;
    delete[] city;
    delete[] state;
    delete[] studentName;
}

// Member fucntions - Mutators.
void Student::setStreet(char *street)
{
    strcpy(this->street, street);
}

void Student::setCity(char *city)
{
    strcpy(this->city, city);
}

void Student::setState(char *state)
{
    strcpy(this->state, state);
}

void Student::setStudentName(char *studentName)
{
    strcpy(this->studentName, studentName);
}

void Student::setId(long id)
{
    this->id = id;
}

/* Member functions - Accessors.
char* Student::getStreet() const
{
    return street;
}

char* Student::getCity() const
{
    return this->city;
}

char* Student::getState() const
{
    
}*/


// Assign operator overloading.
Student& Student::operator=(const Student & other)
{
    if(this != &other)
    {
        delete[] street;
        delete[] city;
        delete[] state;
        delete[] studentName;
        
        street = new char[strlen(other.street) + 1];
        strcpy(street, other.street);

        city = new char[strlen(other.city) + 1];
        strcpy(city, other.city);

        state = new char[strlen(other.state) + 1];
        strcpy(state, other.state);

        studentName = new char[strlen(other.studentName) + 1];
        strcpy(studentName, other.studentName);

        id = other.id;
    }
    
    return *this;
}

// Increment and Decrement operator overloading.
Student& Student::operator++()
{
    id++;
    return *this;
}

Student& Student::operator--()
{
    id--;
    return *this;
}

// Friend operator function
/*friend ostream& operator<<(ostream &out, const Student &other)
{
    out << "Student ID: " <<
}*/