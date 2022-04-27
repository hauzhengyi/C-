#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void perm(vector<int>& vec, int n){
    if(n == vec.size()){
        for(int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    for(int i = n; i < vec.size(); i++){
        swap(vec[n], vec[i]);
        perm(vec, n + 1);
        swap(vec[n], vec[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
        vec[i] = i + 1;
    perm(vec, 0);
    return 0;
}