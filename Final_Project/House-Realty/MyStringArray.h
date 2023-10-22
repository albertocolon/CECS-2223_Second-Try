// Class made by the profesor Luis Ortiz so each object of the class a MyString array.

#ifndef MYSTRINGARRAY_H
#define MYSTRINGARRAY_H

#include "MyString.h"
#include <iostream>

using namespace std;

const int MAX = 100;

class MyStringArray
{
    private:
    MyString array[MAX];
    int amount;

    public:
    MyStringArray();
    MyStringArray(const MyStringArray &anArray);

    ~MyStringArray();

    MyStringArray &operator=(const MyStringArray &anArray);

    int arrayAmount() const;

    bool operator ==(const MyStringArray &anArray) const;
    bool operator !=(const MyStringArray &anArray) const;

    bool insert(int index, const MyString &aMyString);
    bool insert(int index, const char *aString);
    bool insert(int index, const MyStringArray &anArray);

    bool insertAtStart(const MyString &aMyString);
    bool insertAtStart(const char *aString);
    bool insertAtStart(const MyStringArray &anArray);

    bool insertAtEnd(const MyString &aMyString);
    bool insertAtEnd(const char *aString);
    bool insertAtEnd(const MyStringArray &anArray);

    MyStringArray & operator +(const MyString &aMyString);
    MyStringArray & operator +(const char *aString);
    MyStringArray & operator +(const MyStringArray &anArray);

    friend MyStringArray & operator +(const MyString &aMyString, const MyStringArray &anArray);
    friend MyStringArray & operator +(const char *aString, const MyStringArray &anArray);

    bool isFull() const;
    bool isEmpty() const;

    bool include(const MyString &aMyString) const;
    bool include(const char *aString) const;

    int indexOf(const MyString &aMyString) const;
    int indexOf(const char *aString) const;
    int indexOfLast(const MyString &aMyString) const;
    int indexOfLast(const char *aString) const;

    bool remove(int index);
    bool removeFirst();
    bool removeLast();
    bool remove(int index, MyString &aMyString);
    bool removeFirst(MyString &aMyString);
    bool removeLast(MyString &aMyString);

    MyStringArray & operator -(const MyString &aMyString);
    MyStringArray & operator -(const char *aString);
    MyStringArray & operator -(int index);

    friend MyStringArray & operator -(const char *aString, MyStringArray &anArray);
    friend MyStringArray & operator -(const MyString &aMyString, MyStringArray &anArray);

    void emptyIt();

    void ascendingSort();
    void descendingSort();

    bool replace(int index, const MyString &aMyString);
    bool replace(int index, const char *aString);

    const MyString & operator [](int index) const;
    MyString & operator [](int index);

    int frequency(const MyString &aMyString) const;
    int frequency(const char *aString) const;

    static int MaxArrays();

    friend ostream & operator <<(ostream &out, const MyStringArray &anArray);
};

#endif // MYSTRINGARRAY_H