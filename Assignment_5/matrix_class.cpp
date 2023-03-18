#include "matrix_class.h"

#include <cmath>
#include <vector>

Matrix::Matrix() : rows{1}, columns{1}
{
    matrix_data = new double[1];
}

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
            else os << mat.matrix_data[mat.index(i,j)] << ", ";
        }
    }
    os << std::endl;
    return os;
}

bool break_down_matrix(std::istream &is, Matrix &mat, std::vector<double> &data)
{
    char character;
    double number;
    bool first_row{true};
    int rows{0};
    int columns{0};
    int j{1};
    while (is) {
        // Check if input starts with '[' (always indicates new row)
        if (is >> character && character == '[') {
            ++rows;
            if (first_row == true) ++columns;
        }
        // Check if input is a comma (always indicates new column) and if it is the first row (if first row, then increment columns)
        else if (character == ',' & first_row == false) ++j;
        else if (character == ',' & first_row == true) ++j && ++columns;
        // Check if input is a ']' (always indicates end of row)
        else if (character == ']') {
            if (j != columns) {
                std::cout << "Error: input error" << std::endl;
                exit(1);
            }
            // Check if input is a ']' and if it is the last row (if last row, then break)
            else if (j == columns && std::cin.peek() == '\n') break;
            // Reset column counter and set first_row to false
            j = 1;
            first_row = false;
            continue;
        }
        // Check if input is a number
        if (is >> number) data.push_back(number);
        // If input is not a number, then input is invalid and program exits
        if (std::cin.fail()) {
            std::cout << "Error: input error" << std::endl;
            exit(1);
        }
    }
    // If input is valid, then set matrix dimensions and allocate memory
    mat = Matrix(rows, columns);
    return true;
}


std::istream & operator>>(std::istream &is, Matrix &mat)
{
    std::vector<double> data;
    if (break_down_matrix(is, mat, data)) {
        for(int i{1}; i<=mat.rows; ++i) {
            for(int j{1}; j<=mat.columns; ++j) {
                mat.matrix_data[mat.index(i,j)] = data[mat.index(i,j)];
            }
        }
    }
    return is;
}

// Access functions
int Matrix::get_rows() const {return rows;} // Return number of rows
int Matrix::get_cols() const {return columns;} // Return number of columns
int Matrix::index(int m, int n) const // Return position in array of element (m,n)
{
    if(m>0 && m<=rows && n>0 && n<=columns) return (n-1)+(m-1)*columns;
    else {std::cout<<"Error: out of range"<<std::endl; exit(1);}
}
double & Matrix::operator()(int m, int n) const
{
    return matrix_data[index(m,n)];
}

// Assignment operators
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

// Arithmetic operators
Matrix Matrix::operator+(const Matrix &mat) const
{
    if (rows != mat.rows || columns != mat.columns) {
        std::cout << "Error: matrices must have the same dimensions" << std::endl;
        exit(1);
    }
    Matrix result(rows, columns);
    for(int i{1}; i<=rows; ++i) {
        for(int j{1}; j<=columns; ++j) {
            result.matrix_data[result.index(i,j)] = matrix_data[index(i,j)] + mat.matrix_data[mat.index(i,j)];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &mat) const
{
    if (rows != mat.rows || columns != mat.columns) {
        std::cout << "Error: matrices must have the same dimensions" << std::endl;
        exit(1);
    }
    Matrix result(rows, columns);
    for(int i{1}; i<=rows; ++i) {
        for(int j{1}; j<=columns; ++j) {
            result.matrix_data[result.index(i,j)] = matrix_data[index(i,j)] - mat.matrix_data[mat.index(i,j)];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &mat) const
{
    if (columns != mat.rows) {
        std::cout << "Error: matrices must have compatible dimensions" << std::endl;
        exit(1);
    }
    Matrix result(rows, mat.columns);
    for(int i{1}; i<=rows; ++i) {
        for(int j{1}; j<=mat.columns; ++j) {
            result.matrix_data[result.index(i,j)] = 0;
            for(int k{1}; k<=columns; ++k) {
                result.matrix_data[result.index(i,j)] +=\
                matrix_data[index(i,k)] * mat.matrix_data[mat.index(k,j)];
            }
        }
    }
    return result;
}

// Submatrix with row n and column m removed
Matrix Matrix::remove_row_column(int n, int m) const
{
    if (n>rows || m>columns) {
        std::cout << "Error: out of range" << std::endl;
        exit(1);
    }
    if (rows==1 || columns==1) {
        std::cout << "Error: matrix must have at least 2 rows and 2 columns" << std::endl;
        exit(1);
    }
    Matrix result(rows-1, columns-1);
    for(int i{1}; i<=rows; ++i) {
        for(int j{1}; j<=columns; ++j) {
            if (i<n && j<m) result.matrix_data[result.index(i,j)] = matrix_data[index(i,j)];
            if (i<n && j>m) result.matrix_data[result.index(i,j-1)] = matrix_data[index(i,j)];
            if (i>n && j<m) result.matrix_data[result.index(i-1,j)] = matrix_data[index(i,j)];
            if (i>n && j>m) result.matrix_data[result.index(i-1,j-1)] = matrix_data[index(i,j)];
        }
    }
    return result;
}

// Determinant
double Matrix::determinant() const
{
    if (rows != columns) {
        std::cout << "Error: matrix must be square" << std::endl;
        exit(1);
    }
    if (rows==1) return matrix_data[0];
    if (rows==2) return matrix_data[0]*matrix_data[3] - matrix_data[1]*matrix_data[2];
    double det{0};
    for(int i{1}; i<=rows; ++i) {
        det += pow(-1,i+1) * matrix_data[index(1,i)] * remove_row_column(1,i).determinant();
    }
    return det;
}