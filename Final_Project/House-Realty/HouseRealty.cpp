// Here goes the Houserealty class's methods definitions:

#include "HouseRealty.h"
#include "Inventory.h"
#include "MyString.h"
#include "MyInt.h"
#include "MyStringArray.h"
#include "Properties.h"
#include "MyDate.h"
#include "House.h"
#include "MyMenu.h"

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void HouseRealty::adding()
{
    House house;

    cout << "Enter the house's Information: " << endl;
    cin >> house;

    if(this->include(house))
    {
        cout << "ERROR: The house is already in the inventory. Either the same id or -description-." << endl;
    }
    else if(this->isFull())
    {
        cout << "ERROR: The inventory is full." << endl;
        cout << "The house was not added." << endl;
    }
    else
    {
        (*this) + house;
        /*this->housesIn[this->houseInAmount()] = house;
        this->housesIn[this->houseInAmount()].setAddDate(MyDate());
        this->housesIn[this->houseInAmount()].setID(this->houseInAmount() + 1);
        this->housesIn[this->houseInAmount()].setPrice(0.0);*/

        cout << "The house was added successfully." << endl;
    }

    cout << endl << endl;

}

void HouseRealty::removing()
{
    MyMenu menu;
    int operation;
    MyInt id;

    menu.setDescription("House Realty System");
    menu.setQuestion("What do you want to do?: ");
    menu + "Remove by ID" + "Cancel";

    do
    {
        cout << menu;
        cin >> operation;

        switch(operation)
        {
            case 1:
            {
                cout << "*** Remove by ID ***" << endl;
                cout << "Enter the house's ID: ";
                cin >> id;

                if(this->include(id))
                {
                    (*this) - id;
                }else
                {
                    cout << "ERROR: The ID does not match any house is not in the system." << endl;
                }
                break;
            }

            case 2:
            {
                cout << "*** Returning to the main menu ***" << endl;
                break;
            }

            default:
            {
                cout << "ERROR: Invalid option." << endl;
                break;
            }
        cout << endl << endl;

        }
    }
    while (operation != menu.getOptionCount());

}

void HouseRealty::print() const
{
    cout << "House Realty System" << endl;
    cout << (*this) << endl << endl << endl;
}

void HouseRealty::lookUp() const
{
    MyMenu menu;
    int operation;
    MyInt id;
    House house;

    menu.setDescription("House Realty System");
    menu.setQuestion("What do you want to do?: ");
    menu + "Look up by ID" + "Look up by House" + "Cancel";

    do
    {
        cout << menu;
        cin >> operation;

        switch(operation)
        {
            case 1:
            {
                cout << "*** Look up by ID ***" << endl;
                cout << "Enter the house's ID: ";
                cin >> id;

                if(this->include(id, house))
                {
                    cout << "The house is in the system." << endl;
                    cout << (*this)[id] << endl;
                }else
                {
                    cout << "ERROR: The ID does not match any house is not in the system." << endl;
                }
                break;
            }

            case 2:
            {
                cout << "*** Look up by House ***" << endl;
                cout << "Enter the description of the house: ";
                cin >> house;

                if(this->include(house))
                {
                    cout << "The house is in the system." << endl;
                    cout << house << endl;
                }else
                {
                    cout << "ERROR: The date does not match any house is not in the system." << endl;
                }
                break;
            }

            case 3:
            {
                cout << "*** Returning to the main menu ***" << endl;
                break;
            }

            default:
            {
                cout << "ERROR: Invalid option." << endl;
                break;
            }

        }
        cout << endl << endl;
    }
    while (operation != menu.getOptionCount());
    
}

void HouseRealty::writetoFile()
{
    ofstream out("HouseRealty.txt");

    if(out.is_open())
    {
        out << (*this);
        out.close();
    }else
    {
        cout << "ERROR: The file could not be opened." << endl;
    }
}


void HouseRealty::readfromFile()
{
    ifstream in("HouseRealty.txt");

    if(in.is_open())
    {
        in >> (*this);
        in.close();
    }else
    {
        cout << "ERROR: The file could not be opened." << endl;
    }
}

HouseRealty::HouseRealty(const MyString &file)
{
    this->file = file;
    this->writetoFile();
}

HouseRealty::HouseRealty(const char *file)
{
    this->file = file;
    this->writetoFile();
}

HouseRealty::HouseRealty(const HouseRealty &aHouseRealty)
{
    this->housesIn = aHouseRealty.housesIn;
    this->housesOut = aHouseRealty.housesOut;
    this->file = aHouseRealty.file;
}

HouseRealty::~HouseRealty()
{
    this->writetoFile();
}

HouseRealty &HouseRealty::operator=(const HouseRealty &aHouseRealty)
{
    this->housesIn = aHouseRealty.housesIn;
    this->housesOut = aHouseRealty.housesOut;
    this->file = aHouseRealty.file;

    return(*this);
}



int HouseRealty::houseInAmount() const
{
    return this->housesIn.houseAmount();
}

int HouseRealty::houseOutAmount() const
{
    return this->housesOut.houseAmount();
}

int HouseRealty::houseInAmount() const
{
    return this->housesIn.houseAmount() + this->housesOut.houseAmount();
}

bool HouseRealty::isFull() const
{
    return(this->housesIn.isFull() && this->housesOut.isFull());
}


bool HouseRealty::isEmpty() const
{
    return(this->housesIn.isEmpty());
}

bool HouseRealty::include(const House &aHouse) const
{
    return(this->housesIn.include(aHouse));
}

bool HouseRealty::include(const MyInt &anID) const
{
    return(this->housesIn.include(anID));
}

bool HouseRealty::include(const MyInt &anID, House &aHouse) const
{
    return(this->housesIn.include(anID, aHouse));
}

HouseRealty &HouseRealty::operator+(const House &aHouse)
{
    if(!(this->isFull()) && !(this->include(aHouse)))
    {
        this->housesIn + aHouse;
    }

    return(*this);
}

HouseRealty &HouseRealty::operator-(const House &aHouse)
{
    if(this->include(aHouse))
    {
        this->housesIn - aHouse;
    }

    return(*this);
}   

HouseRealty &HouseRealty::operator-(const MyInt &anID)
{
    if(this->include(anID))
    {
        this->housesIn - anID;
    }

    return(*this);
}


ostream &operator<<(ostream &out, const HouseRealty &aHouseRealty)
{
    out << "Houses In: " << endl;
    out << aHouseRealty.housesIn << endl;
    out << "Houses Out: " << endl;
    out << aHouseRealty.housesOut << endl;

    return(out);
}   

const House &HouseRealty::operator[](const int &index) const
{
    return(this->housesIn[index]);
}

House &HouseRealty::operator[](int index)
{
    return(this->housesIn[index]);
}

int HouseRealty::indexOf(const House &aHouse) const
{
    return(this->housesIn.indexOf(aHouse));
}

int HouseRealty::indexOf(const MyInt &anID) const
{
    return(this->housesIn.indexOf(anID));
}

// Here goes the Inventory class's methods definitions:
