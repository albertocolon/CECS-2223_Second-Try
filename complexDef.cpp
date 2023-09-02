#include "Complex.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Definition of the Complex Class methods an functions

// Defining the Constructors and Destructor.
Complex::Complex()
{
	this->real = 0.0;
	this->img = 0.0;
}

Complex::Complex(double real, double img)
{
	this->real = real;
	this->img = img;
}

Complex::Complex(const Complex& aComplex)
{
	this->real = aComplex.real;
	this->img = aComplex.img;
}

Complex::~Complex(){ }

// Defining the Mutators (Setters)
void Complex::setReal(double real)
{
	this->real = real;
}

void Complex::setImg(double img)
{
	this->img = img;
}

// Defining the Accessors (Getters)
double Complex::getReal() const
{
	return(this->real);
}

double Complex::getImg() const
{
	return(this->img);
}