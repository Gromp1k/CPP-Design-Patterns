#include <iostream>
#include <string>
#include <vector>
#include <memory>

class IShape{
public:
    IShape(){std::cout << "IShape() -> ";}
	virtual ~IShape(){std::cout << "~IShape()\n";}
	virtual void Render() = 0;
};

class Triangle : public IShape{
    public:
        Triangle(){ std::cout << "Triangle()\n"; }
		~Triangle(){ std::cout << "~Triangle() -> "; }
        void Render() override{ std::cout << "\n  *  \n * * \n*****\n"; }
};

class Rectangle : public IShape{
    public:
        Rectangle(){std::cout << "Rectangle\n";}
		~Rectangle(){ std::cout << "~Rectangle() -> "; }
         void Render() override{ std::cout << "\n***\n* *\n***\n"; }
};

class Circle : public IShape{
    public:
        Circle(){std::cout << "Circle\n";}
		~Circle(){ std::cout << "~Circle() -> "; }
        void Render() override{ std::cout << "\n *** \n*   *\n*   *\n *** \n"; }
};

// So-called Factory method
IShape* CreateIShapeObject(const std::string& type){
    if(type == "triangle") return new Triangle;
	else if(type == "circle") return new Circle;
    else if(type =="rectangle") return new Rectangle;
}

/*
	Factory - Creational Design Pattern
	purpose : avoid directly creating instances of object(s) -> encapsulate HOW object is created
*/
int main(int argc, char** argv){
    IShape* t1 = CreateIShapeObject("triangle");
    IShape* t2 = CreateIShapeObject("rectangle");
    IShape* t3 = CreateIShapeObject("circle");
	std::vector<IShape*> shapeObjects{ t1,t2,t3 };
	/*
	IShape* t4 = CreateIShapeObject("rhombus");
	shapeObjects.push_back(t4);
	shapeObjects.push_back(CreateIShapeObject("rectegle"));
	*/
	for(IShape* object: shapeObjects) {
		object->Render();
		delete object;
	}
    return 0;
}
