//
//  House.h
//  Final-Project Lab-HomeRealty
//
//  Created by Alberto Colon on 10/21/23.
//

#ifndef House_h
#define House_h

#include "MyString.h"
#include "MyInt.h"
#include "MyStringArray.h"
#include "Properties.h"
#include "MyDate.h"
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class House: public Properties
{
    private:
    MyInt id;
    double price;
    MyDate addDate;

    public:
    House(const MyInt &anID = 0, const double &aPrice = 0.0, const MyDate &aDate = MyDate());
    House(const House &aHouse);
    virtual ~House();

    House &operator=(const House &aHouse);

    void setID(const MyInt &anID);
    void setID(const int &anID);
    void setPrice(const double &aPrice);
    void setAddDate(const MyDate &aDate);
    void setAddDate(const int &aMonth, const int &aDay, const int &aYear);


    const MyInt &getID()const;
    const double &getPrice()const;
    const MyDate &getAddDate()const;

    virtual void print()const;
    virtual void input();


    friend ostream &operator<<(ostream &out, const House &aHouse);
    friend istream &operator>>(istream &in, House &aHouse);

    friend bool operator==(const House &aHouse, const House &bHouse);
    friend bool operator!=(const House &aHouse, const House &bHouse);

    virtual MyString getType()const;

};

#endif /* House_h */
