// OOP with C++ - Unit II and Unit III merged program file
// Student: Pratik Bhosle | PRN: 125UAD1256 | Class/Division: SY C | Roll No.: AD2305 | Branch: AIDS
// Unit I has been removed. All Unit II and Unit III programs are preserved below.
// Run this file and select a program number from the menu.
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// ===== 1. Unit-II | Program_01/program01.cpp =====
namespace Program_1 {
// Program 01: Demonstrates single inheritance using Person as base and Student as derived class.


class Person {
protected:
     std::string name;


public:
     explicit Person(std::string personName) : name(std::move(personName)) {}


     void displayName() const {
         std::cout << "Name: " << name << '\n';
     }
};


class Student : public Person {
private:

     int rollNumber;


public:
     Student(std::string studentName, int roll)
         : Person(std::move(studentName)), rollNumber(roll) {}


     void displayStudent() const {
         displayName();
         std::cout << "Roll Number: " << rollNumber << '\n';
     }
};


int run_program_1() {
     Student student("Amit", 101);
     student.displayStudent();
     return 0;
}
}

// ===== 2. Unit-II | Program_02/program02.cpp =====
namespace Program_2 {
// Program 02: Shows access to a protected base-class member from a derived class.


class Employee {
protected:
     std::string name;


public:
     explicit Employee(std::string employeeName) : name(std::move(employeeName)) {}
};


class Developer : public Employee {
private:
     std::string language;


public:
     Developer(std::string employeeName, std::string programmingLanguage)
         : Employee(std::move(employeeName)), language(std::move(programmingLanguage)) {}


     void display() const {
         std::cout << "Developer: " << name << '\n';
         std::cout << "Language: " << language << '\n';
     }
};


int run_program_2() {
     Developer developer("Neha", "C++");
     developer.display();
     return 0;
}
}

// ===== 3. Unit-II | Program_03/program03.cpp =====
namespace Program_3 {
// Program 03: Contrasts public and private inheritance accessibility.


class Base {
public:
     void show() const {
         std::cout << "Base public function\n";
     }
};


class PublicDerived : public Base {
};


class PrivateDerived : private Base {
public:
     void callBaseShow() const {
         show();
     }
};


int run_program_3() {
     PublicDerived publicObject;
     publicObject.show();


     PrivateDerived privateObject;
     privateObject.callBaseShow();

    // privateObject.show(); // Error: show() is private through private inheritance.


    return 0;
}
}

// ===== 4. Unit-II | Program_04/program04.cpp =====
namespace Program_4 {
// Program 04: Implements a Person -> Employee -> Manager three-level hierarchy.


class Person {
protected:
    std::string name;


public:
    explicit Person(std::string personName) : name(std::move(personName)) {}


    void showPerson() const {
        std::cout << "Name: " << name << '\n';
    }

};


class Employee : public Person {
protected:
     int employeeId;


public:
     Employee(std::string employeeName, int id)
         : Person(std::move(employeeName)), employeeId(id) {}


     void showEmployee() const {
         std::cout << "Employee ID: " << employeeId << '\n';
     }
};


class Manager : public Employee {
private:
     int teamSize;


public:
     Manager(std::string managerName, int id, int size)
         : Employee(std::move(managerName), id), teamSize(size) {}


     void showManager() const {
         showPerson();
         showEmployee();
         std::cout << "Team Size: " << teamSize << '\n';
     }
};


int run_program_4() {
     Manager manager("Ravi", 501, 8);
     manager.showManager();
     return 0;

}
}

// ===== 5. Unit-II | Program_05/program05.cpp =====
namespace Program_5 {
// Program 05: Implements hierarchical inheritance with Vehicle as a common base.


class Vehicle {
protected:
     std::string registrationNumber;


public:
     explicit Vehicle(std::string registration)
         : registrationNumber(std::move(registration)) {}


     void start() const {
         std::cout << "Vehicle " << registrationNumber << " started\n";
     }
};


class Car : public Vehicle {
public:
     explicit Car(std::string registration) : Vehicle(std::move(registration)) {}


     void openBoot() const {

         std::cout << "Car boot opened\n";
     }
};


class Bike : public Vehicle {
public:
     explicit Bike(std::string registration) : Vehicle(std::move(registration)) {}


     void helmetReminder() const {
         std::cout << "Please wear a helmet\n";
     }
};


int run_program_5() {
     Car car("MH12AB1234");
     Bike bike("MH12CD5678");


     car.start();
     car.openBoot();


     bike.start();
     bike.helmetReminder();


     return 0;
}
}

// ===== 6. Unit-II | Program_06/program06.cpp =====
namespace Program_6 {
// Program 06: Demonstrates multiple inheritance from two base classes.


class Academic {
protected:
     int academicMarks;


public:
     explicit Academic(int marks) : academicMarks(marks) {}


     void showAcademic() const {
         std::cout << "Academic Marks: " << academicMarks << '\n';
     }
};


class Sports {
protected:
     int sportsMarks;


public:
     explicit Sports(int marks) : sportsMarks(marks) {}


     void showSports() const {
         std::cout << "Sports Marks: " << sportsMarks << '\n';
     }
};


class Student : public Academic, public Sports {
public:
     Student(int academic, int sports)
         : Academic(academic), Sports(sports) {}

     void showTotal() const {
         std::cout << "Total Marks: " << academicMarks + sportsMarks << '\n';
     }
};


int run_program_6() {
     Student student(80, 15);
     student.showAcademic();
     student.showSports();
     student.showTotal();
     return 0;
}
}

// ===== 7. Unit-II | Program_07/program07.cpp =====
namespace Program_7 {
// Program 07: Resolves ambiguity between same-named members of two base classes.


class Academic {
public:
     void display() const {
         std::cout << "Academic information\n";
     }
};


class Sports {
public:

     void display() const {
         std::cout << "Sports information\n";
     }
};


class Student : public Academic, public Sports {
public:
     void displayAll() const {
         Academic::display();
         Sports::display();
     }
};


int run_program_7() {
     Student student;


     student.Academic::display();
     student.Sports::display();
     student.displayAll();


     return 0;
}
}

// ===== 8. Unit-II | Program_08/program08.cpp =====
namespace Program_8 {
// Program 08: Demonstrates base/derived constructor and destructor order.


class Base {
public:
     Base() {
         std::cout << "Base constructor\n";
     }


     ~Base() {
         std::cout << "Base destructor\n";
     }
};


class Derived : public Base {
public:
     Derived() {
         std::cout << "Derived constructor\n";
     }


     ~Derived() {
         std::cout << "Derived destructor\n";
     }
};


int run_program_8() {
     Derived object;
     return 0;
}
}

// ===== 9. Unit-II | Program_09/program09.cpp =====
namespace Program_9 {
// Program 09: Initializes a parameterized base class through a derived constructor.


class Person {
protected:
     std::string name;


public:
     explicit Person(std::string personName) : name(std::move(personName)) {}
};


class Student : public Person {
private:
     int rollNumber;


public:
     Student(std::string studentName, int roll)

         : Person(std::move(studentName)), rollNumber(roll) {}


     void display() const {
         std::cout << "Name: " << name << '\n';
         std::cout << "Roll Number: " << rollNumber << '\n';
     }
};


int run_program_9() {
     Student student("Kiran", 24);
     student.display();
     return 0;
}
}

// ===== 10. Unit-II | Program_10/program10.cpp =====
namespace Program_10 {
// Program 10: Demonstrates overriding of a virtual member function.


class Vehicle {
public:
     virtual void move() const {
         std::cout << "Vehicle is moving\n";
     }


     virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
     void move() const override {
         std::cout << "Car moves on roads\n";
     }
};


class Boat : public Vehicle {
public:
     void move() const override {
         std::cout << "Boat moves on water\n";
     }
};


int run_program_10() {
     Car car;
     Boat boat;


     car.move();
     boat.move();
     return 0;
}
}

// ===== 11. Unit-II | Program_11/program11.cpp =====
namespace Program_11 {
// Program 11: Creates an abstract base class using a pure virtual function.


class Shape {
public:
     virtual double area() const = 0;
     virtual ~Shape() = default;
};


class Rectangle : public Shape {
private:
     double length;
     double width;


public:
     Rectangle(double givenLength, double givenWidth)
         : length(givenLength), width(givenWidth) {}


     double area() const override {
         return length * width;
     }
};


class Circle : public Shape {
private:
     double radius;


public:
     explicit Circle(double givenRadius) : radius(givenRadius) {}


     double area() const override {
         return 3.141592653589793 * radius * radius;
     }

};


int run_program_11() {
     Rectangle rectangle(5.0, 3.0);
     Circle circle(2.0);


     std::cout << "Rectangle Area: " << rectangle.area() << '\n';
     std::cout << "Circle Area: " << circle.area() << '\n';
     return 0;
}
}

// ===== 12. Unit-II | Program_12/program12.cpp =====
namespace Program_12 {
// Program 12: Demonstrates virtual inheritance for the diamond hierarchy.


class Person {
protected:
     std::string name;


public:
     explicit Person(std::string personName) : name(std::move(personName)) {}

     void displayName() const {
         std::cout << "Name: " << name << '\n';
     }
};


class Student : virtual public Person {
public:
     Student() : Person("Unknown") {}
};


class Employee : virtual public Person {
public:
     Employee() : Person("Unknown") {}
};


class TeachingAssistant : public Student, public Employee {
public:
     explicit TeachingAssistant(std::string assistantName)
         : Person(std::move(assistantName)), Student(), Employee() {}
};


int run_program_12() {
     TeachingAssistant assistant("Riya");
     assistant.displayName();
     return 0;
}
}

// ===== 13. Unit-II | Program_13/program13.cpp =====
namespace Program_13 {
// Program 13: Demonstrates special access using a friend class.


class Account {
private:
     double balance;


     friend class Auditor;


public:
     explicit Account(double initialBalance) : balance(initialBalance) {}
};


class Auditor {
public:
     void inspect(const Account& account) const {
         std::cout << "Account Balance: " << account.balance << '\n';
     }
};


int run_program_13() {
     Account account(5000.0);
     Auditor auditor;

    auditor.inspect(account);
    return 0;
}
}

// ===== 14. Unit-II | Program_14/program14.cpp =====
namespace Program_14 {
// Program 14: Creates and uses a nested class inside another class.


class University {
public:
    class Department {
    private:
         std::string name;


    public:
         explicit Department(std::string departmentName)
             : name(std::move(departmentName)) {}


         void display() const {
             std::cout << "Department: " << name << '\n';
         }
    };

};


int run_program_14() {
     University::Department department("Artificial Intelligence and Data Science");
     department.display();
     return 0;
}
}

// ===== 15. Unit-II | Program_15/program15.cpp =====
namespace Program_15 {
// Program 15: Builds a vehicle rental application using inheritance and overriding.


class Vehicle {
protected:
     std::string registrationNumber;
     double ratePerDay;


public:
     Vehicle(std::string registration, double rate)
         : registrationNumber(std::move(registration)), ratePerDay(rate) {}


     virtual double calculateRent(int days) const {
         return ratePerDay * days;
     }


     virtual void display() const {

         std::cout << "Registration: " << registrationNumber << '\n';
         std::cout << "Rate per day: " << ratePerDay << '\n';
     }


     virtual ~Vehicle() = default;
};


class Car : public Vehicle {
private:
     int numberOfDoors;


public:
     Car(std::string registration, double rate, int doors)
         : Vehicle(std::move(registration), rate), numberOfDoors(doors) {}


     void display() const override {
         Vehicle::display();
         std::cout << "Doors: " << numberOfDoors << '\n';
     }
};


class Bike : public Vehicle {
private:
     int engineCapacity;


public:
     Bike(std::string registration, double rate, int capacity)
         : Vehicle(std::move(registration), rate), engineCapacity(capacity) {}


     double calculateRent(int days) const override {
         return ratePerDay * days * 0.9;
     }


     void display() const override {

         Vehicle::display();
         std::cout << "Engine Capacity: " << engineCapacity << " cc\n";
     }
};


int run_program_15() {
     Car car("MH12AB1234", 2000.0, 5);
     Bike bike("MH12CD5678", 800.0, 150);


     std::cout << "Car Details\n";
     car.display();
     std::cout << "Rent for 3 days: " << car.calculateRent(3) << "\n\n";


     std::cout << "Bike Details\n";
     bike.display();
     std::cout << "Rent for 3 days: " << bike.calculateRent(3) << '\n';


     return 0;
}
}

// ===== 16. Unit-II | Program_16/program16.cpp =====
namespace Program_16 {
// Program 16: Builds an employee payroll system using an abstract base class and overriding.


class Employee {
protected:
     int employeeId;
     std::string name;


public:
     Employee(int id, std::string employeeName)
         : employeeId(id), name(std::move(employeeName)) {}


     virtual double calculateSalary() const = 0;


     void displayBasicDetails() const {
         std::cout << "Employee ID: " << employeeId << '\n';
         std::cout << "Name: " << name << '\n';
     }


     virtual ~Employee() = default;
};


class PermanentEmployee : public Employee {

private:
     double basicSalary;
     double allowance;


public:
     PermanentEmployee(int id, std::string employeeName, double basic, double extra)
         : Employee(id, std::move(employeeName)), basicSalary(basic), allowance(extra) {}


     double calculateSalary() const override {
         return basicSalary + allowance;
     }
};


class ContractEmployee : public Employee {
private:
     double hourlyRate;
     int hoursWorked;


public:
     ContractEmployee(int id, std::string employeeName, double rate, int hours)
         : Employee(id, std::move(employeeName)), hourlyRate(rate), hoursWorked(hours) {}


     double calculateSalary() const override {
         return hourlyRate * hoursWorked;
     }
};


void displayPaySlip(const Employee& employee) {
     employee.displayBasicDetails();
     std::cout << "Salary: " << employee.calculateSalary() << "\n\n";
}


int run_program_16() {
     PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0);

     ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);


     displayPaySlip(permanentEmployee);
     displayPaySlip(contractEmployee);


     return 0;
}
}

// ===== 17. Unit-II | Real-Time-Applications/01_employee_payroll_system/main.cpp =====
namespace Program_17 {
// Real-Time Application: 01 Employee Payroll System
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


int run_program_17() {
     FullTimeEmployee f1(101, "Amit", "IT", 65000);
     PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);
     Intern i1(103, "Rohan", "Marketing", 15000);


     cout << "=== Employee Payroll ===" << endl;
     f1.display();
     p1.display();
     i1.display();
}
}

// ===== 18. Unit-II | Real-Time-Applications/02_digital_payment_gateway/main.cpp =====
namespace Program_18 {
// Real-Time Application: 02 Digital Payment Gateway
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



int run_program_18() {
    vector<unique_ptr<PaymentMethod>> payments;
    payments.push_back(make_unique<CreditCardPayment>("TXN001", 2500, "XXXX-XXXX-1234"));
    payments.push_back(make_unique<UPIPayment>("TXN002", 1200, "student@upi"));
    payments.push_back(make_unique<NetBankingPayment>("TXN003", 5000, "Example Bank"));


    cout << "=== Payment Gateway ===" << endl;
    for (const auto& payment : payments) {
        payment->processPayment();
    }
}
}

// ===== 19. Unit-II | Real-Time-Applications/03_vehicle_fleet_management/main.cpp =====
namespace Program_19 {
// Real-Time Application: 03 Vehicle Fleet Management
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


int run_program_19() {
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
}

// ===== 20. Unit-III | Program_01/program01.cpp =====
namespace Program_20 {
// Program 01: Demonstrates compile-time polymorphism through function overloading.

int add(int first, int second) {
   return first + second;
}

double add(double first, double second) {
  return first + second;
}

int add(int first, int second, int third) {
   return first + second + third;
}

int run_program_20() {
   std::cout << "Sum of two integers: " << add(10, 20) << '\n';
   std::cout << "Sum of two doubles: " << add(2.5, 3.7) << '\n';
   std::cout << "Sum of three integers: " << add(10, 20, 30) << '\n';






    return 0;
}
}

// ===== 21. Unit-III | Program_02/program02.cpp =====
namespace Program_21 {
// Program 02: Calculates areas using overloaded functions for different shapes.

int calculateArea(int side) {
   return side * side;
}

int calculateArea(int length, int width) {
   return length * width;
}

double calculateArea(double radius) {
  constexpr double PI = 3.141592653589793;
  return PI * radius * radius;
}

int run_program_21() {
   std::cout << "Square Area: " << calculateArea(5) << '\n';
   std::cout << "Rectangle Area: " << calculateArea(6, 4) << '\n';
   std::cout << "Circle Area: " << calculateArea(2.0) << '\n';

    return 0;
}
}

// ===== 22. Unit-III | Program_03/program03.cpp =====
namespace Program_22 {
// Program 03: Overloads unary minus for a user-defined Number class.

class Number {
private:
   int value;

public:
  explicit Number(int givenValue) : value(givenValue) {}

     Number operator-() const {
       return Number(-value);
     }

     void display() const {
       std::cout << value << '\n';
     }
};

int run_program_22() {
   Number first(25);
   Number second = -first;

     std::cout << "Original value: ";
     first.display();

     std::cout << "Negated value: ";
     second.display();

     return 0;
}
}

// ===== 23. Unit-III | Program_04/program04.cpp =====
namespace Program_23 {
// Program 04: Overloads prefix and postfix increment operators.

class Counter {
private:
   int value;

public:
  explicit Counter(int initialValue = 0) : value(initialValue) {}

     Counter& operator++() {
       ++value;
       return *this;
     }

     Counter operator++(int) {
       Counter old = *this;
       ++value;
       return old;
     }

     void display() const {
       std::cout << value << '\n';
     }
};

int run_program_23() {
   Counter counter(5);

     std::cout << "After prefix increment: ";
     ++counter;
     counter.display();

     std::cout << "Value returned by postfix increment: ";
     Counter oldValue = counter++;





     oldValue.display();

     std::cout << "Counter after postfix increment: ";
     counter.display();

     return 0;
}
}

// ===== 24. Unit-III | Program_05/program05.cpp =====
namespace Program_24 {
// Program 05: Overloads the binary + operator for complex numbers.

class Complex {
private:
   int real;
   int imaginary;

public:
  Complex(int realPart = 0, int imaginaryPart = 0)
     : real(realPart), imaginary(imaginaryPart) {}

     Complex operator+(const Complex& other) const {
       return Complex(real + other.real, imaginary + other.imaginary);
     }

     void display() const {
       std::cout << real;
       if (imaginary >= 0) {
           std::cout << " + ";
       } else {
           std::cout << " - ";
       }
       std::cout << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
     }
};






int run_program_24() {
   Complex first(2, 3);
   Complex second(4, 5);
   Complex sum = first + second;

    std::cout << "First complex number: ";
    first.display();

    std::cout << "Second complex number: ";
    second.display();

    std::cout << "Sum: ";
    sum.display();

    return 0;
}
}

// ===== 25. Unit-III | Program_06/program06.cpp =====
namespace Program_25 {
// Program 06: Overloads a relational operator for user-defined Distance objects.

class Distance {
private:
   int meters;

public:
  explicit Distance(int value) : meters(value) {}

    bool operator>(const Distance& other) const {
      return meters > other.meters;
    }

    void display() const {
      std::cout << meters << " meters\n";
    }




};

int run_program_25() {
   Distance first(120);
   Distance second(90);

     std::cout << "First distance: ";
     first.display();

     std::cout << "Second distance: ";
     second.display();

     if (first > second) {
         std::cout << "First distance is greater\n";
     } else {
         std::cout << "Second distance is greater or equal\n";
     }

     return 0;
}
}

// ===== 26. Unit-III | Program_07/program07.cpp =====
namespace Program_26 {
// Program 07: Demonstrates operator overloading through a non-member/friend function.

class Complex {
private:
   int real;
   int imaginary;

public:
  Complex(int realPart = 0, int imaginaryPart = 0)
     : real(realPart), imaginary(imaginaryPart) {}

     friend Complex operator+(int value, const Complex& number);

     void display() const {
       std::cout << real;
       if (imaginary >= 0) {




            std::cout << " + ";
         } else {
            std::cout << " - ";
         }
         std::cout << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
     }
};

Complex operator+(int value, const Complex& number) {
  return Complex(value + number.real, number.imaginary);
}

int run_program_26() {
   Complex number(2, 3);
   Complex result = 10 + number;

     std::cout << "Result: ";
     result.display();

     return 0;
}
}

// ===== 27. Unit-III | Program_08/program08.cpp =====
namespace Program_27 {
// Program 08: Demonstrates static binding through a base pointer and non-virtual function.

class Base {
public:
   void display() const {
     std::cout << "Base display function\n";
   }
};

class Derived : public Base {
public:
   void display() const {
     std::cout << "Derived display function\n";
   }
};

int run_program_27() {
   Derived derivedObject;
   Base* basePointer = &derivedObject;

     basePointer->display();




     return 0;
}
}

// ===== 28. Unit-III | Program_09/program09.cpp =====
namespace Program_28 {
// Program 09: Demonstrates run-time polymorphism through a base pointer and virtual function.

class Animal {
public:
   virtual void sound() const {
      std::cout << "Animal makes a sound\n";
   }

     virtual ~Animal() = default;
};

class Dog : public Animal {
public:
   void sound() const override {
     std::cout << "Dog barks\n";
   }
};

class Cat : public Animal {
public:
   void sound() const override {
     std::cout << "Cat meows\n";
   }
};

int run_program_28() {
   Dog dog;
   Cat cat;

     Animal* animal = &dog;
     animal->sound();

     animal = &cat;
     animal->sound();

     return 0;






}
}

// ===== 29. Unit-III | Program_10/program10.cpp =====
namespace Program_29 {
// Program 10: Uses a base reference for dynamic dispatch.

class Shape {
public:
   virtual double area() const {
      return 0.0;
   }

     virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
   double length;
   double width;

public:
  Rectangle(double givenLength, double givenWidth)
     : length(givenLength), width(givenWidth) {}

     double area() const override {
       return length * width;
     }
};

class Circle : public Shape {
private:
   double radius;

public:
  explicit Circle(double givenRadius) : radius(givenRadius) {}

     double area() const override {
       constexpr double PI = 3.141592653589793;
       return PI * radius * radius;
     }




};

void printArea(const Shape& shape) {
  std::cout << "Area: " << shape.area() << '\n';
}

int run_program_29() {
   Rectangle rectangle(5.0, 3.0);
   Circle circle(2.0);

     printArea(rectangle);
     printArea(circle);

     return 0;
}
}

// ===== 30. Unit-III | Program_11/program11.cpp =====
namespace Program_30 {
// Program 11: Creates an abstract class with a pure virtual function.

class Shape {
public:
   virtual double area() const = 0;
   virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
   double length;
   double width;

public:
  Rectangle(double givenLength, double givenWidth)
     : length(givenLength), width(givenWidth) {}

     double area() const override {
       return length * width;
     }
};

int run_program_30() {




     Rectangle rectangle(8.0, 4.0);
     std::cout << "Rectangle Area: " << rectangle.area() << '\n';
     return 0;
}
}

// ===== 31. Unit-III | Program_12/program12.cpp =====
namespace Program_31 {
// Program 12: Processes derived shape objects through a polymorphic base pointer collection.

class Shape {
public:
   virtual double area() const = 0;
   virtual void displayName() const = 0;
   virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
   double length;
   double width;

public:
  Rectangle(double givenLength, double givenWidth)
     : length(givenLength), width(givenWidth) {}

     double area() const override {
       return length * width;
     }

     void displayName() const override {
       std::cout << "Rectangle";
     }
};

class Circle : public Shape {
private:
   double radius;






public:
  explicit Circle(double givenRadius) : radius(givenRadius) {}

     double area() const override {
       constexpr double PI = 3.141592653589793;
       return PI * radius * radius;
     }

     void displayName() const override {
       std::cout << "Circle";
     }
};

int run_program_31() {
   std::vector<std::unique_ptr<Shape>> shapes;
   shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0));
   shapes.push_back(std::make_unique<Circle>(2.0));

     for (const auto& shape : shapes) {
        shape->displayName();
        std::cout << " Area: " << shape->area() << '\n';
     }

     return 0;
}
}

// ===== 32. Unit-III | Program_13/program13.cpp =====
namespace Program_32 {
// Program 13: Demonstrates correct derived destruction through a virtual base destructor.

class Base {
public:
   virtual ~Base() {
      std::cout << "Base destructor\n";
   }
};

class Derived : public Base {
public:




     ~Derived() override {
       std::cout << "Derived destructor\n";
     }
};

int run_program_32() {
   Base* pointer = new Derived();
   delete pointer;
   return 0;
}
}

// ===== 33. Unit-III | Program_14/program14.cpp =====
namespace Program_33 {
// Program 14: Demonstrates object slicing and why references preserve polymorphic behavior.

class Base {
public:
   virtual void display() const {
      std::cout << "Base object\n";
   }

     virtual ~Base() = default;
};

class Derived : public Base {
public:
   void display() const override {
     std::cout << "Derived object\n";
   }
};

void displayByValue(Base object) {
  object.display();
}

void displayByReference(const Base& object) {




    object.display();
}

int run_program_33() {
   Derived derived;

    std::cout << "Passing by value: ";
    displayByValue(derived);

    std::cout << "Passing by reference: ";
    displayByReference(derived);

    return 0;
}
}

// ===== 34. Unit-III | Program_15/program15.cpp =====
namespace Program_34 {
// Program 15: Implements a polymorphic payment-processing interface.

class Payment {
public:
   virtual void pay(double amount) const = 0;
   virtual ~Payment() = default;
};

class CardPayment : public Payment {
public:
   void pay(double amount) const override {
     std::cout << "Paid Rs. " << amount << " using card\n";
   }
};

class UpiPayment : public Payment {
public:
   void pay(double amount) const override {
     std::cout << "Paid Rs. " << amount << " using UPI\n";
   }
};






class NetBankingPayment : public Payment {
public:
   void pay(double amount) const override {
     std::cout << "Paid Rs. " << amount << " using net banking\n";
   }
};

void processPayment(const Payment& payment, double amount) {
  payment.pay(amount);
}

int run_program_34() {
   CardPayment card;
   UpiPayment upi;
   NetBankingPayment netBanking;

    processPayment(card, 1250.0);
    processPayment(upi, 750.0);
    processPayment(netBanking, 500.0);

    return 0;
}
}

// ===== 35. Unit-III | Program_16/program16.cpp =====
namespace Program_35 {
// Program 16: Builds an employee payroll mini-project using run-time polymorphism.

class Employee {
protected:
   int employeeId;
   std::string name;





public:
  Employee(int id, std::string employeeName)
     : employeeId(id), name(std::move(employeeName)) {}

     virtual double calculateSalary() const = 0;

     void displayBasicDetails() const {
       std::cout << "Employee ID: " << employeeId << '\n';
       std::cout << "Name: " << name << '\n';
     }

     virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
private:
   double basicSalary;
   double allowance;

public:
  PermanentEmployee(int id, std::string employeeName, double basic, double extra)
     : Employee(id, std::move(employeeName)), basicSalary(basic), allowance(extra) {}

     double calculateSalary() const override {
       return basicSalary + allowance;
     }
};

class ContractEmployee : public Employee {
private:
   double hourlyRate;
   int hoursWorked;

public:
  ContractEmployee(int id, std::string employeeName, double rate, int hours)
     : Employee(id, std::move(employeeName)), hourlyRate(rate), hoursWorked(hours) {}

     double calculateSalary() const override {
       return hourlyRate * hoursWorked;
     }
};

void printPaySlip(const Employee& employee) {
  employee.displayBasicDetails();
  std::cout << "Salary: Rs. " << employee.calculateSalary() << "\n\n";
}

int run_program_35() {
   PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0);
   ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);

     printPaySlip(permanentEmployee);
     printPaySlip(contractEmployee);

     return 0;




}
}

// ===== 36. Unit-III | Real-Time-Applications/01_cad_shape_drawing_system/main.cpp =====
namespace Program_36 {
// Real-Time Application: 01 Cad Shape Drawing System
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


int run_program_36() {
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
}

// ===== 37. Unit-III | Real-Time-Applications/02_complex_number_calculator/main.cpp =====
namespace Program_37 {
// Real-Time Application: 02 Complex Number Calculator
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


int run_program_37() {



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
}

// ===== 38. Unit-III | Real-Time-Applications/03_input_validation_service/main.cpp =====
namespace Program_38 {
// Real-Time Application: 03 Input Validation Service
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


int run_program_38() {
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
}

int main() {
    cout << "\n=== OOP C++ Unit II & Unit III ===\n";
    cout << "Unit I removed | 38 programs merged into this single file.\n\n";
    cout << "Enter program number (1-38), or 0 to exit.\n";
    int choice;
    while (true) {
        cout << "\nProgram number: ";
        if (!(cin >> choice)) return 0;
        if (choice == 0) break;
        switch (choice) {
            case 1: Program_1::run_program_1(); break;
            case 2: Program_2::run_program_2(); break;
            case 3: Program_3::run_program_3(); break;
            case 4: Program_4::run_program_4(); break;
            case 5: Program_5::run_program_5(); break;
            case 6: Program_6::run_program_6(); break;
            case 7: Program_7::run_program_7(); break;
            case 8: Program_8::run_program_8(); break;
            case 9: Program_9::run_program_9(); break;
            case 10: Program_10::run_program_10(); break;
            case 11: Program_11::run_program_11(); break;
            case 12: Program_12::run_program_12(); break;
            case 13: Program_13::run_program_13(); break;
            case 14: Program_14::run_program_14(); break;
            case 15: Program_15::run_program_15(); break;
            case 16: Program_16::run_program_16(); break;
            case 17: Program_17::run_program_17(); break;
            case 18: Program_18::run_program_18(); break;
            case 19: Program_19::run_program_19(); break;
            case 20: Program_20::run_program_20(); break;
            case 21: Program_21::run_program_21(); break;
            case 22: Program_22::run_program_22(); break;
            case 23: Program_23::run_program_23(); break;
            case 24: Program_24::run_program_24(); break;
            case 25: Program_25::run_program_25(); break;
            case 26: Program_26::run_program_26(); break;
            case 27: Program_27::run_program_27(); break;
            case 28: Program_28::run_program_28(); break;
            case 29: Program_29::run_program_29(); break;
            case 30: Program_30::run_program_30(); break;
            case 31: Program_31::run_program_31(); break;
            case 32: Program_32::run_program_32(); break;
            case 33: Program_33::run_program_33(); break;
            case 34: Program_34::run_program_34(); break;
            case 35: Program_35::run_program_35(); break;
            case 36: Program_36::run_program_36(); break;
            case 37: Program_37::run_program_37(); break;
            case 38: Program_38::run_program_38(); break;
            default: cout << "Invalid program number. Choose 1-38.\n"; break;
        }
    }
    cout << "Exiting...\n";
    return 0;
}
