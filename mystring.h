//
// Created by Hugo-PC on 24/5/2022.
//

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H

class Mystring {
public:
    Mystring mystring(const char *s = nullptr);

    char *strcpy(char *dest, const char *src);

private:
    char *m_data;
};

#endif //MYSTRING_MYSTRING_H
