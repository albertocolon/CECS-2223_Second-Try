// Creating my own version of the int class (Based on the Profesor Luis Ortiz Course's Annotations)

#ifndef MYINT_H
#define MYINT_H

#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class MyInt
{
    private:
    int value;

    public:
    // Constructors and Destructor
    MyInt(int value = 0);
    MyInt(const MyInt & anInteger);

    ~MyInt();

    // Assign operator overloading
    MyInt & operator =(int value);
    MyInt & operator =(const MyInt & anInteger);  // REQUIRED

    // Mutators and Accessors
    void setValue(int value);
    int getValue() const;

    MyInt absolute() const;

    // Operator overloading
    MyInt operator +(int value) const;
    MyInt operator +(const MyInt & anInteger) const;

    
    friend MyInt operator +(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    MyInt operator -(int value) const;
    MyInt operator -(const MyInt & anInteger) const;

    friend MyInt operator -(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    MyInt operator *(int value) const;
    MyInt operator *(const MyInt & anInteger) const;

    friend MyInt operator *(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    MyInt operator /(int value) const;
    MyInt operator /(const MyInt & anInteger) const;

    friend MyInt operator /(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    MyInt operator %(int value) const;
    MyInt operator %(const MyInt & anInteger) const;

    friend MyInt operator %(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    bool operator ==(int value) const;
    bool operator ==(const MyInt & anInteger) const;

    friend bool operator ==(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    bool operator !=(int value) const;
    bool operator !=(const MyInt & anInteger) const;

    friend bool operator !=(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    bool operator >(int value) const;
    bool operator >(const MyInt & anInteger) const;

    friend bool operator >(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    bool operator <(int value) const;
    bool operator <(const MyInt & anInteger) const;

    friend bool operator <(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    bool operator >=(int value) const;
    bool operator >=(const MyInt & anInteger) const;

    friend bool operator >=(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    bool operator <=(int value) const;
    bool operator <=(const MyInt & anInteger) const;

    friend bool operator <=(int value, const MyInt & anInteger);

    // --------------------------------------------------------------------

    operator int() const;

    bool operator >=(const MyInt & anInteger) const;
    bool operator >=(int value) const;

    friend bool operator >=(int value, const MyInt & anInteger);

    MyInt & operator +=(int value);
    MyInt & operator +=(const MyInt & anInteger);

    MyInt & operator -=(int value);
    MyInt & operator -=(const MyInt & anInteger);

    MyInt & operator *=(int value);
    MyInt & operator *=(const MyInt & anInteger);

    MyInt & operator /=(int value);
    MyInt & operator /=(const MyInt & anInteger);

    MyInt & operator %=(int value);
    MyInt & operator %=(const MyInt & anInteger);

    MyInt operator -() const;   // -Object
    MyInt operator +() const;   // +Object

    MyInt & operator ++();      // ++Object
    MyInt operator ++(int);     // Object++

    MyInt & operator --();      // --Object
    MyInt operator --(int);     // Object--

    friend istream & operator >> (istream & in, MyInt & anInteger);
    friend ostream & operator << (ostream & out, const MyInt & anInteger);
};
#endif /* MYINT_H */