#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

// base abstract class with pure virtual function
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
		
        void Render() override{ std::cout << "\n  *  \n * * \n*****\n"; }
		
        static std::shared_ptr<IShape> Create(){return std::make_shared<Triangle>();}
};

class Rectangle : public IShape{
    public:
        Rectangle(){std::cout << "Rectangle()\n";}
        ~Rectangle(){std::cout << "~Rectangle() -> ";}
		
        void Render() override{ std::cout << "\n***\n* *\n***\n"; }
		
        static std::shared_ptr<IShape> Create(){return std::make_shared<Rectangle>();}
};

class Circle : public IShape{
    public:
        Circle(){std::cout << "Circle()\n";}
        //Circle(const std::string& r){std::cout << "Circle("<<r<<")\n";}
        ~Circle(){std::cout << "~Circle() -> ";}
        
		void Render() override{ std::cout << "\n *** \n*   *\n*   *\n *** \n"; }
		
        static std::shared_ptr<IShape> Create(){return std::make_shared<Circle>();}
		//static std::shared_ptr<IShape> Create(const std::string& r){return std::make_shared<Circle>(r);}
};


class ShapeFactory{
    public:
        typedef std::shared_ptr<IShape> (*ShapeCreateCallback)();// callback/delegate for creating <IShape> objects
        
        static void RegisterObject(const std::string& type, ShapeCreateCallback cb){ map[type] = cb; } // map.insert(std::make_pair(type,cb)); 
        static void UnregisterObject(const std::string& type){ map.erase(type); }
        
        static std::shared_ptr<IShape> CreateObject(const std::string& type){
            std::unordered_map<std::string, ShapeCreateCallback>::iterator it = map.find(type);
            return (it!=map.end()) ? (it->second)() : nullptr;
        }
        
    private:
        inline static std::unordered_map<std::string, ShapeCreateCallback> map; //inline due to [abi:cxx11] compiler error
};

int main(int argc, char** argv){
    ShapeFactory::RegisterObject("CIRCLE",Circle::Create);
    ShapeFactory::RegisterObject("TRIANGLE",Triangle::Create);
	//ShapeFactory::RegisterObject("TRIANGLE_PARAM",Triangle::Create("z"));
    ShapeFactory::RegisterObject("RECTANGLE",Rectangle::Create);
	//ShapeFactory::UnregisterObject("RECTANGLE");
    
    std::vector<std::shared_ptr<IShape> > shapeObjects;
    
   shapeObjects.push_back(ShapeFactory::CreateObject("CIRCLE"));
   shapeObjects.push_back(ShapeFactory::CreateObject("TRIANGLE"));
   shapeObjects.push_back(ShapeFactory::CreateObject("RECTANGLE"));
   
    
    for(const auto& object: shapeObjects) object->Render();
    
    return 0;
}
