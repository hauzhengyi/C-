#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x;
    vector<int> vec;
    while(cin >> x)
        vec.push_back(x);
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    return 0;
}