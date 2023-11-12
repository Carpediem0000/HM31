#include "addcarwindow.h"
#include "ui_addcarwindow.h"
#include <QIntValidator>
#include <QDoubleValidator>

AddCarWindow::AddCarWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCarWindow)
{
    ui->setupUi(this);
    arr = nullptr;

    ui->CYearlineEdit->setValidator(new QIntValidator);
    ui->CCostlineEdit->setValidator(new QDoubleValidator);
    ui->CSpeedlineEdit->setValidator(new QDoubleValidator);
    ui->CDourlineEdit->setValidator(new QIntValidator);
}

AddCarWindow::~AddCarWindow()
{
    arr = nullptr;
    delete ui;
}

void AddCarWindow::setGarage(Garage* arr) {
    this->arr = arr;
}

void AddCarWindow::on_BackCPushButton_clicked()
{
    this->hide();
}


void AddCarWindow::on_addCPushButton_clicked()
{
    QString model = ui->CModellineEdit->text();
    int year = ui->CYearlineEdit->text().toInt();
    int dour = ui->CDourlineEdit->text().toInt();
    double speed = ui->CSpeedlineEdit->text().toDouble();
    double price = ui->CCostlineEdit->text().toDouble();

    if(ui->CModellineEdit->text().isEmpty() || ui->CYearlineEdit->text().isEmpty() || ui->CDourlineEdit->text().isEmpty() ||
        ui->CSpeedlineEdit->text().isEmpty() || ui->CCostlineEdit->text().isEmpty() || (ui->addCComboBox->currentIndex() == 0)){}
    else {
        QString fuel = ui->addCComboBox->currentText();
        arr->addVehicle(new Car(model, year, price, speed, dour, fuel));
        this->hide();
    }
}

