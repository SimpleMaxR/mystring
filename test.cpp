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
    Mystring s1;
    Mystring s2("Hello");
    Mystring s3(s2);
    Mystring s4(s2, 1, 3);
    Mystring s5(s2, 1);
    Mystring s6(2, 'a');
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;
    cout << "s6: " << s6 << endl;
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

void test::test_stoi() {
    Mystring a;
    const char *str_dec = "2001, A Space Odyssey";
    const char *str_hex = "40c3";
    const char *str_bin = "-10010110001";
    const char *str_auto = "0x7f";

    size_t *p;

    int i_dec = a.stoi(str_dec, p, 0);
    int i_hex = a.stoi(str_hex, nullptr, 16);
    int i_bin = a.stoi(str_bin, nullptr, 2);
    int i_auto = a.stoi(str_auto, nullptr, 0);

//    cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n"; //TODO substr未完成
    cout << str_hex << ": " << i_hex << '\n';
    cout << str_bin << ": " << i_bin << '\n';
    cout << str_auto << ": " << i_auto << '\n';
}

void test::test_stol() {
    Mystring a;
    const char *str_dec = "2001, A Space Odyssey";
    const char *str_hex = "40c3";
    const char *str_bin = "-10010110001";
    const char *str_auto = "0x7f";

    size_t *p;

    long i_dec = a.stol(str_dec, p, 0);
    long i_hex = a.stol(str_hex, nullptr, 16);
    long i_bin = a.stol(str_bin, nullptr, 2);
    long i_auto = a.stol(str_auto, nullptr, 0);
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


