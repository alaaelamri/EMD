#ifndef RECHERCHE_PATIENT_H
#define RECHERCHE_PATIENT_H

#include <QDialog>
#include "modifier.h"
namespace Ui {
class Recherche_Patient;
}

class Recherche_Patient : public QDialog
{
    Q_OBJECT

public slots:
    void open_Modifier(QString);
public:
    explicit Recherche_Patient(QWidget *parent = nullptr);
    ~Recherche_Patient();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::Recherche_Patient *ui;
    Modifier *Mmodifier;
};

#endif // RECHERCHE_PATIENT_H
