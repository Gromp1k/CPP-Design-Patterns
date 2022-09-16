//
// Created by Kacper on 05/08/2022.
//

#include <memory>
#include <iostream>
#include "ConcreteVehicles.h"

Aircraft::Aircraft() {
    this->addComponent("Wings");
}

std::unique_ptr<Vehicle> Aircraft::clone() {
    return std::make_unique<Aircraft>(*this);
}

void Aircraft::listComponents() const {
    std::cout
    << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n"
    << "This is the aircraft object: " << m_vehicleName
    << "\nComponents of the aircraft:\n" << m_components << "\n"
    << "\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
}

Car::Car() {
    this->addComponent("Shift gear");
}

std::unique_ptr<Vehicle> Car::clone() {
    return std::make_unique<Car>(*this);
}

void Car::listComponents() const {
    std::cout
    << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n"
    << "This is the car object: " << m_vehicleName
    << "\nComponents of the car:\n" << m_components
    << "\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
}

VehicleFactory::VehicleFactory() {
    prototypes[VehicleType::AIRCRAFT] = std::make_unique<Aircraft>();
    prototypes[VehicleType::CAR] = std::make_unique<Car>();
}

std::unique_ptr<Vehicle> VehicleFactory::createVehicle(VehicleType vehicleType){
    return prototypes[vehicleType]->clone();
}