//
// Created by Hugo-PC on 23/5/2022.
//

#ifndef MYSTRING_BASIC_H
#define MYSTRING_BASIC_H
class Basic{
public:
    friend std::ostream& operator<<(std::ostream& os, const Basic& b);
public:
    void basic();
    void basic(int newNum);
    int printNum();
    void setter();
    Basic operator+(const Basic& t);
    int number = 6206;
    ~Basic();
private:

};
#endif //MYSTRING_BASIC_H
