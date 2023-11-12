#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>
#include <QListWidget>

class Vehicle {
protected:
    QString model;
    int year;
    double price;
    double maxSpeed;
public:
    Vehicle(const QString &model, int year, double price, double maxSpeed);
    virtual ~Vehicle();

    void displayInfo(QListWidget* qlw) const;

    // Геттеры
    int getYear() const;
    double getPrice() const;
    double getMaxSpeed() const;
    virtual QString getClassName()const = 0;
    QString getModel()const;

    // Сеттеры
    void setModel(const QString &model);
    void setYear(int year);
    void setPrice(double price);
    void setMaxSpeed(double maxSpeed);
};

#endif // VEHICLE_H
