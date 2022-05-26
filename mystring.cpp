//
// Created by Hugo-PC on 24/5/2022.
//
#include <iostream>
#include "mystring.h"

//默认构造函数以及值传递构造函数
Mystring::Mystring(const char *s) {
    if (s == nullptr) {
        m_data = new char[1];
        *m_data = '\0';
    } else {
        int length = strlen(s);
        m_data = new char[length + 1];
        strcpy(m_data, s);
    }
}

//拷贝构造函数
Mystring::Mystring(const Mystring &source) {

    int length = strlen(source.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, source.m_data);
    std::cout << "copy constructor called, new m_data is" << m_data << std::endl;
}

//实现strcpy
char *Mystring::strcpy(char *cpy, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        cpy[i] = src[i];
        i++;
    }
    cpy[i] = '\0';
    return cpy;
}

//实现strlen
int Mystring::strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

//重载输出运算符
std::ostream &operator<<(std::ostream &os, const Mystring &s) {
    os << s.m_data;
    return os;
}