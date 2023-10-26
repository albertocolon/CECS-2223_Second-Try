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

