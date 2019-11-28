#include "patient.h"
#include <QDebug>

Patient::Patient()
{
    nom="";
    prenom="";
    date="";
    lieu = "";
    CIN = "";
    adresse = "";
    sexe = "";

}
Patient::Patient(QString nom, QString prenom, QString date, QString lieu, QString CIN, QString adresse, QString sexe)
{
    this->nom = nom;
    this->prenom = prenom;
    this->date = date;
    this->lieu = lieu;
    this->CIN = CIN;
    this->adresse = adresse;
    this->sexe = sexe;
}

QString Patient::get_nom(){return  nom;}
QString Patient::get_prenom(){return prenom;}
QString Patient::get_date(){return  date;}
QString Patient::get_lieu(){return lieu;}
QString Patient::get_CIN(){return CIN;}
QString Patient::get_Adresse(){return  adresse;}
QString Patient::get_Sexe(){return sexe;}


bool Patient::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Patient (NOM, PRENOM, DATE, LIEU, CIN, ADRESSE, SEXE) "
                        "VALUES (:nom, :prenom, :date, :lieu, :CIN, :adresse, :sexe)");
    query.bindValue(":date", date);
    query.bindValue(":CIN", CIN);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":lieu", lieu);
    query.bindValue(":adresse", adresse);
    query.bindValue(":sexe", sexe);

    return
          query.exec();
}
QSqlQueryModel * Patient::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from TABLE_PATIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Sexe"));

    return model;
}

bool Patient::supprimer(QString nomm)
{
QSqlQuery query;
query.prepare("Delete from etudiant where Nom = :nom ");
query.bindValue(":nom", nomm);
return    query.exec();
}
