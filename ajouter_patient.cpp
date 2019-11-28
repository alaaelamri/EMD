#include "ajouter_patient.h"
#include "ui_ajouter_patient.h"
#include <qpixmap.h>
#include "patient.h"
#include <QString>
#include <QSqlDatabase>
#include "connection.h"
#include <QMessageBox>
#include <QSqlError>
Ajouter_Patient::Ajouter_Patient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajouter_Patient)
{
    ui->setupUi(this);
    QPixmap pix("D:/Projet C++/Projet/Ressource/icon_add.png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));

    QPixmap pix1("D:/Projet C++/Projet/Ressource/Background_color.png");
    int w1 = ui->label_2->width();
    int h1 = ui->label_2->height();
    ui->label_2->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));

    QPixmap pix2(":/Ressource/checked.png");
    int w2 = ui->label_10->width();
    int h2 = ui->label_10->height();
    ui->label_10->setPixmap(pix2.scaled(h2,w2,Qt::IgnoreAspectRatio));

    QPixmap pix3(":/Ressource/cancel.png");
    int w3 = ui->label_11->width();
    int h3 = ui->label_11->height();
    ui->label_11->setPixmap(pix3.scaled(h3,w3,Qt::IgnoreAspectRatio));

    ui->pushButton->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 20pt Bahnschrift;");
    ui->pushButton_3->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
}

Ajouter_Patient::~Ajouter_Patient()
{
    delete ui;
}


void Ajouter_Patient::on_pushButton_2_pressed()
{
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 20pt Bahnschrift;");

}

void Ajouter_Patient::on_pushButton_2_released()
{
    QString nom, prenom, lieu, adresse, sexe, date, CIN;
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_clicked.png)3 10 3 10; font: 20pt Bahnschrift;");
    date = ui->dateEdit->text();
    CIN = ui->CINEdit->text();
    nom = ui->nomEdit->text();
    prenom = ui->prenomEdit->text();
    lieu = ui->LieuEdit->text();
    sexe = ui->SexeEdit->text();
    adresse = ui->adresseEdit->text();

    if ((ui->nomEdit->text().isEmpty()) || (ui->prenomEdit->text().isEmpty()) || (ui->LieuEdit->text().isEmpty()) || (ui->SexeEdit->text().isEmpty()) || (ui->adresseEdit->text().isEmpty()) ||  (ui->dateEdit->text().isEmpty()) ||  (ui->CINEdit->text().isEmpty()))
    {
        QMessageBox::warning(nullptr, QObject::tr("Attention"),
                    QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);

    }
    else
    {
        QSqlQuery query;
        query.prepare("insert into TABLE_PATIENT (CIN, DAT, ADRESSE, SEXE, NOM, PRENOM, LIEU) values ('"+CIN+"','"+date+"','"+adresse+"','"+sexe+"', '"+nom+"', '"+prenom+"', '"+lieu+"' )");
        query.bindValue(":CIN", CIN);
        query.bindValue(":date", date);
        query.bindValue(":adresse", adresse);
        query.bindValue(":sexe", sexe);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":lieu", lieu);


        if (query.exec())
        {
            QMessageBox::information(this, tr("Ajout Patient"), tr("Le nouveau Patient est ajouté avec success"));
        }
        else
        {
            QMessageBox::critical(this, tr("SAVE"), query.lastError().text());
        }
    }
}

void Ajouter_Patient::on_radioMale_clicked()
{
    ui->SexeEdit->setText("Male");
}

void Ajouter_Patient::on_radioFemelle_clicked()
{
    ui->SexeEdit->setText("Femelle");
}

void Ajouter_Patient::on_pushButton_3_clicked()
{
    ui->nomEdit->setText("");
    ui->prenomEdit->setText("");
    ui->dateEdit->setText("");
    ui->adresseEdit->setText("");
    ui->SexeEdit->setText("");
    ui->LieuEdit->setText("");
    ui->CINEdit->setText("");

}
