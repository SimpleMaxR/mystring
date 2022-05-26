//
// Created by Hugo-PC on 24/5/2022.
//

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H

class Mystring {
    friend std::ostream &operator<<(std::ostream &os, const Mystring &s);

    friend std::istream &operator>>(std::istream &is, Mystring &s);

public:
    Mystring(const char *s);

    Mystring(const Mystring &source);

public:
    char *strcpy(char *copy, const char *src);

    int strlen(const char *s);

private:
    char *m_data;
};

#endif //MYSTRING_MYSTRING_H
