#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
/*
 * Singleton == only one instance with global access 
*/
enum class VehicleType { VOLVO, TOYOTA };

class IVehicle{ 
    public: 
    virtual void GetDetails()=0; 
    virtual ~IVehicle(){};
};

class Volvo : public IVehicle {
    public:
        Volvo(){std::cout << "Volvo!\n";}
        void GetDetails() override{ std::cout << "Volvo Details!\n";}
        static IVehicle* Create(){ return new Volvo;}
};

class Toyota : public IVehicle {
    public:
        Toyota(){ std::cout << "Toyota!\n";}     
        void GetDetails() override{std::cout << "Toyota Details!\n";}
        static IVehicle* Create(){ return new Toyota;}
};

class VehicleFactory
{
    public:
        VehicleFactory(VehicleFactory const&) = delete;
        VehicleFactory& operator=(VehicleFactory const&) = delete;
        
        static VehicleFactory& getInstance(){
            static VehicleFactory instance;
            return instance;
        }

        static std::vector<VehicleType> GetKeys(){
            std::vector<VehicleType> keys;
            for(const auto& [k,_]: map) keys.push_back(k);
            return keys;
        }

        static IVehicle* CreateObject(VehicleType key){ return map[key](); }

    private:
        VehicleFactory() { }
        typedef IVehicle* (*Callback)();
        inline static std::unordered_map<VehicleType,Callback> map =
        { 
            {VehicleType::TOYOTA, Toyota::Create},
            {VehicleType::VOLVO, Volvo::Create}
        };
};

int main(int argc, char** argv){
    //auto factory = VehicleFactory();
    //factory = VehicleFactory::getInstance();
    //std::cout << &VehicleFactory::getInstance() << '\n';
    for(const auto& key: VehicleFactory::GetKeys() ){
        IVehicle* object = VehicleFactory::CreateObject(key);
        object->GetDetails();
        delete object;
    }   
}