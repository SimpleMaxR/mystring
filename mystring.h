//
// Created by Hugo-PC on 24/5/2022.
//
#include<iostream>

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H


class Mystring {
    friend std::ostream &operator<<(std::ostream &os, const Mystring &s);

    friend std::istream &operator>>(std::istream &is, Mystring &s);

public:
    Mystring();

    Mystring(const char *s);

    Mystring(const Mystring &source);

//<cstring>的24个功能
public:
    void *memcpy(void *destination, const void *source, size_t num);

    void *memmove(void *destination, const void *source, size_t num);

    char *strcpy(char *copy, const char *src);

    char *strncpy(char *destination, const char *source, size_t num);

    char *strcat(char *destination, const char *source);

    char *strncat(char *destination, const char *source, size_t num);

    int memcmp(const void *ptr1, const void *ptr2, size_t num);

    int strcmp(const char *str1, const char *str2);

    int strcoll(const char *str1, const char *str2);

    int strncmp(const char *str1, const char *str2, size_t num);

    size_t strxfrm(char *destination, const char *source, size_t num);

public:
    int strlen(const char *s);

private:
    char *m_data;
};

#endif //MYSTRING_MYSTRING_H
