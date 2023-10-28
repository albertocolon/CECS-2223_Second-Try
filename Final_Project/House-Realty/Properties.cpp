// Here is the definition of the Properties class

#include "Properties.h"
#include "MyString.h"
#include "MyInt.h"
#include "MyStringArray.h"
#include <iostream>
#include <cstring>

using namespace std;

Properties::Properties() : bedrooms(NULL), bathrooms(NULL), floors(NULL), address(), capacity(0), size(0)
{
}

Properties::Properties(const Properties &aProperty) : bedrooms(NULL), bathrooms(NULL), floors(NULL), address(), capacity(0), size(0)
{
    (*this) = aProperty;
}

Properties::~Properties()
{
    if(bedrooms != NULL)
    {
        delete bedrooms;
        bedrooms = NULL;
    }

    if(bathrooms != NULL)
    {
        delete bathrooms;
        bathrooms = NULL;
    }

    if(floors != NULL)
    {
        delete floors;
        floors = NULL;
    }
}

Properties &Properties::operator=(const Properties &aProperty)
{
    if(this != &aProperty)
    {
        if(bedrooms != NULL)
        {
            delete bedrooms;
            bedrooms = NULL;
        }

        if(bathrooms != NULL)
        {
            delete bathrooms;
            bathrooms = NULL;
        }

        if(floors != NULL)
        {
            delete floors;
            floors = NULL;
        }

        bedrooms = new MyInt(*(aProperty.bedrooms));
        bathrooms = new MyInt(*(aProperty.bathrooms));
        floors = new MyInt(*(aProperty.floors));
        address = aProperty.address;
        capacity = aProperty.capacity;
        size = aProperty.size;
    }

    return *this;
}

void Properties::setBedrooms(const MyInt &aBedroom)
{
    if(bedrooms != NULL)
    {
        delete bedrooms;
        bedrooms = NULL;
    }

    bedrooms = new MyInt(aBedroom);
}

void Properties::setBedrooms(const int &aBedroom)
{
    if(bedrooms != NULL)
    {
        delete bedrooms;
        bedrooms = NULL;
    }

    bedrooms = new MyInt(aBedroom);
}

void Properties::setBathrooms(const MyInt &aBathroom)
{
    if(bathrooms != NULL)
    {
        delete bathrooms;
        bathrooms = NULL;
    }

    bathrooms = new MyInt(aBathroom);
}

void Properties::setBathrooms(const int &aBathroom)
{
    if(bathrooms != NULL)
    {
        delete bathrooms;
        bathrooms = NULL;
    }

    bathrooms = new MyInt(aBathroom);
}

void Properties::setFloors(const MyInt &aFloor)
{
    if(floors != NULL)
    {
        delete floors;
        floors = NULL;
    }

    floors = new MyInt(aFloor);
}

void Properties::setFloors(const int &aFloor)
{
    if(floors != NULL)
    {
        delete floors;
        floors = NULL;
    }

    floors = new MyInt(aFloor);
}

void Properties::setAddress(const MyStringArray &anAddress)
{
    address = anAddress;
}

void Properties::setAddress(const MyString &aString)
{
    address.insertAtEnd(aString);
}

void Properties::setAddress(const char *aString)
{
    address.insertAtEnd(aString);
}

const MyInt &Properties::getBedrooms()const
{
    return *bedrooms;
}

const MyInt &Properties::getBathrooms()const
{
    return *bathrooms;
}

const MyInt &Properties::getFloors()const
{
    return *floors;
}

const MyStringArray &Properties::getAddress()const
{
    return address;
}

void Properties::print()const
{
    cout << "Bedrooms: " << *bedrooms << endl;
    cout << "Bathrooms: " << *bathrooms << endl;
    cout << "Floors: " << *floors << endl;
    cout << "Address: " << address << endl;
}

void Properties::input()
{
    cout << "Enter the number of bedrooms: ";
    cin >> *bedrooms;
    cout << "Enter the number of bathrooms: ";
    cin >> *bathrooms;
    cout << "Enter the number of floors: ";
    cin >> *floors;
    cout << "Enter the address: ";
    cin >> address;
}

void Properties::save(ostream &out)const
{
    out << *bedrooms << endl;
    out << *bathrooms << endl;
    out << *floors << endl;
    out << address << endl;
}

void Properties::load(istream &in)
{
    in >> *bedrooms;
    in >> *bathrooms;
    in >> *floors;
    in >> address;
}

ostream &operator<<(ostream &out, const Properties &aProperty)
{
    aProperty.print();
    return out;
}



// Path: Final_Project/House-Realty/MyString.cpp


