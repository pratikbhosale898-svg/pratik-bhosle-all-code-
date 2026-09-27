// Program 06: Demonstrates automatic constructor initialization and destructor cleanup.

#include <iostream>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Constructor called\n";
    }

    ~Demo() {
        cout << "Destructor called\n";
    }
};

int main() {
    Demo d;
    return 0;
}
