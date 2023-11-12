#ifndef LORRY_H
#define LORRY_H


#include "vehicle.h"

class Lorry : public Vehicle {
private:
    int cargoCapacity;
    QString cargoType;
public:
    Lorry(const QString &model, int year, double price, double maxSpeed, int cargoCapacity, const QString &cargoType);

    // Геттеры и Сеттеры для специфичных полей Lorry
    int getCargoCapacity() const;
    QString getCargoType() const;
    void setCargoCapacity(int cargoCapacity);
    void setCargoType(const QString &cargoType);

    QString getClassName()const override;
};
#endif // LORRY_H
