//
// Created by Hugo-PC on 23/5/2022.
//
#include <iostream>
#include "basic.h"

using namespace std;

void Basic::basic() {
    cout << "basic func start" << endl;
}

void Basic::basic(int newNum) {
    this->number = newNum;
}

Basic::~Basic() {
    delete this;
}

int Basic::printNum() {
    return number;
}

void Basic::setter() {
    cin >> this->number;
}

Basic Basic::operator+(const Basic &t) {
    Basic temp;
    temp.number = this->number + t.number;
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Basic &b) {
    os << b.number;
    return os;
}
