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
    //strlen用来检查字符串长度，标准函数声明 : size_t strlen(const char *str);

    Mystring a;                //方法一：为了调用函数，要先创建一个对象a
    const char *s1("hello");
    a.strlen(s1);

    Mystring s2("hello");   //方法二：更符合使用直觉，但函数声明和标准库定义的不一样
    s2.strlen();

    test t;
    t.test_strtol();
}

int main() {
//    debugString();
    debugMyString();
    return 0;
}