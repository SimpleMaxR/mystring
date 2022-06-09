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

void debugPass() {
    test t;
    t.test_memcpy();
    t.test_strcpy();
    t.test_strncpy();
    t.test_strcat();
    t.test_strncat();
    t.test_memcmp();
    t.test_strncmp();
    t.test_strxfrm();
    t.test_memchr();
    t.test_strchr();
    t.test_strcspn();


}

void debugMyString() {
    test t;
    Mystring s1 = "Hello";
    t.test_append();


}

int main() {
    debugMyString();
}