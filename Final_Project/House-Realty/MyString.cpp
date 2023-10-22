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
    strcpy_s(this->s, MAX_LEN + 1, s);
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
    strcpy_s(this->s, MAX_LEN + 1, aMyString.s);
    return (*this);

    /*
         (*this) = aMyString.s;
         return (*this);
    */
}

void MyString::setS(const char * s)
{
    strcpy_s(this->s, MAX_LEN + 1, s);
}

// ************************************************************************************************
//                 FROM THIS POINT ON IS TO BE COPIED ON THE FINAL PROJECT                        *
// ************************************************************************************************


const char * MyString::getS() const
{
    return (this->s);
}

int MyString::len() const
{
    return (strlen(this->s));
}

MyString MyString::operator +(const char * s) const
{
    MyString r(*this);
    strcat_s(r.s, MAX_LEN + 1, s);
    return (r);
}

MyString MyString::operator+(char ch) const
{
    MyString r(*this);
    if((this->len() + 1) <= MAX_LEN)
    {
        (r.s)[this->len()] = ch;
        (r.s)[this->len() + 1] = '\0';
    }
    return (r);
}

MyString MyString::operator+(const MyString & aMyString) const
{
    return ((*this) + aMyString.s);
}

MyString operator +(const char * s, const MyString & aMyString)
{
   return (MyString(s) + aMyString);
}

MyString operator +(char ch, const MyString & aMyString)
{
    return (MyString(ch) + aMyString);
}

bool MyString::operator ==(const char * s) const
{
    return (strcmp(this->s, s) == 0);
}

bool MyString::operator ==(const MyString & aMyString) const
{
    return (strcmp(this->s, aMyString.s) == 0);
}

bool operator ==(const char * s, const MyString & aMyString)
{
    return (strcmp(s, aMyString.s) == 0);
}

bool MyString::operator !=(const char * s) const
{
    return(strcmp(this->s, s) != 0);
}

bool MyString::operator !=(const MyString & aMyString) const
{
    return(strcmp(this->s, aMyString.s) != 0);
}

bool operator !=(const char * s, const MyString & aMyString)
{
    return(strcmp(s, aMyString.s) != 0);
}

bool MyString::operator <(const char * s) const
{
    return(strcmp(this->s, s) < 0);
}

bool MyString::operator <(const MyString & aMyString) const
{
    return(strcmp(this->s, aMyString.s) < 0);
}

bool operator <(const char * s, const MyString & aMyString)
{
    return(strcmp(s, aMyString.s) < 0);
}

bool MyString::operator >(const char * s) const
{
    return(strcmp(this->s, s) > 0);
}

bool MyString::operator >(const MyString & aMyString) const
{
    return(strcmp(this->s, aMyString.s) > 0);
}

bool operator >(const char * s, const MyString & aMyString)
{
    return(strcmp(s, aMyString.s) > 0);
}

const char & MyString::operator [](int index) const
{
    return (this->s[index]);
}

char & MyString::operator [](int index)
{
    return (this->s[index]);
}

ostream & operator <<(ostream & out, const MyString & aMyString)
{
    out << aMyString.s;
    return (out);
}

istream & operator >>(istream & in, MyString & aMyString)
{
    char ch;

    aMyString = "";

    ch = in.get();
    while(ch == ' ')
        ch = in.get();

    while(ch != '\n')
    {
        aMyString = aMyString + ch;
        ch = in.get();
    }

    return (in);
}

MyString MyString::trimLeadingSpaces() const
{
    MyString r;
    int i;

    for(i = 0; (this->s)[i] == '\t' || (this->s)[i] == ' '; i++);

    for( ; i < this->len(); i++)
        r = r + (this->s)[i];
    
    return (r);
}

MyString MyString::trimEndingSpaces() const
{
    MyString r;
    int i;

    for(i = this->len() - 1; (this->s)[i] == '\t' || (this->s)[i] == ' '; i--);

    for( ; i >= 0; i--)
        r = (this->s)[i] + r;

    return (r);
}

MyString MyString::trimAllSpaces() const
{
    MyString r;
    int i;

    for(i = 0; i < this->len(); i++)
        if((this->s)[i] != '\t' && (this->s)[i] != ' ')
            r = r + (this->s)[i];

    return (r);
}

MyString MyString::toUppercase() const
{
    MyString r(*this);

    for(int i = 0; i < this->len(); i++)
        if((this->s)[i] >= 'a' && (this->s)[i] <= 'z')
            (r.s)[i] = ((this->s)[i] - 32);

    return (r);
}

MyString MyString::toLowercase() const
{
    MyString r(*this);

    for(int i = 0; i < this->len(); i++)
        if((this->s)[i] >= 'A' && (this->s)[i] <= 'Z')
            (r.s)[i] = ((this->s)[i] + 32);

    return (r);
}

MyString MyString::createSubstring(int from, int to) const
{
    MyString r;

    if(from >= 0 && from < this->len())
        for(int i = from; i <= to; i++)
            r = r + (this->s)[i];

    return (r);
}

MyString MyString::reverse() const
{
    MyString r(*this);
    char ch;

    for(int i = 0, j = this->len() - 1; i < j; i++, j--)
    {
        ch = (r.s)[i];
        (r.s)[i] = (r.s)[j];
        (r.s)[j] = ch;
    }

    return (r);
}

int MyString::indexOf(char ch) const
{
    int index = -1;

    for(int i = 0; (i < this->len()) && (index == -1); i++)
        if((this->s)[i] == ch)
            index = i;

    return (index);
}

int MyString::indexOfLast(char ch) const
{
    int index = -1;

    for(int i = this->len() - 1; (i >= 0) && (index == -1); i--)
        if((this->s)[i] == ch)
            index = i;

    return (index);
}

bool MyString::include(char ch) const
{
    bool found = false;

    for (int i = 0; i < this->len() && !found; i++)
        if((this->s)[i] == ch)
            found = true;
} 

bool MyString::isEmpty() const
{
    return (this->len() == 0);
}

int MyString::frequency(char ch) const
{
    int f = 0;

    for(int i = 0; i < this->len(); i++)
        if((this->s)[i] == ch)
            ++f;

    return (f);
}

bool MyString::representAnUnsignInteger() const
{
    bool represent = true;

    for(int i = 0; i < this->len() && represent; i++)
        if((this->s)[i] < '0' || (this->s)[i] > '9')
            represent = false;

    return (represent && this->len() > 0);
}

bool MyString::representAnInteger() const
{
    MyString r(*this);
    
    if((this->s)[0] == '+' || (this->s)[0] == '-')
        r = this->createSubstring(1, this->len() - 1);

    return (r.representAnUnsignInteger());
}

bool MyString::representAReal() const
{
    int point = this->indexOf('.');
    MyString prefix, sufix;
    bool valid;

    if(point != -1)
    {
        prefix = this->createSubstring(0, point - 1);
        sufix = this->createSubstring(point + 1, this->len() - 1);
        valid = prefix.representAnInteger() && sufix.representAnUnsignInteger();
    }
    else
        valid = this->representAnInteger();

    return (valid);
}

int MyString::MaxLen()
{
    return (MAX_LEN);
}

MyString & MyString::operator +=(const MyString & aMyString)
{
    return ((*this) = (*this) + aMyString);
}

MyString & MyString::operator +=(const char * s)
{
    return ((*this) = (*this) + s);
}

MyString & MyString::operator +=(char ch)
{
    return ((*this) = (*this) + ch);
}

MyString & MyString::operator ++()
{
    return((*this) = this->toUppercase());
}

MyString MyString::operator ++(int)
{
    MyString r(*this);

    (*this) = this->toUppercase();

    return (r);
}

MyString & MyString::operator --()
{
    return ((*this) = this->toLowercase());
}

MyString MyString::operator --(int)
{
    MyString r(*this);

    (*this) = this->toLowercase();

    return (r);
}


