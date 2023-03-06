#include <iostream>

#include "complex_number_class.h"

void print_divider() {
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

int main()
{
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
        double real, imaginary;
        std::cout << "Enter the real part: ";
        std::cin >> real;
        std::cout << "Enter the imaginary part: ";
        std::cin >> imaginary;
        ComplexNumber complex_number_4(real, imaginary);
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