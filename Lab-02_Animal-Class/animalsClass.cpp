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
#include <cstdlib>

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
void displayAnimal(Animal [], int);


//********************************************************************************************************
// Here is the main.
//********************************************************************************************************

int main()
{
    
    return 0;
}


//********************************************************************************************************
// Here we will be the functions definitions.
//********************************************************************************************************

void showMenu()
{
    system("clear");
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
        getline(cin, name);
        cout << endl;
        
        cout << "Enter the Animal's Weight: ";
        cin >> weight;
        cout << endl;
        
        cout << "Enter the Animal's Color: ";
        getline(cin, color);
        cout << endl;
        
        cout << "Enter how many legs does the animal have: ";
        cin >> legAmount;
        cout << endl;
        
        animals[count] = Animal(name, weight, color, legAmount);
        ++count;
    } else
    {
        cout << "Maximum number of animals reached.\n";
    }
}

void displayAnimal(const Animal animals[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        cout << "Animal " << i + 1 << ":\n";
        animals[i].displayInfo();
        cout << "\n";
        
    }
}

