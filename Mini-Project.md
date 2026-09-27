# Unit I Mini-Project

Smart Home Device Manager
Model smart devices such as lights, thermostats, cameras, and door locks. Each device should
have a device ID, location, status, and last-updated time. Implement operations to switch devices
on or off, change status, and display an overall home dashboard.



Unit II: Inheritance
Syllabus Coverage
  •   Base and derived classes
  •   Protected members
  •   Relationship between base and derived classes
  •   Constructors and destructors in derived classes
  •   Overriding member functions
  •   Class hierarchies
  •   Public and private inheritance
  •   Types of inheritance
  •   Multiple-inheritance ambiguity
  •   Virtual base classes
  •   Abstract classes
  •   Friend classes
  •   Nested classes
Industry Relevance
Inheritance helps build extensible software where related entities share common properties and
operations. It is useful for modeling class hierarchies in domains such as employee systems,
vehicles, payment methods, document types, user roles, devices, games, and framework plug-ins.
In industry, inheritance is used carefully; composition is preferred where an object merely contains
another object rather than being a specialized form of it.



Real-Time Application 1: Employee Payroll System
Problem Scenario
A company employs full-time employees, part-time employees, and interns. All employees share
common information, but salary calculations vary by employment type.
OOP Concepts Used
 •   Base class and derived classes
 •   Protected members
 •   Hierarchical inheritance
 •   Constructor chaining
 •   Function overriding
 •   Abstract base class
Live Example
#include <iostream>
#include <string>
using namespace std;


class Employee {
protected:
  int empId;
  string name;
  string department;


public:
  Employee(int id, string n, string dept)
     : empId(id), name(n), department(dept) {}


  void displayBasicInfo() const {
     cout << "ID: " << empId
          << " | Name: " << name



            << " | Department: " << department;
     }


     virtual double calculateSalary() const = 0;
     virtual ~Employee() = default;
};


class FullTimeEmployee : public Employee {
private:
     double monthlySalary;


public:
     FullTimeEmployee(int id, string n, string dept, double salary)
         : Employee(id, n, dept), monthlySalary(salary) {}


     double calculateSalary() const override {
         return monthlySalary;
     }


     void display() const {
         displayBasicInfo();
         cout << " | Type: Full-Time | Salary: Rs. "
            << calculateSalary() << endl;
     }
};


class PartTimeEmployee : public Employee {
private:
     double hourlyRate;
     int hoursWorked;



public:
     PartTimeEmployee(int id, string n, string dept, double rate, int hours)
         : Employee(id, n, dept), hourlyRate(rate), hoursWorked(hours) {}


     double calculateSalary() const override {
         return hourlyRate * hoursWorked;
     }


     void display() const {
         displayBasicInfo();
         cout << " | Type: Part-Time | Salary: Rs. "
            << calculateSalary() << endl;
     }
};


class Intern : public Employee {
private:
     double stipend;


public:
     Intern(int id, string n, string dept, double stipendAmount)
         : Employee(id, n, dept), stipend(stipendAmount) {}


     double calculateSalary() const override {
         return stipend;
     }


     void display() const {
         displayBasicInfo();
         cout << " | Type: Intern | Stipend: Rs. "
            << calculateSalary() << endl;



     }
};


int main() {
     FullTimeEmployee f1(101, "Amit", "IT", 65000);
     PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);
     Intern i1(103, "Rohan", "Marketing", 15000);


     cout << "=== Employee Payroll ===" << endl;
     f1.display();
     p1.display();
     i1.display();
}


Real-Time Application 2: Digital Payment Gateway
Problem Scenario
A payment gateway supports credit-card, UPI, net-banking, and wallet payments. All payment
modes implement a common processing interface.
OOP Concepts Used
    •    Abstract class
    •    Hierarchical inheritance
    •    Pure virtual function
    •    Virtual destructor
    •    Runtime polymorphism
Live Example
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;




class PaymentMethod {
protected:
     string transactionId;
     double amount;


public:
     PaymentMethod(string tid, double amt)
         : transactionId(tid), amount(amt) {}


     virtual bool processPayment() const = 0;
     virtual ~PaymentMethod() = default;
};


class CreditCardPayment : public PaymentMethod {
private:
     string maskedCardNumber;


public:
     CreditCardPayment(string tid, double amt, string card)
         : PaymentMethod(tid, amt), maskedCardNumber(card) {}


     bool processPayment() const override {
         cout << "Credit-card transaction " << transactionId
            << " for Rs. " << amount
            << " using " << maskedCardNumber << " completed." << endl;
         return true;
     }
};


class UPIPayment : public PaymentMethod {



private:
     string upiId;


public:
     UPIPayment(string tid, double amt, string upi)
         : PaymentMethod(tid, amt), upiId(upi) {}


     bool processPayment() const override {
         cout << "UPI transaction " << transactionId
            << " for Rs. " << amount
            << " from " << upiId << " completed." << endl;
         return true;
     }
};


class NetBankingPayment : public PaymentMethod {
private:
     string bankName;


public:
     NetBankingPayment(string tid, double amt, string bank)
         : PaymentMethod(tid, amt), bankName(bank) {}


     bool processPayment() const override {
         cout << "Net-banking transaction " << transactionId
            << " for Rs. " << amount
            << " through " << bankName << " completed." << endl;
         return true;
     }
};



int main() {
    vector<unique_ptr<PaymentMethod>> payments;
    payments.push_back(make_unique<CreditCardPayment>("TXN001", 2500, "XXXX-XXXX-
1234"));
    payments.push_back(make_unique<UPIPayment>("TXN002", 1200, "student@upi"));
    payments.push_back(make_unique<NetBankingPayment>("TXN003", 5000, "Example
Bank"));


    cout << "=== Payment Gateway ===" << endl;
    for (const auto& payment : payments) {
        payment->processPayment();
    }
}


Real-Time Application 3: Vehicle Fleet Management
Problem Scenario
A logistics company manages trucks, delivery vans, and delivery bikes. All are vehicles with
common identity and fuel attributes, while each has specialized properties.
OOP Concepts Used
    •   Base and derived classes
    •   Hierarchical inheritance
    •   Function overriding
    •   Virtual functions
    •   Protected data
Live Example
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;




class Vehicle {
protected:
     string vehicleId;
     string registrationNumber;
     double fuelLevel;


public:
     Vehicle(string vid, string reg)
         : vehicleId(vid), registrationNumber(reg), fuelLevel(100.0) {}


     void startEngine() const {
         cout << "Vehicle " << vehicleId << " engine started." << endl;
     }


     void refuel(double amount) {
         fuelLevel += amount;
         if (fuelLevel > 100.0) {
             fuelLevel = 100.0;
         }
     }


     virtual void displayInfo() const {
         cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%" << endl;
     }


     virtual ~Vehicle() = default;
};



class Truck : public Vehicle {
private:
     double cargoCapacity;


public:
     Truck(string vid, string reg, double capacity)
         : Vehicle(vid, reg), cargoCapacity(capacity) {}


     void displayInfo() const override {
         cout << "Truck | ";
         Vehicle::displayInfo();
         cout << "Cargo capacity: " << cargoCapacity << " tonnes" << endl;
     }
};


class DeliveryVan : public Vehicle {
private:
     int packageCount;


public:
     DeliveryVan(string vid, string reg, int packages)
         : Vehicle(vid, reg), packageCount(packages) {}


     void displayInfo() const override {
         cout << "Delivery Van | ";
         Vehicle::displayInfo();
         cout << "Packages loaded: " << packageCount << endl;
     }
};


class Bike : public Vehicle {



private:
     bool hasDeliveryBox;


public:
     Bike(string vid, string reg, bool hasBox)
         : Vehicle(vid, reg), hasDeliveryBox(hasBox) {}


     void displayInfo() const override {
         cout << "Delivery Bike | ";
         Vehicle::displayInfo();
         cout << "Delivery box: " << (hasDeliveryBox ? "Available" : "Not available") << endl;
     }
};


int main() {
     vector<unique_ptr<Vehicle>> fleet;
     fleet.push_back(make_unique<Truck>("V001", "MH12-AB-1234", 10.5));
     fleet.push_back(make_unique<DeliveryVan>("V002", "MH12-CD-5678", 50));
     fleet.push_back(make_unique<Bike>("V003", "MH12-EF-9012", true));


     cout << "=== Fleet Status ===" << endl;
     for (const auto& vehicle : fleet) {
         vehicle->startEngine();
         vehicle->displayInfo();
         cout << endl;
     }
}



Unit II Mini-Project
Banking System with Account Hierarchy
Create a base Account class and derived classes SavingsAccount, CurrentAccount, and
FixedDepositAccount. Include account number, holder name, balance, deposit, withdrawal, and
interest-calculation features. Use virtual functions for account-specific behavior.



Unit III: Polymorphism
Syllabus Coverage
 •   Introduction to polymorphism
 •   Types of polymorphism
 •   Operator overloading
 •   Unary and binary operator overloading
 •   Function overloading
 •   Run-time polymorphism
 •   Base-class pointers
 •   Virtual functions
 •   Pure virtual functions and virtual tables
 •   Virtual destructors
 •   Abstract base classes
Industry Relevance
Polymorphism enables extensible systems. It is valuable in graphics engines, user-interface
frameworks, configurable payment systems, document processors, simulation systems, media
applications, and plug-in architectures. Function and operator overloading make APIs clearer
when used consistently and without surprising behavior.
Real-Time Application 1: CAD Shape Drawing System
Problem Scenario
A computer-aided design application handles circles, rectangles, and triangles. Each shape is
drawn and its area is calculated through a common base-class interface.
OOP Concepts Used
 •   Abstract base class
 •   Pure virtual functions
 •   Runtime polymorphism
 •   Vector of smart pointers
 •   Virtual destructor



Live Example
#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Shape {
public:
     virtual double area() const = 0;
     virtual void draw() const = 0;
     virtual ~Shape() = default;
};


class Circle : public Shape {
private:
     double radius;


public:
     explicit Circle(double r) : radius(r) {}


     double area() const override {
         return 3.14159265359 * radius * radius;
     }


     void draw() const override {
         cout << "Drawing circle with radius " << radius << endl;
     }
};


class Rectangle : public Shape {
private:



     double length;
     double width;


public:
     Rectangle(double l, double w) : length(l), width(w) {}


     double area() const override {
         return length * width;
     }


     void draw() const override {
         cout << "Drawing rectangle " << length << " x " << width << endl;
     }
};


class Triangle : public Shape {
private:
     double base;
     double height;


public:
     Triangle(double b, double h) : base(b), height(h) {}


     double area() const override {
         return 0.5 * base * height;
     }


     void draw() const override {
         cout << "Drawing triangle with base " << base
            << " and height " << height << endl;
     }



};


int main() {
     vector<unique_ptr<Shape>> shapes;
     shapes.push_back(make_unique<Circle>(5.0));
     shapes.push_back(make_unique<Rectangle>(4.0, 6.0));
     shapes.push_back(make_unique<Triangle>(3.0, 8.0));


     cout << "=== CAD Shape System ===" << endl;
     for (const auto& shape : shapes) {
         shape->draw();
         cout << "Area: " << shape->area() << " square units" << endl;
     }
}


Real-Time Application 2: Complex Number Calculator
Problem Scenario
Engineering, signal processing, and simulation applications use complex numbers. Operator
overloading allows arithmetic expressions to be written naturally.
OOP Concepts Used
    •    Binary operator overloading
    •    Constructor with default arguments
    •    Constant member functions
    •    Encapsulation
Live Example
#include <iostream>
using namespace std;


class Complex {
private:



     double real;
     double imag;


public:
     Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}


     Complex operator+(const Complex& other) const {
         return Complex(real + other.real, imag + other.imag);
     }


     Complex operator-(const Complex& other) const {
         return Complex(real - other.real, imag - other.imag);
     }


     Complex operator*(const Complex& other) const {
         return Complex(
              real * other.real - imag * other.imag,
              real * other.imag + imag * other.real
         );
     }


     bool operator==(const Complex& other) const {
         return real == other.real && imag == other.imag;
     }


     void display() const {
         cout << real << " + " << imag << "i" << endl;
     }
};


int main() {



    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);


    cout << "C1: ";
    c1.display();
    cout << "C2: ";
    c2.display();


    cout << "Sum: ";
    (c1 + c2).display();


    cout << "Difference: ";
    (c1 - c2).display();


    cout << "Product: ";
    (c1 * c2).display();
}


Real-Time Application 3: Input Validation Service
Problem Scenario
A business application validates different kinds of user data, including marks, names, and payment
amounts. Function overloading offers a common, readable validate() interface.
OOP Concepts Used
    •   Function overloading
    •   Compile-time polymorphism
    •   String processing
    •   Input validation
Live Example
#include <cctype>
#include <iostream>



#include <string>
using namespace std;


class Validator {
public:
     bool validate(int marks) const {
         return marks >= 0 && marks <= 100;
     }


     bool validate(double amount) const {
         return amount > 0.0 && amount <= 1000000.0;
     }


     bool validate(const string& name) const {
         if (name.empty()) {
             return false;
         }


         for (char ch : name) {
             if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ') {
                 return false;
             }
         }
         return true;
     }
};


int main() {
     Validator validator;


     cout << boolalpha;



    cout << "Marks 88 valid: " << validator.validate(88) << endl;
    cout << "Marks 120 valid: " << validator.validate(120) << endl;
    cout << "Amount 4500.50 valid: " << validator.validate(4500.50) << endl;
    cout << "Name Priya Sharma valid: "
       << validator.validate(string("Priya Sharma")) << endl;
    cout << "Name Priya123 valid: "
       << validator.validate(string("Priya123")) << endl;
}


Unit III Mini-Project
Media Player with Polymorphic Controls
Create a base class Media with derived classes Audio, Video, and Image. Provide operations such
as play(), pause(), stop(), and showDetails(). Manage media items using a collection of base-class
pointers.
