// My Menu class declaration for the association to the Realty class

#ifndef MYMENU_H
#define MYMENU_H

#include "MyStringArray.h"
#include "MyString.h"
#include <iostream>

using namespace std;

class MyMenu
{
    private:
    MyStringArray list;

    const MyString &operator[](int index) const;
    MyString &operator[](int index);

    public:
    MyMenu(const MyString & description = "Description", const MyString & question = "Question");
    MyMenu(const char * description, const char * question);
    MyMenu(const MyMenu &aMenu);

    ~MyMenu();

    MyMenu &operator=(const MyMenu &aMenu);

    void setDescription(const MyString & description);
    void setDescription(const char * description);
    void setQuestion(const MyString & question);
    void setQuestion(const char * question);

    void setOption(int index, const MyString & option);
    void setOption(int index, const char * option);

    const MyString &getDescription() const;
    const MyString &getQuestion() const;
    const MyString &getOption(int index) const;

    int getOptionCount() const;

    bool addOption(const MyString & option);
    bool addOption(const char * option);

    MyMenu &operator+(const MyString & option);
    MyMenu &operator+(const char * option);

    friend ostream &operator<<(ostream &out, const MyMenu &aMenu);

};


#endif /* MYMENU_H */