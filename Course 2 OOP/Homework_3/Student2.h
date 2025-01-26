#ifndef STUDENT2_H
#define STUDENT2_H

#include "Student.h"
#include <string>

class Student2 : public Student {
private:
    std::string thesis;
    std::string supervisor;

public:
    Student2(const std::string& n, long i, const std::string& th, const std::string& sup);
    virtual ~Student2(){}
    virtual void print() const;
    virtual bool isExcellent() const;
    std::string getSupervisor() const;
};

#endif //STUDENT2_H