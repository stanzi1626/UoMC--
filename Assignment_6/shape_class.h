#pragma once

#include <iostream>
#include <string>

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
        std::cout << "Shape2D, Name: " << m_name << std::endl;
        std::cout << "Area: " << m_area << std::endl;
        std::cout << "Perimeter: " << m_perimeter << std::endl;
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
        std::cout << "Shape3D, Name: " << m_name << std::endl;
        std::cout << "Volume: " << m_volume << std::endl;
        std::cout << "Surface Area: " << m_surfaceArea << std::endl;
    }
};