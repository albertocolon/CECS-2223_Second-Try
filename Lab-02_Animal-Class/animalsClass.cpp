//
//  main.cpp
//  animalClass_Lab02-Classes
//
//  Created by Alberto Colon on 8/19/23.
//  CECS-2223 | Sec. 31 | Carlos De La Torres Ugarte - Professor
//  This program is to create a class Animal with its attributes, services constructors and that an user can enter an animal, view it and exit the program.
//  All will be done inline.

#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

//********************************************************************************************************
// Creation of the Class Animal. Here is declare the attributes as private and the services as public.
//********************************************************************************************************
class Animal
{

private:
    string name;
    double weight;
    string color;
    int legAmount;

public:
    // Constructors and destructor
    Animal();
    Animal(string name, double weight, string color, int legAmount);
    Animal(const Animal & obj);
    ~Animal();
    
    // Mutators
    void setName(string name);
    void setWeight(double weight);
    void setColor(string color);
    void setLegs(int legAmount);
    
    // Accesors
    string getName() const;
    double getWeight() const;
    string getColor() const;
    int getLegs() const;
    
    // Other member functions
    void displayInfo() const;
    
};


//********************************************************************************************************
// Here we will define the classes services
//********************************************************************************************************

// Constructor definitions.
Animal::Animal()
{
    this->name = " ";
    this->weight = 0.0;
    this->color = " ";
    this->legAmount = 0;
}

Animal::Animal(string name, double weight, string color, int legAmount)
{
    this->name = name;
    this->weight = weight;
    this->color = color;
    this->legAmount = legAmount;
}

Animal::Animal(const Animal &obj)
{
    this->name = obj.name;
    this->weight = obj.weight;
    this->color = obj.color;
    this->legAmount = obj.legAmount;
}

Animal::~Animal()
{
    
}

// Defining mutators functions
void Animal::setName(string name)
{
    this-> name = name;
}

void Animal::setWeight(double weight)
{
    this-> weight = weight;
}

void Animal::setColor(string color)
{
    this-> color = color;
}

void Animal::setLegs(int legAmount)
{
    this-> legAmount = legAmount;
}

// Defining Accesosrs
string Animal::getName() const
{
    return (this->name);
}


double Animal::getWeight() const
{
    return(this->weight);
}

string Animal::getColor() const
{
    return (this->color);
}

int Animal::getLegs() const
{
    return (this->legAmount);
}

void Animal::displayInfo() const
{
    cout << "Name: " << name << "\n";
    cout << "Weight: " << weight << " kg\n";
    cout << "Color: " << color << "\n";
    cout << "Legs: " << legAmount << "\n";
}


//********************************************************************************************************
// Here will be the Functions Prototype (declarations).
//********************************************************************************************************

void showMenu();
void addAnimals(Animal [], int);
void displayAnimal(const Animal [], int);
// bool quiting();


//********************************************************************************************************
// Here is the main.
//********************************************************************************************************

int main()
{
    
    const int MAX_ANIMALS = 5;                  // Max amount of animals to enter.
    const int ADD = 1, DISPLAY = 2, QUIT = 3;   // Constant values for the menu choice option.
    int animalCount = 0, choice;                // Number of animals currently in the array.
    bool canContinue = true;                    // Boolean value used as a "flag" in order to manage the do while.
    bool close = false;                         // Boolean value use to relate the closing of the program.
    char confirm;                               // Chararacter variable for the decision to quit the program.
   
    
    // Class declaration
    Animal animals[MAX_ANIMALS];                // Array to store the animals instances.
    
    do
    {
        showMenu();
        cin >> choice;
        while (choice < ADD || choice > QUIT)   // Validation
        {
            cout << "Wrong entry. Please enter a valid selection from the Menu: ";
            cin >> choice;
        }
        
        switch (choice)
        {
            case ADD:
                addAnimals(animals, animalCount);
                break;
            case DISPLAY:
                displayAnimal(animals, animalCount);
                break;
            case QUIT:
                cout << "Are you sure you want to quit? (Y/N): ";
                cin >> confirm;
                
                if (confirm == 'Y' || confirm == 'y')
                {
                    close = true;
                }else if (confirm == 'N' || confirm == 'n')
                {
                    close = false;
                }else
                {
                    cout << "Invalid choice. Please enter 'Y' (yes) or 'N'(no)." << endl;
                    continue;
                }
                
                if (close == true)
                {
                    canContinue = false;
                }
                break;
        }
        
    } while (canContinue);
    
    
    
    return 0;
}


//********************************************************************************************************
// Here we will be the functions definitions.
//********************************************************************************************************

void showMenu()
{
    
    cout << "\n\t\tANIMAL LOVER MENU\n\n"
         << "1. Enter a new animal\n"
         << "2. View animal entry\n"
         << "3. Exit the program\n"
         << "\n"
         << "Choice: ";
}


void addAnimals(Animal animals[], int count)
{
    if (count < 10)
    {
        string name, color;
        double weight;
        int legAmount;
        
        cout << "Enter the Animal's Name: ";
        cin >> name;
        cout << endl;
        
        cout << "Enter the Animal's Weight: ";
        cin >> weight;
        cout << endl;
        
        cout << "Enter the Animal's Color: ";
        cin >> color;
        cout << endl;
        
        cout << "Enter how many legs does the animal have: ";
        cin >> legAmount;
        cout << endl;
        
        animals[count] = Animal(name, weight, color, legAmount);
        count++;
    } else
    {
        cout << "Maximum number of animals reached.\n";
    }
}

void displayAnimal(const Animal animals[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "Animal " << i + 1 << ":\n";
        animals[i].displayInfo();
        cout << "\n";
        
    }
}

// Had the idea of making a function for the quit but had issues and was not running so I did it inline.
/*bool quiting()
{
    bool close = false;                         // Boolean value use to relate the closing of the program.
    char confirm;                               // Chararacter variable for the decision to quit the program.
    
    cout << "Are you sure you want to quit? (Y/N): ";
    cin >> confirm;
    
    if (confirm == 'Y' || confirm == 'y')
    {
        close = true;
    }else if (confirm == 'N' || confirm == 'n')
    {
        close = false;
    }else
    {
        cout << "Invalid choice. Please enter 'Y' (yes) or 'N'(no): " << endl;
        cin >> confirm;
    }
    

    return close;
}*/