#ifndef NAMES_H
#define NAMES_H
#include <iostream>


class Names {
private:
    char** names;
    int size;
    static int total;

public:
    Names();
    Names(const Names& other);
    ~Names();

    int getsSize() const { return size; };
    const char* getName(int index) const;
    Names& operator=(const Names& other);
    friend std::ostream& operator<<(std::ostream& os, const Names& group);
    Names& operator+=(const char* name);
    Names& operator-=(const char* name);
    bool operator==(const Names& other) const;
    bool contains(const char* name) const;
    Names operator*(const Names& other) const; // Intersection operator
    static int getTotalSize();




};



#endif //NAMES_H
