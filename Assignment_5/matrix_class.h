#pragma once

#include <iostream>

class Matrix
{
    // Friends
    friend std::ostream & operator<<(std::ostream &os, const Matrix &mat);
    friend std::istream & operator>>(std::istream &is, Matrix &mat);
private:
    double *matrix_data{nullptr};
    int rows{1};
    int columns{1};
public:
    // Default constructor
    Matrix();
    // Parameterized constructor
    Matrix(int m, int n);
    // Copy constructor 
    Matrix(const Matrix &mat);
    // Move constructor
    Matrix(Matrix &&mat);
    // Destructor
    ~Matrix();
    // Access functions
    int get_rows() const;
    int get_cols() const;
    int index(int m, int n) const;
    double & operator()(int m, int n) const;

    // Assignment operators
    Matrix & operator=(const Matrix &mat);
    Matrix & operator=(Matrix &&mat);
    //  Arithmetic operators
    Matrix operator+(const Matrix &mat) const;
    Matrix operator-(const Matrix &mat) const;
    Matrix operator*(const Matrix &mat) const;
    // Submatrix with row m and column n removed
    Matrix remove_row_column(int m, int n) const;
    // Determinant
    double determinant() const;
};