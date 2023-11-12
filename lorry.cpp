#include "lorry.h"

Lorry::Lorry(const QString &model, int year, double price, double maxSpeed, int cargoCapacity, const QString &cargoType)
    : Vehicle(model, year, price, maxSpeed), cargoCapacity(cargoCapacity), cargoType(cargoType) {}

int Lorry::getCargoCapacity() const {
    return cargoCapacity;
}

QString Lorry::getCargoType() const {
    return cargoType;
}

QString Lorry::getClassName() const {
    return "Lorry";
}

void Lorry::setCargoCapacity(int cargoCapacity) {
    this->cargoCapacity = cargoCapacity;
}

void Lorry::setCargoType(const QString &cargoType) {
    this->cargoType = cargoType;
}
