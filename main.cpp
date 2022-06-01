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
    string s1;
    cin >> s1;
    cout << s1 << endl;
}

void debugMyString() {
    cout << "debugMyString" << endl;
    char str[] = "memmove can be very useful......";
    char s1[] = "12345";
    char s2[] = "abc12";
    cout << strpbrk(s1, s2) << endl;
}

int main() {
//    debugString();
    debugMyString();
    return 0;
}