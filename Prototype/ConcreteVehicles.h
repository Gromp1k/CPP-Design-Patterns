//
// Created by Kacper on 05/08/2022.
//

#ifndef CPP_DESIGN_PATTERNS_AIRCRAFT_H
#define CPP_DESIGN_PATTERNS_AIRCRAFT_H

#include <memory>
#include <map>
#include "Vehicle.h"

class Aircraft : public Vehicle{
public:
    Aircraft();
    virtual std::unique_ptr<Vehicle> clone() override;
    virtual void listComponents() const override;
};

class Car : public Vehicle{
public:
    Car();
    virtual std::unique_ptr<Vehicle> clone() override;
    virtual void listComponents() const override;
};

class VehicleFactory{
public:
    VehicleFactory();

    enum VehicleType {
        AIRCRAFT, CAR
    };
    std::unique_ptr<Vehicle> createVehicle(VehicleType vehicleType);

private:
    std::map<VehicleType, std::unique_ptr<Vehicle>> prototypes;

};

#endif //CPP_DESIGN_PATTERNS_AIRCRAFT_H
