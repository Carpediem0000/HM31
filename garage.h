#ifndef GARAGE_H
#define GARAGE_H

#include <QVector>
#include "QListWidget"
#include <QString>
#include "vehicle.h"
#include "car.h"
#include "bicycle.h"
#include "lorry.h"

class Garage {
private:
    QVector<Vehicle*> arr;
public:
    Garage();
    ~Garage();

    int size()const;
    QString getType(int ind)const;
    Vehicle* returnObj(int ind)const;

    void addVehicle(Vehicle *vehicle);
    void removeVehicle(int index);
    void displayVehicles(QListWidget* qlw);
    void sortBy(int num);
};

#endif // GARAGE_H
