// Definitions of the MyStringArray class member functions

#include "MyStringArray.h"
#include "MyString.h"
#include <iostream>

using namespace std;

MyStringArray::MyStringArray()
{
    this->amount = 0;
}

MyStringArray::MyStringArray(const MyStringArray &anArray)
{
    (*this) = anArray;
}

MyStringArray::~MyStringArray()
{
    // Destructor
}

MyStringArray &MyStringArray::operator=(const MyStringArray &anArray)
{
    this->amount = anArray.amount;

    for(int i = 0; i < anArray.amount; i++)
    {
        (*this)[i] = anArray[i];
    }

    return(*this);
}

MyStringArray &MyStringArray::operator+(const MyString &aMyString)
{
    this->insertAtEnd(aMyString);

    return(*this);
}

MyStringArray &MyStringArray::operator+(const char *aString)
{
    this->insertAtEnd(aString);

    return(*this);
}

MyStringArray &MyStringArray::operator+(const MyStringArray &anArray)
{
    this->insertAtEnd(anArray);

    return(*this);
}

MyStringArray &MyStringArray::operator-(const MyString &aMyString)
{
    this->remove(this->indexOfLast(aMyString));

    return(*this);
}

MyStringArray &MyStringArray::operator-(const char *aString)
{
    this->remove(this->indexOfLast(aString));

    return(*this);
}

MyStringArray &MyStringArray::operator-(int index)
{
    this->remove(index);

    return(*this);
}

const MyString &MyStringArray::operator[](int index) const
{
    return((this->array)[index]);
}

MyString &MyStringArray::operator[](int index)
{
    return((this->array)[index]);
}

