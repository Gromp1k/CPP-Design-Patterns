//
// Created by Kacper on 05/08/2022.
//

#ifndef CPP_DESIGN_PATTERNS_VEHICLE_H
#define CPP_DESIGN_PATTERNS_VEHICLE_H

#include <memory>
#include <string>
class Vehicle {
protected:
    std::string m_components;
    std::string m_vehicleName;

public:
    Vehicle();
    virtual ~Vehicle(){}

    virtual std::unique_ptr<Vehicle> clone() = 0;
    virtual void listComponents() const = 0;

    virtual void addComponent(std::string component);
    virtual void setVehicleName(std::string vehicleName);;
};


#endif //CPP_DESIGN_PATTERNS_VEHICLE_H
