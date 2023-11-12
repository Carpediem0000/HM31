#include "editbicuclewindow.h"
#include "ui_editbicuclewindow.h"
#include <QIntValidator>
#include <QDoubleValidator>

editBicucleWindow::editBicucleWindow(QWidget *parent, int ind, Garage *arr) :
    QDialog(parent),
    ui(new Ui::editBicucleWindow)
{
    this->ind = ind;
    this->arr = arr;
    ui->setupUi(this);

    ui->BModellineEdit->setText(arr->returnObj(ind)->getModel());
    ui->BYearlineEdit->setText(QString::number(arr->returnObj(ind)->getYear()));
    ui->BCostlineEdit->setText(QString::number(arr->returnObj(ind)->getPrice()));
    ui->BSpeedlineEdit->setText(QString::number(arr->returnObj(ind)->getMaxSpeed()));
    ui->BWeellineEdit->setText(QString::number(((Bicycle*)arr->returnObj(ind))->getNumWheels()));

    ui->BCostlineEdit->setValidator(new QDoubleValidator);
    ui->BSpeedlineEdit->setValidator(new QDoubleValidator);
    ui->BWeellineEdit->setValidator(new QIntValidator);
    ui->BYearlineEdit->setValidator(new QIntValidator);
}

editBicucleWindow::~editBicucleWindow()
{
    delete ui;
}

void editBicucleWindow::on_BackBPushButton_clicked()
{
    this->hide();
}


void editBicucleWindow::on_editBPushButton_clicked()
{
    QString model = ui->BModellineEdit->text();
    int year = ui->BYearlineEdit->text().toInt();
    int wheal = ui->BWeellineEdit->text().toInt();
    double speed = ui->BSpeedlineEdit->text().toDouble();
    double price = ui->BCostlineEdit->text().toDouble();

    if(ui->BCostlineEdit->text().isEmpty() || ui->BModellineEdit->text().isEmpty() || ui->BSpeedlineEdit->text().isEmpty() ||
        ui->BWeellineEdit->text().isEmpty() || ui->BYearlineEdit->text().isEmpty()){}
    else {
        arr->returnObj(ind)->setModel(model);
        arr->returnObj(ind)->setYear(year);
        arr->returnObj(ind)->setMaxSpeed(speed);
        arr->returnObj(ind)->setPrice(price);
        ((Bicycle*)arr->returnObj(ind))->setNumWheels(wheal);
        this->hide();
    }
}

