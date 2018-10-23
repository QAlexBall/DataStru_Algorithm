//
// Created by alex on 10/21/18.
//

#include <iostream>
#include "mytime1.h"

Time1::Time1() {
    hours = minutes = 0;
}

Time1::Time1(int h, int m) {
    hours = h;
    minutes = m;
}

void Time1::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time1::AddHr(int h) {
    hours += h;
}

void Time1::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time1 Time1::operator+(const Time1 &t) const {
    Time1 sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time1::Show() const {
    std::cout << hours << " hours, " << minutes << " minutes";
}

Time1 Time1::operator*(double n) const {
    Time1 result;
    long totalminutes = hours * n * 60 + minutes * n;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Time1 &t) {
    os << t.hours << "hours, " << t.minutes << " minutes";
    return os;
}

