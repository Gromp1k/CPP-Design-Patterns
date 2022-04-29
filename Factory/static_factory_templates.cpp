#include <utility>
#include <string>
#include <iostream>
#include <memory>
#include <vector>

enum class IShapeType { TRIANGLE, RECTANGLE, CIRCLE };

template<IShapeType>
struct tag {};

class IShape{
public:
    IShape(){std::cout << "IShape() -> ";}
	virtual ~IShape(){std::cout << "~IShape()\n";}
	virtual void Render() = 0;
};

class Triangle : public IShape{
    public:
        Triangle(){ std::cout << "Triangle()\n"; }
        ~Triangle(){std::cout << "~Triangle() -> ";}
		
        void Render() override;
		
        static std::shared_ptr<IShape> Create(){return std::make_shared<Triangle>();}
};
void Triangle::Render(){ std::cout << "\n  *  \n * * \n*****\n"; }

class Rectangle : public IShape{
    public:
        Rectangle(){std::cout << "Rectangle()\n";}
        Rectangle(const std::string& a){std::cout << "Rectangle() with param: ["<< a << "]\n";}
		Rectangle(const std::string& a, const std::string& b){std::cout << "Rectangle() with params: ["<< a << "] [" << b <<"]\n";}
        ~Rectangle(){std::cout << "~Rectangle() -> ";}
        
        void Render() override;
        
        static std::shared_ptr<IShape> Create(){return std::make_shared<Rectangle>();}
        static std::shared_ptr<IShape> Create(const std::string& a){return std::make_shared<Rectangle>(a);}
        static std::shared_ptr<IShape> Create(const std::string& a, const std::string& b){return std::make_shared<Rectangle>(a,b);}
};
void Rectangle::Render(){ std::cout << "\n  *  \n * * \n*****\n"; }

class Circle : public IShape{
    public:
        Circle(){std::cout << "Circle()\n";}
		Circle(const std::string& r){std::cout << "Circle() with param: ["<< r <<"]\n";}
        ~Circle(){std::cout << "~Circle() -> ";}
		
        void Render() override;
		
        static std::shared_ptr<IShape> Create(){return std::make_shared<Circle>();}
        static std::shared_ptr<IShape> Create(const std::string& r){return std::make_shared<Circle>(r);}
};
void Circle::Render(){ std::cout << "\n  *  \n * * \n*****\n"; }

class ShapeFactory {
    public:
        template<IShapeType T, typename... A>
        static std::shared_ptr<IShape> Create(A&&... args) {return Create(tag<T>{}, std::forward<A>(args)...);}

    private:
        static std::shared_ptr<IShape> Create(tag<IShapeType::RECTANGLE>) {return Rectangle::Create(); }
        static std::shared_ptr<IShape> Create(tag<IShapeType::RECTANGLE>,const std::string& a) { return Rectangle::Create(a);}
		static std::shared_ptr<IShape> Create(tag<IShapeType::RECTANGLE>,const std::string& a, const std::string& b) { return Rectangle::Create(a,b);}
        
        static std::shared_ptr<IShape> Create(tag<IShapeType::CIRCLE>) {return Circle::Create(); }
        static std::shared_ptr<IShape> Create(tag<IShapeType::CIRCLE>,const std::string& a) { return Circle::Create(a);}
        
        static std::shared_ptr<IShape> Create(tag<IShapeType::TRIANGLE>) {return Triangle::Create();}
};

int main() {
    
    std::vector< std::shared_ptr<IShape> > shapeObjects;
    
    shapeObjects.push_back(ShapeFactory::Create<IShapeType::RECTANGLE>());
    shapeObjects.push_back(ShapeFactory::Create<IShapeType::RECTANGLE>("A"));
    shapeObjects.push_back(ShapeFactory::Create<IShapeType::RECTANGLE>("A","B"));
    
    shapeObjects.push_back(ShapeFactory::Create<IShapeType::CIRCLE>());
    shapeObjects.push_back(ShapeFactory::Create<IShapeType::CIRCLE>("R"));
    
    shapeObjects.push_back(ShapeFactory::Create<IShapeType::TRIANGLE>());
    
    for(const auto& object: shapeObjects) object->Render();
    
    
    return 0;
}
