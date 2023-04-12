#include <iostream>
#include <vector>

#include "2DShapes.h"
#include "3DShapes.h"

void print_divider()
{
    std::cout << "----------------------------------------" << std::endl;
}

int main()
{
    std::vector <Shape*> shapes;

    shapes.push_back(new Circle(5));
    shapes.push_back(new Ellipse(5, 10));
    shapes.push_back(new Rectangle(5, 10));
    shapes.push_back(new Square(5));
    shapes.push_back(new Sphere(5));
    shapes.push_back(new Ellipsoid(5, 10, 15));
    shapes.push_back(new Cuboid(5, 10, 15));
    shapes.push_back(new Cube(5));
    shapes.push_back(new Prism(new Circle(5), 10));

    for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it)
    {
        (*it)->info();
        print_divider();
    }

    return 0;
}