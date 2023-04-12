#pragma once

#include "shape_class.h"

class Sphere : public Shape3D
{
private:
    double m_radius;
public:
    Sphere(): m_radius{0} {};
    Sphere(double radius);
    ~Sphere() {};
};

class Ellipsoid : public Shape3D
{
private:
    double m_majorAxis;
    double m_minorAxis;
    double m_minorAxis2;
public:
    Ellipsoid(): m_majorAxis{0}, m_minorAxis{0}, m_minorAxis2{0} {};
    Ellipsoid(double majorAxis, double minorAxis, double minorAxis2);
    ~Ellipsoid() {};
};

class Cube : public Shape3D
{
private:
    double m_side;
public:
    Cube(): m_side{0} {};
    Cube(double side);
    ~Cube() {};
};

class Cuboid : public Shape3D
{
private:
    double m_width;
    double m_height;
    double m_depth;
public:
    Cuboid(): m_width{0}, m_height{0}, m_depth{0} {};
    Cuboid(double width, double height, double depth);
    ~Cuboid() {};
};

class Prism : public Shape3D
{
private:
    Shape2D *m_base;
    double m_length;
public:
    Prism(): m_base{nullptr}, m_length{0} {};
    Prism(Shape2D *base, double length);
    ~Prism() {};
};