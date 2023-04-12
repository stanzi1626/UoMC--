#pragma once

#include "shape_class.h"

class Circle : public Shape2D
{
private:
    double m_radius;
public:
    Circle(): m_radius{0} {};
    Circle(double radius);
    ~Circle() {};
};

class Ellipse : public Shape2D
{
private:
    double m_majorAxis;
    double m_minorAxis;
public:
    Ellipse(): m_majorAxis{0}, m_minorAxis{0} {};
    Ellipse(double majorAxis, double minorAxis);
    ~Ellipse() {};
};

class Rectangle : public Shape2D
{
private:
    double m_width;
    double m_height;
public:
    Rectangle(): m_width{0}, m_height{0} {};
    Rectangle(double width, double height);
    ~Rectangle() {};
};

class Square : public Shape2D
{
private:
    double m_side;
public:
    Square(): m_side{0} {};
    Square(double side);
    ~Square() {};
};