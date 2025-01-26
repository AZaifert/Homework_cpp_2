#ifndef STUDENT1_H
#define STUDENT1_H

#include "Student.h"
#include "Course.h"
#include <string>

// Max number lets say 10
#define MAX_COURSES 10

class Student1 : public Student {
private:
    Course courses[MAX_COURSES];
    int courseCount;
    int year;

public:
    Student1(const std::string& n, long i, int yr);
    virtual ~Student1() {}
    void addOrUpdateCourse(const std::string& courseName, const std::string& teacherName, int grade);

    virtual void print() const;
    virtual bool isExcellent() const;

    int getYear() const;
};

#endif //STUDENT1_H