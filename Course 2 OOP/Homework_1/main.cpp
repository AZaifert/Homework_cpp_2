#include <iostream>
#include "MyMatrix.h"
using namespace std;
#define START_POINT 0
#define EXIT 0

//This main function takes from user 3 user input matrices
//as per the requirement of the assignment I've written the code even though some of the functions not used e.g. "is_inverse"
//The builder instruction also confused me a bit , however the main runs as per the requirement.

    int main() {
    // Initialize matrices with dynamic memory, so we can send it to the constructor
    float** matrixA = new float*[SIZE];
    float** matrixB = new float*[SIZE];
    float** matrixC = new float*[SIZE];

    for (int i = START_POINT ; i < SIZE; i++) {
        matrixA[i] = new float[SIZE];
        matrixB[i] = new float[SIZE];
        matrixC[i] = new float[SIZE];
    }
    cout<< "Hello dear user , it is good to see you here!"<<endl;
    // Input matrices from user
    cout << "Enter matrix A (2x2) [ , , , ]:" << endl;
    for (int i = START_POINT ; i < SIZE; i++)
        for (int j = START_POINT ; j < SIZE; j++)
            cin >> matrixA[i][j];

    cout << "Enter matrix B (2x2) [ , , , ]:" << endl;
    for (int i = START_POINT ; i < SIZE; i++)
        for (int j = START_POINT ; j < SIZE; j++)
            cin >> matrixB[i][j];

    cout << "Enter matrix C (2x2) [ , , , ]:" << endl;
    for (int i = START_POINT ; i < SIZE; i++)
        for (int j = START_POINT ; j < SIZE; j++)
            cin >> matrixC[i][j];

    // Create MyMatrix objects using the pointer to the matrices
    MyMatrix A(matrixA);
    MyMatrix B(matrixB);
    MyMatrix C(matrixC);

    // Check if matrices are equal
    if (A.is_equal(B)) {
        cout << "Matrix A is equal to Matrix B" << endl;
    }
    if (A.is_equal(C)) {
        cout << "Matrix A is equal to Matrix C" << endl;
    }
    if (B.is_equal(C)) {
        cout << "Matrix B is equal to Matrix C" << endl;
    }

    //determinants
    cout << "Determinant of Matrix A: " << A.det() << endl;
    cout << "Determinant of Matrix B: " << B.det() << endl;
    cout << "Determinant of Matrix C: " << C.det() << endl;

    //A*B+C using result matrix so we won't change the values of A, B, and C
    MyMatrix result(A);
    result.mult(B);
    result.add(C);
    cout << "Matrix A*B+C:" << endl;
    result.printMatrix();

    //input for Matrix B
    cout << "Enter new matrix B (2x2) [ , , , ]:" << endl;
    for (int i = START_POINT ; i < SIZE; i++)
        for (int j = START_POINT ; j < SIZE; j++)
            cin >> matrixB[i][j];

    // Update matB with new values
    MyMatrix newB(matrixB);

    //A*B+C with new B , same trick with the result.
    result.set(A);
    result.mult(newB);
    result.add(C);
    cout << "Matrix A*B+C with new B:" << endl;
    result.printMatrix();

    // Free memory
    for (int i = START_POINT ; i < SIZE; i++) {
        delete[] matrixA[i];
        delete[] matrixB[i];
        delete[] matrixC[i];
    }
    delete[] matrixA;
    delete[] matrixB;
    delete[] matrixC;

    return EXIT;
}


//Assigment 2.
#include <iostream>
#include "MyMatrix.h"
#include "MatArr.h"
using namespace std;
#define START_POINT 0
#define EXIT 0
#define ERROR 2
#define INDEX_ONE 1
#define LOWER_BOUND 1

int main()
{
    //We get amount of matrices from user.
    cout<< "Greeting dear user ,it is good to see you here!"<<endl;
    int numMatrices=0;
    do
    {
        cout << "Enter how many MyMatrix matrices you want (at least 1 is a must):" << endl;
        cin >> numMatrices;
        if (numMatrices < LOWER_BOUND)
            {
            cout << "You must enter at least 1 matrices come on!" << endl;
        }
    }while (numMatrices < LOWER_BOUND);

    //We create a MatArr object and input the matrices.
    MatArr matArr;
    MatArr::inputMatrices(matArr, numMatrices);
    //We print the matrices for ease of checking.
    cout << "The matrices you entered are:" << endl;
    matArr.printMatArr();
    //We ask the user to input two index numbers to multiply the matrices.
    int index1, index2;
    if (numMatrices == LOWER_BOUND)
    {
        cout << "Now you only have one index to choose from , should've added more matrices." << endl;
    }
    cout << "Enter the index of the first matrix: pick (1 to " << numMatrices << "): " << endl;
    cin >> index1;
    cout << "Enter the index of the second matrix: pick (1 to " << numMatrices << "): " << endl;
    cin >> index2;

    //We check if the indices are valid.
    MyMatrix matrix1, matrix2;
    if (matArr.get(index1 - INDEX_ONE, matrix1) && matArr.get(index2 - INDEX_ONE, matrix2)) {
        // Multiply the two matrices
        MyMatrix resultMatrix = matrix1;
        resultMatrix.mult(matrix2);

        // Add the resulting matrix to the array
        matArr.addMyMatrix(resultMatrix);

        // Print all matrices in MatArr
        cout << "All matrices in MatArr after adding the result of multiplication:" << endl;
        matArr.printMatArr();

        // Calculate and print the sum of all matrices
        if (MyMatrix* sumMatrix = matArr.sumofMatrices()){
            cout << "Sum of matrices in MatArr:" << endl;
            sumMatrix->printMatrix();
            delete sumMatrix;
        }
    } else
        {
        cout << "Invalid index" << endl;
        cout << "Failed" << endl;
    }

    return EXIT;
}
