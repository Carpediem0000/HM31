#ifndef ADDCARWINDOW_H
#define ADDCARWINDOW_H

#include <QDialog>
#include "car.h"
#include "garage.h"

namespace Ui {
class AddCarWindow;
}

class AddCarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddCarWindow(QWidget *parent = nullptr);
    ~AddCarWindow();

    void setGarage(Garage* arr);

private slots:
    void on_BackCPushButton_clicked();

    void on_addCPushButton_clicked();

private:
    Ui::AddCarWindow *ui;
    Garage* arr;
};

#endif // ADDCARWINDOW_H
