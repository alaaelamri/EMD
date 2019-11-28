#ifndef AJOUTER_PATIENT_H
#define AJOUTER_PATIENT_H

#include <QDialog>

namespace Ui {
class Ajouter_Patient;
}

class Ajouter_Patient : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter_Patient(QWidget *parent = nullptr);
    ~Ajouter_Patient();

private slots:

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_radioMale_clicked();

    void on_radioFemelle_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Ajouter_Patient *ui;
};

#endif // AJOUTER_PATIENT_H
