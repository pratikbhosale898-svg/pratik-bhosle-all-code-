// Program 08: Demonstrates an inline getter and a friend function accessing private data.

#include <iostream>
using namespace std;

class Test {
private:
    int value;

public:
    Test(int v) : value(v) {}

    inline int getValue() {
        return value;
    }

    friend void show(Test t);
};

void show(Test t) {
    cout << t.value;
}

int main() {
    Test obj(50);
    cout << obj.getValue() << endl;
    show(obj);
    return 0;
}
