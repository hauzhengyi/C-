#include <iostream>
#include <cstring>

using namespace std;

class Class {
public:
    int x = 1;
    void operator ++ (int) {
        cout << "post-increment" << endl;
        x++;
    }
    //wrong way
    void operator ++ () {
        cout << "pre-increment" << endl;
        ++x;
    }
    //wrong way

    Class operator * (const Class& obj) {
        Class temp;
        temp.x = this->x * obj.x;
        return temp;
    }
    //one way to overload

    friend Class operator + (const Class& obj1, const Class& obj2);
    //another (better) way to overload
    //ensures that both objects are not modified

    void operator += (const Class& obj) {
        *this = *this + obj;
    }

    friend void display(const Class& obj);
};

void display(const Class& obj) {
    cout << obj.x << endl;
}

Class operator + (const Class& obj1, const Class& obj2) {
    Class temp;
    temp.x = obj1.x + obj2.x;
    return temp;
}

int main() {
    Class obj1, obj2;
    obj1++;
    ++obj2;
    display(obj1 + obj2);
    obj1 += obj2;
    display(obj1);
    display(obj1 * obj2);
}