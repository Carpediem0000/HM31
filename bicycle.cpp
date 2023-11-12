#include "bicycle.h"

Bicycle::Bicycle(const QString &model, int year, double price, double maxSpeed, int numWheels)
    : Vehicle(model, year, price, maxSpeed), numWheels(numWheels) {}

int Bicycle::getNumWheels() const {
    return numWheels;
}

QString Bicycle::getClassName() const {
    return "Bicycle";
}

void Bicycle::setNumWheels(int numWheels) {
    this->numWheels = numWheels;
}
