//
// Created by Hugo-PC on 24/5/2022.
//
#include<iostream>
#include <iterator>


#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H


class Mystring {
    friend std::ostream &operator<<(std::ostream &os, const Mystring &s);

    friend std::istream &operator>>(std::istream &is, Mystring &s);

    friend Mystring &operator+(const Mystring &left, const Mystring &right);

    friend Mystring &operator+(const Mystring &lhs, char rhs);

    friend Mystring &operator+(const Mystring &lhs, const char *rhs);

    friend Mystring &operator+(char lhs, const Mystring &rhs);

    friend Mystring &operator+(const char *lhs, const Mystring &rhs);

    friend bool operator==(const Mystring &left, const Mystring &right);

    friend bool operator==(const char *left, const Mystring &right);

    friend bool operator==(const Mystring &left, const char *right);

    friend bool operator!=(const Mystring &left, const Mystring &right);

    friend bool operator!=(const char *left, const Mystring &right);

    friend bool operator!=(const Mystring &left, const char *right);

    friend bool operator>(const Mystring &left, const Mystring &right);

    friend bool operator>(const char *left, const Mystring &right);

    friend bool operator>(const Mystring &left, const char *right);

    friend bool operator<(const Mystring &left, const Mystring &right);

    friend bool operator<(const char *left, const Mystring &right);

    friend bool operator<(const Mystring &left, const char *right);

    friend bool operator<=(const Mystring &left, const Mystring &right);

    friend bool operator<=(const char *left, const Mystring &right);

    friend bool operator<=(const Mystring &left, const char *right);

    friend bool operator>(const Mystring &left, const Mystring &right);

    friend bool operator>(const char *left, const Mystring &right);

    friend bool operator>(const Mystring &left, const char *right);

    friend bool operator>=(const Mystring &left, const Mystring &right);

    friend bool operator>=(const char *left, const Mystring &right);

    friend bool operator>=(const Mystring &left, const char *right);


//1. <cstring>的24个功能  https://m.cplusplus.com/reference/cstring/
public:
//    Copying:
    void *memcpy(void *dest, const void *src, size_t num);

    void *memmove(void *dest, const void *source, size_t count);

    char *strcpy(char *copy, const char *src);

    char *strncpy(char *destination, const char *source, size_t num) const;

//    Concatenation:

    char *strcat(char *destination, const char *source);

    char *strncat(char *destination, const char *source, size_t num);

//    Comparison:

    int memcmp(const void *ptr1, const void *ptr2, size_t num);

    int strcmp(const char *str1, const char *str2);

    int strcoll(const char *str1, const char *str2);

    int strncmp(const char *str1, const char *str2, size_t num);

    size_t strxfrm(char *destination, const char *source, size_t num);

//    Searching:

    void *memchr(const void *ptr, int value, size_t num) const;

    char *strchr(const char *str, int character) const;

    size_t strcspn(const char *str1, const char *str2) const;

    char *strpbrk(char *str1, const char *str2) const;

    char *strrchr(const char *str, int value) const;

    size_t strspn(const char *str1, const char *str2) const;

    char *strstr(const char *str1, const char *str2) const;

    char *strtok(char *str, const char *delimiters);

//    2、实现以下功能。（共9个）。功能描述与使用见：http://www.cplusplus.com/reference/string/
//      Convert from strings
    int stoi(const char *str, size_t *idx, int base);

    long stol(const char *str, size_t *idx, int base);

    unsigned long stoul(const Mystring &str, size_t *idx = 0, int base = 10);

    long long stoll(const Mystring &str, size_t *idx = 0, int base = 10);

    unsigned long long stoull(const Mystring &str, size_t *idx = 0, int base = 10);

    float stof(const Mystring &str, size_t *idx = 0);

    double stod(const Mystring &str, size_t *idx = 0);

    long double stold(const Mystring &str, size_t *idx = 0);

    long strtol(const char *str, char **endptr, int base);

    unsigned long int strtoul(const char *str, char **endptr, int base);

// 3、Construct string object。（共6个）。功能描述与使用见：http://www.cplusplus.com/reference/string/string/string/ (

    Mystring();

    Mystring(const Mystring &str);

    Mystring(const Mystring &str, size_t pos, size_t len = npos);

    Mystring(const char *s);

    Mystring(const char *s, size_t n);

    Mystring(size_t n, char c);

//    4、实现以下功能。（共40个）功能描述与使用见：http://www.cplusplus.com/reference/string/string/

public:
    Mystring &operator=(const Mystring &);

    Mystring &operator=(const char *str);

    Mystring &operator=(char c);

////    Iterator begin();

////    Iterator end();

////    Reverse iterator rbegin();

////    Reverse iterator rend();

////    const_iterator cbegin() const noexcept;

////    const_iterator cend() const noexcept;

////    const_reverse_iterator crbegin() const noexcept;

////    const_reverse_iterator crend() const noexcept;

//Capacity:
    size_t size() const;

    size_t length() const;

    size_t max_size() const;

    void resize(size_t n, char c);

    void resize(size_t n);

    size_t capacity() const;

    void reserve(Mystring s, size_t n = 0);

    void reserve(size_t n = 0);

    void clear();

    bool empty() const;

    void shrink_to_fit();

//Element access:
    char operator[](size_t index) const;

    char &operator[](size_t index);

    char &at(size_t pos);

    const char &at(size_t pos) const;

    char &back();

    const char &back() const;

    char &front();

    const char &front() const;

//Modifiers:
    Mystring &operator+=(const Mystring &str);

    Mystring &operator+=(const char *&s);

    Mystring &operator+=(char c);

    Mystring &append(Mystring &first, const Mystring &last);

    Mystring &append(Mystring &first, const Mystring &str, size_t subpos, size_t sublen);

    Mystring &append(Mystring &first, const char *s);

    Mystring &append(Mystring &first, const char *s, size_t n);

    Mystring &append(Mystring &first, size_t n, char c);

    template<class InputIterator>
    Mystring &append(InputIterator first, InputIterator last);

    void push_back(char c);

    void push_back(Mystring &s, char c);

    Mystring &assign(Mystring &first, const Mystring &str);

    Mystring &assign(Mystring &first, const Mystring &str, size_t subpos, size_t sublen);

    Mystring &assign(Mystring &first, const char *s);

    Mystring &assign(Mystring &first, const char *s, size_t n);

    Mystring &assign(Mystring &first, size_t n, char c);

    template<class InputIterator>
    Mystring &assign(InputIterator first, InputIterator last);

    Mystring &insert(size_t pos, const Mystring &str, Mystring &first);

    Mystring &insert(Mystring &first, size_t pos, const Mystring &str, size_t subpos, size_t sublen);

    Mystring &insert(Mystring &first, size_t pos, const char *s);

    Mystring &insert(Mystring &first, size_t pos, const char *s, size_t n);

    Mystring &insert(Mystring &first, size_t pos, size_t n, char c);

    Mystring &erase(size_t pos = 0, size_t len = npos);

    Mystring &replace(size_t pos, size_t len, const Mystring &str);

    Mystring &replace(size_t pos, size_t len, const Mystring str, size_t subpos, size_t sublen);

    Mystring &replace(size_t pos, size_t len, const char *s);

    Mystring &replace(size_t pos, size_t len, const char *s, size_t n);

    Mystring &replace(size_t pos, size_t len, size_t n, char c);

//    Mystring &replace(iterator i1, iterator i2, size_t n, char c);
//
//    template<class InputIterator>
//    Mystring &replace(iterator i1, iterator i2, InputIterator first, InputIterator last);

    void pop_back();

    void pop_back(Mystring &s);

//    String operations:
    char *const c_str() const;

    const char *data() const;

    size_t copy(Mystring &src, char *s, size_t len, size_t pos = 0);

    size_t find(const Mystring &str, size_t pos = 0) const;

    size_t find(const char *s, size_t pos) const;

    size_t find(const char *s, size_t pos, size_t n) const;

    size_t find(char c, size_t pos = 0) const;

    size_t rfind(const Mystring &str, size_t pos = npos) const;

    size_t rfind(const char *s, size_t pos = npos) const;

    size_t rfind(const char *s, size_t pos, size_t n) const;

    size_t rfind(char c, size_t pos = npos) const;

    size_t find_first_of(const Mystring &str, size_t pos = 0) const;

    size_t find_first_of(const char *s, size_t pos = 0) const;

    size_t find_first_of(const char *s, size_t pos, size_t n) const;

    size_t find_first_of(char c, size_t pos = 0) const;


    size_t find_last_of(const Mystring &str, size_t pos = npos) const;

    size_t find_last_of(const char *s, size_t pos = npos) const;

    size_t find_last_of(const char *s, size_t pos, size_t n) const;

    size_t find_last_of(char c, size_t pos = npos) const;


    size_t find_first_not_of(const Mystring &str, size_t pos = 0) const;

    size_t find_first_not_of(const char *s, size_t pos = 0) const;

    size_t find_first_not_of(const char *s, size_t pos, size_t n) const;

    size_t find_first_not_of(char c, size_t pos = 0) const;

    size_t find_last_not_of(const Mystring &str, size_t pos = npos) const;

    size_t find_last_not_of(const char *s, size_t pos = npos) const;

    size_t find_last_not_of(const char *s, size_t pos, size_t n) const;

    size_t find_last_not_of(char c, size_t pos = npos) const;

    Mystring substr(size_t pos = 0, size_t len = npos) const;

    int compare(const Mystring &str) const;

    int compare(size_t pos, size_t len, const Mystring &str) const;

    int compare(size_t pos, size_t len, const Mystring &str, size_t subpos, size_t sublen) const;

    int compare(const char *s) const;

    int compare(size_t pos, size_t len, const char *s) const;

    int compare(size_t pos, size_t len, const char *s, size_t n) const;

    int compare(const char *str1, const char *str2) const;

    void swap(Mystring &str);

    void swap(Mystring &str, Mystring &str2);

    std::istream &getline(std::istream &is, Mystring &str, char delim = '\n');

    std::istream &getline(std::istream &is, Mystring &str);


    //    other
    void *memset(void *ptr, int value, size_t num);

    size_t strlen() const;

    size_t strlen(const char *str);

    size_t strlen(const char *str) const;

    char *strerror(int errnum);

    char *strrstr(char *string, const char *str) const;

    char *strrpbrk(char *string, const char *const str) const;

public:
    ~Mystring();

private:
    char *m_data;//    指向字符串的指针
    static const size_t npos = -1;//    表示不存在的位置
    size_t m_length;//    字符串长度
    size_t m_capacity;//    字符串容量

    inline void setNewCapacity(size_t newCapacity);

    void
    void setNewCapacity(size_t newCapacity, Mystring s);
    void setNewLength(size_t newLength);
    void setNewLength(size_t newLength, Mystring s);


};

#endif //MYSTRING_MYSTRING_H
