#include "matrix_class.h"

#include <cmath>
#include <vector>

Matrix::Matrix() {}

Matrix::Matrix(int m, int n) : rows{m}, columns{n}
{
    matrix_data = new double[m*n];
}

Matrix::Matrix(int m, int n, double *data) : rows{m}, columns{n}
{
    matrix_data = new double[m*n];
    for(int i{1}; i<=m; ++i) {
        for(int j{1}; j<=n; ++j) {
            matrix_data[index(i,j)] = data[index(i,j)];
        }
    }
}

Matrix::Matrix(const Matrix &mat)
{
/**
 * @brief Copy constructor for the Matrix class
 * @param mat
 * 
 */
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
/**
 * @brief Move constructor for the Matrix class
 * @param mat (address of the matrix to be moved)
 * 
 */
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
/**
 * @brief Overloaded << operator for the Matrix class, prints matrix in the form [a, b, ...] \\ [c, d, ...] \\ ...
 * @param os, mat
 * @return std::ostream
 * 
 */
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
    return os;
}

bool break_down_matrix(std::istream &is, Matrix &mat, std::vector<double> &data)
{
/**
 * @brief Breaks down the input stream into a vector of doubles, which is then stored in data, and checks if the input is valid
 * @param is, mat, data
 * @return bool
 */
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
                return false;
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
            return false;
        }
    }
    // If input is valid, then set matrix dimensions and allocate memory
    mat = Matrix(rows, columns);
    return true;
}


std::istream & operator>>(std::istream &is, Matrix &mat)
{
/**
 * @brief Overloaded >> operator for the Matrix class, reads matrix from input stream, uses break_down_matrix to check if input is valid
 * @param is, mat
 * @return std::istream
 * 
 */
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
/**
 * @brief Overloaded () operator for the Matrix class, returns element (m,n) of the matrix
 * @param m, n
 * @return double
 */
    return matrix_data[index(m,n)];
}

// Assignment operators
Matrix & Matrix::operator=(const Matrix &mat)
{
/**
 * @brief Overloaded = operator for the Matrix class, copies matrix mat to the current matrix
 * @param mat
 * @return Matrix
 */
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
/**
 * @brief Overloaded = operator for the Matrix class, moves matrix mat to the current matrix, then sets mat to nullptr
 * @param mat
 * @return Matrix
 */
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
/**
 * @brief Overloaded + operator for the Matrix class, adds matrix mat to the current matrix, matrices must have the same dimensions
 * @param mat
 * @return Matrix
 */
    if (rows != mat.rows || columns != mat.columns) {
        std::cout << "Error: matrices must have the same dimensions" << std::endl;
        return Matrix{};
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
/**
 * @brief Overloaded - operator for the Matrix class, subtracts matrix mat from the current matrix, 
 * matrices must have the same dimensions
 * @param mat
 * @return Matrix
 */
    if (rows != mat.rows || columns != mat.columns) {
        std::cout << "Error: matrices must have the same dimensions" << std::endl;
        return Matrix{};
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
/**
 * @brief Overloaded * operator for the Matrix class, multiplies the current matrix with matrix mat, 
 * matrices must have compatible dimensions (no. current matrix columns = no. mat matrix rows)
 * @param mat
 * @return Matrix
 */
    if (columns != mat.rows) {
        std::cout << "Error: matrices must have compatible dimensions" << std::endl;
        std::cout << "No. current matrix columns = " << columns << std::endl;
        std::cout << "No. mat matrix rows = " << mat.rows << std::endl;
        return Matrix{};
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

Matrix Matrix::remove_row_column(int n, int m) const
{
/**
 * @brief Removes row n and column m from the current matrix, returns the resulting matrix, used to find submatrix
 * @param n, m
 * @return Matrix
 */
    if (n>rows || m>columns) {
        std::cout << "Error: out of range" << std::endl;
        return Matrix{};
    }
    if (rows==1 || columns==1) {
        std::cout << "Error: matrix must have at least 2 rows and 2 columns" << std::endl;
        return Matrix{};
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
/**
 * @brief Calculates the determinant of the current matrix, by recursively removing finding the determinant of submatrices
 * @return double
 */
    if (rows != columns) {
        std::cout << "Error: matrix must be square -> returning ";
        return 0;
    }
    if (rows==1) return matrix_data[0];
    if (rows==2) return matrix_data[0]*matrix_data[3] - matrix_data[1]*matrix_data[2];
    double det{0};
    for(int i{1}; i<=rows; ++i) {
        det += pow(-1,i+1) * matrix_data[index(1,i)] * remove_row_column(1,i).determinant();
    }
    return det;
}