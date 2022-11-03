//
// Created by Jahed Hossain on 11/9/22.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>

class Rectangle
{
private:
    float length = 0.0;
    float width = 0.0;

public:
    // CONSTRUCTORS
    Rectangle() = default;
    Rectangle(float l, float w): length(l), width(w) {}

    // SETTERS
    void setLength(float length)
    {
        this->length = length;
    }

    void setWidth(float width)
    {
        this->width = width;
    }

    // PUBLIC METHODS
    float perimeter() const
    {
        return 2*length + 2*width;
    }

    float area() const
    {
        return length * width;
    }

    void show() const
    {
        std::cout << "Length: " <<  length
        << ", Width: " << width << std::endl;
    }

    friend int sameArea(const Rectangle& rect1, const Rectangle& rect2)
    {   // returns 1 or 0:
        return rect1.length == rect2.length &&
                rect1.width == rect2.width;
    }

    static void printRect(Rectangle&);
};

int sameArea(const Rectangle&, const Rectangle&);

void Rectangle::printRect(Rectangle& rect)
{
    rect.show(); // print length and width
    std::cout << "Area: " << std::to_string(rect.area()) << std::endl;
    std::cout << "Perimeter: " << std::to_string(rect.perimeter()) << std::endl;
}

#endif //RECTANGLE_H
