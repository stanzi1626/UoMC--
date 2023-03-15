#include "matrix_class.h"

Matrix::Matrix() = default;

Matrix::Matrix(int m, int n) : rows{m}, columns{n}
{
    matrix_data = new double[m*n];
}

std::ostream & operator<<(std::ostream &os, const Matrix &mat)
{
  // Code goes here

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