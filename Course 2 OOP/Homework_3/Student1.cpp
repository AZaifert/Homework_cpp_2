#include "Student1.h"
#include <iostream>
#define YEAR1_2_EXCELLENT 90.0
#define YEAR3_4_EXCELLENT 85.0

#define MAX_COURSES 10

Student1::Student1(const std::string& n, long i, int yr) : Student(n, i), courseCount(0), year(yr) {}

void Student1::addOrUpdateCourse(const std::string& courseName, const std::string& lecturer, int grade) {

    for (int index = 0; index < courseCount; index++) {
        if (courses[index].getName() == courseName) {
            // Update existing
            courses[index].setLecturer(lecturer);
            courses[index].setGrade(grade);
            return;
        }
    }
    // we didn't find so we add
    if (courseCount < MAX_COURSES) {
        courses[courseCount].setName(courseName);
        courses[courseCount].setLecturer(lecturer);
        courses[courseCount].setGrade(grade);
        courseCount++;
    } else { // i have created a limit of 10 courses since nothing was told not to.
        std::cout << "Cannot add more courses (limit " << MAX_COURSES << ").\n";
    }
}

void Student1::print() const {
    std::cout << "Student " << name << " (ID: " << id << ", Year: " << year << ")\n";

    if (courseCount == 0) {
        std::cout << "No courses.\n";
    } else {
        std::cout << "Courses:\n";
        for (int index = 0; index < courseCount; index++) {
            std::cout << "  " << courses[index].getName() << " (Lecturer: " << courses[index].getLecturer() << ", Grade: " << courses[index].getGrade() << ")\n";
        }
    }
}

bool Student1::isExcellent() const {
    if (courseCount == 0) return false;  // can't be excellent if you don't have any courses

    long long sum = 0;
    for (int index = 0; index < courseCount; index++) {
        sum += courses[index].getGrade();
    }
    double average = static_cast<double>(sum) / courseCount;

    if ((year == 1 || year == 2) && average >= YEAR1_2_EXCELLENT) {
        return true;
    }
    if ((year == 3 || year == 4) && average >= YEAR3_4_EXCELLENT) {
        return true;
    }
    return false;
}

int Student1::getYear() const {
    return year;
}