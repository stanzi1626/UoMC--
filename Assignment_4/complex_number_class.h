#pragma once

#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    ComplexNumber();
    ComplexNumber(double real, double imaginary);
    double getReal() const;
    double getImaginary() const;
    void setReal(double real);
    void setImaginary(double imaginary);
    ComplexNumber complex_conjugate() const;
    double modulus() const;
    double argument() const;
    ComplexNumber operator+(const ComplexNumber& other_complex_number) const;
    ComplexNumber operator-(const ComplexNumber& other_complex_number) const;
    ComplexNumber operator*(const ComplexNumber& other_complex_number) const;
    ComplexNumber operator/(const ComplexNumber& other_complex_number) const;
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex_number);
    bool break_down_complex_number(std::istream& is, double& real, double& imaginary);
    friend std::istream& operator>>(std::istream& is, ComplexNumber& complex_number);
};