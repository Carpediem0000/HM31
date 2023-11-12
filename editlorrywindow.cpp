#include "editlorrywindow.h"
#include "ui_editlorrywindow.h"
#include <QIntValidator>
#include <QDoubleValidator>

editLorryWindow::editLorryWindow(QWidget *parent, int ind, Garage *arr) :
    QDialog(parent),
    ui(new Ui::editLorryWindow)
{
    ui->setupUi(this);
    this->ind = ind;
    this->arr = arr;

    ui->LModellineEdit_2->setText(arr->returnObj(ind)->getModel());
    ui->LYearlineEdit_2->setText(QString::number(arr->returnObj(ind)->getYear()));
    ui->LCostlineEdit_2->setText(QString::number(arr->returnObj(ind)->getPrice()));
    ui->LSpeedlineEdit_2->setText(QString::number(arr->returnObj(ind)->getMaxSpeed()));
    ui->LCargoCaplineEdit_2->setText(QString::number(((Lorry*)arr->returnObj(ind))->getCargoCapacity()));
    ui->LTypelineEdit_2->setText(((Lorry*)arr->returnObj(ind))->getCargoType());

    ui->LCostlineEdit_2->setValidator(new QDoubleValidator);
    ui->LCargoCaplineEdit_2->setValidator(new QIntValidator);
    ui->LSpeedlineEdit_2->setValidator(new QDoubleValidator);
    ui->LYearlineEdit_2->setValidator(new QIntValidator);
}

editLorryWindow::~editLorryWindow()
{
    delete ui;
}

void editLorryWindow::on_BackCPushButton_2_clicked()
{
    this->hide();
}


void editLorryWindow::on_editCPushButton_2_clicked()
{
    QString model = ui->LModellineEdit_2->text();
    int year = ui->LYearlineEdit_2->text().toInt();
    double speed = ui->LSpeedlineEdit_2->text().toDouble();
    double price = ui->LCostlineEdit_2->text().toDouble();
    int cargoCapacity = ui->LCargoCaplineEdit_2->text().toInt();
    QString cargoType = ui->LTypelineEdit_2->text();

    if(ui->LModellineEdit_2->text().isEmpty() || ui->LYearlineEdit_2->text().isEmpty() || ui->LSpeedlineEdit_2->text().isEmpty() ||
        ui->LCostlineEdit_2->text().isEmpty() || ui->LCargoCaplineEdit_2->text().isEmpty() || ui->LTypelineEdit_2->text().isEmpty()){}
    else {
        arr->returnObj(ind)->setModel(model);
        arr->returnObj(ind)->setYear(year);
        arr->returnObj(ind)->setMaxSpeed(speed);
        arr->returnObj(ind)->setPrice(price);
        ((Lorry*)arr->returnObj(ind))->setCargoCapacity(cargoCapacity);
        ((Lorry*)arr->returnObj(ind))->setCargoType(cargoType);
        this->hide();
    }
}

