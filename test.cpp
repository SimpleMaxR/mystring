//
// Created by Hugo-PC on 5/6/2022.
//

#include "test.h"
#include "mystring.h"
#include <iostream>

using namespace std;

void test::test_inputoutput() {
    Mystring s1;
    cin >> s1;
    cout << s1 << endl;
}

void test::test_constructor() {
    Mystring s1("Hello");
    cout << s1 << endl;
}

void test::test_copyConstructor() {
    Mystring s1("Hello");
    Mystring s2(s1);
    cout << s2 << endl;
}

void test::test_memcpy() {
    Mystring s1;
    Mystring s2("hello");
    s1.memcpy(s2, 3);//調用方法的对象将作为destination
    cout << s1 << endl;
}

//TODO 加号运算符未重载
void test::test_memmove() {
//    Mystring s1 = "memmove can be very useful......";
//    s1.memmove(s1 + 15, s1 + 20, +15);
//    puts (str);
//    return 0;
}

void test::test_strtol() {

    char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
    char *pEnd;
    long int li1, li2, li3, li4;
    li1 = li2 = li3 = li4 = 0;
    li1 = strtol(szNumbers, &pEnd, 10);
    li2 = strtol(pEnd, &pEnd, 16);
    li3 = strtol(pEnd, &pEnd, 2);
    li4 = strtol(pEnd, NULL, 0);
    printf("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
}


