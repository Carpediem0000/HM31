#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "garage.h"
#include "car.h"
#include "bicycle.h"
#include "lorry.h"
#include "vehicle.h"

#include "addbicyclewindow.h"
#include "addcarwindow.h"
#include "addlorrywindow.h"
#include "editcarwindow.h"
#include "editbicuclewindow.h"
#include "editlorrywindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_activated(int index);

    void on_addVehicleBtn_clicked();

    void on_removeVehicleBtn_clicked();

    void on_editVehicleBtn_clicked();

private:
    Ui::MainWindow *ui;
    AddBicycleWindow *addBicycleWindow;
    AddCarWindow *addCarWindow;
    AddLorryWindow *addLorryWindow;
    editBicucleWindow *editBicycleWindow;
    editCarWindow *editCarWindows;
    editLorryWindow *editLorryWindows;
    Garage* arr;
};
#endif // MAINWINDOW_H
