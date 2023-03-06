#include "complex_number_class.h"

#include <cmath>

ComplexNumber::ComplexNumber() {}

ComplexNumber::ComplexNumber(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

double ComplexNumber::getReal() const {
    return real;
}

double ComplexNumber::getImaginary() const {
    return imaginary;
}

void ComplexNumber::setReal(double real) {
    this->real = real;
}

void ComplexNumber::setImaginary(double imaginary) {
    this->imaginary = imaginary;
}

ComplexNumber ComplexNumber::complex_conjugate() const {
    return ComplexNumber(real, -imaginary);
}

double ComplexNumber::modulus() const {
    return sqrt(real * real + imaginary * imaginary);
}

double ComplexNumber::argument() const {
    return atan2(imaginary, real);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other_complex_number) const {
    return ComplexNumber(real + other_complex_number.real, imaginary + other_complex_number.imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other_complex_number) const {
    return ComplexNumber(real - other_complex_number.real, imaginary - other_complex_number.imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other_complex_number) const {
    return ComplexNumber(real * other_complex_number.real - imaginary * other_complex_number.imaginary,
                         real * other_complex_number.imaginary + imaginary * other_complex_number.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other_complex_number) const {
    double denominator = other_complex_number.real * other_complex_number.real + other_complex_number.imaginary * other_complex_number.imaginary;
    return ComplexNumber((real * other_complex_number.real + imaginary * other_complex_number.imaginary) / denominator,
                         (imaginary * other_complex_number.real - real * other_complex_number.imaginary) / denominator);
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex_number) {
    if (complex_number.imaginary < 0) {
        return os << complex_number.real << " - " << -complex_number.imaginary << "i";
    } else {
        return os << complex_number.real << " + " << complex_number.imaginary << "i";
    }
    return os;
}

std::istream& operator>>(std::istream& is, ComplexNumber& complex_number) {
    is >> complex_number.real >> complex_number.imaginary;
    return is;
}