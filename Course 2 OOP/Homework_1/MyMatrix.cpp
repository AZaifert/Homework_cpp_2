#include "MyMatrix.h"
#include "MatArr.h"
#include <iostream>
//Defines
using namespace std;
#define START_POINT 0
#define ZERO 0
#define ONE 1
#define IDENONE 1.0
#define IDENZERO 0.0
//MyMatrix Default Constructor.
MyMatrix::MyMatrix() {
    for (int i = START_POINT; i < SIZE; i++)
        for (int j = START_POINT; j < SIZE; j++)
            matrix_a[i][j] = ZERO;
}
//MyMatrix Constructor using a matrix as a parameter.
MyMatrix::MyMatrix(float **matrix) {
    for (int i = START_POINT; i < SIZE; i++)
        for (int j = START_POINT; j < SIZE; j++)
            matrix_a[i][j] = matrix[i][j];
}
//MyMatrix Copy Constructor.
MyMatrix::MyMatrix(const MyMatrix &copy) {
    for (int i = START_POINT; i < SIZE; i++)
        for (int j = START_POINT; j < SIZE; j++)
            matrix_a[i][j] = copy.matrix_a[i][j];
}

//PrintMatrix Method for printing Matrix.
void MyMatrix::printMatrix() const {
    for (int i = START_POINT; i < SIZE; i++) {
        for (int j = START_POINT; j < SIZE; j++)
            cout << matrix_a[i][j] << " ";
        cout << endl;
    }
}
//Set Method to set the matrix.
void MyMatrix::set(const MyMatrix &m) {
    for (int i = START_POINT; i < SIZE; i++)
        for (int j = START_POINT; j < SIZE; j++)
            this->matrix_a[i][j] = m.matrix_a[i][j];
}
//compare two matrix if they are equal.
bool MyMatrix::is_equal(const MyMatrix &m) const {
    for (int i = START_POINT; i < SIZE; i++)
        for (int j = START_POINT; j < SIZE; j++)
            if (matrix_a[i][j] != m.matrix_a[i][j])
                return false;
    return true;
}
//det Method to calculate the determinant of the matrix(made for square matrix).
float MyMatrix::det() const
{
    return matrix_a[ZERO][ZERO] * matrix_a[ONE][ONE] - matrix_a[ZERO][ONE] * matrix_a[ONE][ZERO];
}
//add two matrix.
void MyMatrix::add(const MyMatrix &m) {
    for (int i = START_POINT; i < SIZE; i++)
        for (int j = START_POINT; j < SIZE; j++)
            this->matrix_a[i][j] += m.matrix_a[i][j];
}
//mult Method to multiply two matrix, using temp matrix to store the result then copy it to the original matrix.
void MyMatrix::mult(const MyMatrix &m) {
    float temp[SIZE][SIZE];
    for (int i = START_POINT; i < SIZE; i++)
        for (int j = START_POINT; j < SIZE; j++) {
            temp[i][j] = ZERO;
            for (int k = START_POINT; k < SIZE; k++)
                temp[i][j] += this->matrix_a[i][k] * m.matrix_a[k][j];
        }
    for (int i = START_POINT; i < SIZE; i++) {
        for (int j = START_POINT; j < SIZE; j++) {
            this->matrix_a[i][j] = temp[i][j];
        }
    }
}

//is_inverse Method to check if the matrix is invertible.
bool MyMatrix::is_inverse(const MyMatrix &m) const
{
    //so we won't do all the calculations if the determinant is 0
    if (m.det() == ZERO)
        return false;


    MyMatrix A(*this);
    A.mult(m); // A = A * m


    MyMatrix D(m);
    D.mult(*this); // D = m * *this

    // I matrix
    MyMatrix identity;
    identity.matrix_a[ZERO][ZERO] = IDENONE;
    identity.matrix_a[ZERO][ONE] = IDENZERO;
    identity.matrix_a[ONE][ZERO] = IDENZERO;
    identity.matrix_a[ONE][ONE] = IDENONE;

    // Check if A*m = I and m*A = I
    return A.is_equal(identity) && D.is_equal(identity);
}











