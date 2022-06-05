//
// Created by Hugo-PC on 24/5/2022.
//
#include<iostream>

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H


class Mystring {
    friend std::ostream &operator<<(std::ostream &os, const Mystring &s);

    friend std::istream &operator>>(std::istream &is, Mystring &s);

    friend Mystring &operator+(const Mystring &left, const Mystring &right);

    friend bool operator==(const Mystring &left, const Mystring &right);

    friend bool operator!=(const Mystring &left, const Mystring &right);

    friend bool operator>(const Mystring &left, const Mystring &right);

    friend bool operator<(const Mystring &left, const Mystring &right);

    friend bool operator<=(const Mystring &left, const Mystring &right);

    friend bool operator>=(const Mystring &left, const Mystring &right);

public://    运算符重载
    Mystring &operator+=(const Mystring &s);

    Mystring operator=(const Mystring &);

public:
    Mystring();

    Mystring(const char *s);

    Mystring(const Mystring &source);

    char operator[](size_t index) const;

    char &operator[](size_t index);


//<cstring>的24个功能  https://m.cplusplus.com/reference/cstring/
public:
//    Copying:
    void *memcpy(const Mystring source, size_t num);

    void *memmove(void *dest, const void *source, size_t count);

    char *strcpy(char *copy, const char *src);

    char *strncpy(char *destination, const char *source, size_t num);

//    Concatenation:

    char *strcat(const char *source);

    char *strncat(char *destination, const char *source, size_t num);

//    Comparison:

    int memcmp(const void *ptr1, const void *ptr2, size_t num);

    int strcmp(const char *str1, const char *str2);

    int strcoll(const char *str1, const char *str2);

    int strncmp(const char *str1, const char *str2, size_t num);

    size_t strxfrm(char *destination, const char *source, size_t num);

//    Searching:

    void *memchr(const void *ptr, int value, size_t num);

    char *strchr(const char *str, int character);

    size_t strcspn(const char *str1, const char *str2);

    char *strpbrk(char *str1, const char *str2);

    char *strrchr(const char *str, int value);

    size_t strspn(const char *str1, const char *str2);

    char *strstr(const char *str1, const char *str2);

    char *strtok(char *str, const char *delimiters);

//    2、实现以下功能。（共9个）。功能描述与使用见：http://www.cplusplus.com/reference/string/
//      Convert from strings
    int stoi(const char *str, size_t *idx, int base);

    long stol(const char *str, size_t *idx, int base);

    unsigned long stoul(const Mystring &str, size_t *idx = 0, int base = 10);

    long strtol(const char *str, char **endptr, int base);

    unsigned long int strtoul(const char *str, char **endptr, int base);


//    other
    void *memset(void *ptr, int value, size_t num);

    size_t strlen() const;

    size_t strlen(const char *str);

    char *strerror(int errnum);

public:
    ~Mystring();

private:
    char *m_data;
};

#endif //MYSTRING_MYSTRING_H
