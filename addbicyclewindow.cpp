#include "addbicyclewindow.h"
#include "ui_addbicyclewindow.h"
#include <QIntValidator>
#include <QDoubleValidator>

AddBicycleWindow::AddBicycleWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBicycleWindow)
{
    ui->setupUi(this);
    arr = nullptr;

    ui->BCostlineEdit->setValidator(new QDoubleValidator);
    ui->BSpeedlineEdit->setValidator(new QDoubleValidator);
    ui->BWeellineEdit->setValidator(new QIntValidator);
    ui->BYearlineEdit->setValidator(new QIntValidator);
}

AddBicycleWindow::~AddBicycleWindow()
{
    arr = nullptr;
    delete ui;
}

void AddBicycleWindow::setGarage(Garage *arr) {
    this->arr = arr;
}

void AddBicycleWindow::on_BackBPushButton_clicked()
{
    this->hide();
}


void AddBicycleWindow::on_addBPushButton_clicked()
{
    QString model = ui->BModellineEdit->text();
    int year = ui->BYearlineEdit->text().toInt();
    int wheal = ui->BWeellineEdit->text().toInt();
    double speed = ui->BSpeedlineEdit->text().toDouble();
    double price = ui->BCostlineEdit->text().toDouble();

    if(ui->BCostlineEdit->text().isEmpty() || ui->BModellineEdit->text().isEmpty() || ui->BSpeedlineEdit->text().isEmpty() ||
        ui->BWeellineEdit->text().isEmpty() || ui->BYearlineEdit->text().isEmpty()){}
    else {
        arr->addVehicle(new Bicycle(model, year, price, speed, wheal));
        this->hide();
    }
}

