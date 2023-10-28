// Here are the definitions for the methods of the Record class

#include "Record.h"
#include "House.h"
#include <iostream>

using namespace std;

Record::Record(const House &data) : data(data)
{
    this->active = true;
}

Record::Record(const Record &aRecord) : data(aRecord.data)
{
    this->active = aRecord.active;
}

Record::~Record()
{
}

Record &Record::operator=(const Record &aRecord)
{
    this->data = aRecord.data;
    this->active = aRecord.active;

    return *this;
}

void Record::setData(const House &data)
{
    this->data = data;
}

const House &Record::getData()const
{
    return data;
}

void Record::activate()
{
    active = true;
}

void Record::deactivate()
{
    active = false;
}

bool Record::isActive()const
{
    return(this->active);
}

ostream &operator<<(ostream &out, const Record &aRecord)
{
    out << aRecord.data << endl;
    
    if(aRecord.isActive())
    {
        out << "Active" << endl;
    }
    else
    {
        out << "Inactive" << endl;
    }
    
    return out;
}

