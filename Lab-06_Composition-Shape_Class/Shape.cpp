//
// Lab-06 Shapes
// Composition in Class creation
// Alberto A. Colón Reyes ID 67689
// CECS 2223 - Prof. Carlos De La Torre Ugarte
// 

#include <iostream>
#include "Point.h"
#include "Shape.h"

using namespace std;

Shape::Shape(const Point & a, const Point & b, const Point & c)
{
    //this->points = new Point[3];
    this->howManyPoints = 3;
    this->points[0] = a;
    this->points[1] = b;
    this->points[2] = c;
}

Shape::Shape(const Shape & aShape)
{
    this->points = NULL;
    *this = aShape;
    
}

Shape::~Shape()
{
    delete[](this->points);
}

Shape & Shape::operator=(const Shape & aShape)
{
    delete[](this->points);
    if(aShape.howManyPoints > 0)
    {
        this->points = new Point[aShape.howManyPoints];
        for(int i = 0; i < aShape.howManyPoints; i++)
        {
            this->points[i] = aShape.points[i];
        }
    }
    else
    {
        this->points = NULL;
    }

    this->howManyPoints = aShape.howManyPoints;
    return *this;
}

int Shape::vertexAmount() const
{
    return this->howManyPoints;
}

void addVertex(const Point & aPoint)
{
    // It is created a new dinamic array with one more space
    Point * array = new Point[this->howManyPoints + 1];

    // The new array is filled with the old array
    for(int i = 0; i < this->howManyPoints; i++)
    {
        array[i].setX((this->points)[i].getX());
        array[i].setY((this->points)[i].getY());
    }

    // The new, copied point is added to the new array's las index.
    array[this->howManyPoints] = aPoint;

    // In order to release the memory, the old array is deleted.
    delete[](this->points);

    // Is saved the new array's address in the old array's pointer.
    this->points = array;
    (this->howManyPoints)++;
}

bool Shape::removeVertex(int vertexPosition)
{
    bool isRemoved = false;
    Point * array;

    if(vertexPosition >= 0 && vertexPosition < this->howManyPoints)
    {
        // 1. Create a new array with one less space
        array = new Point[this->howManyPoints - 1];

        // 2. Copy the old array to the new array. The first for loop copied the elements before the vertex to be removed.
        for(int i = 0; i < vertexPosition; i++)
        {
            array[i].setX((this->points)[i].getX());
            array[i].setY((this->points)[i].getY());
        }

        // 3. The second for loop copied the elements after the vertex to be removed.
        for(int i = vertexPosition + 1; i < this->howManyPoints; i++)
        {
            array[i - 1].setX((this->points)[i].getX());
            array[i - 1].setY((this->points)[i].getY());
        }

        // 4. The old array is deleted.
        delete[](this->points);
        (this->howManyPoints)--;

        if((this->howManyPoints) == 0)
        {
            this->points = NULL;
        }
        else
        {
            // 5. The new array's address is saved in the old array's pointer.
            this->points = array;
        }

        isRemoved = true;
    }

    return isRemoved;

}

double Shape::perimeter() const
{
    double perimeter = 0.0;
    for(int i = 0; i < this->howManyPoints; i++)
    {
        perimeter += (this->points)[i].distance((this->points)[(i + 1) % this->howManyPoints]);
    }
    return perimeter;
}

istream & operator >> (istream & in, Shape & aShape)
{
    Point vertex;
    delete[](aShape.points);

    cout << "How many vertexes does the shape have? ";
    in >> aShape.howManyPoints;

    while((aShape.howManyPoints) < 3)
    {
        cout << "ERROR: The shape must have at least 3 vertexes. Try again: ";
        in >> aShape.howManyPoints;
    }
    aShape.points = new Point[aShape.howManyPoints];
    for(int i = 0; i < aShape.howManyPoints; i++)
    {
        cout << "Vertex #" << (i + 1) << endl;
        in >> vertex;
        aShape.points[i] = vertex;
    }

    return in;
}

ostream & operator << (ostream & out, const Shape & aShape)
{
    out << "The shape has " << aShape.howManyPoints << " vertexes: " << endl;
    
    out << "The vertexes are: " << endl;
    for(int i =0; i < aShape.howManyPoints; i++)
    {
        out << "\tVertex # " << (i + 1) << ": (" << (aShape.points)[i].getX() << ", " << (aShape.points)[i].getY() << ")" << endl;
    }

    out << "The perimeter of the shape is: " << aShape.perimeter() << endl;

    return (out);
}


