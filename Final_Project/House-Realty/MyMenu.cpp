// My Menu class definition 

#include "MyMenu.h"
#include <iostream>

using namespace std;

MyMenu::MyMenu(const MyString & description, const MyString &question)
{
    (*this) + description;
    (*this) + question;
}

MyMenu::MyMenu(const char * description, const char * question)
{
    (*this) + description;
    (*this) + question;
}

MyMenu::MyMenu(const MyMenu &aMenu) : list(aMenu.list)
{
}

MyMenu::~MyMenu()
{
}

MyMenu &MyMenu::operator=(const MyMenu &aMenu)
{
    this->list = aMenu.list;

    return(*this);
}

void MyMenu::setDescription(const MyString &description)
{
    (*this)[0] = description;
}

void MyMenu::setDescription(const char *description)
{
    (*this)[0] = description;
}

void MyMenu::setQuestion(const MyString &question)
{
    (*this)[1] = question;
}

void MyMenu::setQuestion(const char *question)
{
    (*this)[1] = question;
}

const MyString &MyMenu::getDescription()const
{
    return((*this)[0]);
}

const MyString &MyMenu::getQuestion()const
{
    return((*this)[1]);
}

int MyMenu::getOptionCount()const
{
    return((this->list).arrayAmount() -2);
}

MyMenu &MyMenu::operator+(const MyString &option)
{
    (this->list) + option;
    return(*this);
}

MyMenu &MyMenu::operator+(const char *option)
{
    (this->list) + option;
    return(*this);
}

const MyString & MyMenu::operator[](int index)const
{
    return((this->list)[index]);
}

MyString &MyMenu::operator[](int index)
{
    return((this->list)[index]);
}

ostream &operator<<(ostream &out, const MyMenu &aMenu)
{
    out << aMenu.getDescription() << endl;

    for(int i = 0; i < aMenu.getOptionCount(); i++)
    {
        out << '\t' << (i + 1) << ". " << aMenu[i + 2] << endl;
    }

    out << aMenu.getQuestion() << endl;

    return(out);
}

void MyMenu::setOption(int index, const MyString &option)
{
    int amount = (this->list).arrayAmount();

    if(index >= 0 && index < amount)
    {
        (*this)[index + 2] = option;
    }
}

void MyMenu::setOption(int index, const char *optioin)
{
    this->setOption(index, MyString(optioin));
}

const MyString & MyMenu::getOption(int index) const
{
    return((*this)[index + 2]);
}

bool MyMenu::aggregateOption(const MyString &option)
{
    return((this->list).insertAtEnd(option));
}

bool MyMenu::aggregateOption(const char *option)
{
    return((this->list).insertAtEnd(option));
}


