#ifndef EDITCARWINDOW_H
#define EDITCARWINDOW_H

#include <QDialog>
#include "garage.h"

namespace Ui {
class editCarWindow;
}

class editCarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editCarWindow(QWidget *parent = nullptr, int ind=0, Garage *arr = nullptr);
    ~editCarWindow();

private slots:
    void on_BackCPushButton_clicked();

    void on_editCPushButton_clicked();

private:
    Ui::editCarWindow *ui;
    Garage* arr;
    int ind;
};

#endif // EDITCARWINDOW_H
