#include "2DShapes.h"

#include <cmath>

Circle::Circle(double radius) : m_radius(radius)
/**
 * @brief Construct a new Circle object, calculates area and perimeter
 * @param radius
 * 
 */
{
    m_name = "Circle";
    m_area = PI * m_radius * m_radius;
    m_perimeter = 2 * PI * m_radius;
}

Ellipse::Ellipse(double majorAxis, double minorAxis) : m_majorAxis(majorAxis), m_minorAxis(minorAxis)
/**
 * @brief Construct a new Ellipse object, calculates area and perimeter
 * @param majorAxis, minorAxis
 * 
 */
{
    m_name = "Ellipse";
    m_area = PI * m_majorAxis * m_minorAxis;
    m_perimeter = 2 * PI * std::sqrt((m_majorAxis * m_majorAxis + m_minorAxis * m_minorAxis) / 2);
}

Rectangle::Rectangle(double width, double height) : m_width(width), m_height(height)
/**
 * @brief Construct a new Rectangle object, calculates area and perimeter
 * @param width, height
 * 
 */
{
    m_name = "Rectangle";
    m_area = m_width * m_height;
    m_perimeter = 2 * (m_width + m_height);
}

Square::Square(double side) : m_side{side}
/**
 * @brief Construct a new Square object, calculates area and perimeter
 * @param side
 * 
 */
{
    m_name = "Square";
    m_area = m_side * m_side;
    m_perimeter = 4 * m_side;
}