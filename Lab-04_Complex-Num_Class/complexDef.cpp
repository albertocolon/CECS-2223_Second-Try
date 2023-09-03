//  complexDef.cpp
//  complexClass_Lab04
//
//  Created by Alberto Colon on 9/2/23.
//

#include <stdio.h>
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

// *******************************************************************************************************
//                          Definition for the operator overloading                                      *
// *******************************************************************************************************

Complex & Complex::operator = (const Complex & aComplex)
{
    this->real = aComplex.real;
    this->img = aComplex.img;
    return(*this);
}

Complex Complex::operator + (const Complex& aComplex) const
{
    return(Complex(this->real + aComplex.real, this->img + aComplex.img));
}

Complex Complex::operator - (const Complex& aComplex) const
{
    return(Complex(this->real - aComplex.real, this->img - aComplex.img));
}
Complex Complex::operator * (const Complex& aComplex) const
{
    return(Complex((this->real * aComplex.real)-(this->img * aComplex.img),((this->real * aComplex.img)+(this->img * aComplex.real))));
    // ---> Multiplication for complex numbers. Let say we have this (a+bi)(c+di) then the multiplication is (ac-bd)+(ad+bc)i. I think I did it right.
}

// Definign the friends operators functions iostream.

ostream & operator << (ostream & out, const Complex & aComplex)
{
    out << "(" << aComplex.real << " + " << aComplex.img << ")i";
    return out;
}

istream & operator >> (istream & in, Complex & aComplex)
{
    cout << "Complex number - Real part: ";
    in >> aComplex.real;
    cout << "Complex number - Imaginary part: ";
    in >> aComplex.img;
    return in;
}
