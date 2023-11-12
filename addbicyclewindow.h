#ifndef ADDBICYCLEWINDOW_H
#define ADDBICYCLEWINDOW_H

#include <QDialog>
#include "garage.h"
#include "bicycle.h"

namespace Ui {
class AddBicycleWindow;
}

class AddBicycleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddBicycleWindow(QWidget *parent = nullptr);
    ~AddBicycleWindow();

    void setGarage(Garage* arr);

private slots:
    void on_BackBPushButton_clicked();

    void on_addBPushButton_clicked();

private:
    Ui::AddBicycleWindow *ui;
    Garage* arr;
};

#endif // ADDBICYCLEWINDOW_H
