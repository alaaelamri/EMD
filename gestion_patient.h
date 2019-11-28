#ifndef GESTION_PATIENT_H
#define GESTION_PATIENT_H

#include <QDialog>
#include <QApplication>
#include "ajouter_patient.h"
#include "modifier_patient.h"
#include "supprimer_patient.h"
namespace Ui {
class Gestion_Patient;
}

class Gestion_Patient : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion_Patient(QWidget *parent = nullptr);
    ~Gestion_Patient();

public slots:
    void open_Ajouter_Patient();

    void open_Modifier_Patient();

    void open_Supprimer_Patient();

private slots:

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

private :
    Ui::Gestion_Patient *ui;
    Ajouter_Patient *mAjouterPatient;
    Modifier_Patient *mModifierPatient;
    Supprimer_Patient *mSupprimerPatient;

};

#endif // GESTION_PATIENT_H
