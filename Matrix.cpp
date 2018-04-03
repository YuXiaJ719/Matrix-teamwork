#include <iostream>
#include <iomanip>
#include "Matrix.hh"
using namespace std;


ostream& operator << (ostream& s, Matrix m){
    for(int i = 0; i<m.rows; i++){
        for(int j = 0; j<m.cols; j++)
            cout << setw(5) << m.mat[i*m.cols + j] << setw(3) << " ";
        cout << '\n';
    }

    return s;
}
Matrix operator +(Matrix left, Matrix right){
    if(left.rows != right.rows || left.cols != right.cols){
        cout << "Dimensions are not matching: " << '(' << left.rows << ',' << left.cols << ')' << ',' << '(' << right.rows << ',' << right.cols << ')';
        return Matrix(0, 0, 0);
    }
    int size = left.rows * right.cols;
    Matrix res(left.rows, left.cols);
    for(int i = 0; i < size; i++)
        res.mat[i] = left.mat[i] + right.mat[i];
    
    return res;
}

Matrix operator*(Matrix a, Matrix b) {
    Matrix c(a.rows, b.cols);
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.rows; j++) {
            for (int k = 0; k < a.cols; k++) {
                c.mat[i * a.rows + j] += a.mat[i * a.cols + k] * b.mat[k * b.cols + j];
            }
        }
    }
    return c;
}

Matrix& Matrix::operator =(const Matrix& orig){
    if(this != &orig){
        delete [] mat;

        rows = orig.rows;
        cols = orig.cols;

        mat = new double[rows*cols];

        for(int i = 0; i < rows*cols; i++)
            mat[i] = orig.mat[i];
    }

    return *this;
}
