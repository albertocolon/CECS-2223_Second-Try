// Definitions for the MyInt class.

#include "MyInt.h"
#include <iostream>
#include <cmath>
#include <iostream>

using namespace std;

MyInt::MyInt(int value)
{
    this->value = value;
}

MyInt::MyInt(const MyInt & anInteger)
{
    this->value = anInteger.value;
}

MyInt::~MyInt()
{
    // Nothing to release.
}

MyInt & MyInt::operator =(int value)
{
    this->value = value;
    return (*this);
}

MyInt & MyInt::operator =(const MyInt & anInteger)
{
    this->value = anInteger.value;
    return (*this);
}

void MyInt::setValue(int value)
{
    this->value = value;
}

int MyInt::getValue() const
{
    return (this->value);
}

MyInt MyInt::absolute() const
{
    return (MyInt(abs(this->value)));

    /* return(((*this) >= 0) ? (*this) : (-(*this))); */
}

MyInt MyInt::operator +(int value) const
{
    return (MyInt(this->value + value));
}

MyInt MyInt::operator +(const MyInt & anInteger) const
{
    return (MyInt(this->value + anInteger.value));
}

MyInt operator +(int value, const MyInt & anInteger)
{
    return (MyInt(value + anInteger.value));
}

MyInt MyInt::operator -(int value) const
{
    return (MyInt(this->value - value));
}

MyInt MyInt::operator -(const MyInt & anInteger) const
{
    return (MyInt(this->value - anInteger.value));
}

MyInt operator -(int value, const MyInt & anInteger)
{
    return (MyInt(value - anInteger.value));
}

MyInt MyInt::operator *(int value) const
{
    return (MyInt(this->value * value));
}

MyInt MyInt::operator *(const MyInt & anInteger) const
{
    return (MyInt(this->value * anInteger.value));
}

MyInt operator *(int value, const MyInt & anInteger)
{
    return (MyInt(value * anInteger.value));
}

MyInt MyInt::operator /(int value) const
{
    return (MyInt(this->value / value));
}

MyInt MyInt::operator /(const MyInt & anInteger) const
{
    return (MyInt(this->value / anInteger.value));
}

MyInt operator /(int value, const MyInt & anInteger)
{
    return (MyInt(value / anInteger.value));
}

MyInt MyInt::operator %(int value) const
{
    return (MyInt(this->value % value));
}

MyInt MyInt::operator %(const MyInt & anInteger) const
{
    return (MyInt(this->value % anInteger.value));
}

MyInt operator %(int value, const MyInt & anInteger)
{
    return (MyInt(value % anInteger.value));
}

bool MyInt::operator ==(int value) const
{
    return (this->value == value);
}

bool MyInt::operator ==(const MyInt & anInteger) const
{
    return (this->value == anInteger.value);
}

bool operator ==(int value, const MyInt & anInteger)
{
    return (value == anInteger.value);
}

bool MyInt::operator !=(int value) const
{
    return (this->value != value);
}

bool MyInt::operator !=(const MyInt & anInteger) const
{
    return (this->value != anInteger.value);
}

bool operator !=(int value, const MyInt & anInteger)
{
    return (value != anInteger.value);
}

bool MyInt::operator >(int value) const
{
    return (this->value > value);
}

bool MyInt::operator >(const MyInt & anInteger) const
{
    return (this->value > anInteger.value);
}

bool operator >(int value, const MyInt & anInteger)
{
    return (value > anInteger.value);
}

bool MyInt::operator <(int value) const
{
    return (this->value < value);
}

bool MyInt::operator <(const MyInt & anInteger) const
{
    return (this->value < anInteger.value);
}

bool operator <(int value, const MyInt & anInteger)
{
    return (value < anInteger.value);
}   

bool MyInt::operator >=(int value) const
{
    return (this->value >= value);
}

bool MyInt::operator >=(const MyInt & anInteger) const
{
    return (this->value >= anInteger.value);
}

bool operator >=(int value, const MyInt & anInteger)
{
    return (value >= anInteger.value);
}

bool MyInt::operator <=(int value) const
{
    return (this->value <= value);
}

bool MyInt::operator <=(const MyInt & anInteger) const
{
    return (this->value <= anInteger.value);
}

bool operator <=(int value, const MyInt & anInteger)
{
    return (value <= anInteger.value);
}

MyInt & MyInt::operator +=(const MyInt & anInteger)
{
   (*this) = (*this) + anInteger.value;

   return(*this);

   /*  this->value += anInteger.value;
    return (*this); */
}

MyInt & MyInt::operator +=(int value)
{
    (*this) = (*this) + value;

    return(*this);

    /* this->value += value;
    return (*this); */
}

MyInt & MyInt::operator -=(const MyInt & anInteger)
{
    (*this) = (*this) - anInteger.value;

    return(*this);

    /* this->value -= anInteger.value;
    return (*this); */
}

MyInt & MyInt::operator -=(int value)
{
    (*this) = (*this) - value;

    return(*this);

    /* this->value -= value;
    return (*this); */
}

MyInt & MyInt::operator *=(const MyInt & anInteger)
{
    (*this) = (*this) * anInteger.value;

    return(*this);

    /* this->value *= anInteger.value;
    return (*this); */
}

MyInt & MyInt::operator *=(int value)
{
    (*this) = (*this) * value;

    return(*this);

    /* this->value *= value;
    return (*this); */
}

MyInt & MyInt::operator /=(const MyInt & anInteger)
{
    (*this) = (*this) / anInteger.value;

    return(*this);

    /* this->value /= anInteger.value;
    return (*this); */
}

MyInt & MyInt::operator /=(int value)
{
    (*this) = (*this) / value;

    return(*this);

    /* this->value /= value;
    return (*this); */
}

MyInt & MyInt::operator %=(const MyInt & anInteger)
{
    (*this) = (*this) % anInteger.value;

    return(*this);

    /* this->value %= anInteger.value;
    return (*this); */
}

MyInt & MyInt::operator %=(int value)
{
    (*this) = (*this) % value;

    return(*this);

    /* this->value %= value;
    return (*this); */
}

MyInt MyInt::operator +() const
{
    return (MyInt(this->value));
}

MyInt MyInt::operator -() const
{
    return (MyInt(-this->value));
}

MyInt & MyInt::operator ++()
{
    (*this) += 1;       // this->value++;
    return (*this);
}

MyInt MyInt::operator++(int)
{
    (*this) += 1;
    return((*this) -1);
}

MyInt & MyInt::operator --()
{
    (*this) -= 1;
    return (*this);
}

MyInt MyInt::operator--(int)
{
    (*this) -= 1;
    return((*this) + 1);
}

ostream & operator <<(ostream & out, const MyInt & anInteger)
{
    out << anInteger.value;
    return (out);
}

istream & operator >>(istream & in, MyInt & anInteger)
{
    in >> anInteger.value;
    return (in);
}

MyInt::operator int() const
{
    return (this->value);
}





