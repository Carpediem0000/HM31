#ifndef EDITLORRYWINDOW_H
#define EDITLORRYWINDOW_H

#include <QDialog>
#include "garage.h"

namespace Ui {
class editLorryWindow;
}

class editLorryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editLorryWindow(QWidget *parent = nullptr, int ind=0, Garage *arr = nullptr);
    ~editLorryWindow();

private slots:
    void on_BackCPushButton_2_clicked();

    void on_editCPushButton_2_clicked();

private:
    Ui::editLorryWindow *ui;
    Garage* arr;
    int ind;
};

#endif // EDITLORRYWINDOW_H
