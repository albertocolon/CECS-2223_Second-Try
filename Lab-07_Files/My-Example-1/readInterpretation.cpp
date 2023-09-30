// A2-f Professor's Annotations - Files (Read and Interpretation of what was read) -- Archivos (Lectura e interpretación de lo leído)
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;
    int character = 0, digit = 0;
    char ch;

    file.open("numeros.txt");
    if(file.fail())
        cout << "Error: This file could not be open: " << "numeros.txt" << endl;
    else
    {
        ch = file.get();
        while(!file.eof())
        {
            ++character;
            if(ch >= '0' && ch <= '9')
                ++digit;
            ch = file.get();
        }

        cout << "There is " << character << " characters on the file." << endl << "There's also, " << digit << " digits on the file." << endl;
        file.close();
    }

    return 0;
}