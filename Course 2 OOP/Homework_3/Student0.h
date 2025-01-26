#ifndef STUDENT0_H
#define STUDENT0_H

#include "Student.h"

class Student0 : public Student {
private:
    bool is_short;

public:
    Student0(const std::string& n, long i, bool isShort): Student(n, i), is_short(isShort) {}
    virtual ~Student0() {}
    virtual void print() const;
    virtual bool isExcellent() const;
};

#endif //STUDENT0_H