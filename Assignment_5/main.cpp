//  PHYS 30762 Programming in C++
//  Assignment 5 - A Matrix class
//  Created by Alexander Stansfield 15/03/2023

//  Look at preamble.h for description of programme

#include<iostream>
#include "Matrix_class.h"

void print_divider()
{
/**
 * @brief Prints a divider to the console
 * 
 */
    std::cout << "========================================" << std::endl << std::endl;
}

void answer_check(char &answer)
{
/**
 * @brief Checks if the answer entered by the user is valid, has to be either 'y' or 'n'
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
 * @brief Asks the user if they would like to input their own matrix for matrixA
 * @param matrixA
 */
    std::cout << "Would you like to input your own matrix for matrixA? (y/n)" << std::endl;
    std::cout << "Answer: ";
    char answer;
    answer_check(answer);
    if (answer == 'y') {
        std::cout << "Please enter the values in the following format: [a, b, ...][c, d, ...][...]" << std::endl;
        std::cout << "where the number of elements in each square brackets (i.e. # of columns) is the same" << std::endl << std::endl;
        std::cout << "Please enter the values for matrixA: ";
        Matrix temp_matrix;
        std::cin >> temp_matrix;
        matrixA = temp_matrix;
        temp_matrix.~Matrix();
        std::cout << "Matrix is valid" << std::endl;
        print_divider();
    } else {
        std::cout << "Using default values for matrixA" << std::endl;
        print_divider();
        // Set values for matrixA
        double matrixA_data[9] = {1, 2, 3, 9, 8, 7, 4, 5, 6};
        matrixA = Matrix{3, 3, matrixA_data};
    }
}

int main()
{
/**
 * @brief Main function, read preamble.h for description of programme
 * 
 */
    // Set values for matrixA
    double matrixA_data[9] = {1, 2, 3, 9, 8, 7, 4, 5, 6};
    Matrix matrixA{3, 3, matrixA_data};

    // Set values for matrixB
    double matrixB_data[9] = {5, 5, 4, 1, 2, 3, 6, 9, 8};
    Matrix matrixB{3, 3, matrixB_data};

    // Set values for matrixC
    double matrixC_data[6] = {1, 2, 3, 4, 5, 6};
    Matrix matrixC{2, 3, matrixC_data};

    // Print matrices
    std::cout<< "Printing matrices" << std::endl;
    std::cout << "Matrix A: " << std::endl;
    std::cout << matrixA << std::endl;
    std::cout << "Matrix B: " << std::endl;
    std::cout << matrixB << std::endl;
    std::cout << "Matrix C: " << std::endl;
    std::cout << matrixC << std::endl;
    print_divider();

    // Addition of 2 matrices
    std::cout << "Adding matrixA and matrixB:" << std::endl;
    std::cout << matrixA + matrixB << std::endl;
    print_divider();

    // Subtraction of 2 matrices
    std::cout << "Subtracting matrixA and matrixB:" << std::endl;
    std::cout << matrixA - matrixB << std::endl;
    print_divider();

    // Multiplication of 2 matrices
    std::cout << "Multiplying matrixA and matrixB:" << std::endl;
    std::cout << matrixA * matrixB << std::endl << std::endl;

    // If using default values for matrixA, this will not work. Uncomment to test
    // std::cout << "Multiplying matrixA and matrixC:" << std::endl;
    // std::cout << matrixA * matrixC << std::endl;
    print_divider();

    // User input for matrixA
    user_option(matrixA);
    print_divider();

    // Determinant
    std::cout << "Determinant of matrixA: ";
    std::cout << matrixA.determinant() << std::endl;
    std::cout << "Determinant of matrixB: ";
    std::cout << matrixB.determinant() << std::endl;
    // std::cout << "Determinant of matrixC: ";
    // std::cout << matrixC.determinant() << std::endl;
    print_divider();

    // Copy matrixA into matrixD, mani


    return 0;
}