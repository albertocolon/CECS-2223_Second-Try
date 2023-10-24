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

bool MyStringArray::removeFirst(MyString &aMyString)
{
    return(this->remove(0, aMyString));
}

bool MyStringArray::removeLast(MyString &aMyString)
{
    return(this->remove(this->amount - 1, aMyString));
}

MyStringArray & operator +(const char *aString, MyStringArray &anArray)
{
    anArray.insertAtStart(aString);

    return(anArray);
}

ostream & operator <<(ostream & out, const MyStringArray &anArray)
{
    if(anArray.isEmpty())
    {
        out << "The array is empty." << endl;
    }else
    {
        for(int i = 0; i <anArray.amount; i++)
        {
            out << (i + 1) << ". " << anArray[i] << endl;
        }
    }

    return(out);

}

void MyStringArray::ascendingSort()
{
    int n = this->amount;

    MyString temp;
    bool switched = true;

    for(int pass = 0; pass < (n - 1) && switched; pass++)
    {
        switched = false;

        for(int j = 0; j < (n - 1 - pass); j++)
        {
            if((*this)[j] > (*this)[j + 1])
            {
                temp = (*this)[j];
                (*this)[j] = (*this)[j + 1];
                (*this)[j + 1] = temp;
                switched = true;
            }
        }
    }
}

bool MyStringArray::operator==(const MyStringArray & anArray) const
{
    bool equal = (this->amount == anArray.amount);

    if(equal)
    {
        for(int j = 0; j < this->amount && equal; j++)
        {
            if((*this)[j] != anArray[j])
            {
                equal = false;
            }
        }
    }

    return(equal);

}

bool MyStringArray::operator!=(const MyStringArray &anArray) const
{
    return(!(*this == anArray));
}

void MyStringArray::descendingSort()
{
    int n = this->amount;

    MyString temp;
    bool switched = true;

    for(int pass = 0; pass < (n - 1) && switched; pass++)
    {
        switched = false;
        for(int j = 0; j <(n - 1 - pass); j++)
        {
            if((*this)[j] < (*this)[j + 1])
            {
                temp = (*this)[j];
                (*this)[j] = (*this)[j + 1];
                (*this)[j + 1] = temp;
                switched = true;
            }
        }
    }
}

bool MyStringArray::replace(int index, const char *aString)
{
    return(this->replace(index, MyString(aString)));
}

bool MyStringArray::replace(int index, const MyString &aMyString)
{
    bool replace = false;

    if(index >= 0 && index < this->amount)
    {
        (*this)[index] = aMyString;
        replace = true;
    }

    return(replace);
}

bool MyStringArray::remove(int index)
{
    MyString temp;

    return(this->remove(index, temp));
}

bool MyStringArray::removeFirst()
{
    MyString temp;

    return(this->removeFirst(temp));
}

bool MyStringArray::removeLast()
{
    MyString temp;

    return(this->removeLast(temp));
}

MyStringArray & operator -(const char *aString, MyStringArray &anArray)
{
    anArray.remove(anArray.indexOf(aString));

    return(anArray);
}

MyStringArray & operator -(const MyString &aMyString, MyStringArray &anArray)
{
    anArray.remove(anArray.indexOf(aMyString));

    return(anArray);
}

int MyStringArray::indexOfLast(const MyString &aMyString) const
{
    int index = -1;

    for(int i = this->amount - 1; i >= 0 && index == -1; i--)
    {
        if((*this)[i] == aMyString)
        {
            index = i;
        }
    }

    return(index);
}

int MyStringArray::indexOfLast(const char *aString) const
{
    return(this->indexOfLast(MyString(aString)));
}

int MyStringArray::arrayAmount() const
{
    return(this->amount);
}

bool MyStringArray::insertAtEnd(const MyStringArray & anArray)
{
    return(this->insert(this->amount, anArray));
}

bool MyStringArray::insertAtStart(const MyStringArray & anArray)
{
    return(this->insert(0, anArray));
}

bool MyStringArray::insert(int index, const MyStringArray & anArray)
{
    bool inserted = false;
    if(((this->amount + anArray.amount) <= MAX) && (index >= 0 && index <= this->amount))
    {
        for(int i = 0; i < anArray.amount; i++)
        {
            this->insert(index + i, anArray[i]);
        }

        inserted = true;
    }

    return(inserted);
}

int MyStringArray::MaxArrays()
{
    return(MAX);
}
