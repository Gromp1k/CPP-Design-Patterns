#include <iostream>
#include <string>
#include "./Headers/Shapes.h"

int main(int argc, char const *argv[])
{

    Circle circle{4};

    ColoredShape col_square{ Square{5}, "red"};

    TransparentShape trans_circle{ ColoredShape{Circle{8},"yellow"},73};
 
    IShape* list[3] = {&circle, &col_square, &trans_circle};

    for(auto e: list){
        std::cout << std::string(*e) << std::endl;
    }
    return 0;
}
