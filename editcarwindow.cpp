#include "editcarwindow.h"
#include "ui_editcarwindow.h"
#include <QIntValidator>
#include <QDoubleValidator>

editCarWindow::editCarWindow(QWidget *parent, int ind, Garage *arr) :
    QDialog(parent),
    ui(new Ui::editCarWindow)
{
    ui->setupUi(this);
    this->ind = ind;
    this->arr = arr;

    ui->CModellineEdit->setText(arr->returnObj(ind)->getModel());
    ui->CYearlineEdit->setText(QString::number(arr->returnObj(ind)->getYear()));
    ui->CCostlineEdit->setText(QString::number(arr->returnObj(ind)->getPrice()));
    ui->CSpeedlineEdit->setText(QString::number(arr->returnObj(ind)->getMaxSpeed()));
    ui->CDourlineEdit->setText(QString::number(((Car*)arr->returnObj(ind))->getNumDoors()));

    ui->CYearlineEdit->setValidator(new QIntValidator);
    ui->CCostlineEdit->setValidator(new QDoubleValidator);
    ui->CSpeedlineEdit->setValidator(new QDoubleValidator);
    ui->CDourlineEdit->setValidator(new QIntValidator);
}

editCarWindow::~editCarWindow()
{
    delete ui;
}

void editCarWindow::on_BackCPushButton_clicked()
{
    this->hide();
}


void editCarWindow::on_editCPushButton_clicked()
{
    QString model = ui->CModellineEdit->text();
    int year = ui->CYearlineEdit->text().toInt();
    double speed = ui->CSpeedlineEdit->text().toDouble();
    double price = ui->CCostlineEdit->text().toDouble();
    int numDoors = ui->CDourlineEdit->text().toInt();
    QString fuelType = ui->addCComboBox->currentText();

    if(ui->CModellineEdit->text().isEmpty() || ui->CYearlineEdit->text().isEmpty() || ui->CSpeedlineEdit->text().isEmpty() ||
        ui->CCostlineEdit->text().isEmpty() || ui->CDourlineEdit->text().isEmpty() || ui->addCComboBox->currentText().isEmpty()){}
    else {
        arr->returnObj(ind)->setModel(model);
        arr->returnObj(ind)->setYear(year);
        arr->returnObj(ind)->setMaxSpeed(speed);
        arr->returnObj(ind)->setPrice(price);
        ((Car*)arr->returnObj(ind))->setNumDoors(numDoors);
        ((Car*)arr->returnObj(ind))->setFuelType(fuelType);
        this->hide();
    }
}

