// Lab - 03 Complex Class - Operator Overloading
// Alberto A. Colón - 67689
// CECS 222

#pragma once
#ifndef Complex_h
#define Complex_h

#include <iostream>
#include <iomanip>

using namespace std;

class Complex
{
private:
	double real;
	double img;

public:
	Complex();
	Complex(double real, double img);
	Complex(const Complex& aComplex);

	~Complex();

	// Mutators
	void setReal(double real);
	void setImg(double img);

	// Accessors
	double getReal() const;
	double getImg() const;

	// Arithmetic and Equal operators.
	Complex operator + (const Complex& aComplex) const;
	Complex operator - (const Complex& aComplex) const;
	Complex operator * (const Complex& aComplex) const;
	Complex operator / (const Complex& aComplex) const;

	void operator = (const Complex& aComplex);
	bool operator == (const Complex& aComplex);
	bool operator != (const Complex& aComplex);

	// Friend operators function declaration
	friend ostream& operator << (ostream& out, const Complex& aComplex);
	friend istream& operator >> (istream& in, Complex& aComplex);

};


#endif // !Complex_h
