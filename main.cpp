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
//    t.test_strpbrk();
    t.test_strchr();


}

int main() {
//    debugString();
    debugMyString();
//Mystring s1;
//    char str16[] = "This is a sample string";
//    char key2[] = "aeiou";
//    char* pch2;
//    cout << "Vowels in \"" << str16 << "\" : ";
//    pch2 = s1.strpbrk(str16, key2);
//
//
//    while (pch2 != nullptr)
//    {
//        cout << *pch2 << ' ';
//        pch2 = s1.strpbrk(pch2 + 1, key2);
//    }
//    cout << endl;
//    return 0;
}