#ifndef RECHERCHE_PATIENT_2_H
#define RECHERCHE_PATIENT_2_H

#include <QDialog>

namespace Ui {
class Recherche_Patient_2;
}

class Recherche_Patient_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Recherche_Patient_2(QWidget *parent = nullptr);
    ~Recherche_Patient_2();

private slots:
    void on_pushButton_pressed();
    void on_pushButton_released();

private:
    Ui::Recherche_Patient_2 *ui;
};

#endif // RECHERCHE_PATIENT_2_H
