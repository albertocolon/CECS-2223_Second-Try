// This C++ program ...

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	string filename;
	cout << "Enter the file name: ";
	cin >> filename;
	
	ifstream inputFile(filename);
	
	if (!inputFile) {
		cerr << "Error: Unable to open the file." << endl;
		return 1;
	}
	
	int totalGrades = 0;
	double sum = 0.0;
	int grade;
	
	while (inputFile >> grade) {
		if (grade >= 0) {
			sum += grade;
			totalGrades++;
		}
	}
	
	inputFile.close();
	
	if (totalGrades == 0) {
		cout << "The file is empty." << endl;
	} else {
		double average = sum / totalGrades;
		cout << "Total grades are: " << totalGrades << endl;
		cout << "The average is: " << fixed << setprecision(1) << average << "%" << endl;
	}
	
	return 0;
}
