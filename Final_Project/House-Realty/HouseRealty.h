// Here will be declare the House Realty Class

#ifndef HouseRealty_h
#define HouseRealty_h

#include "Inventory.h"
#include "MyString.h"
#include "MyInt.h"
#include "MyStringArray.h"
#include "Properties.h"
#include "MyDate.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class HouseRealty
{
    private:
    Inventory housesIn;
    Inventory housesOut;

    MyString file;

    const House & operator[](const int &index)const;
    House & operator[] (int index);

    int indexOf(const House &aHouse)const;
    int indexOf(const MyInt &anID)const;

    // Here can be add it the Properties description as well as on the Invenotry class, replacing the MyString tittle from the example.


    public:
    HouseRealty(const MyString &file = "HouseRealty.txt");
    HouseRealty(const char *file);
    HouseRealty(const HouseRealty &aHouseRealty);

    ~HouseRealty();

    HouseRealty &operator=(const HouseRealty &aHouseRealty);

    int houseInAmount()const;
    int houseOutAmount()const;

    bool isFull()const;
    bool isEmpty()const;

    bool include(const House &aHouse)const;
    bool include(const MyInt &anID)const;

    bool include(const MyInt &anID, House &aHouse)const;
    // Here would be that other bool method with the what I think should be the "type property description", as a replacement for the one MyString tittle from the example.

    void adding();
    void removing();
    void lookUp()const;
    void print()const;      // This is equivalent to the 'mostrar' method from the example.

    HouseRealty &operator+(const House &aHouse);
    HouseRealty &operator-(const House &aHouse);
    HouseRealty &operator-(const MyInt &anID);

    friend ostream &operator<<(ostream &out, const HouseRealty &aHouseRealty);
    friend istream &operator>>(istream &in, HouseRealty &aHouseRealty);

    void readfromFile();
    void writetoFile();

};

#endif /* HouseRealty_h */