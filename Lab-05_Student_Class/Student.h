//
//  Student.hpp
//  studentClass_Lab05
//
//  Created by Alberto Colon on 9/9/23.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

// const int MAX_CH = 90;

class Student
{
private:
    char *street;
    char *city;
    char *state;
    char *studentName;
    long id;
    
public:
    // Constructor with default arguments to avoid writting the default constructor.
    Student(const char* street = "", const char* city = "", const char* state = "", const char* studentName = "", long id = 0);
    // Copy constructor.
    Student(const Student &other);
    // Destructor.
    ~Student();
    
    // Member functions - Mutators
    void setStreet(char *street);
    void setCity(char *city);
    void setState(char *state);
    void setStudentName(char *studentName);
    void setId(long id);
    
    // Member functions - Accessors
    char getStreet() const;
    char getCity() const;
    char getState() const;
    char getStudentName() const;
    long getId() const;
    
    void displayStudent() const;
    
    // Operator Overloading
    Student& operator=(const Student &other);
    Student& operator++();
    Student& operator--();
    
    // Friend Operator Functions.
    friend ostream& operator<<(ostream out, const Student &other);
    friend istream& operator>>(istream in, Student &other);
    
};

#endif /* Student_hpp */