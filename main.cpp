#include <iostream>
//#include <cstring>
//#include "basic.h"
//#include <string>
#include "mystring.h"
#include "test.h"

using namespace std;

struct {
    char name[40];
    int age;
} person, person_copy;

void debugString() {
//    string s1;
//    cin >> s1;
//    cout << s1 << endl;
}

void debugMyString() {
    test t;
//    t.test_strtol();
    t.test_stoi();
}

int main() {
//    debugString();
    debugMyString();
    return 0;
}