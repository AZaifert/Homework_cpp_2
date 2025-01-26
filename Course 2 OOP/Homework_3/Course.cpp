#include "Course.h"

Course::Course() : name(""), lecturer(""), grade(0) {}

Course::Course(const std::string& name, const std::string& lecturer, int grade)
    : name(name), lecturer(lecturer), grade(grade) {}

std::string Course::getName() const {
    return name;
}

void Course::setName(const std::string& name) {
    this->name = name;
}

std::string Course::getLecturer() const {
    return lecturer;
}

void Course::setLecturer(const std::string& lecturer) {
    this->lecturer = lecturer;
}

int Course::getGrade() const {
    return grade;
}

void Course::setGrade(int grade) {
    this->grade = grade;
}