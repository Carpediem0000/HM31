#ifndef BICYCLE_H
#define BICYCLE_H

#include "vehicle.h"

class Bicycle : public Vehicle {
private:
    int numWheels;
public:
    Bicycle(const QString &model, int year, double price, double maxSpeed, int numWheels);

    // Геттеры и Сеттеры для специфичных полей Bicycle
    int getNumWheels() const;
    void setNumWheels(int numWheels);

    QString getClassName()const override;
};

#endif // BICYCLE_H
