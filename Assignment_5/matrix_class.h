#pragma once

#include <iostream>

class Matrix
{
    // Friends
    friend std::ostream & operator<<(std::ostream &os, const Matrix &mat);
private:
    double *matrix_data {nullptr};
    int rows{0};
    int columns{0};
public:
    // Default constructor
    Matrix();
    // Parameterized constructor
    Matrix(int m, int n);
    // Copy constructor

    // Move constructor

    // Destructor

    // Access functions
    int get_rows() const;
    int get_cols() const;
    int index(int m, int n) const;
    double & operator()(int m, int n) const;
    // Other access functions go here

    // Other functions 
    // Copy  Assignment operator

    // Move Assignment operator

    // Addition, subtraction and multiplication

    // minor

    // determinant

};