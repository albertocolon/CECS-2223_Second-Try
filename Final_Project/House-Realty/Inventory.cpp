// Here is the definition for the Inventory class:

#include "Inventory.h"
#include "House.h"
#include "MyInt.h"
#include "MyString.h"
#include <iostream>

using namespace std;

Inventory::Inventory()
{
    this->amount = 0;
}

Inventory::Inventory(const Inventory &anInventory)
{
    (*this) = anInventory;
}

Inventory::~Inventory()
{
}

const House &Inventory::operator[](const int &index)const
{
    return ((this->houses)[index]);
}

House &Inventory::operator[](const int &index)
{
    return ((this->houses)[index]);
}

Inventory & Inventory::operator=(const Inventory &anInventory)
{
    this->amount = anInventory.amount;

    for(int i = 0; i < anInventory.amount; i++)
    {
        (*this)[i] = anInventory[i];
    }

    return(*this);
}

int Inventory::houseAmount()const
{
    return(this->amount);
}

bool Inventory::isEmpty()const
{
    return(this->amount == 0);
}

bool Inventory::isFull()const
{
    return(this->amount == MAX_HOUSES);
}

bool Inventory::include(const MyInt &anID, House &aHouse)const
{
    bool included = false;

    for(int i = 0; i < this->amount && !included; i++)
    {
        if((*this)[i] == anID)
        {
            included = true;
            aHouse = (*this)[i];
        }
    }

    return(included);
}

bool Inventory::include(const House &aHouse) const
{
    return(this->include(aHouse.getID()));
}

bool Inventory::include(MyInt &anID)const
{
    House aHouse;
    return(this->include(anID, aHouse));
}

Inventory &Inventory::operator+(const House &aHouse)
{
    if(!(this->isFull()) && !(this->include(aHouse)))
    {
        (*this)[this->amount] = aHouse;
        ++(this->amount);
    }

    return(*this);
}

Inventory &Inventory::operator-(const MyInt &anID)
{
    int index = this->indexOf(anID);

    if(index != -1)
    {
        for(int i = index; i < (this->amount - 1); i++)
        {
            (*this)[i] = (*this)[i + 1];
        }
        --(this->amount);
    }

    return(*this);
}

Inventory &Inventory::operator-(const House &aHouse)
{
    return((*this) - aHouse.getID());
}

int Inventory::indexOf(const MyInt &anID)const
{
    int index = -1;

    for(int i = 0; i < this->amount && index == -1; i++)
    {
        if((*this)[i] == anID)
        {
            index = i;
        }
    }

    return(index);
}

int Inventory::indexOf(const House &aHouse)const
{
    return(this->indexOf(aHouse.getID()));
}

ostream &operator<<(ostream &out, const Inventory &anInventory)
{
    if(anInventory.isEmpty())
    {
        out << "There are no houses in the inventory." << endl;
    }else
    {
        out << "There are " << anInventory.houseAmount() << " houses in the inventory." << endl;
        for(int i = 0; i < anInventory.houseAmount(); i++)
        {
            out << anInventory[i] << endl;
        }
    }

    return(out);
}
