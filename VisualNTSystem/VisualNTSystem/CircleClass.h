#pragma once

#include <string>

class CircleClass
{
public:
    std::string name; // Name of the circle
    int x;            // X-coordinate of the circle's position
    int y;            // Y-coordinate of the circle's position
    int radius;       // Radius of the circle

    // Constructor
    CircleClass(const std::string& name, int x, int y, int radius);

    // Optional: Add methods for future functionality
    void Move(int newX, int newY); // Move the circle to a new position
    std::string ToString() const; // Get a string representation of the circle
};
