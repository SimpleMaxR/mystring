//
// Created by Hugo-PC on 24/5/2022.
//

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H

class Mystring {
public:
    Mystring(const char *s);

public:
    char *strcpy(char *dest, const char *src);

    int strlen(const char *s);

private:
    char *m_data;
};

#endif //MYSTRING_MYSTRING_H
