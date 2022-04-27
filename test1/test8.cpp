#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A" << endl;
    }
};

class B : virtual public A {
public:
    B() {
        cout << "B" << endl;
    }
};

class C: virtual public A {
public:
    C() {
        cout << "C" << endl;
    }
};

class D: virtual public B, virtual public C {
public:
    D() {
        cout << "D" << endl;
    }
};

class E: virtual public B, virtual public C {
public:
    E() {
        cout << "E" << endl;
    }
};

class F: public D, public E {
public:
    F() {
        cout << "F" << endl;
    }
};

int main()
{
    F f;
    return 0;
}