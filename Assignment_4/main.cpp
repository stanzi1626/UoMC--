#include <iostream>

#include "complex_number_class.h"

void print_divider()
{
/**
 * @brief This function prints a divider to separate the output of the program
 */
    std::cout << "--------------------------" << std::endl;
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
        } else {
            break;
        }
    } while (true);
}

void complex_number_check(ComplexNumber &complex_number)
{
/**
 * @brief This function checks if the complex number entered by the user is valid
 * @param complex_number
 */
    do {
        std::cin >> complex_number;

        if (std::cin.fail()) {
            std::cout << "Please enter a valid complex number." << std::endl;
            std::cout << "Complex Number: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            continue;
        } else {
            break;
        }
    } while (true);
}

int main()
{
/**
 * @brief This is the main function of the program that creates two complex numbers and performs
 * some operations on them, then asks the user if they want to input their own complex number
 */
    ComplexNumber complex_number_1(3, 4);

    print_divider();
    std::cout << "Complex Number 1: " << complex_number_1 << std::endl << std::endl;
    std::cout << "Real: " << complex_number_1.getReal() << std::endl;
    std::cout << "Imaginary: " << complex_number_1.getImaginary() << std::endl;
    std::cout << "Modulus: " << complex_number_1.modulus() << std::endl;
    std::cout << "Argument: " << complex_number_1.argument() << std::endl;
    std::cout << "Complex Conjugate: " << complex_number_1.complex_conjugate() << std::endl;
    print_divider();

    ComplexNumber complex_number_2(1, -2);
    print_divider();
    std::cout << "Complex Number 2: " << complex_number_2 << std::endl << std::endl;
    std::cout << "Real: " << complex_number_2.getReal() << std::endl;
    std::cout << "Imaginary: " << complex_number_2.getImaginary() << std::endl;
    std::cout << "Modulus: " << complex_number_2.modulus() << std::endl;
    std::cout << "Argument: " << complex_number_2.argument() << std::endl;
    std::cout << "Complex Conjugate: " << complex_number_2.complex_conjugate() << std::endl;
    print_divider();

    print_divider();
    ComplexNumber complex_number_3 = complex_number_1 + complex_number_2;
    std::cout << "Addition: " << complex_number_3 << std::endl;
    complex_number_3 = complex_number_1 - complex_number_2;
    std::cout << "Subtraction: " << complex_number_3 << std::endl;
    complex_number_3 = complex_number_1 * complex_number_2;
    std::cout << "Multiplication: " << complex_number_3 << std::endl;
    complex_number_3 = complex_number_1 / complex_number_2;
    std::cout << "Division: " << complex_number_3 << std::endl;
    print_divider();

    print_divider();
    std::cout << "Would you like to input your own complex number? (y/n): ";
    char input;
    answer_check(input);
    if (input == 'y') {
        ComplexNumber complex_number_4;
        std::cout << "Please input your complex number of the form a+bi or a + bi, where a and b are real numbers." << std::endl;
        std::cout << "(Note: Can also not input b if b = 1, i.e. 1 + i is a valid input)" << std::endl;
        std::cout << "Complex Number: ";
        complex_number_check(complex_number_4);
        print_divider();
        std::cout << "User's Complex Number: " << complex_number_4 << std::endl << std::endl;
        std::cout << "Real: " << complex_number_4.getReal() << std::endl;
        std::cout << "Imaginary: " << complex_number_4.getImaginary() << std::endl;
        std::cout << "Modulus: " << complex_number_4.modulus() << std::endl;
        std::cout << "Argument: " << complex_number_4.argument() << std::endl;
        std::cout << "Complex Conjugate: " << complex_number_4.complex_conjugate() << std::endl;
        print_divider();
    }

    return 0;
}