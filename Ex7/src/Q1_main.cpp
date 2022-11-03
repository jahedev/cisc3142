#include <iostream>
#include <string>

#include "Rectangle.h"

using namespace std;

void printEquality(Rectangle& rect1, Rectangle& rect2)
{
    string rectAreEqual = sameArea(rect1, rect2) ? "Yes" : "No";
    cout << "\nAre these rectangles equal?: " << rectAreEqual << endl;
}

void printRectInfo(Rectangle& rect, std::string name)
{
    cout << "Rectangle" << name << ":" << endl;
    Rectangle::printRect(rect);
}

int main() {
    // Part 2
    Rectangle rect1(5, 2.5);

    Rectangle rect2(5, 18.9);

    printRectInfo(rect1, "One");
    printRectInfo(rect1, "Two");

    // Part 3
    printEquality(rect1, rect2);

    rect1.setLength(15);
    rect2.setWidth(6.3);
    printRectInfo(rect1, "One");
    printRectInfo(rect1, "Two");
    printEquality(rect1, rect2);

    return 0;
}
