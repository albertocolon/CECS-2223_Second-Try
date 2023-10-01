/* Lab - 07 (10) FILES
Alberto A. Colón - ID-67689
FA-23 | CECS 2223 Sec.  31
Professor: Carlos De la Torre Ugarte
Sept 30 2023
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Global variable
int choice;

// Function prototype to calculate the grades average and to show tittle.
double CalcAverage(double, int);
void showTittle();
void menu();


int main()
{
    string fileName;
    ofstream gradeFile;
    ifstream readGradesFile;
    double grade, average;
    double gradeSum = 0.0;
    int amount;

    // Show the tittle
    showTittle();
    do
    {
        menu();
        cout << "\tEnter your choice:";
        cin >> choice;

        while (choice < 1 || choice > 3)
        {
            cout << "Error: Choose one of the presented options.";
            cin >> choice;
        }

        switch (choice)
        {
            case 1:
                // Create a new file
                cout << "Enter the file name (including the .txt extension): ";
                cin >> fileName;

                gradeFile.open(fileName);
                if(gradeFile.fail())
                    cout << "Error: " << fileName << " File, could not be open." << endl;
                else
                {
                    cout << "Enter the amount of grades to be add on to the file: ";
                    cin >> amount;
                    for (int i = 1; i <= amount; i++)
                        {
                            cout << "Enter now the grades, each separated by 'enter' key: ";
                            cin >> grade;
                            if(grade < 0.00 || grade > 100.00)
                                cout << "Error: Incorrect grade value. Try again: ";
                                cin >> grade;
                            gradeFile << grade << endl;
                            gradeSum += grade;
                        }
                    gradeFile.close();
                }
                break;
            case 2:
                // Open the file to read
                cout << "Great!" << endl;

                readGradesFile.open(fileName);
                if(readGradesFile.fail())
                    cout << "Error: File could not be open" << endl;
                else
                {
                    readGradesFile >> grade;
                    cout << "The entered grades on the " << fileName << " file are: " << endl;
                    while (!readGradesFile.eof())
                    {
                        cout << grade << " % " << endl;
                        readGradesFile >> grade;
                    }
                    cout << "Total grades entered, is: " << amount << "." << endl;

                    // Calculating and displaying the average
                    average = CalcAverage(gradeSum, amount);
                    cout << fixed << setprecision(2);
                    cout << "The Average grade is: " << average << "% " << endl;

                    // Closing the file
                    readGradesFile.close();
                }
                break;
        }
            


    } while (choice != 3);

    return 0;
}

// ***********************************************************************************
// ************************** Functions definitions **********************************
// ***********************************************************************************

double CalcAverage(double sum, int count)
{
    return ((count == 0) ? 0.0 : (sum / count));
}

void showTittle()
{
    cout << "\t\tWelcome to the Lab 07 (10) about files\t\t\n";
    cout << "****************************************************************" << endl;
    cout << endl;
    cout << "Let's begin!" << endl;
    cout << endl;
}

void menu()
{
    cout << "\t\tWhat would you like to do?\t" << endl;
    cout << "\t\t--------------------------\t" << endl;
    cout << "\t1. Create a grade file.\n";
    cout << "\t2. Open the grade file to see the content.\n";
    cout << "\t3. Quit.\n";
}