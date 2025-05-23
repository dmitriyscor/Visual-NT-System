#include "CircleClass.h"
#include <sstream>

// Constructor
CircleClass::CircleClass(const std::string& name, int x, int y, int radius)
    : name(name), x(x), y(y), radius(radius) {}

// Move the circle to a new position
void CircleClass::Move(int newX, int newY)
{
    x = newX;
    y = newY;
}

// Get a string representation of the circle
std::string CircleClass::ToString() const
{
    std::ostringstream oss;
    oss << "Circle(Name: " << name << ", X: " << x << ", Y: " << y << ", Radius: " << radius << ")";
    return oss.str();
}
