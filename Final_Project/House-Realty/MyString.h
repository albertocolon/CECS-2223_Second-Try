// Professor's annotations - A1-d String Class (Clase Cadena)
// The objects of this class each represents a string of characters. 

#ifndef _MyString_h
#define _MyString_h

#include <iostream>
#include <string>

using namespace std;

const int MAX_LEN = 80;

class MyString
{
    private:
    char s[MAX_LEN + 1];                                // Attribute

    public:
    // Constructors and Destructor
    MyString(const char * s = "");                      // Constructor with default argument. Replace the Default constructor. Either is REQUIRED.
    MyString(char ch);
    MyString(const MyString & aMyString);               // Copy Constructor. REQUIRED

    ~MyString();                                        // Destructor. REQUIRED

    // Assign operator overloading
    MyString & operator =(const char * s);
    MyString & operator =(char ch);
    MyString & operator =(const MyString & aMyString);  // REQUIRED

    // Mutators and Accessors
    void setS(const char * s);
    const char * getS() const;

    // Operator overloading - CONCATENATE
    MyString operator +(const char * s) const;
    MyString operator +(char ch) const;
    MyString operator +(const MyString & aMyString) const;

    // Friend operator functions - CONCATENATE
    friend MyString operator +(const char * s, const MyString & aMyString);
    friend MyString operator +(char ch, const MyString & aMyString);

    // More operator overloaing
    bool operator ==(const char * s) const;
    bool operator ==(const MyString & aMyString) const;

    friend bool operator ==(const char * s, const MyString & aMyString);
    // --------------------------------------------------------------------
    bool operator !=(const char * s) const;
    bool operator !=(const MyString & aMyString) const;

    friend bool operator !=(const char * s, const MyString & aMyString);
    // --------------------------------------------------------------------
    bool operator >(const char * s) const;
    bool operator >(const MyString & aMyString) const;

    friend bool operator >(const char * s, const MyString & aMyString);
    // --------------------------------------------------------------------
    bool operator <(const char * s) const;
    bool operator <(const MyString & aMyString) const;

    friend bool operator <(const char * s, const MyString & aMyString);

    // Array list [] operator overloading. REQUIRED
    const char & operator [](int index) const;
    char & operator [](int index);                  // Here the 'char &', by reference returns an element of the array of characters of the insantnce that calls the function. 

    // Friend iostream operators function (overloading)
    friend istream & operator >> (istream & in, MyString & aMyString);
    friend ostream & operator << (ostream & out, const MyString & aMyString);

    // ************************ Additional Member functions to deal with the string of characters. 
    
    MyString trimLeadingSpaces() const;
    MyString trimEndingSpaces() const;
    MyString trimAllSpaces() const;

    MyString toUppercase() const;
    MyString toLowercase() const;

    MyString createSubstring(int from, int to) const;

    int len() const;
    bool isEmpty() const;

    MyString reverse() const;

    int indexOf(char ch) const;
    int indexOfLast(char ch) const;
    bool include(char ch) const;
    int frequency(char ch) const;

    bool representAnUnsignInteger() const;
    bool representAnInteger() const;
    bool representAReal() const;

    static int MaxLen();

    MyString & operator +=(const MyString & aMyString);
    MyString & operator +=(const char * s);
    MyString & operator +=(char ch);

    MyString & operator ++();                    // ++ Object -> to uppercase
    MyString operator ++(int);                   // Object ++ -> to uppercase
    
    MyString & operator --();                    // -- Object -> to lowercase
    MyString operator --(int);                   // Object -- -> to lowercase
};

#endif

// _ MyString.h _ class declaration. 