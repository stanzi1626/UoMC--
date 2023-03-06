#include <iostream>

#include "complex_number_class.h"

void print_divider() {
    std::cout << "--------------------------" << std::endl;
}

int main()
{
    ComplexNumber complex_number_1(1, 2);

    print_divider();
    std::cout << "Complex Number 1: " << complex_number_1 << std::endl << std::endl;
    std::cout << "Real: " << complex_number_1.getReal() << std::endl;
    std::cout << "Imaginary: " << complex_number_1.getImaginary() << std::endl;
    std::cout << "Modulus: " << complex_number_1.modulus() << std::endl;
    std::cout << "Argument: " << complex_number_1.argument() << std::endl;
    std::cout << "Complex Conjugate: " << complex_number_1.complex_conjugate() << std::endl;
    print_divider();


    ComplexNumber complex_number_2(3, 4);
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

    return 0;
}