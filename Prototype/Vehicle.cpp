//
// Created by Kacper on 05/08/2022.
//

#include "Vehicle.h"
#include <iostream>
Vehicle::Vehicle(): m_components{"Engine\nFuel tanks"},m_vehicleName{"Some default vehicle"}{}

void Vehicle::setVehicleName(std::string vehicleName) {
    this->m_vehicleName = vehicleName;
}

void Vehicle::addComponent(std::string component) {
    this->m_components+=("\n" + component);
}