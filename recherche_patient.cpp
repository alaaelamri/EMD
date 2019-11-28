#include "recherche_patient.h"
#include "ui_recherche_patient.h"
#include "modifier_patient.h"
#include <qpixmap.h>
#include <QMessageBox>
#include <QSqlError>
#include <QString>
#include <QSqlDatabase>
Recherche_Patient::Recherche_Patient(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Recherche_Patient)
{
    ui->setupUi(this);
    QPixmap pix(":/Ressource/Background_color.png");
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));
    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");
}

Recherche_Patient::~Recherche_Patient()
{
    delete ui;
}

void Recherche_Patient::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");
}

void Recherche_Patient::open_Modifier(QString nom)
{
    Mmodifier = new Modifier(nullptr,nom);

    Mmodifier->show();

}

void Recherche_Patient::on_pushButton_released()
{
    QString nom;
    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 18pt Bahnschrift;");
    nom = ui->lineEdit->text();
    QSqlQuery query;
    if (ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(nullptr, tr("Ajout Patient"), tr("Veuillez entrer le nom du patient à modifier"));
    }
    else
    {
        open_Modifier(nom);
    }
}
