#include "modifier.h"
#include "ui_modifier.h"
#include <QSqlDatabase>
#include <qpixmap.h>
#include <QMessageBox>
#include <QSqlError>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"
#include <QSqlRecord>

Modifier::Modifier(QWidget *parent, QString nom):QDialog(parent),ui(new Ui::Modifier)
{
    QString prenom, date, cin, lieu, adresse, sexe;
    ui->setupUi(this);
    QPixmap pix("D:/Projet C++/Projet/Ressource/Background_color.png");
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));
    QPixmap pix1("D:/Projet C++/Projet/Ressource/icon_edit.png");
    int w1 = ui->label->width();
    int h1 = ui->label->height();
    ui->label->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));
    QPixmap pix2("D:/Projet C++/Projet/Ressource/checked.png");
    int w2 = ui->label_10->width();
    int h2 = ui->label_10->height();
    ui->label_10->setPixmap(pix2.scaled(w2,h2,Qt::IgnoreAspectRatio));
    QPixmap pix3("D:/Projet C++/Projet/Ressource/cancel.png");
    int w3 = ui->label_11->width();
    int h3 = ui->label_11->height();
    ui->label_11->setPixmap(pix3.scaled(w3,h3,Qt::IgnoreAspectRatio));
    ui->pushButton->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 20pt Bahnschrift;");
    ui->pushButton_3->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
    QSqlQuery query;
    ui->nomEdit->setText(nom);
  
}
Modifier::~Modifier()
{
    delete ui;
}

void Modifier::on_pushButton_2_pressed()
{

}
void Modifier::on_pushButton_2_released()
{
    QString nom,CIN,date,adresse,sexe,prenom,lieu;
    QSqlQuery query;
    date = ui->dateEdit->text();
    CIN = ui->CINEdit->text();
    nom = ui->nomEdit->text();
    prenom = ui->prenomEdit->text();
    lieu = ui->LieuEdit->text();
    sexe = ui->SexeEdit->text();
    adresse = ui->adresseEdit->text();
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_clicked.png)3 10 3 10; font: 20pt Bahnschrift;");
    if(query.prepare("Select from TABLE_PATIENT where NOM = '"+nom+"'") == false)
    {
        QMessageBox::information(this, tr("Modifier Patient"), tr("Veuillez entrer un nom de patient deja existant"));
    }
    else
    {
        query.prepare("UPDATE TABLE_PATIENT "
                  " SET CIN = '"+CIN+"', DAT = '"+date+"', ADRESSE = '"+adresse+"', SEXE = '"+sexe+"', NOM = '"+nom+"', PRENOM ='"+prenom+"', LIEU = '"+lieu+"'"
                  "WHERE nom = '"+nom+"' ");
        if(query.exec())
        {
            QMessageBox::information(this, tr("Modifier Patient"), tr("Le Patient a ete modifie avec success"));
        }
        else {
            QMessageBox::critical(this, tr("SAVE"), query.lastError().text());
        }
    }
}
void Modifier::on_radioMale_clicked()
{
    ui->SexeEdit->setText("Male");
}

void Modifier::on_radioFemelle_clicked()
{
    ui->SexeEdit->setText("Femelle");
}

void Modifier::on_pushButton_3_clicked()
{
    ui->nomEdit->setText("");
    ui->prenomEdit->setText("");
    ui->dateEdit->setText("");
    ui->adresseEdit->setText("");
    ui->SexeEdit->setText("");
    ui->LieuEdit->setText("");
    ui->CINEdit->setText("");
}
