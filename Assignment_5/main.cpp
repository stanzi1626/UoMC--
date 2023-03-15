//  PHYS 30762 Programming in C++
//  Assignment 5 - A Matrix class
//  Created by Alexander Stansfield 15/03/2023

//  Look at preamble.h for description of programme

#include<iostream>
#include "Matrix_class.h"

void print_divider()
{
/**
 * @brief This function prints a divider to the console
 * 
 */
    std::cout << "========================================" << std::endl;
}

void answer_check(char &answer)
{
/**
 * @brief This function checks if the answer entered by the user is valid, has to be either 'y' or 'n'
 * @param answer
 */
  do {
      std::cin >> answer;

      if (answer != 'y' && answer != 'n' || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Please enter a valid option." << std::endl;
            std::cout << "Answer: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            continue;
      } else break;
  } while (true);
}

void user_option(Matrix &matrixA)
{
/**
 * @brief This function asks the user if they would like to input their own matrix for matrixA
 * @param matrixA
 */
    std::cout << "Would you like to input your own matrix for matrixA? (y/n)" << std::endl;
    std::cout << "Answer: ";
    char answer;
    answer_check(answer);
    if (answer == 'y') {
        std::cout << "Please enter the values for matrixA: " << std::endl;
        std::cin >> matrixA;
    } else {
        std::cout << "Using default values for matrixA" << std::endl;
        matrixA = Matrix{3, 3};
        matrixA(1,1)=1;
        matrixA(1,2)=2;
        matrixA(1,3)=3;
        matrixA(2,1)=9;
        matrixA(2,2)=8;
        matrixA(2,3)=7;
        matrixA(3,1)=4;
        matrixA(3,2)=2;
        matrixA(3,3)=6;
    }
}

int main()
{
    Matrix matrixA;
    Matrix matrixB{3, 3};
    Matrix matrixC{2, 3};

    user_option(matrixA);

    // Set values for matrixB here
    matrixB(1,1)=5;
    matrixB(1,2)=5;
    matrixB(1,3)=4;
    matrixB(2,1)=1;
    matrixB(2,2)=2;
    matrixB(2,3)=3;
    matrixB(3,1)=6;
    matrixB(3,2)=9;
    matrixB(3,3)=8;

    // Set values for matrixC here
    matrixC(1,1)=3;
    matrixC(1,2)=4;
    matrixC(1,3)=1;
    matrixC(2,1)=2;
    matrixC(2,2)=5;
    matrixC(2,3)=6;

    // Print matrices
    std::cout << matrixA << std::endl;
    std::cout << matrixB << std::endl;
    std::cout << matrixC << std::endl;
    // Addition of 2 matrices
    std::cout << matrixA + matrixB << std::endl;
    // Subtraction of 2 matrices
    std::cout << matrixA - matrixB << std::endl;
    // Multiplication of 2 matrices
    std::cout << matrixA * matrixB << std::endl;
    // std::cout << matrixA * matrixC << std::endl;
    // Determinant
    std::cout << matrixA.determinant() << std::endl;
    std::cout << matrixB.determinant() << std::endl;
    std::cout << matrixC.determinant() << std::endl;

    return 0;
}