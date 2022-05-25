//
// Created by Hugo-PC on 24/5/2022.
//

#include "mystring.h"

Mystring Mystring::mystring(const char *s) {
    //默认构造函数以及值传递构造函数
    if (s == nullptr) {
        m_data = new char[1];
        *m_data = '\0';
    } else {
        int length = strlen(s);
        m_data = new char[length + 1];
        strcpy(m_data, s);
    }
}

//实现strcpy
char *Mystring::strcpy(char *copy, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}

