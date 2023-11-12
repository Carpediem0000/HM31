#ifndef EDITBICUCLEWINDOW_H
#define EDITBICUCLEWINDOW_H

#include <QDialog>
#include "garage.h"
#include "bicycle.h"

namespace Ui {
class editBicucleWindow;
}

class editBicucleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editBicucleWindow(QWidget *parent = nullptr, int ind=0, Garage *arr = nullptr);
    ~editBicucleWindow();


private slots:
    void on_BackBPushButton_clicked();

    void on_editBPushButton_clicked();

private:
    Ui::editBicucleWindow *ui;
    Garage* arr;
    int ind;
};

#endif // EDITBICUCLEWINDOW_H
