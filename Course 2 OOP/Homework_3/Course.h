#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
private:
    std::string name;
    std::string lecturer;
    int grade;

public:
    Course(); // Default constructor
    Course(const std::string& name, const std::string& lecturer, int grade);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getLecturer() const;
    void setLecturer(const std::string& lecturer);

    int getGrade() const;
    void setGrade(int grade);
};

#endif // COURSE_H