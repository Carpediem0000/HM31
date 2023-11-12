#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle {
private:
    int numDoors;
    QString fuelType;
public:
    Car(const QString &model, int year, double price, double maxSpeed, int numDoors, const QString &fuelType);

    // Геттеры и Сеттеры для специфичных полей Car
    int getNumDoors() const;
    QString getFuelType() const;
    void setNumDoors(int numDoors);
    void setFuelType(const QString &fuelType);

    QString getClassName()const override;
};

#endif // CAR_H
