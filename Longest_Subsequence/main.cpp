#include <iostream>

using namespace std;

int main() {
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    int matrix[str1.size()][str2.size()] = {0};

    for(int i = 0; i < str1.size(); i++) {
        for(int j = 0; j < str2.size(); j++) {
            if(str1[i] == str2[j])
                matrix[i][j] = (i > 0 && j > 0) ? matrix[i-1][j-1] + 1 : 1;
                // if the elements match, take the element
                // from the top-left and add 1
            else {
                int x, y;
                x = i > 0 ? matrix[i-1][j] : 0;
                y = j > 0 ? matrix[i][j-1] : 0;
                matrix[i][j] = x > y ? x : y;
                // if the elements don't match, take
                // the top and left elements, compare
                // and take the larger one
            }
        }
    }

    for(int i = 0; i < str1.size(); i++) {
        for(int j = 0; j < str2.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Longest subsequence: " << matrix[str1.size() - 1][str2.size() - 1];
    return 0;
}