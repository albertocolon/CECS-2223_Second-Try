// This C++ program is the first sugestion since I failed to annotate the class where this was discuss. 
#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
	Employee(const string& name, int employeeID) : name(name), employeeID(employeeID) {}
	
	virtual double calculatePay() const = 0; // Virtual function to calculate pay
	
	void displayInfo() const {
		cout << "Name: " << name << ", Employee ID: " << employeeID << ", Pay: " << calculatePay() << endl;
	}
	
protected:
	string name;
	int employeeID;
};

class CommissionEmployee : public Employee {
public:
	CommissionEmployee(const string& name, int employeeID, double commissionRate, double sales) 
	: Employee(name, employeeID), commissionRate(commissionRate), sales(sales) {}
	
	double calculatePay() const override {
		return commissionRate * sales;
	}
	
private:
	double commissionRate;
	double sales;
};

class SalaryEmployee : public Employee {
public:
	SalaryEmployee(const string& name, int employeeID, double monthlySalary) 
	: Employee(name, employeeID), monthlySalary(monthlySalary) {}
	
	double calculatePay() const override {
		return monthlySalary;
	}
	
private:
	double monthlySalary;
};

int main() {
	CommissionEmployee commissionEmp("John Doe", 101, 0.1, 5000.0);
	SalaryEmployee salaryEmp("Jane Smith", 102, 3000.0);
	
	commissionEmp.displayInfo();
	salaryEmp.displayInfo();
	
	return 0;
}
