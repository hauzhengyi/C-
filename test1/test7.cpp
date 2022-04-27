#include <iostream>

using namespace std;

class A {
public:
    int x = 1;
    virtual void display() {
        cout << x << endl;
    }
    A(int x) {
        this->x = x;
    }
    virtual A& operator = (const A& a) {
        this->x = a.x;
        return *this;
    }
};

class B : public A {
public:
    int y = 2;
    void display() {
        cout << y << endl;
        cout << x << endl;
    }
    B& operator = (const A& a) {
        A::operator=(a);
        return *this;
    }
    virtual B& operator = (const B& b) {
        A::operator=(b);
        this->y = b.y;
        return *this;
    }
    B(int y, int x) : A(x) {
        this->y = y;
    }
};

class C : public B {
public:
    int z;
    void display() {
        cout << z << endl;
        cout << y << endl;
        cout << x << endl;
    }
    C& operator = (const A& a) {
        A::operator=(a);
        return *this;
    }
    C& operator = (const B& b) {
        B::operator=(b);
        return *this;
    }
    C& operator = (const C& c) {
        B::operator=(c);
        this->z = c.z;
        return *this;
    }
    C(int z, int y, int x) : B(y, x) {
        this->z = z;
    }
};


void function(A& obj) {
    obj.display();
}

int main () {
    B *bPtr = new C(3, 2, 1);
    A a(10);
    B b(101, 100);
    *bPtr = b;
    bPtr->display();
}