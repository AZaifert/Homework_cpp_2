#ifndef COLLEGE_H
#define COLLEGE_H
#include "Student.h"
#include <string>

#define MAX_STUDENTS 10

class College {
private:
    Student* students[MAX_STUDENTS];
    int studentCount;

public:
    College();
    ~College();

    bool add_student();
    bool add_grade(long studentId, const std::string& courseName, const std::string& lecturer, int grade) const;
    void print_all() const;
    void print_excellent() const;
    void find_types() const;
    void supervisor(const std::string& supervisorName) const;
    Student* findStudentById(long id) const;

    void menu();
};

#endif //COLLEGE_H