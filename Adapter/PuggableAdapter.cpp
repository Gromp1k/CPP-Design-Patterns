//
// Created by Kacper on 16/09/2022.
//
#include <functional>
#include <iostream>
#include <memory>

using std::cout, std::endl;
/* -------------------------------------------------------------- */
struct Beverage {
    virtual void getBeverage() = 0;
};

struct CoffeeMaker : Beverage {
    void Brew() { cout << "brewing coffee" << endl;}
    void getBeverage() { Brew(); }
};

void make_drink(Beverage &drink){
    drink.getBeverage();
}
/* --------------------------------------------------------------------------- */
struct JuiceMaker {
    void Squeeze() { cout << "making Juice" << endl; }
};

struct Adapter : Beverage {
    std::function<void()>    m_request;
    Adapter(std::shared_ptr<CoffeeMaker> cm) { m_request = [cm]( ) { cm->Brew(); }; }
    Adapter(std::shared_ptr<JuiceMaker> jm) { m_request = [jm]( ) { jm->Squeeze(); }; }
    void getBeverage() { m_request(); }
};

int main() {
    auto coffeeMaker = std::make_shared<CoffeeMaker>();
    auto juiceMaker = std::make_shared<JuiceMaker>();
    Adapter adp1(coffeeMaker);
    make_drink(adp1);
    Adapter adp2(juiceMaker);
    make_drink(adp2);

    return 0;
}