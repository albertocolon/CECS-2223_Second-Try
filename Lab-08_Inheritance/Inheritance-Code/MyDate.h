//
//  MyDate.h
//  dateClass_Lab03_Val-MemberFunct
//
//  Created by Alberto Colon on 8/26/23.
//

#ifndef LabDate_h
#define LabDate_h

#include <iostream>

using namespace std;

class MyDate
{
private:
    // Declaring the attributes of the what makes a date a date.
    int day, month, year;
    
    // Declaring the member validation functions prototypes.
    void askDay();
    void askMonth();
    void askYear();
    
public:
    // Use the constructor with default arguments to skip the default constructor.
    MyDate(int day = 1, int month = 1, int year =1);
    
    // Copy Constructor.
    MyDate(const MyDate &dDate);
    
    // Destructor.
    ~MyDate();
    
    // Declaring the Accesosr and Mutators Member Functions.
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    // Additional Member Functions
    void showDay() const;
    void showMonth() const;
    void showYear() const;
    void showDate() const;
    
    // Setter and Accesors functions for the Before & After Christ category. Inspire by class annotations.
    void setBC();
    void setAC();
    
    bool isBC() const;
    bool isAC() const;
    bool isLeapYear() const;        // Member function to work with the Leap Year validation.
    
    void askDate();
    
    // Operator Overloading declaration
    MyDate & operator=(const MyDate & aDate);
    
    bool operator==(const MyDate & aDate) const;
    bool operator!=(const MyDate & aDate) const;
    bool operator<(const MyDate & aDate) const;
    bool operator>(const MyDate & aDate) const;
    
    // Declaring the friend functions
    friend ostream & operator<<(ostream & out, const MyDate & aDate);
    friend istream & operator>>(istream & in, MyDate & aDate);
    
};

#endif /* MyDate_h */
