
#include <string>
#include <sstream>
#include "./../Headers/Shapes.h"

Circle::Circle(const float& radius) : _radius{radius} {}

void Circle::resize(float factor){ _radius *= factor;}

Circle::operator std::string(){
    std::ostringstream oss;
    oss << "A circle of radius : " << _radius;
    return oss.str();
}

Square::Square(const float& side) : _side{side} {}

Square::operator std::string(){
    std::ostringstream oss;
    oss << "A square of side: " << _side;
    return oss.str();
}

