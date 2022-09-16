//
// Created by Kacper on 05/08/2022.
//
#include "./Vehicle.h"
#include "./ConcreteVehicles.h"

int main(){
    VehicleFactory factory;

    auto vehicle = factory.createVehicle(VehicleFactory::AIRCRAFT);
    vehicle->listComponents();
    vehicle->setVehicleName("Flying cucumber");
    vehicle->listComponents();

    auto vehicle2 = factory.createVehicle(VehicleFactory::CAR);
    vehicle2->addComponent("Turbo");
    vehicle2->listComponents();

    auto vehicle3 = factory.createVehicle(VehicleFactory::CAR);
    vehicle3->addComponent("Seat belts");
    vehicle3->setVehicleName("Toyota Supra");
    vehicle3->listComponents();

    vehicle->listComponents();
    vehicle2->listComponents();
    vehicle3->listComponents();
}
