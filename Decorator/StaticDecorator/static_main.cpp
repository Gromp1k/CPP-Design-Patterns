#include <iostream>
#include "./Headers/Shapes.h"

int main(int argc, char const *argv[])
{
    Circle circle{5};
    circle.resize(3);
    std::cout << std::string(circle) << std::endl;

    ColoredShape<Circle> colCircle{"yellow",6};
    colCircle.resize(2);
    std::cout << std::string(colCircle) << std::endl;

    TransparentShape< ColoredShape<Square>> transColSquare{ 75, "purple", 16 };

    return 0;
}
