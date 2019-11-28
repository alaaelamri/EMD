#ifndef MODIFIER_PATIENT_H
#define MODIFIER_PATIENT_H

#include <QDialog>
#include "recherche_patient.h"
#include "afficher_patient.h"
namespace Ui {
class Modifier_Patient;
}

class Modifier_Patient : public QDialog
{
    Q_OBJECT

public:
    explicit Modifier_Patient(QWidget *parent = nullptr);
    ~Modifier_Patient();

public slots:
    void openRecherche_Patient();
    void openAfficher_Patient();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Modifier_Patient *ui;
    Recherche_Patient *mrecherche_Patient;
    Afficher_Patient *mafficher_Patient;
};

#endif // MODIFIER_PATIENT_H
