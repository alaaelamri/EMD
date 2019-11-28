#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestion_patient.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void openGestionPatient();

private slots:

    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
    Gestion_Patient *mgestionPatient;
};

#endif // MAINWINDOW_H
