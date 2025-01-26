#include "Student2.h"
#include <iostream>

Student2::Student2(const std::string& n, long i, const std::string& th, const std::string& sup)
    : Student(n, i), thesis(th), supervisor(sup) {}

void Student2::print() const {
    std::cout << "Student " << name << " (ID: " << id << ")\n";
    std::cout << "Thesis: " << thesis << "\n";
    std::cout << "Supervisor: " << supervisor << "\n";
}

bool Student2::isExcellent() const {
    return true;
}

std::string Student2::getSupervisor() const {
    return supervisor;
}