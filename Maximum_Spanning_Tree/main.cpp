#include <iostream>

using namespace std;

bool visited[9] = {0};

int matrix[9][9] = {
//  {a,  b,  c,  d,  e,  f,  g,  h,  i},
    {0,  4,  0,  0,  0,  0,  0,  8,  0},
    {4,  0,  8,  0,  0,  0,  0,  8,  0},
    {0,  8,  0,  7,  0,  4,  0,  0,  2},
    {0,  0,  7,  0,  9,  14, 0,  0,  0},
    {0,  0,  0,  9,  0,  10, 0,  0,  0},
    {0,  0,  4,  14, 10, 0,  2,  0,  0},
    {0,  0,  0,  0,  0,  2,  0,  1,  6},
    {8,  8,  0,  0,  0,  0,  1,  0,  7},
    {0,  0,  2,  0,  0,  0,  6,  7,  0},
};

bool connected(int i, int j) {
    if(visited[i] || visited[j]) return true;
    else return false;
}

int main() {
    int maxTreeSpan = 0;

    for(int n = 0; n < 8; n++) {
        int maxEdge = 0, imax, jmax;
        for(int i = 0, start = 1; i < 9; i++) {
            for(int j = start; j < 9; j++) {
                if(!matrix[i][j]) continue;
                if(visited[i] && visited[j]) continue;
                if(matrix[i][j] > maxEdge && (connected(i, j) || n == 0)) {
                    maxEdge = matrix[i][j];
                    imax = i;
                    jmax = j;
                }
            }
            start++;
        }
        maxTreeSpan += maxEdge;
        visited[imax] = 1;
        visited[jmax] = 1;
    }

    cout << maxTreeSpan << endl;

    return 0;
}