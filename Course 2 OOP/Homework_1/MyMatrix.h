#ifndef MYMATRIX_H
#define MYMATRIX_H
#define SIZE 2



class MyMatrix  {

public:
    MyMatrix();
    explicit MyMatrix(float** matrix);
    MyMatrix(const MyMatrix &copy);
    ~MyMatrix(){}
    void printMatrix() const;
    void set(const MyMatrix &m);
    bool is_equal(const MyMatrix &m) const;
    float det() const;
    bool is_inverse(const MyMatrix &m) const;
    void add(const MyMatrix &m);
    void mult(const MyMatrix &m);



private:
    float matrix_a[SIZE][SIZE]{};


};



#endif //MYMATRIX_H
