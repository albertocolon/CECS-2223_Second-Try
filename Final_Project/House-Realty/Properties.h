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
#include "MyDate.h"
#include "MyInt.h"
#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

class Properties
{
    private:
    MyInt bedrooms;
    MyInt bathrooms;
    MyString address;

    public:
    Properties(MyInt bedrooms = 0, MyInt bathrooms = 0, MyString address = " ");
    Properties(const Properties &aProperties);
    ~Properties();

    Properties &operator=(const Properties &aProperties);
    
        
};







#endif /* Properties_h */