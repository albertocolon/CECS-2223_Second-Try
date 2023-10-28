// Here is the definitions for the methos of the House class

#include "House.h"
#include "MyString.h"
#include "MyInt.h"
#include "MyStringArray.h"
#include "Properties.h"
#include "MyDate.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

House::House(const MyInt &anID, const double &aPrice, const MyDate &aDate) : Properties(), id(anID), price(aPrice), addDate(aDate)
{
}

House::House(const House &aHouse) : Properties(), id(this->id), price(this->price), addDate(this->addDate)
{
    (*this) = aHouse;
}

House::~House()
{
}

House &House::operator=(const House &aHouse)
{
    if(this != &aHouse)
    {
        Properties::operator=(aHouse);
        id = aHouse.id;
        price = aHouse.price;
        addDate = aHouse.addDate;
    }
    return *this;
}

void House::setID(const MyInt &anID)
{
    id = anID;
}

void House::setID(const int &anID)
{
    id = anID;
}

void House::setPrice(const double &aPrice)
{
    price = aPrice;
}

void House::setAddDate(const MyDate &aDate)
{
    addDate = aDate;
}

void House::setAddDate(const int &aMonth, const int &aDay, const int &aYear)
{
    addDate.setMonth(aMonth);
    addDate.setDay(aDay);
    addDate.setYear(aYear);
}

const MyInt &House::getID()const
{
    return id;
}

const double &House::getPrice()const
{
    return price;
}

const MyDate &House::getAddDate()const
{
    return addDate;
}

void House::print()const
{
    cout << "ID: " << id << endl;
    cout << "Price: " << price << endl;
    cout << "Date Added: " << addDate << endl;
    cout << "Bedrooms: " << bedrooms << endl;
    cout << "Bathrooms: " << bathrooms << endl;
    cout << "Floors: " << floors << endl;
    cout << "Address: " << address << endl;
}

void House::input()
{
    cout << "Enter the ID: ";
    cin >> id;
    cout << "Enter the price: ";
    cin >> price;
    cout << "Enter the date added: ";
    cin >> addDate;
    cout << "Enter the number of bedrooms: ";
    cin >> *bedrooms;
    cout << "Enter the number of bathrooms: ";
    cin >> *bathrooms;
    cout << "Enter the number of floors: ";
    cin >> *floors;
    cout << "Enter the address: ";
    cin >> address;
}

ostream &operator<<(ostream &out, const House &aHouse)
{
    aHouse.print();
    return out;
}

istream &operator>>(istream &in, House &aHouse)
{
    aHouse.input();
    return in;
}

bool operator==(const House &aHouse, const House &bHouse)
{
    return (aHouse.id == bHouse.id);
}

bool operator!=(const House &aHouse, const House &bHouse)
{
    return !(aHouse == bHouse);
}

MyString House::getType()const
{
    return "House";
}

// Path: Final_Project/House-Realty/MyString.cpp

