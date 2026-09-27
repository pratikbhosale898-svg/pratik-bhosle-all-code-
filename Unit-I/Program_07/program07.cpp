// Program 07: Counts created objects using a static class data member.

#include <iostream>
using namespace std;

class Student {
public:
    static int count;

    Student() {
        count++;
    }
};

int Student::count = 0;

int main() {
    Student s1, s2, s3;
    cout << Student::count;
    return 0;
}
