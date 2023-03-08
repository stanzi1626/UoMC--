#include "complex_number_class.h"

#include <cmath>

ComplexNumber::ComplexNumber() {}

ComplexNumber::ComplexNumber(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

double ComplexNumber::get_real() const
{
    return real;
}

double ComplexNumber::get_imaginary() const
{
    return imaginary;
}

ComplexNumber ComplexNumber::complex_conjugate() const
{
    return ComplexNumber(real, -imaginary);
}

double ComplexNumber::modulus() const
{
    return sqrt(real * real + imaginary * imaginary);
}

double ComplexNumber::argument() const
{
    return atan2(imaginary, real);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other_complex_number) const
{
    return ComplexNumber(real + other_complex_number.real, imaginary + other_complex_number.imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other_complex_number) const
{
    return ComplexNumber(real - other_complex_number.real, imaginary - other_complex_number.imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other_complex_number) const
{
    return ComplexNumber(real * other_complex_number.real - imaginary * other_complex_number.imaginary,
                         real * other_complex_number.imaginary + imaginary * other_complex_number.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other_complex_number) const
{
    double denominator = other_complex_number.real * other_complex_number.real + other_complex_number.imaginary * other_complex_number.imaginary;
    return ComplexNumber((real * other_complex_number.real + imaginary * other_complex_number.imaginary) / denominator,
                         (imaginary * other_complex_number.real - real * other_complex_number.imaginary) / denominator);
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex_number)
{
/**
 * @brief This function is used to print out the complex number in the form of a + bi with edge cases
 * @param os, complex_number
 */
    if (complex_number.imaginary == 0) {
        return os << complex_number.real;
    } else if (complex_number.real == 0) {
        if (complex_number.imaginary == 1) {
            return os << "i";
        } else if (complex_number.imaginary == -1) {
            return os << "-i";
        } else {
            return os << complex_number.imaginary << "i";
        }
    } else if (complex_number.real == 0 && complex_number.imaginary == 0) {
        return os << 0;
    } else if (complex_number.imaginary == 1) {
        return os << complex_number.real << " + i";
    } else if (complex_number.imaginary == -1) {
        return os << complex_number.real << " - i";
    } else if (complex_number.imaginary < 0) {
        return os << complex_number.real << " - " << -complex_number.imaginary << "i";
    } else {
        return os << complex_number.real << " + " << complex_number.imaginary << "i";
    }
}

bool ComplexNumber::break_down_complex_number(std::istream& input, double& real_input, double& imaginary_input)
{
/**
 * @brief This function is used to break down the user's complex number into real and imaginary parts and return true if the input is valid
 * with edge cases
 * @param input, real_input, imaginary_input
 */
    char filter;
    double temp;
    char next;

    if (input >> filter && filter == 'i' && std::cin.peek() == '\n') {
        real_input = 0.0;
        imaginary_input = 1.0;
        return true;
    }
    std::cin.unget();
    if (input >> filter && filter == '-') {
        if (input >> filter && filter == 'i' && std::cin.peek() == '\n') {
            real_input = 0.0;
            imaginary_input = -1.0;
            return true;
        }
    }
    std::cin.unget();
    if (input >> temp) {
        next = input.peek();
        if (next != 'i') {
            real_input = temp;
            if (next == ' ') {
                input >> next;
            }
            if (next == '+' || next == '-') {
                if (input >> filter && filter == 'i' && std::cin.peek() == '\n') {
                    if (next == '-') {
                        imaginary_input = -1.0;
                        return true;
                    } else {
                        imaginary_input = 1.0;
                        return true;
                    }
                }
                std::cin.unget();
                if (input >> imaginary_input >> filter  && filter == 'i' && std::cin.peek() == '\n') {
                    if (next == '-' && imaginary_input > 0) {
                        imaginary_input = -imaginary_input;
                        return true;
                    } else {
                        return true;
                    }
                }
            } else {
                return true;
            }
        } else {
            if (input >> filter && filter == 'i' && std::cin.peek() == '\n') {
                real_input = 0.0;
                imaginary_input = temp;
                return true;
            }
        }
    }
    return false;
}

std::istream& operator>>(std::istream& input, ComplexNumber& complex_number)
{
/**
 * @brief This function overloads the >> operator to take in the user's complex number and returns the input true if it is valid
 * 
 */
    double real = 0.0;
    double imag = 0.0;

    if (complex_number.break_down_complex_number(input, real, imag)) {
        complex_number.real = real;
        complex_number.imaginary = imag;
        input.clear();
        return input;
    }
    input.setstate(std::ios::failbit);
    return input;
}