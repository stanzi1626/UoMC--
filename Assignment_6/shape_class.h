#pragma once

#include <iostream>
#include <string>
#include <iomanip>

const double PI = 3.14159265358979323846;

class Shape
{
public:
    virtual ~Shape() {};
    virtual void info() = 0;
};

class Shape2D : public Shape
{
protected:
    double m_area;
    double m_perimeter;
    std::string m_name;
public:
    virtual ~Shape2D() {};

    std::string getName() { return m_name; }
    double getArea() { return m_area; }
    double getPerimeter() { return m_perimeter; }

    void info() {
        std::cout.setf(std::ios::fixed, std::ios::floatfield);
        std::cout << "Shape2D, Name: " << m_name << std::endl;
        std::cout << "Area: " << std::setprecision(2) << m_area << std::endl;
        std::cout << "Perimeter: " << std::setprecision(2) << m_perimeter << std::endl;
    }
};

class Shape3D : public Shape
{
protected:
    double m_volume;
    double m_surfaceArea;
    std::string m_name = "Shape3D";
public:
    virtual ~Shape3D() {};

    void info() {
        std::cout.setf(std::ios::fixed, std::ios::floatfield);
        std::cout << "Shape3D, Name: " << m_name << std::endl;
        std::cout << "Volume: " << std::setprecision(2) << m_volume << std::endl;
        std::cout << "Surface Area: " << std::setprecision(2) << m_surfaceArea << std::endl;
    }
};