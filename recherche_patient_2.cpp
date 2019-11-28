#include "recherche_patient_2.h"
#include "ui_recherche_patient_2.h"
#include "modifier_patient.h"
#include <qpixmap.h>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlDatabase>
#include "connection.h"
Recherche_Patient_2::Recherche_Patient_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recherche_Patient_2)
{
    ui->setupUi(this);
    QPixmap pix(":/Ressource/Background_color.png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));
    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");
}

Recherche_Patient_2::~Recherche_Patient_2()
{
    delete ui;
}

void Recherche_Patient_2::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");
}

void Recherche_Patient_2::on_pushButton_released()
{
    QSqlQuery query;
    QString nom;
    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 18pt Bahnschrift;");
    nom = ui->lineEdit->text();
    if (ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(nullptr, tr("Ajout Patient"), tr("Veuillez entrer le nom du patient à supprimer"));
    }
    else
    {
        if (query.prepare("Select from TABLE_PATIENT where NOM = '"+nom+"'") == false)
        {
            QMessageBox::information(nullptr, tr("Ajout Patient"), tr("Veuillez entrer le nom d'un patient deja existant."));
        }
        else
        {
            query.prepare("Delete from TABLE_PATIENT where NOM = '"+nom+"' ");
            query.bindValue(":nom", nom);
            if (query.exec())
            {
                QMessageBox::information(this, tr("Ajout Patient"), tr("Le Patient a ete supprimé avec success"));
            }
            else
            {
                QMessageBox::critical(this, tr("SAVE"), query.lastError().text());
            }
        }
    }
}
