//
// Created by Hugo-PC on 24/5/2022.
//
#include <iostream>
#include "mystring.h"
//默认构造函数
Mystring::Mystring() {
    m_data = new char[1];
    *m_data = '\0';
}

//值传递构造函数
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


//实现strlen
int strlen(const char *s) {
    int i = 0;
    //遍历字符串，直到遇到结束符
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

//重载输入运算符
std::istream &operator>>(std::istream &is, Mystring &s) {
    is >> s.m_data;
    return is;
}

//实现memcpy
void *Mystring::memcpy(void *destination, const void *source, size_t num) {
    char *d = (char *) destination;
    char *s = (char *) source;
    for (int i = 0; i < num; i++) {
        d[i] = s[i];
    }
    return destination;
}

//实现memmove
void *memmove(void *destination, const void *source, size_t num) {
    char *d = (char *) destination;
    char *s = (char *) source;
    if (d < s) {
        for (int i = 0; i < num; i++) {
            d[i] = s[i];
        }
    } else {
        for (int i = num - 1; i >= 0; i--) {
            d[i] = s[i];
        }
    }
    return destination;
}

//实现strcpy
char *Mystring::strcpy(char *cpy, const char *src) {
    int i = 0;
    //拷贝原字符串到目标字符串
    while (src[i] != '\0') {
        cpy[i] = src[i];
        i++;
    }
    cpy[i] = '\0';
    return cpy;
}

//实现strncpy
char *strncpy(char *destination, const char *source, size_t num) {
    int i = 0;
    //拷贝源字符串中num个字符到目标字符串
    while (source[i] != '\0' && i < num) {
        destination[i] = source[i];
        i++;
    }
    //将目标字符串中剩余的字符设置为'\0'
    while (i < num) {
        destination[i] = '\0';
        i++;
    }
    return destination;
}

//实现strcat
char *strcat(char *destination, const char *source) {
    int i = 0;
    int j = 0;
    //找到字符串的末尾
    while (destination[i] != '\0') {
        i++;
    }
    //拷贝字符串
    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }
    destination[i] = '\0';
    return destination;
}

//实现strncat
char *strncat(char *destination, const char *source, size_t num) {
    int i = 0;
    //定位到最后一个字符
    while (destination[i] != '\0') {
        i++;
    }
    int j = 0;
    //拷贝num个字符
    while (source[j] != '\0' && j < num) {
        destination[i] = source[j];
        i++;
        j++;
    }
    destination[i] = '\0';
    return destination;
}

//实现memcmp
int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    char *p1 = (char *) ptr1;
    char *p2 = (char *) ptr2;
    for (int i = 0; i < num; i++) {
        if (p1[i] > p2[i]) {
            return 1;
        } else if (p1[i] < p2[i]) {
            return -1;
        }
    }
    return 0;
}

//strcmp
int strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return -1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else if (str1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}