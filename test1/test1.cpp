#include <iostream>

using namespace std;

class Test {
public:
    int x;
    Test& operator = (const Test& test) {
        this->x = test.x;
        return *this;
    }
    
    Test operator ++ () {
        Test temp;
        temp.x = ++x;
        return temp;
    }

    Test operator ++ (int) {
        Test temp;
        temp.x = x++;
        return temp;
    }
};

int main()
{
    Test a, b;
    a.x = 1;
    b.x = 2;
    a = b++;
    cout << a.x << endl;
    return 0;
}