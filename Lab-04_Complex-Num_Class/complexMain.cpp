//
//  main.cpp
//  complexClass_Lab04
//
//  Created by Alberto Colon on 9/2/23.
//

#include <iostream>
#include "Complex.h"
#include <iomanip>

using namespace std;

void menu();
void getComplexNum(Complex&, Complex&);



int main()
{
    Complex cn1, cn2, cnR;
    int option = 0;
    
    cout << "\t*** Complex Numbers Lab ***\n";
    
    do
    {
        menu();
        cin >> option;
        
        switch(option)
        {
            case 1:
                getComplexNum(cn1, cn2);
                cnR = cn1 + cn2;
                // cnR = complexAdd(cn1, cn2);
                cout << cn1 << " + " << cn2 << " = " << cnR;
                cout << "\n";
                break;
            case 2:
                getComplexNum(cn1, cn2);
                // cnR = complexSubstract(cn1, cn2);
                cnR = cn1 - cn2;
                cout << cn1 << " - " << cn2 << " = " << cnR;
                cout << "\n";
                break;
            case 3:
                getComplexNum(cn1, cn2);
                cnR = cn1 * cn2;
                // cnR = complexMult(cn1, cn2);
                cout << cn1 << " * " << cn2 << " = " << cnR;
                cout << "\n";
                break;
            case 4:
                system("clear");
                break;
            case 5:
                cout << "\nBYE\n";
                break;
            default:
                cout << "Invalid option. Please, try again.\n";
                break;
        }   // end of Switch.
        
    } while (option != 5);
    
    return 0;
}


// ******************************************************************************************
//                              Functions Definitions                                       *
// ******************************************************************************************


void menu()
{
    cout << "\n***Select one of the following options***\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Clear the Screen\n";
    cout << "5. Exit\n";
}


void getComplexNum(Complex& cn1, Complex& cn2)
{
    cout << "\nTo enter a Compelex number it will be prompt to enter, first the Real part and then the Imaginary part.\n";
    cout << "\nEnter the First number: \n";
    cin >> cn1;
    cout << "\n";
    cout << "Enter the Second number: \n";
    cin >> cn2;
    cout << "\n";
}

