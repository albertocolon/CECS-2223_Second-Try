// Definitons for all the methods of the MyString class declared in MyString.h

#include "MyString.h"
#include <cstring>
#include <iostream>

using namespace std;

MyString::MyString(const char * s)
{
    (*this) = s;
}

MyString::MyString(char ch)
{
    (*this) = ch;
}

MyString::MyString(const MyString & aMyString)
{
    (*this) = aMyString;
}

MyString::~MyString()
{
    // Nothing to release.
}

MyString & MyString::operator =(const char * s)
{
    strcpy(this->s, MAX_LEN + 1, s);
    return (*this);
}

MyString & MyString::operator =(char ch)
{
    (*this) = "";
    (*this) = (*this) + ch;
    return (*this);
}

MyString & MyString::operator =(const MyString & aMyString)
{
    strcpy(this->s, MAX_LEN + 1, aMyString.s);
    return (*this);

    /*
         (*this) = aMyString.s;
         return (*this);
    */
}

void MyString::setS(const char * s)
{
    strcpy(this->s, MAX_LEN + 1, s);
}