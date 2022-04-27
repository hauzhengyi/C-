#include <iostream>

using namespace std;

class Class {
public:
    Class();
    void func(Class object) {
        cout << "non-const" << endl;
    }
    void func(Class object) const { //overloading by const
        cout << "const" << endl;
    }
};

Class::Class() {
    cout << "Hello" << endl;
}

int main() {
    const Class object;
    object.func(object);
    return 0;
}