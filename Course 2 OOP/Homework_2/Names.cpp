#include "Names.h"
#include <cstring>

int Names::total = 0;

Names::Names() : names(nullptr), size(0) {}

Names::Names(const Names& other) : size(other.size) {
    names = new char*[size];
    for (int i = 0; i < size; ++i) {
        names[i] = new char[strlen(other.names[i]) + 1];
        strcpy(names[i], other.names[i]);
    }
    total += size;
}

Names::~Names() {
    for (int i = 0; i < size; ++i) {
        delete[] names[i];
    }
    delete[] names;
    total -= size;
}

const char* Names::getName(int index) const {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    return names[index];
}

Names& Names::operator=(const Names& other) {
    if (this == &other) return *this;


    for (int i = 0; i < size; ++i) {
        delete[] names[i];
    }
    delete[] names;


    size = other.size;
    names = new char*[size];
    for (int i = 0; i < size; ++i) {
        names[i] = new char[strlen(other.names[i]) + 1];
        strcpy(names[i], other.names[i]);
    }

    total += size;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Names& group) {
    for (int i = 0; i < group.size; ++i) {
        os << group.names[i] << " ";
    }
    return os;
}

Names& Names::operator+=(const char* name) {
    if (contains(name)) return *this;


    char** newNames = new char*[size + 1];
    for (int i = 0; i < size; ++i) {
        newNames[i] = names[i];
    }
    newNames[size] = new char[strlen(name) + 1];
    strcpy(newNames[size], name);


    delete[] names;
    names = newNames;
    ++size;
    ++total;

    return *this;
}

Names& Names::operator-=(const char* name) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(names[i], name) == 0) {
            delete[] names[i];


            for (int j = i; j < size - 1; ++j) {
                names[j] = names[j + 1];
            }


            char** newNames = new char*[size - 1];
            for (int k = 0; k < size - 1; ++k) {
                newNames[k] = names[k];
            }
            delete[] names;
            names = newNames;

            --size;
            --total;
            return *this;
        }
    }
    return *this;
}

bool Names::operator==(const Names& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i) {
        if (!other.contains(names[i])) return false;
    }
    return true;
}

bool Names::contains(const char* name) const {
    for (int i = 0; i < size; ++i) {
        if (strcmp(names[i], name) == 0) return true;
    }
    return false;
}

Names Names::operator*(const Names& other) const {
    Names result;
    for (int i = 0; i < size; ++i) {
        if (other.contains(names[i])) {
            result += names[i];
        }
    }
    return result;
}

int Names::getTotalSize() {
    return total;
}