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
    memmove(str + 10, str + 15, 11);
    memcpy(str + 10, str + 15, 11);
    puts(str);
}

int main() {
//    debugString();
    debugMyString();
    return 0;
}