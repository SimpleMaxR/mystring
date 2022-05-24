#include <iostream>
#include <string>
#include "basic.h"
#include "mystring.h"

using namespace std;

int main() {
    string::size_type sz;
    int num1 = stoi("123", &sz);
    int num2 = stoi("hello", &sz);
    cout << num1 << endl;
    cout << num2 << endl;
    return 0;
}