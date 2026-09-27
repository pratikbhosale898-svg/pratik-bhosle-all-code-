// Program 03: Uses an array and loop to print five student marks.

#include <iostream>
using namespace std;

int main() {
    int marks[5] = {78, 82, 91, 67, 88};
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }
    return 0;
}
