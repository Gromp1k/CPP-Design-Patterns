#include <string>
#include <sstream>
#include "./../Headers/Shapes.h"

Circle::Circle(const float& radius) : _radius{radius} {}

void Circle::resize(const float& factor){ _radius *= factor;}

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

ColoredShape::ColoredShape(const IShape& shape, const std::string& color) : _shape{shape}, _color{color} {}

ColoredShape::operator std::string() {
    std::ostringstream oss;
    oss << std::string(const_cast<IShape&>(_shape)) << " has the color " << _color;
    return oss.str();
}

TransparentShape::TransparentShape(const IShape& shape, const uint8_t& alpha) : _shape{shape}, _alpha{alpha} {}

TransparentShape::operator std::string(){
    std::ostringstream oss;
    oss << std::string(const_cast<IShape&>(_shape)) << " has " << static_cast<float>(_alpha) / 255.f * 100.f << " % transparency";
    return oss.str();
}