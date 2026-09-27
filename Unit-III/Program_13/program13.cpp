// Program 13: Demonstrates correct derived destruction through a virtual base destructor.

#include <iostream>

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

int main() {
   Base* pointer = new Derived();
   delete pointer;
   return 0;
}
