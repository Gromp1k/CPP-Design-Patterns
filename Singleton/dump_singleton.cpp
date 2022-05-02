#include <iostream>

/*
    Static Singleton
    -all data members are static.
    -creating multi instances is possible BUT 
        all instances refer to the same context.
*/
class StaticSingleton{
    public :
        StaticSingleton() { /* */ }
        int& Get() { return value; }
    private:
        inline static int value = 0;
};

int main(int c, char** v){
    StaticSingleton ss1;
    ss1.Get() = 111;

    std::cout << "ss1 value:" << ss1.Get() << std::endl;

    StaticSingleton ss2(ss1);
    ss2.Get() = 222;

    std::cout << "ss1 value:" << ss1.Get() << std::endl;
    std::cout << "ss2 value:" << ss2.Get() << std::endl;

    StaticSingleton ss3 = ss1;
    ss3.Get() = 333;

    std::cout << "ss1 value:" << ss1.Get() << std::endl;
    std::cout << "ss2 value:" << ss2.Get() << std::endl;
    std::cout << "ss3 value:" << ss3.Get() << std::endl;
}