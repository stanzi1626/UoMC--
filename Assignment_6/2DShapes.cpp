#include "2DShapes.h"

#include <cmath>

Circle::Circle(double radius) : m_radius(radius)
{
    m_name = "Circle";
    m_area = 3.14159 * m_radius * m_radius;
    m_perimeter = 2 * 3.14159 * m_radius;
}

Ellipse::Ellipse(double majorAxis, double minorAxis) : m_majorAxis(majorAxis), m_minorAxis(minorAxis)
{
    m_name = "Ellipse";
    m_area = 3.14159 * m_majorAxis * m_minorAxis;
    m_perimeter = 2 * 3.14159 * std::sqrt((m_majorAxis * m_majorAxis + m_minorAxis * m_minorAxis) / 2);
}

Rectangle::Rectangle(double width, double height) : m_width(width), m_height(height)
{
    m_name = "Rectangle";
    m_area = m_width * m_height;
    m_perimeter = 2 * (m_width + m_height);
}

Square::Square(double side) : m_side{side}
{
    m_name = "Square";
    m_area = m_side * m_side;
    m_perimeter = 4 * m_side;
}