#include "Student0.h"
#include <iostream>

void Student0::print() const {
    std::cout << "Student Mechina: Name: " << name << ", ID: " << id << ", Short Mechina?: " << (is_short ? "true" : "false") << std::endl;
}

bool Student0::isExcellent() const {
    return false;
}