//
// Lab-06 Shapes
// Composition in Class creation
// Alberto A. Colón Reyes ID 67689
// CECS 2223 - Prof. Carlos De La Torre Ugarte
// 

#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

// Point Class methods definitions

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point(const Point & aPoint)
{
    (*this) = aPoint;
}

Point::~Point()
{
    // None resourse to freed.
}

Point & Point::operator = (const Point & aPoint)
{
    this->x = aPoint.x;
    this->y = aPoint.y;
    return(*this);
}
    
int Point::getX() const
{
    return(this->x);
}

int Point::getY() const
{
    return(this->y);
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

double Point::distance(const Point & aPoint) const
{
    return(sqrt(pow((this->x - aPoint.x), 2) + pow((this->y - aPoint.y), 2)));
}

ostream & operator << (ostream & out, const Point & aPoint)
{
    out << "(" << aPoint.x << " , " << aPoint.y << ")";
    return(out);
}

istream & operator >> (istream & in, Point & aPoint)
{
    cout << "Add the X coordenate of the point: ";
    in >> aPoint.x;
    cout << "Add the Y coordenate of the point: ";
    in >> aPoint.y;

    return(in);
}