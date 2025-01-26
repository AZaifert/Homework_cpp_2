#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>

class Student {
protected:
    std::string name;
    long id;

public:
    Student(const std::string& n, long i): name(n), id(i) {}
    virtual ~Student() {}

    void setName(const std::string& n) {
        name = n;
    }
    void setId(long i) {
        id = i;
    }
    std::string getName() const {
        return name;
    }
    long getId() const {
        return id;
    }
    virtual void print() const = 0;
    virtual bool isExcellent() const = 0;
};

#endif //STUDENT_H