#ifndef ADDLORRYWINDOW_H
#define ADDLORRYWINDOW_H

#include <QDialog>
#include "garage.h"
#include "lorry.h"

namespace Ui {
class AddLorryWindow;
}

class AddLorryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddLorryWindow(QWidget *parent = nullptr);
    ~AddLorryWindow();

    void setGarage(Garage* arr);

private slots:
    void on_BackCPushButton_clicked();

    void on_addCPushButton_clicked();

private:
    Ui::AddLorryWindow *ui;
    Garage* arr;
};

#endif // ADDLORRYWINDOW_H
