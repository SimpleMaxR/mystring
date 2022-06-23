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
    t.test_strpbrk();
    t.test_strrchr();
    t.test_strspn();
    t.test_strchr();
    t.test_strtok();
    t.test_size();
    t.test_resize();
    t.test_shrink_to_fit();
    t.test_at();
    t.test_back();
    t.test_front();
    t.test_append();
    t.test_erase();
    t.test_replace();
    t.test_popback();
    t.test_c_str();
    t.test_data();
    t.test_copy();
    t.test_find();
    t.test_find_first_of();

}

void debugMyString() {
    test t;
    Mystring s1 = "Hello";
//    t.test_reserve();
//    t.test_clear();
//    t.test_empty();
//      t.test_insert();
//    t.test_rfind();
    t.test_find_first_not_of();
//    t.test_find_last_of();



}


int main() {
    debugMyString();
}