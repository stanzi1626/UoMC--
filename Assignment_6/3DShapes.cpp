#include "3DShapes.h"

#include <cmath>

Sphere::Sphere(double radius) : m_radius(radius)
{
    m_name = "Sphere";
    m_volume = 4.0 / 3.0 * 3.14159 * m_radius * m_radius * m_radius;
    m_surfaceArea = 4 * 3.14159 * m_radius * m_radius;
}

Ellipsoid::Ellipsoid(double majorAxis, double minorAxis, double minorAxis2)
    : m_majorAxis(majorAxis), m_minorAxis(minorAxis), m_minorAxis2(minorAxis2)
{
    m_name = "Ellipsoid";
    m_volume = 4.0 / 3.0 * 3.14159 * m_majorAxis * m_minorAxis * m_minorAxis2;
    m_surfaceArea = 4 * 3.14159 * std::sqrt((m_majorAxis * m_majorAxis + m_minorAxis * m_minorAxis + m_minorAxis2 * m_minorAxis2) / 3);
}

Cube::Cube(double side) : m_side(side)
{
    m_name = "Cube";
    m_volume = m_side * m_side * m_side;
    m_surfaceArea = 6 * m_side * m_side;
}

Cuboid::Cuboid(double width, double height, double depth)
: m_width(width), m_height(height), m_depth(depth)
{
    m_name = "Cuboid";
    m_volume = m_width * m_height * m_depth;
    m_surfaceArea = 2 * (m_width * m_height + m_width * m_depth + m_height * m_depth);
}

Prism::Prism(Shape2D *base, double length) : m_base(base), m_length(length)
{
    m_name = "Prism -> w/ base of " + m_base->getName();
    m_volume = m_base->getArea() * m_length;
    m_surfaceArea = 2 * m_base->getArea() + m_base->getPerimeter() * m_length;
}