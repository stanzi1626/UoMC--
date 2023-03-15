// PHYS 30762 Programming in C++
// Assignment 5

// A Matrix class - skeleton code

// You are advised to write your own code from scratch but
// you may use this code if you do not know how to get started.

// Note: for longer functions, you are advised to prototype them
// within class and put the function code itself immediately below class. 

#include<iostream>
// #include<stdlib> // for c style exit
#include "Matrix_class.h"

int main()
{

  //
  // First part of assignment: constructing and deep copying matrices
  //

  // Demonstrate default constructor
  Matrix a1;
  std::cout<<a1;

  // Parameterized constructor
  const int m{2};
  const int n{2};
  Matrix a2{m,n};
  // Set values for a2 here

  // Print Matrix a2
  std::cout<<a2;


  // Deep copy by assignment: define new Matrix a3 then copy from a2 to a3
  Matrix a3{m,n};
  std::cout<<a3;
  a3=a2;
  std::cout<<a3;
  // Modify contents of original Matrix and show assigned Matrix is unchanged here

  std::cout<<a2;
  std::cout<<a3;
 

  // Deep copy using copy constructor 
  Matrix a4{a2};
  std::cout<<a4;
  // Modify contents of original Matrix and show copied Matrix is unchanged here

  std::cout<<a2;
  std::cout<<a4;

  // Move copy construction demonstration

  // Move assignment demonstration

  //
  // Second part of assignment: Matrix operations
  //

  // Addition of 2 matrices

  // Subtraction of 2 matrices

  // Multiplication of 2 matrices


  // Determinant

  
  return 0;
}