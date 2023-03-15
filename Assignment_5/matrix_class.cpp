#include "matrix_class.h"

Matrix::Matrix() = default;

Matrix::Matrix(int m, int n) : rows{m}, columns{n}
{
    matrix_data = new double[m*n];
}

Matrix::Matrix(const Matrix &mat)
{
    rows = mat.rows;
    columns = mat.columns;
    matrix_data = new double[rows*columns];
    for(int i{1}; i<=rows; ++i) {
        for(int j{1}; j<=columns; ++j) {
            matrix_data[index(i,j)] = mat.matrix_data[index(i,j)];
        }
    }
}

Matrix::Matrix(Matrix &&mat)
{
    rows = mat.rows;
    columns = mat.columns;
    matrix_data = mat.matrix_data;
    mat.matrix_data = nullptr;
}

Matrix::~Matrix()
{
    delete [] matrix_data;
}

std::ostream & operator<<(std::ostream &os, const Matrix &mat)
{
    if (mat.matrix_data == nullptr) {
        os << "Matrix is empty" << std::endl << std::endl;
        return os;
    }
    for(int i{1}; i<=mat.rows; ++i) {
        os << "[";
        for(int j{1}; j<=mat.columns; ++j) {
            if (j==mat.columns) os << mat.matrix_data[mat.index(i,j)] << "]" << std::endl;
            else os << mat.matrix_data[mat.index(i,j)] << " ,";
        }
    }
    os << std::endl;
    return os;
}

double & Matrix::operator()(int m, int n) const
{
    return matrix_data[index(m,n)];
}

// Access functions
int Matrix::get_rows() const {return rows;} // Return number of rows
int Matrix::get_cols() const {return columns;} // Return number of columns
int Matrix::index(int m, int n) const // Return position in array of element (m,n)
{
    if(m>0 && m<=rows && n>0 && n<=columns) return (n-1)+(m-1)*columns;
    else {std::cout<<"Error: out of range"<<std::endl; exit(1);}
}

Matrix & Matrix::operator=(const Matrix &mat)
{
    if (this == &mat) return *this;
    delete [] matrix_data;
    rows = mat.rows;
    columns = mat.columns;
    matrix_data = new double[rows*columns];
    for(int i{1}; i<=rows; ++i) {
        for(int j{1}; j<=columns; ++j) {
            matrix_data[index(i,j)] = mat.matrix_data[index(i,j)];
        }
    }
    return *this;
}

Matrix & Matrix::operator=(Matrix &&mat)
{
    if (this == &mat) return *this;
    delete [] matrix_data;
    rows = mat.rows;
    columns = mat.columns;
    matrix_data = mat.matrix_data;
    mat.matrix_data = nullptr;
    return *this;
}