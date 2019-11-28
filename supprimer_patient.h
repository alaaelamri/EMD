#ifndef SUPPRIMER_PATIENT_H
#define SUPPRIMER_PATIENT_H

#include <QDialog>
#include "modifier_patient.h"
#include "recherche_patient_2.h"
namespace Ui {
class Supprimer_Patient;
}

class Supprimer_Patient : public QDialog
{
    Q_OBJECT

public slots:
    void openAfficher_Patient();
    void openRecherche_Patient_2();
    
public:
    explicit Supprimer_Patient(QWidget *parent = nullptr);
    ~Supprimer_Patient();

private slots:
    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::Supprimer_Patient *ui;
    Afficher_Patient *mafficher_Patient;
    Recherche_Patient_2 *mRecherche_Patient_2;
    
};

#endif // SUPPRIMER_PATIENT_H
