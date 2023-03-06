#include "complex_number_class.h"

#include <cmath>

ComplexNumber::ComplexNumber() {}

ComplexNumber::ComplexNumber(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

double ComplexNumber::getReal() const
{
    return real;
}

double ComplexNumber::getImaginary() const
{
    return imaginary;
}

void ComplexNumber::setReal(double real)
{
    this->real = real;
}

void ComplexNumber::setImaginary(double imaginary)
{
    this->imaginary = imaginary;
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
    if (complex_number.imaginary < 0) {
        return os << complex_number.real << " - " << -complex_number.imaginary << "i";
    } else if (complex_number.imaginary == 0) {
        return os << complex_number.real;
    } else if (complex_number.real == 0) {
        return os << complex_number.imaginary << "i";
    } else if (complex_number.real == 0 && complex_number.imaginary == 0) {
        return os << 0;
    } else if (complex_number.imaginary == 1) {
        return os << complex_number.real << " + i";
    } else if (complex_number.imaginary == -1) {
        return os << complex_number.real << " - i";
    } else {
        return os << complex_number.real << " + " << complex_number.imaginary << "i";
    }
}

bool ComplexNumber::break_down_complex_number(std::istream& input, double& real_input, double& imaginary_input)
{
    char filter;
    double temp;
    char next;
    if (input >> temp) {
        next = input.peek();
        if (next != 'i') {
            real_input = temp;
            if (next == ' ') {
                input >> next;
            }
            if (next == '+' || next == '-') {
                if (input >> imaginary_input >> filter  && filter == 'i') {
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
            imaginary_input = temp;
            input >> filter;
            return true;
        }
    }
    return false;
}

std::istream& operator>>(std::istream& input, ComplexNumber& complex_number)
{
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