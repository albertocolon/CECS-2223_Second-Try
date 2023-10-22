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

bool MyStringArray::isFull() const
{
    return(this->amount == MAX);
}

bool MyStringArray::isEmpty() const
{
    return(this->amount == 0);
}

bool MyStringArray::include(const MyString &aMyString) const
{
    return(this->indexOf(aMyString) != -1);
}

bool MyStringArray::include(const char *aString) const
{
    return(this->indexOf(MyString(aString)) != -1);
}

int MyStringArray::indexOf(const MyString &aMyString) const
{
    int index = -1;

    for(int i = 0; i < this->amount && index == -1; i++)
    {
        if((*this)[i] == aMyString)
        {
            index = i;
        }
    }
    return(index);
}

int MyStringArray::indexOf(const char * aString) const
{
    return(this->indexOf(MyString(aString)));
}

bool MyStringArray::insert(int index, const MyString &aMyString)
{
    bool inserted = false;

    if(!(this->isFull()) && index >= 0 && index <= this->amount)
    {
        for(int i = this->amount - 1; i >= index; i--)
        {
            (*this)[i + 1] = (*this)[i];
        }

        (*this)[index] = aMyString;
        ++(this->amount);
        inserted = true;
    }

    return(inserted);
}

bool MyStringArray::insert(int index, const char *aString)
{
    return(this->insert(index, MyString(aString)));
}

bool MyStringArray::insert(int indez, const MyString & aMystring)
{
    return(this->insert(0, aMystring));
}

bool MyStringArray::insertAtStart(const char *aString)
{
    return(this->insert(0, MyString(aString)));
}

bool MyStringArray::insertAtEnd(const MyString &aMyString)
{
    return(this->insert(this->amount, aMyString));
}

bool MyStringArray::insertAtEnd(const char *aString)
{
    return(this->insert(this->amount, MyString(aString)));
}

void MyStringArray::emptyIt()
{
    this->amount = 0;
}

int MyStringArray::frequency(const char * aString) const
{
    return(this->frequency(MyString(aString)));
}

int MyStringArray::frequency(const MyString &aMyString) const
{
    int frequent = 0;

    for(int i = 0; i < this->amount; i++)
    {
        if((*this)[i] == aMyString)
        {
            ++frequent;
        }
    }

    return(frequent);
}

bool MyStringArray::remove(int index, MyString & aMyString)
{
    bool removed = false;

    if(index >= 0 && index < this->amount)
    {
        aMyString = (*this)[index];

        for(int i = index; i < (this->amount - 1); i++)
        {
            (*this)[i] = (*this)[i + 1];
        }

        --(this->amount);
        removed = true;
    }

    return(removed);
}
