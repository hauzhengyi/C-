#include <iostream>

using namespace std;

struct matrix{
    int row;
    int col;
};

int main()
{
    int n;
    cout << "Chain length: ";
    cin >> n;
    struct matrix chain[n];
    cout << "Dimensions: " << endl;
    for(int i = 0; i < n; i++){
        cin >> chain[i].row;
        cin >> chain[i].col;
    }

    int minimum_cost[n][n] = {0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(j >= i) minimum_cost[i][j] = 2147483647;

    int root_place[n][n] = {0};
    for(int length = 0; length < n; length++){
        for(int curr = 0; curr < n - length; curr++){
            if(length == 0)
                minimum_cost[curr][curr+length] = 0;
            else{
                for(int root = curr; root < curr + length; root++){
                    int cost = minimum_cost[curr][root] + minimum_cost[root+1][curr+length] + chain[curr].row * chain[root].col * chain[curr+length].col;
                    if(cost < minimum_cost[curr][curr+length]){
                        minimum_cost[curr][curr+length] = cost;
                        root_place[curr][curr+length] = root;
                    }
                }
            }
        }
    }

    cout << "\nCosts:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << minimum_cost[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nRoots:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << root_place[i][j] << "\t";
        }
        cout << endl;
    }
}
