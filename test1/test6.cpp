#include <iostream>
#include <cstring>

using namespace std;

class Class {
public:
    int x;
    int y;
    Class(int x = 1, int y = 2) {
        this->x = x;
        this->y = y;
    }

    operator int() const {
        return (int)x + (int)y;
    }
};

int main() {
    Class obj(0, 0);
    obj = 3;
    //assign int to obj constructs obj(3)
    cout << obj.x << endl;
    cout << obj.y << endl;
    //case

    cout << (int)obj << endl;
    //case
}