#include <iostream>
#include <memory>

/*
 * Singleton == only one instance with global access 
*/
class Singleton
{
public:
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;

    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
    int& Val(){ return val; }
    void print() { std::cout << val << '\n';}

private:
    Singleton() { val = 0;}
    int val=0;
};



int main(int argc, char** argv){
    for(int i=0; i < 10; ++i){
    Singleton::getInstance().Val()=i;
    Singleton::getInstance().print();   
    }
    
}