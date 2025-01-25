#ifndef MATARR_H
#define MATARR_H
#include "MyMatrix.h"


class MatArr {

private:
    MyMatrix* arrptr;
    int length;

public:
    MatArr(): arrptr(nullptr), length(0) {};
    MatArr(MyMatrix *arr, int size);
    MatArr(const MatArr &copy);
    ~MatArr() { delete[] arrptr; arrptr = nullptr; };
    void addMyMatrix(const MyMatrix& newMatarr);
    bool update(int index, const MyMatrix& newMatarr) const;
    bool get(int index, MyMatrix& newMatarr) const;
    void printMatArr() const;
    MyMatrix* sumofMatrices() const;

    static void inputMatrices(MatArr &matArr, int numMatrices);

};



#endif //MATARR_H
