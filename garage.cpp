#include "garage.h"
#include "QListWidgetItem"
#include "QStringList"
#include <algorithm>

Garage::Garage() {}

Garage::~Garage() {
    // Освобождаем память, выделенную под транспортные средства
    qDeleteAll(arr);
}

void Garage::addVehicle(Vehicle *vehicle) {
    arr.append(vehicle);
}

void Garage::removeVehicle(int index) {
    arr.remove(index);
}

int Garage::size()const {
    return arr.size();
}

QString Garage::getType(int ind)const {
    return arr[ind]->getClassName();
}

Vehicle* Garage::returnObj(int ind)const {
    return arr[ind];
}

void Garage::displayVehicles(QListWidget* qlw) {
    for (Vehicle* vehicle : arr) {
        vehicle->displayInfo(qlw);
    }
}

void Garage::sortBy(int num) {
    if (num == 1){
        std::sort(arr.begin(), arr.end(), [](const Vehicle* left, const Vehicle* right){
                return left->getClassName() < right->getClassName();});
    }
    else if (num == 2){
        std::sort(arr.begin(), arr.end(), [](const Vehicle* left, const Vehicle* right){
            return left->getMaxSpeed() > right->getMaxSpeed();});
    }
    else if (num == 3){
        std::sort(arr.begin(), arr.end(), [](const Vehicle* left, const Vehicle* right){
            return left->getPrice() > right->getPrice();});
    }
    else if (num == 4){
        std::sort(arr.begin(), arr.end(), [](const Vehicle* left, const Vehicle* right){
            return left->getYear() > right->getYear();});
    }
}

void Garage::search(QListWidget* qlw, Vehicle* obj){
    obj->displayInfo(qlw);
}

bool compareStringsIgnoreCase(const Vehicle* obj, const QString& str2) {
    QString model = obj->getModel();
    int length1 = model.length();
    int length2 = str2.length();
    int minLength = std::min(length1, length2);

    for (int i = 0; i < minLength; ++i) {
        if (model[i].toLower() != str2[i].toLower()) {
            return false;
        }
    }

    return true;
}
