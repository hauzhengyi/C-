#include <iostream>
#include <list>

using namespace std;

bool visited[9] = {0};
bool inStack[9] = {0};

bool matrix[9][9] = {
//  {a, b, c, d, e, f, g, h, i},
    {0, 1, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 0},
};

list<int> output;

void dfs(int n) {

    list<int> stack;
    stack.push_back(n);

    while(!stack.empty()) {

        int top = stack.back();

        for(int i = 0; i < 9; i++) {
            if(!matrix[top][i]) continue;
            if(visited[i]) continue;
            stack.push_back(i);
        }

        if(top == stack.back()) {
            if(visited[top]) {
                stack.pop_back();
            }
            else {
                visited[top] = 1;
                output.push_front(stack.back());
                stack.pop_back();
            }
        }

    }

}

int main() {

    for(int i = 0; i < 9; i++) {
        if(visited[i]) continue;
        dfs(i);
    }

    for(list<int>::iterator it = output.begin(); it != output.end(); it++) {
        switch(*it) {
        case 0: cout << "a ";
                break;
        case 1: cout << "b ";
            break;
        case 2: cout << "c ";
            break;
        case 3: cout << "d ";
            break;
        case 4: cout << "e ";
            break;
        case 5: cout << "f ";
            break;
        case 6: cout << "g ";
            break;
        case 7: cout << "h ";
            break;
        case 8: cout << "i ";
            break;
        }
    }

    return 0;
}