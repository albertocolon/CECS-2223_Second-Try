

#include <iostream>
#include "shape.h"
#include "point.h"

using namespace std;

void showMenu();

int main()
{
    int choice;
    Shape triangle, rectangle, pentagon, hexagon, shapes;
    
    
    do {

        showMenu();
        cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                cin >> triangle;
                cout << triangle;
                cout << "The Triangle Perimeter is: " << triangle.perimeter() << "\n";
                break;
            }
            case 2:
            {
                cin >> rectangle;
                cout << rectangle;
                cout << "The Rectangle Perimeter is: " << rectangle.perimeter() << "\n";
                break;
            }
            case 3:
            {
                cin >> pentagon;
                cout << pentagon;
                cout << "The Pentagon Perimeter is: " << pentagon.perimeter() << "\n";
                break;
            }
            case 4:
            {
                cin >> hexagon;
                cout << hexagon;
                cout << "The Hexagon Perimeter is: " << hexagon.perimeter() << "\n";
                break;
            }
            case 5:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        
    } while (choice != 5);
    
    return 0;
}


void showMenu()
{
    cout << "Menu:\n";
    cout << "1. Add a Triangle Shape\n";
    cout << "2. Add a Rectangle Shape\n";
    cout << "3. Add a Pentagon Shape\n";
    cout << "4. Add a Hexagon Shape\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}