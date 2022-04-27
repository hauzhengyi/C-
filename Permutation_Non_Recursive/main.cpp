#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, flag;
    cin >> n;
    cout << "Without recursion:" << endl;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
        vec[i] = i + 1;
    vector<int>::iterator lastSmallerElement, lastLargerElement, it;
    while(1)
    {
        flag = 0;
        for(it = vec.begin(); it != vec.end(); it++)
            cout << *it << " ";
        cout << endl;
        for(it = vec.begin(); it != vec.end() - 1; it++)
            if(*it < *(it + 1)){
                lastSmallerElement = it;
                flag = 1;
            }
        if(!flag) break;
        for(it = vec.begin(); it != vec.end(); it++)
            if(*it > *lastSmallerElement)
                lastLargerElement = it;
        swap(*lastSmallerElement, *lastLargerElement);
        reverse(lastSmallerElement + 1, vec.end());
    }
    return 0;
}
