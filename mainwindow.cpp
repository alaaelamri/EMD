#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_patient.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(click()), this, SLOT(openGestionPatient()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openGestionPatient()
{
    mgestionPatient = new Gestion_Patient();

    mgestionPatient->show();
}

void MainWindow::on_pushButton_pressed()
{

}


void MainWindow::on_pushButton_released()
{
     openGestionPatient();
}
