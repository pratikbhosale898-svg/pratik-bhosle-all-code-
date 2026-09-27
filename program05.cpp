// Program 05: Models student details using a class, object and member function.

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;

    void show() {
        cout << name << " " << age << endl;
    }
};

int main() {
    Student s1;
    s1.name = "Amit";
    s1.age = 20;
    s1.show();
    return 0;
}
