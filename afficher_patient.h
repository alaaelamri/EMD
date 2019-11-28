#ifndef AFFICHER_PATIENT_H
#define AFFICHER_PATIENT_H

#include <QDialog>
#include "patient.h"
namespace Ui {
class Afficher_Patient;
}

class Afficher_Patient : public QDialog
{
    Q_OBJECT

public:
    explicit Afficher_Patient(QWidget *parent = nullptr);
    ~Afficher_Patient();

private slots:
    void on_Button_R_A_clicked();

private:
    Ui::Afficher_Patient *ui;
};

#endif // AFFICHER_PATIENT_H
