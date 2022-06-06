#include <iostream>
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

    Mystring s2("Hello");

    Mystring s5(s2, 1);
    cout << "s5: " << s5 << endl;

}

int main() {
//    debugString();
    debugMyString();
    return 0;
}