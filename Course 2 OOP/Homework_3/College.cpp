#include "College.h"
#include "Student0.h"
#include "Student1.h"
#include "Student2.h"
#include <iostream>
#include <string>

enum MenuOptions {
    ADD_STUDENT = 1,
    ADD_GRADE,
    PRINT_ALL,
    PRINT_EXCELLENT,
    FIND_TYPES,
    SUPERVISOR,
    QUIT
};

College::College()
    : studentCount(0)
{
    for(int i = 0; i < MAX_STUDENTS; i++) {
        students[i] = 0;
    }
}

College::~College() {
    for(int i = 0; i < studentCount; i++) {
        delete students[i];
        students[i] = 0;
    }
}

Student* College::findStudentById(long id) const {
    for(int i = 0; i < studentCount; i++) {
        if(students[i]->getId() == id) {
            return students[i];
        }
    }
    return 0;
}

bool College::add_student() {
    if(studentCount >= MAX_STUDENTS) {
        std::cout << "Cannot add more students (limit of " << MAX_STUDENTS << ").\n";
        return false;
    }

    std::cout << "Which type of student? (0=StudentMehcina, 1=Student1, 2=Student2): ";
    int choice;
    std::cin >> choice;

    std::cout << "Enter student name: ";
    std::string stName;
    std::cin.ignore();
    std::getline(std::cin, stName);

    std::cout << "Enter student ID: ";
    long stId;
    std::cin >> stId;

    if(findStudentById(stId) != 0) {
        std::cout << "A student with this ID already exists!\n";
        return false;
    }

    if(choice == 0) {
        std::cout << "Is short Mehcina? (0/1): ";
        int shortVal;
        std::cin >> shortVal;
        bool isShort = (shortVal != 0);

        Student0* s0 = new Student0(stName, stId, isShort);
        students[studentCount++] = s0;
        std::cout << "StudentMechina added.\n";
        return true;
    }
    else if(choice == 1) {
        std::cout << "Enter year (1..4): ";
        int yr;
        std::cin >> yr;

        Student1* s1 = new Student1(stName, stId, yr);

        std::cout << "How many courses to add now? ";
        int num;
        std::cin >> num;

        for(int i = 0; i < num; i++) {
            std::string cName, cLect;
            int cGrade;

            std::cout << "Course #" << (i+1) << " name: ";
            std::cin.ignore();
            std::getline(std::cin, cName);

            std::cout << "Lecturer: ";
            std::getline(std::cin, cLect);

            std::cout << "Grade: ";
            std::cin >> cGrade;

            s1->addOrUpdateCourse(cName, cLect, cGrade);
        }
        students[studentCount++] = s1;
        std::cout << "Student1 added.\n";
        return true;
    }
    else if(choice == 2) {
        std::cout << "Enter thesis title: ";
        std::string thesis;
        std::cin.ignore();
        std::getline(std::cin, thesis);

        std::cout << "Enter supervisor name: ";
        std::string sup;
        std::getline(std::cin, sup);

        Student2* s2 = new Student2(stName, stId, thesis, sup);
        students[studentCount++] = s2;
        std::cout << "Student2 added.\n";
        return true;
    }
    else {
        std::cout << "Invalid choice.\n";
        return false;
    }
}

bool College::add_grade(long studentId, const std::string& courseName, const std::string& lecturer, int grade) const {
    Student* st = findStudentById(studentId);
    if(st == 0) {
        std::cout << "No student with this ID.\n";
        return false;
    }

    Student1* s1 = dynamic_cast<Student1*>(st);
    if(!s1) {
        std::cout << "This student is not of type Student1 (cannot add courses).\n";
        return false;
    }
    s1->addOrUpdateCourse(courseName, lecturer, grade);
    return true;
}

void College::print_all() const {
    if(studentCount == 0) {
        std::cout << "No students.\n";
        return;
    }
    for(int i = 0; i < studentCount; i++) {
        students[i]->print();
    }
}

void College::print_excellent() const {
    bool foundAny = false;
    for(int i = 0; i < studentCount; i++) {
        if(students[i]->isExcellent()) {
            students[i]->print();
            foundAny = true;
        }
    }
    if(!foundAny) {
        std::cout << "No excellent students found.\n";
    }
}

void College::find_types() const {
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for(int i = 0; i < studentCount; i++) {
        if(dynamic_cast<Student0*>(students[i])) {
            count0++;
        }
        else if(dynamic_cast<Student1*>(students[i])) {
            count1++;
        }
        else if(dynamic_cast<Student2*>(students[i])) {
            count2++;
        }
    }

    std::cout << "Number of StudentMechina: " << count0 << "\n";
    std::cout << "Number of Student1: " << count1 << "\n";
    std::cout << "Number of Student2: " << count2 << "\n";
}

void College::supervisor(const std::string& supervisorName) const {
    bool foundAny = false;
    for(int i = 0; i < studentCount; i++) {
        Student2* s2 = dynamic_cast<Student2*>(students[i]);
        if(s2) {
            if(s2->getSupervisor() == supervisorName) {
                s2->print();
                foundAny = true;
            }
        }
    }
    if(!foundAny) {
        std::cout << "No Student2 found with that supervisor name.\n";
    }
}

void College::menu() {
    int choice;
    do {
        std::cout << "\n--SCE MENU --\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Add grade\n";
        std::cout << "3. Print all\n";
        std::cout << "4. Print excellent\n";
        std::cout << "5. Types of student\n";
        std::cout << "6. Supervisor\n";
        std::cout << "7. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch(choice) {
        case ADD_STUDENT: {
            bool ok = add_student();
            if(ok) std::cout << "Student successfully added.\n";
            else  std::cout << "Failed to add student.\n";
        } break;

        case ADD_GRADE: {
            long stId;
            std::string cName, cLect;
            int cGrade;
            std::cout << "Enter student ID: ";
            std::cin >> stId;

            std::cout << "Enter course name: ";
            std::cin.ignore();
            std::getline(std::cin, cName);

            std::cout << "Enter lecturer name: ";
            std::getline(std::cin, cLect);

            std::cout << "Enter grade: ";
            std::cin >> cGrade;

            bool ok = add_grade(stId, cName, cLect, cGrade);
            if(ok) std::cout << "Grade added.\n";
            else  std::cout << "Failed to add grade.\n";
        } break;

        case PRINT_ALL:
            print_all();
            break;

        case PRINT_EXCELLENT:
            print_excellent();
            break;

        case FIND_TYPES:
            find_types();
            break;

        case SUPERVISOR: {
            std::cout << "Enter supervisor name: ";
            std::string supName;
            std::cin.ignore();
            std::getline(std::cin, supName);
            supervisor(supName);
        } break;

        case QUIT:
            std::cout << "Goodbye\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while(choice != QUIT);
}
