// Here is the Inventory class declaration. It is a class that contains a dynamic array of Houses.

#ifndef INVENTORY_H
#define INVENTORY_H

#include "House.h"
#include "MyInt.h"
#include "MyString.h"
#include <iostream>

using namespace std;

const int MAX_HOUSES = 100;

class Inventory
{
    private:
    House houses[MAX_HOUSES];
    int amount;

    public:
    Inventory();
    Inventory(const Inventory &anInventory);
    ~Inventory();

    Inventory &operator=(const Inventory &anInventory);

    int houseAmount()const;

    int indexOf(const House &aHouse)const;
    int indexOf(const MyInt &anID)const;

    const House & operator[](const int &index)const;
    House & operator[](const int &index);

    bool isFull()const;
    bool isEmpty()const;

    bool include(const House &aHouse)const;
    bool include(MyInt &anID)const;
    
    bool include(const MyInt &anID, House &aHouse)const;

    Inventory &operator+(const House &aHouse);
    Inventory &operator-(const House &aHouse);
    Inventory &operator-(const MyInt &anID);

    friend ostream &operator<<(ostream &out, const Inventory &anInventory);

};

#endif /* INVENTORY_H */