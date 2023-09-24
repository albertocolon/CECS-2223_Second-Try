//
// Lab-06 Shapes
// Composition in Class creation
// Alberto A. Colón Reyes ID 67689
// CECS 2223 - Prof. Carlos De La Torre Ugarte
// 

#ifndef _Point_h
#define _Point_h

#include <iostream>

using namespace std;

class Point
{
    private:
    // Here are the attribute variables requested
    int x, y;

    public:
    Point(int x = 0, int = 0);
    Point(const Point & aPoint);
    ~Point();

    Point & operator = (const Point & aPoint);
    
    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);

   // int distance(const Point & aPoint) const; ----> I wanted to use this function but forgot that in order for me to use it I will need the type of the x & y variables to be double. The instructions said to made them int.

    friend ostream & operator << (ostream & out, const Point & aPoint);
    friend istream & operator >> (istream & in, Point & aPoint);


};
#endif
// _Point.h_