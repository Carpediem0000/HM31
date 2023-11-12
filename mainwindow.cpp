#include "mainwindow.h"
#include "addbicyclewindow.h"
#include "./ui_mainwindow.h"

#include "QListWidget"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Garage");
    arr = new Garage();

    arr->addVehicle(new Car("Car1", 2022, 50000, 200, 4, "Gasoline"));
    arr->addVehicle(new Car("Car2", 2022, 4000, 280, 4, "Gasoline"));
    arr->addVehicle(new Car("Car3", 2022, 12000, 150, 4, "Gasoline"));
    arr->addVehicle(new Car("Car4", 2022, 3500, 180, 4, "Gasoline"));
    arr->addVehicle(new Car("Car5", 2022, 9000, 220, 4, "Gasoline"));
    arr->addVehicle(new Bicycle("Bicycle1", 2010, 100, 60, 2));
    arr->addVehicle(new Bicycle("Bicycle2", 2007, 70, 40, 2));
    arr->addVehicle(new Bicycle("Bicycle3", 2003, 400, 30, 2));
    arr->addVehicle(new Lorry("Lorry1", 2012, 70000, 120, 15, "Food"));
    arr->addVehicle(new Lorry("Lorry2", 2010, 70000, 120, 10, "Gas"));
    arr->addVehicle(new Lorry("Lorry3", 2023, 130000, 120, 4, "Bread"));
    arr->addVehicle(new Lorry("Lorry3", 2023, 130000, 120, 4, "Bread"));
    arr->addVehicle(new Lorry("Lorry3", 2023, 130000, 120, 4, "Bread"));
    arr->addVehicle(new Lorry("Lorry3", 2023, 130000, 120, 4, "Bread"));
    arr->addVehicle(new Lorry("Lorry3", 2023, 130000, 120, 4, "Bread"));
    arr->addVehicle(new Lorry("Lorry3", 2023, 130000, 120, 4, "Bread"));
    arr->addVehicle(new Lorry("Lorry3", 2023, 130000, 120, 4, "Bread"));
    arr->addVehicle(new Lorry("Lorry3", 2023, 130000, 120, 4, "Bread"));
    arr->displayVehicles((ui->listWidget));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_activated(int index)
{
    arr->sortBy(index);
    ui->listWidget->clear();
    arr->displayVehicles((ui->listWidget));
}


void MainWindow::on_addVehicleBtn_clicked()
{
    int ind = ui->addComboBox->currentIndex();
    if (ind == 1){
        addCarWindow = new AddCarWindow(this);
        addCarWindow->setGarage(arr);
        addCarWindow->setWindowTitle("Add Car");
        addCarWindow->setModal(true);
        addCarWindow->exec();
    }
    else if (ind == 2){
        addBicycleWindow = new AddBicycleWindow(this);
        addBicycleWindow->setGarage(arr);
        addBicycleWindow->setWindowTitle("Add Bicycle");
        addBicycleWindow->setModal(true);
        addBicycleWindow->exec();
    }
    else if (ind == 3){
        addLorryWindow = new AddLorryWindow(this);
        addLorryWindow->setGarage(arr);
        addLorryWindow->setWindowTitle("Add Lorry");
        addLorryWindow->setModal(true);
        addLorryWindow->exec();
    }
    ui->listWidget->clear();
    arr->displayVehicles((ui->listWidget));
}


void MainWindow::on_removeVehicleBtn_clicked()
{
    int ind = ui->listWidget->currentRow();
    if(ind != -1){
        arr->removeVehicle(ind);
        ui->listWidget->clear();
        arr->displayVehicles((ui->listWidget));
    }
}


void MainWindow::on_editVehicleBtn_clicked()
{
    int index = ui->listWidget->currentRow();
    if (index != -1){
        if (arr->getType(index) == "Car"){
            std::cout << "Car"<<std::endl;
            editCarWindows = new editCarWindow(this, index, arr);
            editCarWindows->setWindowTitle("Edit Car");
            editCarWindows->setModal(true);
            editCarWindows->exec();
        }
        else if (arr->getType(index) == "Bicycle"){
            std::cout << "Bicycle"<<std::endl;
            editBicycleWindow = new editBicucleWindow(this, index, arr);
            editBicycleWindow->setWindowTitle("Edit Bicucle");
            editBicycleWindow->setModal(true);
            editBicycleWindow->exec();
        }
        else if (arr->getType(index) == "Lorry"){
            std::cout << "Lorry"<<std::endl;
            editLorryWindows = new editLorryWindow(this, index, arr);
            editLorryWindows->setWindowTitle("Edit Lorry");
            editLorryWindows->setModal(true);
            editLorryWindows->exec();
        }
        ui->listWidget->clear();
        arr->displayVehicles((ui->listWidget));
    }
}

