// Here is the Record class declaration. Each house has some sort of wrap savedon the file.

#ifndef RECORD_H
#define RECORD_H

#include "House.h"
#include <iostream>

using namespace std;

class Record
{
    private:
    House data;
    bool active;     // In order to determine which properties are active or not

    public:
    Record(const House &aHouse = House());
    Record(const Record &aRecord);

    ~Record();

    Record &operator=(const Record &aRecord);

    void setData(const House &aHouse);
    const House &getData()const;

    void activate();
    void deactivate();
    bool isActive()const;

    friend ostream &operator<<(ostream &out, const Record &aRecord);

};

#endif /* RECORD_H */