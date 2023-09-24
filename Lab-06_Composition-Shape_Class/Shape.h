//
// Lab-06 Shapes
// Composition in Class creation
// Alberto A. Colón Reyes ID 67689
// CECS 2223 - Prof. Carlos De La Torre Ugarte
// 

#ifndef _Shape_h
#define _Shape_h

#include <iostream>
#include "Point.h"

using namespace std;

class Shape
{
    private:
    Point points[6];
    int howManyPoints;

    public:
    Shape(const Point & a = Point(0, 0),const Point & b = Point(0, 3), const Point & c = Point(3, 5));
    Shape(const Shape * aShape);
    ~Shape();

    Shape & operator = (const Shape & aShape);

    bool addVertex(const Point & aPoint);
    bool removeVertex(int vertexPosition);
    int vertexAmount() const;

    friend istream & operator >> (istream & in, Shape & aShape);
    friend ostream & operator << (ostream & out, const Shape & aShape);

};

#endif
// _Shape