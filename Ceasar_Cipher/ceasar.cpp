#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

static int shift = 26;

int shiftFunc(int n) {
    return (n + shift) % 256;
}

int main() {
    string str;
    string src = "../../../Archives/linksource.txt";
    string dst = "../../../Archives/linkdest.txt";
    string tmp;
    ifstream source;
    ofstream dest;
    bool option;
    bool end;

    cout << "0. encrypt" << endl;
    cout << "1. decrypt" << endl;
    cin >> option;

    if(option) { // swap strings
        src.swap(dst);
        shift = -shift;
    }

    source.open(src);
    if(!source.is_open()) {
        cout << "source file not found" << endl;
        goto exit;
    }
    dest.open(dst);
    if(!dest.is_open()) {
        cout << "destination file creation error" << endl;
        goto exit;
    }

    while(getline(source, str)) {
        transform(str.begin(), str.end(), str.begin(), shiftFunc);
        dest << str << endl;
    }

    source.close();
    dest.close();

    if(!remove(src.c_str())) cout << "file deletion successful" << endl; // c_str converts string to const char*
    else cout << "file deletion failed" << endl;

    exit:
    cin >> end;

    return 0;
}