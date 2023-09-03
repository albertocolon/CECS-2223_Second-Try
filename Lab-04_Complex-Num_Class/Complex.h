//
//  Complex.h
//  complexClass_Lab04
//
//  Created by Alberto Colon on 9/2/23.
//

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
    
    // Assign Operator
    Complex & operator = (const Complex & aComplex);
    
    
    // Arithmetic Operators.
    Complex operator + (const Complex& aComplex) const;
    Complex operator - (const Complex& aComplex) const;
    Complex operator * (const Complex& aComplex) const;
    
    
    // Friend operators function declaration
    friend ostream& operator << (ostream& out, const Complex& aComplex);
    friend istream& operator >> (istream& in, Complex& aComplex);
    
};

#endif /* Complex_h */
