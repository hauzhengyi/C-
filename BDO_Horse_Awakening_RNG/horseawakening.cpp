#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));
    x:
    bool again = 1;
    int attempts = 0;
    float rate = 1.0;
    do {
        attempts += 1;
        int n;
        while(true) {
            n = rand();
            if(n < 30000) break;
        }
        n %= 10000; // 0-9999
        float RNG = (float)n / 100.0;
        if(RNG < rate) {
            cout << "Success " << rate << " " << RNG << endl;
            cout << "Attempts " << attempts << endl;
            break;
        }
        else {
            cout << "Failed " << rate << " " << RNG << endl;
            rate += 0.2;
        }
        //cin >> again;
    } while(again);
    cin >> again;
    if(again) goto x;
    return 0;
}