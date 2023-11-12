#include "car.h"

Car::Car(const QString &model, int year, double price, double maxSpeed, int numDoors, const QString &fuelType)
    : Vehicle(model, year, price, maxSpeed), numDoors(numDoors), fuelType(fuelType) {}

int Car::getNumDoors() const {
    return numDoors;
}

QString Car::getFuelType() const {
    return fuelType;
}

void Car::setNumDoors(int numDoors) {
    this->numDoors = numDoors;
}

void Car::setFuelType(const QString &fuelType) {
    this->fuelType = fuelType;
}

QString Car::getClassName()const {
    return "Car";
}
