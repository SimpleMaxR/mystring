#include <iostream>
#include <cstring>
#include "basic.h"
//#include <string>
#include "mystring.h"

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
    cout << "debugMyString" << endl;
    char str[] = "the word should be 123";
    char value[] = "12345";
    cout << strpbrk(str, value) << endl;
}

int main() {
//    debugString();
    debugMyString();
    return 0;
}