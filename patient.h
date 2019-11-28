#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Patient
{
public:
    Patient();
    Patient(QString, QString, QString, QString, QString, QString, QString);
    QString get_nom();
    QString get_prenom();
    QString get_date();
    QString get_lieu();
    QString get_CIN();
    QString get_Adresse();
    QString get_Sexe();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
private:
    QString nom, prenom, lieu, adresse, sexe, date, CIN;
};

#endif // PATIENT_H
