#include "vehicle.h"


Vehicle::Vehicle(const QString &model, int year, double price, double maxSpeed)
    : model(model), year(year), price(price), maxSpeed(maxSpeed) {}

Vehicle::~Vehicle() {}

void Vehicle::displayInfo(QListWidget* qlw)const {
    QListWidgetItem *item = new QListWidgetItem(getClassName()+" - "+getModel()+" - "+QString::number(getYear())+" - "+QString::number(getMaxSpeed())+
                                                " km/h - "+QString::number(getPrice())+"$");
    qlw->addItem(item);
}

QString Vehicle::getModel() const {
    return model;
}

int Vehicle::getYear() const {
    return year;
}

double Vehicle::getMaxSpeed() const {
    return maxSpeed;
}

double Vehicle::getPrice() const {
    return price;
}

void Vehicle::setModel(const QString &model) {
    this->model = model;
}

void Vehicle::setYear(int year) {
    this->year = year;
}

void Vehicle::setPrice(double price) {
    this->price = price;
}

void Vehicle::setMaxSpeed(double maxSpeed) {
    this->maxSpeed = maxSpeed;
}
