//
//
//  House.h
//  Final-Project Lab-HomeRealty
//
//  Created by Alberto Colon on 10/21/23.
//

#ifndef Properties_h
#define Properties_h

#include "MyString.h"
#include "MyInt.h"
#include "MyStringArray.h"
#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

class Properties
{
    protected:
    MyInt* bedrooms;
    MyInt* bathrooms;
    MyInt* floors;
    MyStringArray address;

    int capacity;
    int size;

    public:
    Properties();
    Properties(const Properties &aProperty);
    virtual ~Properties();

    Properties &operator=(const Properties &aProperty);
    
    /*Properties &operator+(const MyString &aString);
    Properties &operator+(const char *aString);
    Properties &operator+(const MyStringArray &anArray);
    Properties &operator-(const MyString &aString);
    Properties &operator-(const char *aString);
    Properties &operator-(const MyStringArray &anArray);*/

    void setBedrooms(const MyInt &aBedroom);
    void setBedrooms(const int &aBedroom);
    void setBathrooms(const MyInt &aBathroom);
    void setBathrooms(const int &aBathroom);
    void setFloors(const MyInt &aFloor);
    void setFloors(const int &aFloor);
    void setAddress(const MyStringArray &anAddress);
    void setAddress(const MyString &aString);
    void setAddress(const char *aString);

    const MyInt &getBedrooms()const;
    const MyInt &getBathrooms()const;
    const MyInt &getFloors()const;
    const MyStringArray &getAddress()const;

    virtual void print()const;
    virtual void input();
    virtual void save(ostream &out)const;
    virtual void load(istream &in); 

    friend ostream &operator<<(ostream &out, const Properties &aProperty);
    friend istream &operator>>(istream &in, Properties &aProperty);

    virtual MyString getType() const = 0;

};

#endif /* Properties_h */