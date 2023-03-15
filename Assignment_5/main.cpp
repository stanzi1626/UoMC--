// PHYS 30762 Programming in C++
// Assignment 5 - A Matrix class
// Created by Alexander Stansfield 15/03/2023

#include<iostream>
// #include<stdlib> // for c style exit
#include "Matrix_class.h"

int main()
{
    // Demonstrate default constructor
    Matrix a1;
    std::cout << a1;

    // Parameterized constructor
    const int m{2};
    const int n{2};
    Matrix a2{m,n};
    // Set values for a2 here
    a2(1,1)=1;
    a2(1,2)=2;
    a2(2,1)=3;
    a2(2,2)=4;

    // Print Matrix a2
    // std::cout << a2;


    // Deep copy by assignment: define new Matrix a3 then copy from a2 to a3
    // Matrix a3{m,n};
    // std::cout << a3;
    // a3 = a2;
    // std::cout << a3;
    // // Modify contents of original Matrix and show assigned Matrix is unchanged here

    // a2(1,1)=5;
    // a2(1,2)=6;
    // a2(2,1)=7;
    // a2(2,2)=8;

    // std::cout << a2;
    // std::cout << a3;
 

    // Deep copy using copy constructor 
    Matrix a4{a2};
    // std::cout<<a4;
    // Modify contents of original Matrix and show copied Matrix is unchanged here

    a2(1,1)=5;
    a2(1,2)=6;
    a2(2,1)=7;
    a2(2,2)=8;

    // std::cout<<a2;
    // std::cout<<a4;

    // Move copy construction demonstration
    Matrix a5(std::move(a2));
    std::cout << a5;
    std::cout << a2;
    // Move assignment demonstration
    Matrix a6;
    a6 = std::move(a5);
    std::cout << a6;
    std::cout << a5;
    //
    // Second part of assignment: Matrix operations
    //

    // Addition of 2 matrices

    // Subtraction of 2 matrices

    // Multiplication of 2 matrices


    // Determinant

  
  return 0;
}