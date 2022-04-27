#include <iostream>

using namespace std;

class Assembly{
public:
    unsigned short int n;
    int *line_1;
    int *line_2;
    int *tfer_1; //transfer cost
    int *tfer_2; //transfer cost
    int begin_1, begin_2;
    Assembly(unsigned short int n) {
        Assembly::n = n;
        line_1 = new int[n]{0};
        line_2 = new int[n]{0};
        tfer_1 = new int[n]{0}; // last element will be
        tfer_2 = new int[n]{0}; // the end costs
    }
    ~Assembly() {
        delete(line_1);
        delete(line_2);
        delete(tfer_1);
        delete(tfer_2);
    }
    void insert_line_1() {
        cout << "Line 1:" << endl;
        for(int i = 0; i < n; i++)
            cin >> line_1[i];
    }
    void insert_line_2() {
        cout << "Line 2:" << endl;
        for(int i = 0; i < n; i++)
            cin >> line_2[i];
    }
    void insert_tfer_1() {
        cout << "Transfer cost 1: " << endl;
        for(int i = 0; i < n; i++)
            cin >> tfer_1[i];
    }
    void insert_tfer_2() {
        cout << "Transfer cost 2:" << endl;
        for(int i = 0; i < n; i++)
            cin >> tfer_2[i];
    }
};
// this class is used to store the data of the assembly line

int main() {
    unsigned short int n;
    cin >> n;
    Assembly assembly(n);
    assembly.insert_line_1();
    assembly.insert_line_2();
    assembly.insert_tfer_1();
    assembly.insert_tfer_2();
    cin >> assembly.begin_1;
    cin >> assembly.begin_2;
    // getting input
    
    int cost[3][n] = {0}; // line 1 corresponds to
    int path[3][n] = {0}; // cost[1] instead of cost[0]
    // cost[] is used to store the shortest path
    // from each node to the end
    // path is used to store the next node to go to
    // in order to take the shortest path

    cost[1][n-1] = assembly.line_1[n-1] + assembly.tfer_1[n-1];
    cost[2][n-1] = assembly.line_2[n-1] + assembly.tfer_2[n-1];
    // the last two nodes are end nodes, just add them into
    // the cost of the last nodes of cost[]

    for(int i = n-2; i >= 0; i--) {
        int stay = cost[1][i+1] + assembly.line_1[i];
        // the cost to stay on the same line

        int tfer = cost[2][i+1] + assembly.line_1[i] + assembly.tfer_1[i];
        // the cost to transfer from one line 1 to line 2

        cost[1][i] = stay < tfer ? stay : tfer;
        // whichever is less costly, store them in cost[]

        path[1][i] = stay < tfer ? 1 : 2;
        // the shorter path is stored in path[]

        stay = cost[2][i+1] + assembly.line_2[i];
        tfer = cost[1][i+1] + assembly.line_2[i] + assembly.tfer_2[i];
        cost[2][i] = stay < tfer ? stay : tfer;
        path[2][i] = stay < tfer ? 2 : 1;
        // do the same for line 2
    }

    cost[1][0] += assembly.begin_1;
    cost[2][0] += assembly.begin_2;
    // add the begin cost to the first nodes

    cout << endl;
    for(int i = 1; i < 3; i++) {
        for(int j = 0; j < n-1; j++)
            cout << cost[i][j] << " ";
        cout << endl;
    }
    // output

    cout << endl;
    for(int i = 1; i < 3; i++) {
        for(int j = 0; j < n-1; j++)
            cout << path[i][j] << " ";
        cout << endl;
    }
    //output

    cout << endl;
    cout << "Minimal cost: " << min(cost[1][0], cost[2][0]) << endl;
    int next = cost[1][0] < cost[2][0] ? 1 : 2;
    cout << "Path: Begin -> " << next;
    for(int i = 0; i < n-1; i++) {
        if(next == 1) {
            next = path[1][i];
            cout << " -> " << next;
            continue;
        }
        if(next == 2) {
            next = path[2][i];
            cout << " -> " << next;
            continue;
        }
    }
    cout << " -> End";
    // output
}