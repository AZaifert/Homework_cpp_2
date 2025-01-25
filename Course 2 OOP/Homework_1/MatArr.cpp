#include "MatArr.h"
#include <iostream>
using namespace std;
#define START_POINT 0
#define INCREMENT 1

//Constructor for MatArr using dynamic memory.
//trivial stuff nothing to explain.
MatArr::MatArr(MyMatrix *arr, int size) : length(size)
{
    arrptr = new MyMatrix[size];
    for (int i = START_POINT; i < size; i++)
        arrptr[i] = arr[i];
}
//Copy Constructor for MatArr.
MatArr::MatArr(const MatArr &copy): length(copy.length)
{
    arrptr = new MyMatrix[copy.length];
    for (int i = START_POINT; i < copy.length; i++)
        arrptr[i] = copy.arrptr[i];
}
//Method to add a new matrix to the array of matrices.
//simple increment by one and deletion of the old array.
void MatArr::addMyMatrix(const MyMatrix &newMatarr) {
    MyMatrix *temp = new MyMatrix[length + INCREMENT];
    for (int i = START_POINT; i < length; i++)
        temp[i] = arrptr[i];
    temp[length] = newMatarr;
    delete[] arrptr;
    arrptr = temp;
    length++;
}
//Method to update a matrix if index is valid.
bool MatArr::update(int index, const MyMatrix &newMatarr) const {
    if (index < START_POINT || index >= length)
        return false;

    arrptr[index] = newMatarr;
    return true;
}
//Method to get a matrix if index is valid.
bool MatArr::get(int index, MyMatrix &newMatarr) const
{
    if (index < START_POINT || index >= length)
        return false;

    newMatarr = arrptr[index];
    return true;
}
//Method to print all matrices in the array.
void MatArr::printMatArr() const
{
    for (int i = START_POINT; i < length; i++)
    {
        cout << "Matrix " << i + INCREMENT << ":" << endl;
       arrptr[i].printMatrix();
        cout << endl;
    }

}
//sum all matrices in the array.
MyMatrix* MatArr::sumofMatrices() const {
    if (length == 0) {
        return nullptr; // Return nullptr if there are no matrices
    }

    MyMatrix* sumMatrix = new MyMatrix;
    *sumMatrix = arrptr[0]; // Initialize with the first matrix

    for (int i = 1; i < length; ++i) {
        sumMatrix->add(arrptr[i]);
    }

    return sumMatrix;
}
//Method to input matrices from the user.
void MatArr::inputMatrices(MatArr &matArr, int numMatrices) {
    for (int n = START_POINT; n < numMatrices; n++) {
        float matrix_data[SIZE][SIZE];
        cout << "Enter values for matrix " << n + INCREMENT << ":" << endl;
        for (int i = START_POINT; i < SIZE; i++) {
            for (int j = START_POINT; j < SIZE; j++) {
                cin >> matrix_data[i][j];
            }
        }

        float* matrix_ptr[SIZE] = {matrix_data[0], matrix_data[1]};
        MyMatrix matrix(matrix_ptr);
        matArr.addMyMatrix(matrix);
    }
}






