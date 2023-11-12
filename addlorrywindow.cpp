#include "addlorrywindow.h"
#include "ui_addlorrywindow.h"
#include <QIntValidator>
#include <QDoubleValidator>

AddLorryWindow::AddLorryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLorryWindow)
{
    ui->setupUi(this);
    arr = nullptr;

    ui->LCostlineEdit->setValidator(new QDoubleValidator);
    ui->LCargoCaplineEdit->setValidator(new QIntValidator);
    ui->LSpeedlineEdit->setValidator(new QDoubleValidator);
    ui->LYearlineEdit->setValidator(new QIntValidator);
}

AddLorryWindow::~AddLorryWindow()
{
    arr = nullptr;
    delete ui;
}

void AddLorryWindow::setGarage(Garage *arr) {
    this->arr = arr;
}

void AddLorryWindow::on_BackCPushButton_clicked()
{
    this->hide();
}


void AddLorryWindow::on_addCPushButton_clicked()
{
    QString model = ui->LModellineEdit->text();
    int year = ui->LYearlineEdit->text().toInt();
    double speed = ui->LSpeedlineEdit->text().toDouble();
    double price = ui->LCostlineEdit->text().toDouble();
    int cargoCapacity = ui->LCargoCaplineEdit->text().toInt();
    QString type = ui->LTypelineEdit->text();

    if(ui->LCargoCaplineEdit->text().isEmpty() || ui->LCostlineEdit->text().isEmpty() || ui->LModellineEdit->text().isEmpty() ||
        ui->LSpeedlineEdit->text().isEmpty() || ui->LTypelineEdit->text().isEmpty() || ui->LYearlineEdit->text().isEmpty()){}
    else {
        arr->addVehicle(new Lorry(model, year, price, speed, cargoCapacity, type));
        this->hide();
    }
}

